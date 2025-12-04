#include "Ant.hpp"
#include "util/util.hpp"
#include "main.hpp"
#include <algorithm>
#include <cmath>

Ant::Ant(int x, int y) : x(x), y(y), direction(initialDirection(gen)) {}

// update the ant's position based on some logic
void Ant::update() {
    const float dist = util::distToBorder(x, y, direction);
    const float actualSpeed = std::min(static_cast<float>(SPEED), dist / (MARGIN * SPEED));

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
        direction += drasticTurnDist(gen);
    } else {
        direction += turnDist(gen);
    }

    direction = std::remainder(direction, 2.0f * M_PI);
}

int Ant::getx() const { return x;}
int Ant::gety() const { return y;}
