#include "AntRenderer/AntRenderer.hpp"
#include "util/util.hpp"
#include <cmath>

const int ANT_RADIUS = 3;

void AntRenderer::draw(SDL_Renderer* renderer, const Ant& ant) {
    util::drawFilledCircle(renderer, ant.getx(), ant.gety(), ANT_RADIUS);
}
