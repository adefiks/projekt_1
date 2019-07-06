#pragma once
#include "Game.h"
#include "ECS.h"
#include "Components.h"

class KeyboardController : public Component
{
private:
    /* data */
public:
    TransformComponent *transform;
    SpriteComponent *sprite;

    void init() override
    {
        transform = &entity->getComponent<TransformComponent>();
        sprite = &entity->getComponent<SpriteComponent>();
    }

    void update() override
    {
        if (Game::event.type == SDL_KEYDOWN)
        {
            switch (Game::event.key.keysym.sym)
            {
            case SDLK_w:
                transform->velocity.y = -1;
                sprite->play_animation("Walk_up");
                break;
            case SDLK_s:
                transform->velocity.y = 1;
                sprite->play_animation("Walk_down");
                break;
            case SDLK_a:
                transform->velocity.x = -1;
                sprite->play_animation("Walk_left");
                break;
            case SDLK_d:
                transform->velocity.x = 1;
                sprite->play_animation("Walk_right");
                break;
            default:
                break;
            }
        }

        if (Game::event.type == SDL_KEYUP)
        {
            switch (Game::event.key.keysym.sym)
            {
            case SDLK_w:
                transform->velocity.y = 0;
                sprite->play_animation("Idle");
                break;
            case SDLK_s:
                transform->velocity.y = 0;
                sprite->play_animation("Idle");
                break;
            case SDLK_a:
                transform->velocity.x = 0;
                sprite->play_animation("Idle");
                break;
            case SDLK_d:
                transform->velocity.x = 0;
                sprite->play_animation("Idle");
                break;
            default:
                break;
            }
        }
    }
};
