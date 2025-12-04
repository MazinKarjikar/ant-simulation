#pragma once

#include <random>

class Ant {
private:
    int x{};
    int y{};
    float direction{};

    inline static constexpr int SPEED = 2;
    inline static constexpr int MARGIN = 5;

    inline static std::random_device rd{};
    inline static std::mt19937 gen{rd()};
    inline static std::uniform_real_distribution<float> initialDirection{0.0f, 2 * 3.1415926535f};
    inline static std::normal_distribution<float> turnDist{0.0f, 0.15f};
    inline static std::normal_distribution<float> drasticTurnDist{0.0f, 0.45f};

public:
    Ant() = default;
    Ant(int x, int y);
    void update();
    void randomDirectionChange();
    int getx() const;
    int gety() const;
};
