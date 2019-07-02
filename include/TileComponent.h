#pragma once
#include "Components.h"
#include "common.h"

class TileComponent : public Component
{
private:
    /* data */
public:
    TransformComponent *transform;
    SpriteComponent *sprite;

    SDL_Rect rect;
    int tileID;
    const char *path;

    TileComponent() = default;

    TileComponent(int x, int y, int h, int w, int ID)
    {
        rect.x = x;
        rect.y = y;
        rect.h = h;
        rect.w = w;
        tileID = ID;

        switch (tileID)
        {
        case 0:
            path = "assets/dirt.png";
            break;
        case 1:
            path = "assets/dirt.png";
            break;
        case 2:
            path = "assets/grass.png";
            break;
        case 3:
            path = "assets/water.png";
            break;
        default:
            break;
        }
    }

    void init() override
    {
        entity->addComponent<TransformComponent>((float)rect.x, (float)rect.y, rect.h, rect.w, 1);
        transform = &entity->getComponent<TransformComponent>();

        entity->addComponent<SpriteComponent>(path);
        sprite = &entity->getComponent<SpriteComponent>();
    }
};
