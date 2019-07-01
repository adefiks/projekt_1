#pragma once
#include "Components.h"
#include "Vector2D.h"

class TransformComponent : public Component
{
private:
    // int xpos, ypos;

public:
    Vector2D position;
    Vector2D velocity;

    int speed = 3;
    int width = 32;
    int height = 32;
    int scale = 1;

    TransformComponent()
    {
        position.Zero();
    }

    TransformComponent(int scaleIn)
    {
        position.Zero();

        scale = scaleIn;
    }

    TransformComponent(float x, float y)
    {
        position.x = x;
        position.y = y;
    }

    TransformComponent(float x, float y, int h, int w, int scaleIn)
    {
        position.x = x;
        position.y = y;
        height = h;
        width = w;
        scale = scaleIn;
    }

    // for init this component (set x,y to 0)
    void init() override
    {
        velocity.Zero();
    }

    // updating the x,y pos
    void update() override
    {
        position.x += velocity.x * speed;
        position.y += velocity.y * speed;
    }
};