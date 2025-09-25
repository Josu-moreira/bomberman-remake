#pragma once
#include "include/raylib.h"
#include "sprite.h"

class Animation {
public:
    int currentFrame;
    int maxFrames;
    int row;
    float frameTime;
    float timer;
    bool loop;

    Animation(int frames, float frameDuration, int startRow, bool shouldLoop);

    void update();
    void reset();

    Rectangle getFrame(const Sprite& s) const;
};