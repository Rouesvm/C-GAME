#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <cmath>

namespace utils {
    inline float hireTimeInSeconds() {
        float ticks = SDL_GetTicks();
        ticks *= 0.001F;

        return ticks;
    }
}