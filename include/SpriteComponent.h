#pragma once
#include "Components.h"
#include "common.h"
#include "TextureManager.h"
// #include "Vector2D.h"

class SpriteComponent : public Component
{
private:
    TransformComponent *transform;
    SDL_Texture *texture;
    SDL_Rect srcRect, destRect;

public:
    SpriteComponent() = default;
    SpriteComponent(const char *path)
    {
        setTexture(path);
    }

    ~SpriteComponent()
    {
        SDL_DestroyTexture(texture);
    }

    void setTexture(const char *path)
    {
        texture = TextureManager::LoadTexture(path);
    }

    void init() override
    {
        transform = &entity->getComponent<TransformComponent>();

        srcRect.x = 0;
        srcRect.y = 0;

        srcRect.h = transform->height;
        srcRect.w = transform->width;

        destRect.w = srcRect.w * transform->scale;
        destRect.h = srcRect.h * transform->scale;
    }

    void update() override
    {
        destRect.x = static_cast<int>(transform->position.x);
        destRect.y = static_cast<int>(transform->position.y);
    }

    void draw() override
    {
        TextureManager::Draw(texture, srcRect, destRect);
    }
};