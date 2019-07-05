#pragma once
#include "Components.h"
#include "common.h"
#include "TextureManager.h"
#include "Animation.h"
// #include "Vector2D.h"

class SpriteComponent : public Component
{
private:
    TransformComponent *transform;
    SDL_Texture *texture;
    SDL_Rect srcRect, destRect;

    bool animated = false;
    int frame = 0;
    int animation_speed = 100;

public:
    int animation_index = 0;

    std::map<const char *, Animation> animations;

    SpriteComponent() = default;
    SpriteComponent(const char *path)
    {
        setTexture(path);
    }

    SpriteComponent(const char *path, bool isAnimated)
    {
        Animation walk_down(0, 6, 100);
        Animation walk_right(0, 6, 100);
        Animation walk_up(0, 6, 100);
        Animation walk_left(0, 6, 100);

        // Animation walk_down = Animation(0, 6, 100);
        // Animation walk_right = Animation(1, 6, 100);
        // Animation walk_up = Animation(2, 6, 100);
        // Animation walk_left = Animation(3, 6, 100);

        animations.emplace("Walk_down", walk_down);
        animations.emplace("Walk_right", walk_right);
        animations.emplace("Walk_up", walk_up);
        animations.emplace("Walk_left", walk_left);

        this->animated = true;
        // this->animation_speed = mAnimation_speed;
        // this->frame = mFrame;
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
    }

    void update() override
    {

        srcRect.y = animation_index * transform->height;

        destRect.x = static_cast<int>(transform->position.x);
        destRect.y = static_cast<int>(transform->position.y);
        destRect.w = transform->width * transform->scale;
        destRect.h = transform->height * transform->scale;
    }

    void draw() override
    {
        TextureManager::Draw(texture, srcRect, destRect);
    }

    void play_animation(const char *animation_name)
    {
        this->frame = animations[animation_name].frames;
        this->animation_index = animations[animation_name].index;
        this->animation_speed = animations[animation_name].animation_speed;
    }
};