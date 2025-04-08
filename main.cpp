#include "raylib.h"

int main(){
    // Create new window for game
    const int windowDimensions[2]{384, 384};
    InitWindow(windowDimensions[0], windowDimensions[1], "Knight Battle");
    Texture2D backgroundMap = LoadTexture("nature_tileset/OpenWorldMap.png");
    Vector2 backgroundPos{0.0, 0.0};

    // Game loop
    while(!WindowShouldClose()){
        BeginDrawing();
        DrawTextureEx(backgroundMap, backgroundPos, 0.0, 4.0, WHITE);

        EndDrawing();
    }
}