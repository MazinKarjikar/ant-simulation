#include "Ant.hpp"
#include <random>
#include <cmath>

std::random_device rd;
std::mt19937 gen(rd());
// angle in radians
std::uniform_real_distribution<float> dist(0.0f, 2 * M_PI);

Ant::Ant(int x, int y) : x(x), y(y), direction(dist(gen)) {}

void Ant::update() {

}

void Ant::randomDirectionChange() {
    float directionDelta = dist(gen) / 5;
}