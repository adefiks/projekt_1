#pragma once
#include "common.h"

class Collision
{
private:
    /* data */
public:
    // Axis-Aligned-Bounding-Box
    static bool AABB(const SDL_Rect &object1, const SDL_Rect &object2);
};
