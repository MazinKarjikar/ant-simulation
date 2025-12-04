#include "util/util.hpp"
#include "main.hpp"
#include <algorithm>
#include <cmath>

void util::drawFilledCircle(SDL_Renderer* renderer, const int centerX, const int centerY, const int radius) {
    for (int y = -radius; y <= radius; ++y) {
        int dx = (int)sqrt(radius * radius - y * y); // x distance from center for this y
        int x1 = centerX - dx;
        int x2 = centerX + dx;
        SDL_RenderDrawLine(renderer, x1, centerY + y, x2, centerY + y);
    }
}

float util::distToBorder(const int x, const int y, const float direction) {
    const float dx = std::cos(direction);
    const float dy = std::sin(direction);

    // Sentinel value
    const float INF = static_cast<float>(SCREEN_WIDTH + SCREEN_HEIGHT);
    float minTime = INF;

    // Distance to vertical borders (x = 0 and x = SCREEN_WIDTH)
    if (std::fabs(dx) > 1e-6f) {
        const float timeToLeft = (0.0f - x) / dx;
        if (timeToLeft >= 0.0f) minTime = std::min(minTime, timeToLeft);

        const float timeToRight = (static_cast<float>(SCREEN_WIDTH) - x) / dx;
        if (timeToRight >= 0.0f) minTime = std::min(minTime, timeToRight);
    }

    // Distance to horizontal borders (y = 0 and y = SCREEN_HEIGHT)
    if (std::fabs(dy) > 1e-6f) {
        const float timeToTop = (0.0f - y) / dy;
        if (timeToTop >= 0.0f) minTime = std::min(minTime, timeToTop);

        const float timeToBottom = (static_cast<float>(SCREEN_HEIGHT) - y) / dy;
        if (timeToBottom >= 0.0f) minTime = std::min(minTime, timeToBottom);
    }

    // Compute intersection point along heading, then return pixel distance to it.
    const float hitX = static_cast<float>(x) + minTime * dx;
    const float hitY = static_cast<float>(y) + minTime * dy;
    return distBetweenPoints(static_cast<float>(x), static_cast<float>(y), hitX, hitY);
}

float util::distBetweenPoints(float x1, float y1, float x2, float y2) {
    return std::hypot(x2 - x1, y2 - y1);
}
