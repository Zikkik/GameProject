#include "raylib.h"

class Prop{
    private:
        Texture2D texture{};
        Vector2 worldPos{};
        float scale{4.f};
    public:
        Prop(Vector2 pos, Texture2D tex);
        void render(Vector2 knightPos);
};