#include "Ant.hpp"
#include "util/util.hpp"
#include "main.hpp"
#include <algorithm>
#include <random>
#include <cmath>

std::random_device rd;
std::mt19937 gen(rd());

// angle in radians
std::uniform_real_distribution<float> DIST(0.0f, 2 * M_PI);

// random change in direction in radians
std::normal_distribution<float> TURN_DIST(0.0f, 0.15f);
// drastic random change if near the wall
std::normal_distribution<float> DRASTIC_TURN_DIST(0.0f, 0.7f);

const int MARGIN = 5;

Ant::Ant(int x, int y) : x(x), y(y), direction(DIST(gen)) {}

// update the ant's position based on some logic
void Ant::update() {
    const float dist = util::distToBorder(x, y, direction);
    const float actualSpeed = std::min(static_cast<float>(speed), dist / (MARGIN * speed));

    x += static_cast<int>(actualSpeed * std::cos(direction));
    y += static_cast<int>(actualSpeed * std::sin(direction));

    randomDirectionChange();
}

// change direction slightly randomly
void Ant::randomDirectionChange() {
    // check if close to border, if so, incentivize turning backwards
    const bool nearX = x <= MARGIN || x >= SCREEN_WIDTH  - MARGIN;
    const bool nearY = y <= MARGIN || y >= SCREEN_HEIGHT - MARGIN;

    if (nearX || nearY) {
        direction += DRASTIC_TURN_DIST(gen);
    } else {
        direction += TURN_DIST(gen);
    }

    direction = std::remainder(direction, 2.0f * M_PI);
}

int Ant::getx() const { return x;}
int Ant::gety() const { return y;}
