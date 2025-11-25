#pragma once

class Ant {
private:
    int x, y;
    float direction;

public:
    Ant();
    void move();
    void randomDirectionChange();
};