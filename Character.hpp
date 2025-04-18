#ifndef CHARACTER_H
#define CHARACTER_H

#include "raylib.h"
#include "BaseCharacter.hpp"

class Character : public BaseCharacter {
    private:
    public:
        Character(int winWidth, int winHeight);
        virtual void tick(float DeltaTime) override;
        Vector2 getScreenPos();
};

#endif