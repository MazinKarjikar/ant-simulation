#include "Ant.hpp"
#include <random>
#include <cmath>

std::random_device rd;
std::mt19937 gen(rd());

// angle in radians
std::uniform_real_distribution<float> DIST(0.0f, 2 * M_PI);

// random change in direction in radians
std::normal_distribution<float> TURN_DIST(0.0f, 0.15f);

Ant::Ant(int x, int y) : x(x), y(y), direction(DIST(gen)) {}

void Ant::update() {
    x += static_cast<int>(speed * std::cos(direction));
    y += static_cast<int>(speed * std::sin(direction));
    randomDirectionChange();
}

void Ant::randomDirectionChange() {
    direction += TURN_DIST(gen);
    direction = std::remainder(direction, 2.0f * M_PI);
}

int Ant::getx() const { return x;}
int Ant::gety() const { return y;}