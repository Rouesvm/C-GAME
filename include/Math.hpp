#pragma once

#include <iostream>

struct Vector2f {
    Vector2f()
    :x(0.0F), y(0.0F) 
    {}
    Vector2f(float p_x, float p_y)
    :x(p_x), y(p_y)
    {}

    void print() const{
        std::cout << x << ", " << y << '\n';
    }

    float x, y;
};
