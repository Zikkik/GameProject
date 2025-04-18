#include "raylib.h"
#include "raymath.h"
#include "Character.hpp"
#include "Prop.hpp"
#include "Enemy.hpp"
#include <string>

int main(){
    // Create new window for game
    const int windowDimensions[2]{384, 384};
    InitWindow(windowDimensions[0], windowDimensions[1], "Knight Battle");
    Texture2D backgroundMap = LoadTexture("nature_tileset/OpenWorldMap.png");
    Vector2 backgroundPos{0.0, 0.0};
    const float mapScale{4.0f};

    Character knight(windowDimensions[0], windowDimensions[1]);

    // Create props
    Prop props[2] {
        Prop{ Vector2{600.f, 300.f}, LoadTexture("nature_tileset/Rock.png") },
        Prop{ Vector2{400.f, 500.f}, LoadTexture("nature_tileset/Log.png") },
    };

    // Create enemy
    Enemy goblin{
        Vector2{800.f, 300.f},
        LoadTexture("characters/goblin_idle_spritesheet.png"),
        LoadTexture("characters/goblin_run_spritesheet.png")
    };

    Enemy slime{
        Vector2{600.f, 700.f},
        LoadTexture("characters/slime_idle_spritesheet.png"),
        LoadTexture("characters/slime_run_spritesheet.png")
    };

    Enemy* enemies[] {
        &goblin,
        &slime
    };

    for(auto enemy : enemies)
        enemy->setTarget(&knight);

    SetTargetFPS(60);

    // Game loop
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(WHITE);

        backgroundPos = Vector2Scale(knight.getWorldPos(), -1.f);

        // Draw the background
        DrawTextureEx(backgroundMap, backgroundPos, 0.0, mapScale, WHITE);

        // Draw the props
        for (auto prop : props)
            prop.render(knight.getWorldPos());

        if(!knight.getAlive()){
            DrawText("Game Over!", 55.f, 45.f, 40, RED);
            EndDrawing();
            continue;
        } else {
            std::string knightHealth = "Health: ";
            knightHealth.append(std::to_string(knight.getHealth()), 0, 5);
            DrawText(knightHealth.c_str(), 55.f, 45.f, 40, RED);
        }

        knight.tick(GetFrameTime());
        if (knight.getWorldPos().x < 0.f || 
            knight.getWorldPos().y < 0.f || 
            knight.getWorldPos().x + windowDimensions[0] > backgroundMap.width * mapScale ||
            knight.getWorldPos().y + windowDimensions[1] > backgroundMap.height * mapScale)
        {
            knight.undoMovement();
        }

        for (auto prop : props)
            if (CheckCollisionRecs(prop.getCollisionRec(knight.getWorldPos()), knight.getCollisionRec()))
                knight.undoMovement();

        for(auto enemy : enemies){
            enemy->tick(GetFrameTime());
        }

        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
            for(auto enemy : enemies)
                if(CheckCollisionRecs(enemy->getCollisionRec(), knight.getCollisionRec()))
                    enemy->setAlive(false);
        }

        EndDrawing();
    }
}