#include "anim.h"

Animation::Animation(int frames = 1, float frameDuration = 0.2f, int startRow = 0, bool shouldLoop=true)
    : currentFrame(0), maxFrames(frames), row(startRow), frameTime(frameDuration), timer(0.0f), loop(shouldLoop) {}

void Animation::update() {
    if (!loop) return;

    timer += GetFrameTime();
    if(timer >= frameTime) {
        timer = 0.0f;
        currentFrame++;
        if(currentFrame >= maxFrames) currentFrame = 0;
    }
}

void Animation::reset() {
    currentFrame = 0;
    timer = 0.0f;
}

Rectangle Animation::getFrame(const Sprite& s) const {
    return Rectangle{
        (float)(currentFrame * s.frameWidth),
        (float)(row * s.frameHeight),
        (float)s.frameWidth,
        (float)s.frameHeight
    };
}