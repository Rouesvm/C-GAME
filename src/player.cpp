#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_keyboard.h>
#include <SDL2/SDL_mouse.h>
#include <SDL2/SDL_scancode.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_video.h>

#include "../include/Entity.hpp"
#include "../include/Player.hpp"

Player::Player(SDL_Texture *p_tex) : Entity(p_tex)
{
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = 32;
    currentFrame.h = 32;

    velocity.x = 0;
    velocity.y = 0;
}

void Player::update(float frameTime)
{
    const int SCREEN_WIDTH = 1280;
    const int SCREEN_HEIGHT = 720;

    pos.x += velocity.x * SPEED * frameTime;
    pos.y += velocity.y * SPEED * frameTime;

    if ( (pos.x < 0) || (pos.x + currentFrame.w > SCREEN_WIDTH) ) 
    {
        pos.x -= velocity.x;
    }

    if ( (pos.y < 0) || (pos.y + currentFrame.h > SCREEN_HEIGHT) ) 
    {
        pos.y -= velocity.y;
    }

    setPos(pos);
}

void Player::handleEvent(SDL_Event& event)
{
   if (event.type == SDL_KEYDOWN && event.key.repeat == 0)
    {
        switch (event.key.keysym.sym)
        {
            case SDLK_UP: velocity.y -= 1; break;
            case SDLK_DOWN: velocity.y += 1; break;
            case SDLK_LEFT: velocity.x -= 1; break;
            case SDLK_RIGHT: velocity.x += 1; break;
        }
    } else if (event.type == SDL_KEYUP && event.key.repeat == 0) {
        switch (event.key.keysym.sym)
        {
            case SDLK_UP: velocity.y += 1; break;
            case SDLK_DOWN: velocity.y -= 1; break;
            case SDLK_LEFT: velocity.x += 1; break;
            case SDLK_RIGHT: velocity.x -= 1; break;
        }
    }
}