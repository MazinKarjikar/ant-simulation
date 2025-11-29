#pragma once
#include <SDL2/SDL.h>
#include <array>
#include "Ant/Ant.hpp"
#include "AntRenderer/AntRenderer.hpp"

template <std::size_t Count>
class Simulation {
private:
    std::array<Ant, Count> ants;
    SDL_Renderer* renderer = nullptr;
    SDL_Window* window = nullptr;
    const int SCREEN_WIDTH = 1800;
    const int SCREEN_HEIGHT = 800;
public:
    Simulation() {
        for(std::size_t i = 0; i < Count; i++) {
            ants[i] = Ant(300, 300);
        }
        SDL_Init(SDL_INIT_EVERYTHING);
        SDL_CreateWindowAndRenderer(
            SCREEN_WIDTH,
            SCREEN_HEIGHT,
            0,
            &window,
            &renderer
        );
    }

    ~Simulation() {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    void run() {
        bool running = true;
        SDL_Event event;

        // int SQUARE_SIZE = 20;

        // int x = 200;
        // int y = 200;
        // int vx = 0;
        // int vy = 0;
        // int speed = 8;

        while (running) {
            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_QUIT)
                    running = false;
                // if (event.type == SDL_KEYDOWN && !event.key.repeat) {
                //     switch (event.key.keysym.sym) {
                //         case SDLK_UP:      vy -= speed; break;
                //         case SDLK_DOWN:    vy += speed; break;
                //         case SDLK_RIGHT:   vx += speed; break;
                //         case SDLK_LEFT:    vx -= speed; break;
                //         default: break;
                //     }
                // }
                // if (event.type == SDL_KEYUP) {
                //     switch (event.key.keysym.sym) {
                //         case SDLK_UP:      vy += speed; break;
                //         case SDLK_DOWN:    vy -= speed; break;
                //         case SDLK_RIGHT:   vx -= speed; break;
                //         case SDLK_LEFT:    vx += speed; break;
                //         default: break;
                //     }
                // }
            }

            // Clear screen with black
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderClear(renderer);

            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

            update();
            render();

            // Draw a white rectangle
            // SDL_Rect rect = { x, y, SQUARE_SIZE, SQUARE_SIZE };
            // SDL_RenderFillRect(renderer, &rect);

            // Mirror on X
            // if (x + SQUARE_SIZE > SCREEN_WIDTH) {
            //     SDL_Rect rect2 = { x - SCREEN_WIDTH, y, SQUARE_SIZE, SQUARE_SIZE };
            //     SDL_RenderFillRect(renderer, &rect2);
            // }
            // Mirror on Y
            // if (y + SQUARE_SIZE > SCREEN_HEIGHT) {
            //     SDL_Rect rect2 = { x, y - SCREEN_HEIGHT, SQUARE_SIZE, SQUARE_SIZE };
            //     SDL_RenderFillRect(renderer, &rect2);
            // }

            // Display what has been rendered so far.
            SDL_RenderPresent(renderer);

            // Move rect
            // x = (x + vx + SCREEN_WIDTH) % SCREEN_WIDTH;
            // y = (y + vy + SCREEN_HEIGHT) % SCREEN_HEIGHT;

            SDL_Delay(16); // modifies update rate.
        }
    }

    void update() {
        for (Ant& ant: ants) {
            ant.update();
        }
    }

    void render() {
        for (const Ant& ant : ants) {
            AntRenderer::draw(renderer, ant);
        }
    }
};
