#pragma once
#include "Components.h"
#include "common.h"

class TileComponent : public Component
{
private:
    /* data */
public:
    SDL_Texture *texture;
    SDL_Rect srcRect, destRect;
    Vector2D position;

    TileComponent() = default;

    ~TileComponent()
    {
        SDL_DestroyTexture(texture);
    }

    TileComponent(int src_x, int src_y, int x, int y, const char *path)
    {
        texture = TextureManager::LoadTexture("assets/tiles.png");

        position.x = x;
        position.y = y;

        srcRect.x = src_x;
        srcRect.y = src_y;
        srcRect.h = 32;
        srcRect.w = 32;

        destRect.x = x;
        destRect.y = y;
        destRect.h = 64;
        destRect.w = 64;
    }

    void update() override
    {
        destRect.x = position.x - Game::camera.x;
        destRect.y = position.y - Game::camera.y;
    }

    void draw() override
    {
        TextureManager::Draw(texture, srcRect, destRect);
    }
};
