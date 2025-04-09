#include "raylib.h"
#include "raymath.h"
#include "Character.hpp"

int main(){
    // Create new window for game
    const int windowDimensions[2]{384, 384};
    InitWindow(windowDimensions[0], windowDimensions[1], "Knight Battle");
    Texture2D backgroundMap = LoadTexture("nature_tileset/OpenWorldMap.png");
    Vector2 backgroundPos{0.0, 0.0};

    Character knight;
    knight.setScreenPos(windowDimensions[0], windowDimensions[1]);

    SetTargetFPS(60);

    // Game loop
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(WHITE);

        backgroundPos = Vector2Scale(knight.getWorldPos(), -1.f);

        // Draw the background
        DrawTextureEx(backgroundMap, backgroundPos, 0.0, 4.0, WHITE);

        knight.tick(GetFrameTime());

        EndDrawing();
    }
}