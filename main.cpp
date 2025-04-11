#include "raylib.h"
#include "raymath.h"
#include "Character.hpp"
#include "Prop.hpp"

int main(){
    // Create new window for game
    const int windowDimensions[2]{384, 384};
    InitWindow(windowDimensions[0], windowDimensions[1], "Knight Battle");
    Texture2D backgroundMap = LoadTexture("nature_tileset/OpenWorldMap.png");
    Vector2 backgroundPos{0.0, 0.0};
    const float mapScale{4.0f};

    Character knight(windowDimensions[0], windowDimensions[1]);

    Prop rock{ Vector2{0.f, 0.f}, LoadTexture("nature_tileset/Rock.png") };

    SetTargetFPS(60);

    // Game loop
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(WHITE);

        backgroundPos = Vector2Scale(knight.getWorldPos(), -1.f);

        // Draw the background
        DrawTextureEx(backgroundMap, backgroundPos, 0.0, mapScale, WHITE);

        rock.render(knight.getWorldPos());

        knight.tick(GetFrameTime());
        if (knight.getWorldPos().x < 0.f || 
            knight.getWorldPos().y < 0.f || 
            knight.getWorldPos().x + windowDimensions[0] > backgroundMap.width * mapScale ||
            knight.getWorldPos().y + windowDimensions[1] > backgroundMap.height * mapScale)
        {
            knight.undoMovement();
        }

        EndDrawing();
    }
}