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

    // Create character
    Texture2D knight = LoadTexture("characters/knight_idle_spritesheet.png");
    Vector2 knightPos{
        (float)windowDimensions[0] / 2.0f - 4.0f * (0.5f * (float)knight.width / 6.0f),
        (float)windowDimensions[1] / 2.0f - 4.0f * (0.5f * (float)knight.height)
    };

    // Create variables to store knight's animations
    Texture2D knight_idle = LoadTexture("characters/knight_idle_spritesheet.png");
    Texture2D knight_run = LoadTexture("characters/knight_run_spritesheet.png");

    // 1: facing right | -1: facing right
    float rightLeft{1.f};

    // Animation variables
    float runningTime{};
    int frame{};
    const int maxFrames{6};
    const float updateTime{1.f / 12.f};

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

            if (direction.x < 0.f)
                rightLeft = -1.f;
            else
                rightLeft = 1.f;

            knight = knight_run;
        } else
            knight = knight_idle;

        // Draw the background
        DrawTextureEx(backgroundMap, backgroundPos, 0.0, 4.0, WHITE);

        // Update animation frame
        runningTime += GetFrameTime();
        if(runningTime >= updateTime){
            frame++;
            runningTime = 0.f;
            if(frame > maxFrames) frame = 0;
        }

        // Draw the character
        Rectangle source{(float)knight.width / 6.f * frame, 0.f, (float)knight.width / 6.f * rightLeft, (float)knight.height};
        Rectangle dest{knightPos.x, knightPos.y, 4.0f * (float)knight.width / 6.0f, 4.0f * (float)knight.height};
        DrawTexturePro(knight, source, dest, Vector2{}, 0.f, WHITE);

        EndDrawing();
    }
}