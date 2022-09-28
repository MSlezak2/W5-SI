#pragma once
#include "Garbage.h"

class BottleCap :
    public Garbage {
public:
    enum class colors {PINK, WHITE, BLACK, BLUE, GREEN};
    BottleCap() = default;
    BottleCap(colors color);
    colors getColor() { return color; };

private:
    colors color;
};

