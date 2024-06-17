#include "../include/Entity.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <sys/types.h>

Entity::Entity(SDL_Texture* p_tex)
:pos(Vector2f(0, 0)), tex(p_tex) 
{
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = 32;
    currentFrame.h = 32;
}

Vector2f &Entity::getPos()
{
    return pos;
}

void Entity::setPos(Vector2f vector2f)
{
    this->pos = vector2f;
}