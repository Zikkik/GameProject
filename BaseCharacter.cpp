#include "BaseCharacter.hpp"

BaseCharacter::BaseCharacter(){
    
}

void BaseCharacter::undoMovement(){
    worldPos = worldPosLastFrame;
}

Rectangle BaseCharacter::getCollisionRec(){
    return Rectangle{
        screenPos.x,
        screenPos.y,
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
    
    // Draw the character
    Rectangle source{width * frame, 0.f, width * rightLeft, height};
    Rectangle dest{screenPos.x, screenPos.y, scale * width, scale * height};
    DrawTexturePro(texture, source, dest, Vector2{}, 0.f, WHITE);
}