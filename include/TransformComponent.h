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
        position.x = 0.0f;
        position.y = 0.0f;
    }

    TransformComponent(int scaleIn)
    {
        position.x = 0.0f;
        position.y = 0.0f;

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

    // float x() { return position.x; }
    // float y() { return position.y; }

    // void x(float x) { position.x = x; }
    // void y(float y) { position.y = y; }

    // for init this component (set x,y to 0)
    void init() override
    {
        velocity.x = 0;
        velocity.y = 0;
    }

    // updating the x,y pos
    void update() override
    {
        position.x += velocity.x * speed;
        position.y += velocity.y * speed;
        // xpos++;
        // ypos++;
    }

    // for seting components x,y
    // void setPos(int x, int y)
    // {
    //     xpos = x;
    //     ypos = y;
    // }
};