#include "AntRenderer/AntRenderer.hpp"
#include <cmath>

const int ANT_RADIUS = 3;

void AntRenderer::draw(SDL_Renderer* renderer, const Ant& ant) {
    AntRenderer::drawFilledCircle(renderer, ant.getx(), ant.gety(), ANT_RADIUS);
}

void AntRenderer::drawFilledCircle(SDL_Renderer* renderer, int centerX, int centerY, int radius) {
    for (int y = -radius; y <= radius; ++y) {
        int dx = (int)sqrt(radius * radius - y * y); // x distance from center for this y
        int x1 = centerX - dx;
        int x2 = centerX + dx;
        SDL_RenderDrawLine(renderer, x1, centerY + y, x2, centerY + y);
    }
}