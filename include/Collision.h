#pragma once
#include "common.h"
#include "ColliderComponent.h"

// Forward declaration
class ColliderComponent;

class Collision
{
private:
    /* data */
public:
    // Axis-Aligned-Bounding-Box
    static bool AABB(const SDL_Rect &object1, const SDL_Rect &object2);

    //Axis-Aligned-Bounding-Box with Collider Components
    static bool AABB(const ColliderComponent &col1, const ColliderComponent &col2);
};
