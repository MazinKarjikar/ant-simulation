#include "../main.hpp"
#include "Ant.hpp"
#include <random>
#include <cmath>

const int START_X = 300;
const int START_Y = 300;
const float SPEED = 2.0f;

std::random_device rd;
std::mt19937 gen(rd());
// angle in radians
std::uniform_real_distribution<float> dist(0.0f, 2 * M_PI);

Ant::Ant() : x(START_X), y(START_Y), direction(dist(gen)) {}

void Ant::move() {
}

void Ant::randomDirectionChange() {
    float directionDelta = dist(gen) / 5;

}