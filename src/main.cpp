#include <SDL2/SDL.h>
#include <cmath>
#include "Simulation/Simulation.hpp"

const int SCREEN_HEIGHT = 800;
const int SCREEN_WIDTH = 1800;

void drawFilledCircle(SDL_Renderer* renderer, int centerX, int centerY, int radius) {
    for (int y = -radius; y <= radius; ++y) {
        int dx = (int)sqrt(radius * radius - y * y); // x distance from center for this y
        int x1 = centerX - dx;
        int x2 = centerX + dx;
        SDL_RenderDrawLine(renderer, x1, centerY + y, x2, centerY + y);
    }
}

int main() {

    Simulation sim = Simulation<3>();

    // SDL_Window* window = nullptr;
    // SDL_Renderer* renderer = nullptr;

    // SDL_Init(SDL_INIT_EVERYTHING);
    // SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &window, &renderer);

    // bool running = true;
    // SDL_Event event;

    // int SQUARE_SIZE = 20;

    // int x = 200;
    // int y = 200;
    // int vx = 0;
    // int vy = 0;
    // int speed = 8;

    // while (running) {
    //     while (SDL_PollEvent(&event)) {
    //         if (event.type == SDL_QUIT)
    //             running = false;
    //         if (event.type == SDL_KEYDOWN && !event.key.repeat) {
    //             switch (event.key.keysym.sym) {
    //                 case SDLK_UP:      vy -= speed; break;
    //                 case SDLK_DOWN:    vy += speed; break;
    //                 case SDLK_RIGHT:   vx += speed; break;
    //                 case SDLK_LEFT:    vx -= speed; break;
    //                 default: break;
    //             }
    //         }
    //         if (event.type == SDL_KEYUP) {
    //             switch (event.key.keysym.sym) {
    //                 case SDLK_UP:      vy += speed; break;
    //                 case SDLK_DOWN:    vy -= speed; break;
    //                 case SDLK_RIGHT:   vx -= speed; break;
    //                 case SDLK_LEFT:    vx += speed; break;
    //                 default: break;
    //             }
    //         }
    //     }

    //     // Clear screen with black
    //     SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    //     SDL_RenderClear(renderer);

    //     SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    //     // Draw a white circle
    //     drawFilledCircle(renderer, x, y, 20);

    //     // Draw a white rectangle
    //     // SDL_Rect rect = { x, y, SQUARE_SIZE, SQUARE_SIZE };
    //     // SDL_RenderFillRect(renderer, &rect);

    //     // Mirror on X
    //     // if (x + SQUARE_SIZE > SCREEN_WIDTH) {
    //     //     SDL_Rect rect2 = { x - SCREEN_WIDTH, y, SQUARE_SIZE, SQUARE_SIZE };
    //     //     SDL_RenderFillRect(renderer, &rect2);
    //     // }
    //     // Mirror on Y
    //     // if (y + SQUARE_SIZE > SCREEN_HEIGHT) {
    //     //     SDL_Rect rect2 = { x, y - SCREEN_HEIGHT, SQUARE_SIZE, SQUARE_SIZE };
    //     //     SDL_RenderFillRect(renderer, &rect2);
    //     // }


    //     // Display what was drawn
    //     SDL_RenderPresent(renderer);

    //     // Move rect
    //     x = (x + vx + SCREEN_WIDTH) % SCREEN_WIDTH;
    //     y = (y + vy + SCREEN_HEIGHT) % SCREEN_HEIGHT;

    //     SDL_Delay(16); // approximates 120 FPS
    // }

    // SDL_DestroyRenderer(renderer);
    // SDL_DestroyWindow(window);
    // SDL_Quit();

    return 0;
}
