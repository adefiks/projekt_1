#pragma once
#include "common.h"
#include "Components.h"

class ColliderComponent : public Component
{
private:
    /* data */
public:
    SDL_Rect collider;
    string tag;

    TransformComponent *transform;

    ColliderComponent(string t)
    {
        tag = t;
    }

    ColliderComponent(string t, int x, int y, int size)
    {
        tag = t;
        collider = {x, y, size, size};
    }

    void init() override
    {
        if (!entity->hasComponent<TransformComponent>())
        {
            entity->addComponent<TransformComponent>();
        }
        transform = &entity->getComponent<TransformComponent>();

        // Game::colliders.push_back(this);
    }

    void update() override
    {
        if (tag != "terrain")
        {
            collider.x = static_cast<int>(transform->position.x);
            collider.y = static_cast<int>(transform->position.y);
            collider.w = transform->width * transform->scale;
            collider.h = transform->height * transform->scale;
        }
    }
};
