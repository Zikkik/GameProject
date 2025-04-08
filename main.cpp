#include "raylib.h"
#include "raymath.h"

int main(){
    // Create new window for game
    const int windowDimensions[2]{384, 384};
    InitWindow(windowDimensions[0], windowDimensions[1], "Knight Battle");
    Texture2D backgroundMap = LoadTexture("nature_tileset/OpenWorldMap.png");
    Vector2 backgroundPos{0.0, 0.0};

    // Set movement speed
    const float speed{4.0};

    SetTargetFPS(60);

    // Game loop
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(WHITE);

        // Movement
        Vector2 direction{};
        if(IsKeyDown(KEY_A)) direction.x -= 1.0;
        if(IsKeyDown(KEY_D)) direction.x += 1.0;
        if(IsKeyDown(KEY_W)) direction.y -= 1.0;
        if(IsKeyDown(KEY_S)) direction.y += 1.0;
        if(Vector2Length(direction) != 0.0){
            // Set backgroundPos = backgroundPos - direction
            backgroundPos = Vector2Subtract(backgroundPos, Vector2Scale(Vector2Normalize(direction), speed));
        }

        DrawTextureEx(backgroundMap, backgroundPos, 0.0, 4.0, WHITE);

        EndDrawing();
    }
}