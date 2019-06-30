#pragma once

#include "ECS.h"
#include "PositionComponent.h"
#include "SpriteComponent.h"

// class PositionComponent : public Component
// {
// private:
//     int xpos, ypos;

// public:
//     int x() { return xpos; }
//     int y() { return ypos; }

//     // for init this component (set x,y to 0)
//     void init() override
//     {
//         xpos = 0;
//         ypos = 0;
//     }

//     // updating the x,y pos
//     void update() override
//     {
//         xpos++;
//         ypos++;
//     }

//     // for seting components x,y
//     void setPos(int x, int y)
//     {
//         xpos = x;
//         ypos = y;
//     }
// };
