#pragma once
#include <array>
#include "Ant/Ant.hpp"

template <std::size_t Count>
class Simulation {
private:
    std::array<Ant, Count> ants;
public:
    Simulation() {
        for(size_t i = 0; i < Count; i++) {
            ants[i] = Ant(300, 300);
        }
    }

    void update() {
        for (auto& ant: ants) {
            ant.update();
        }
    }

    void render();
};
