#include "util/util.hpp"
#include "main.hpp"
#include <algorithm>
#include <cmath>

int util::distToBorder(const int x, const int y) {
    return std::min(
        std::min(std::abs(x - 0), std::abs(y - 0)),
        std::min(std::abs(x - SCREEN_WIDTH), std::abs(y - SCREEN_HEIGHT))
    );
}
