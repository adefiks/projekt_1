#pragma once

class Animation
{
public:
    int index_x, index_y;
    int frames;
    int animation_speed;

    Animation(int mIndex_x, int mIndex_y, int mFrames, int mAnimation_speed) : index_x(mIndex_x), index_y(mIndex_y), frames(mFrames), animation_speed(mAnimation_speed){};
};
