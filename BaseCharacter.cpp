#include "BaseCharacter.hpp"
#include "raymath.h"

BaseCharacter::BaseCharacter(){
    
}

void BaseCharacter::undoMovement(){
    worldPos = worldPosLastFrame;
}

Rectangle BaseCharacter::getCollisionRec(){
    return Rectangle{
        getScreenPos().x,
        getScreenPos().y,
        width * scale,
        height * scale
    };
}

void BaseCharacter::tick(float DeltaTime){
    worldPosLastFrame = worldPos;

    // Update animation frame
    runningTime += DeltaTime;
    if(runningTime >= updateTime){
        frame++;
        runningTime = 0.f;
        if(frame > maxFrames) frame = 0;
    }

    if(Vector2Length(velocity) != 0.0){
        // Set worldPos = worldPos + direction
        worldPos = Vector2Add(worldPos, Vector2Scale(Vector2Normalize(velocity), speed));
    
        if (velocity.x < 0.f)
            rightLeft = -1.f;
        else
            rightLeft = 1.f;
    
        texture = run;
    } else
        texture = idle;

    velocity = {};
    
    // Draw the character
    Rectangle source{width * frame, 0.f, width * rightLeft, height};
    Rectangle dest{getScreenPos().x, getScreenPos().y, scale * width, scale * height};
    DrawTexturePro(texture, source, dest, Vector2{}, 0.f, WHITE);
}