#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>

#include "Math.hpp"

class Entity {
    public:
        explicit Entity(SDL_Texture* p_tex);

        Vector2f& getPos();
        void setPos(Vector2f vector2f);

        SDL_Rect currentFrame;
        SDL_Texture* tex;
    private:
        Vector2f pos;
};
