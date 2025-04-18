#ifndef CHARACTER_H
#define CHARACTER_H

#include "raylib.h"
#include "BaseCharacter.hpp"

class Character : public BaseCharacter {
    private:
        int windowWidth{};
        int windowHeight{};
        Texture2D weapon{LoadTexture("characters/weapon_sword.png")};
        Rectangle weaponCollisionRec{};
        float  rotation{};
        float health{100.f};
    public:
        Character(int winWidth, int winHeight);
        virtual void tick(float DeltaTime) override;
        virtual Vector2 getScreenPos() override;
        Rectangle getWaponCollisionRec() { return weaponCollisionRec; }
        float getHealth() const { return health; }
        void takeDamage(float damage);
};

#endif