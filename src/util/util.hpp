#pragma once

#include <SDL2/SDL.h>

namespace util {
    void drawFilledCircle(SDL_Renderer*, const int x, const int y, const int radius);
    float distToBorder(const int x, const int y, const float direction);
    float distBetweenPoints(float x1, float y1, float x2, float y2);
}
