#pragma once
#include "Components.h"
#include "Vector2D.h"

class TransformComponent : public Component
{
private:
    // int xpos, ypos;

public:
    Vector2D position;

    TransformComponent()
    {
        position.x = 0.0f;
        position.y = 0.0f;
    }

    TransformComponent(float x, float y)
    {
        position.x = x;
        position.y = y;
    }

    // float x() { return position.x; }
    // float y() { return position.y; }

    // void x(float x) { position.x = x; }
    // void y(float y) { position.y = y; }

    // for init this component (set x,y to 0)
    // void init() override
    // {
    //     xpos = 0;
    //     ypos = 0;
    // }

    // updating the x,y pos
    void update() override
    {
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