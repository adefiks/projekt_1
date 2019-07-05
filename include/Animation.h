#pragma once

class Animation
{
public:
    int index;
    int frames;
    int animation_speed;

    Animation(int mIndex, int mFrames, int mAnimation_speed) : index(mIndex), frames(mFrames), animation_speed(mAnimation_speed){};
    ~Animation();
};
