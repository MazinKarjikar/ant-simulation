#pragma once
#include "Ant/Ant.hpp"
#include "AntRenderer/AntRenderer.hpp"
#include "util/util.hpp"
#include "main.hpp"
#include <SDL2/SDL.h>
#include <array>
#include <vector>

template <std::size_t Count>
class Simulation {
private:
    std::array<Ant, Count> ants;
    SDL_Renderer* renderer = nullptr;
    SDL_Window* window = nullptr;
    std::vector<std::pair<int,int>> food;
public:
    Simulation() {
        for(std::size_t i = 0; i < Count; i++) {
            ants[i] = Ant(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
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

        while (running) {
            while (SDL_PollEvent(&event)) {
                switch (event.type) {
                    case SDL_QUIT:
                        running = false;
                        break;
                    case SDL_MOUSEBUTTONDOWN:
                        food.emplace_back(event.button.x, event.button.y);
                        break;
                    default: break;
                }
                if (event.type == SDL_QUIT)
                    running = false;
            }

            // Clear screen with black
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderClear(renderer);

            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

            update();
            render();

            SDL_RenderPresent(renderer);

            SDL_Delay(20); // modifies update delay in ms
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
        for (const auto& [x, y] : food) {
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
            util::drawFilledCircle(renderer, x, y, 3);
        }
    }
};
