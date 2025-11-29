#pragma once

#include <SDL2/SDL.h>
#include "Ant/Ant.hpp"
#

namespace AntRenderer {
    void draw(SDL_Renderer*, const Ant&);
    void drawFilledCircle(SDL_Renderer*, int, int, int);
}