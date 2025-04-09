#include "raylib.h"
#include "raymath.h"
#include "Character.hpp"

Character::Character(){
    width = texture.width / maxFrames;
    height = texture.height;
}

void Character::setScreenPos(int winWidth, int winHeight){
    screenPos = {
        (float)winWidth / 2.0f - 4.0f * (0.5f * width),
        (float)winHeight / 2.0f - 4.0f * (0.5f * height)
    };
}

void Character::tick(float DeltaTime){
    // Movement
    Vector2 direction{};
    if(IsKeyDown(KEY_A)) direction.x -= 1.0;
    if(IsKeyDown(KEY_D)) direction.x += 1.0;
    if(IsKeyDown(KEY_W)) direction.y -= 1.0;
    if(IsKeyDown(KEY_S)) direction.y += 1.0;

    if(Vector2Length(direction) != 0.0){
        // Set worldPos = worldPos + direction
        worldPos = Vector2Add(worldPos, Vector2Scale(Vector2Normalize(direction), speed));
    
        if (direction.x < 0.f)
            rightLeft = -1.f;
        else
            rightLeft = 1.f;
    
        texture = run;
    } else
        texture = idle;

    // Update animation frame
    runningTime += DeltaTime;
    if(runningTime >= updateTime){
        frame++;
        runningTime = 0.f;
        if(frame > maxFrames) frame = 0;
    }

    // Draw the character
    Rectangle source{width * frame, 0.f, width * rightLeft, height};
    Rectangle dest{screenPos.x, screenPos.y, 4.0f * width, 4.0f * height};
    DrawTexturePro(texture, source, dest, Vector2{}, 0.f, WHITE);
}