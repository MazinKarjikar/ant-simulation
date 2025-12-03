#pragma once

class Ant {
private:
    int x{};
    int y{};
    float direction{};
    inline static const int speed = 5;

public:
    Ant() = default;
    Ant(int x, int y);
    void update();
    void randomDirectionChange();
    int getx() const;
    int gety() const;
};
