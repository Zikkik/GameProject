#include "raylib.h"
#include "BaseCharacter.hpp"
#include "Character.hpp"

class Enemy : public BaseCharacter {
    private:
        Character* target;
    public:
        Enemy(Vector2 pos, Texture2D idle_texture, Texture2D run_texture);
        virtual void tick(float DeltaTime) override;
        void setTarget(Character* target);
};