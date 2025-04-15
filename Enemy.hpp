#include "raylib.h"


class Enemy{
    private:
        Texture2D texture{LoadTexture("characters/knight_idle_spritesheet.png")};
        Texture2D idle{LoadTexture("characters/goblin_idle_spritesheet.png")};
        Texture2D run{LoadTexture("characters/goblin_run_spritesheet.png")};
        Vector2 screenPos{};
        Vector2 worldPos{};
        Vector2 worldPosLastFrame{};
        // 1: facing right | -1: facing right
        float rightLeft{1.f};
        // Animation variables
        float runningTime{};
        int frame{};
        int maxFrames{6};
        float updateTime{1.f / 12.f};
        float speed{4.f};
        float width{};
        float height{};
        float scale{4.f};
    public:
        Enemy(Vector2 pos, Texture2D idle_texture, Texture2D run_texture);
        Vector2 getWorldPos() { return worldPos; }
        void tick(float DeltaTime);
        void undoMovement();
        Rectangle getCollisionRec();
};