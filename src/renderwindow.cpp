#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <cstddef>
#include <iostream>

#include "../include/RenderWindow.hpp"
#include "../include/Entity.hpp"

RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h)
    :window(NULL), renderer(NULL)
{
    window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h,
     SDL_WINDOW_SHOWN);

    if (window == NULL) {
        std::cout << "Window failed to init. ERROR:" << SDL_GetError() << std::endl;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

SDL_Texture* RenderWindow::loadTexture(const char* p_filePath) {
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(renderer, p_filePath);

    if (texture == NULL)
        std::cout << "Failed to load texture. ERROR:" << SDL_GetError() << std::endl;

    return texture;
}

int RenderWindow::getRefreshRate() {
    int displayIndex = SDL_GetWindowDisplayIndex(window);
    SDL_DisplayMode mode;
    SDL_GetDisplayMode(displayIndex, 0, &mode);

    return mode.refresh_rate;
}

void RenderWindow::cleanUp() {
    SDL_DestroyWindow(window);
}

void RenderWindow::clear() {
    SDL_RenderClear(renderer);
}

void RenderWindow::display() {
    SDL_RenderPresent(renderer);
}

void RenderWindow::render(Entity& entity) {

    SDL_Rect srcRect;
    srcRect.x = 0;
    srcRect.y = 0;

    srcRect.w = entity.currentFrame.w;
    srcRect.h = entity.currentFrame.h;

    SDL_Rect destRect;
    destRect.x = (int) entity.getPos().x * 4;
    destRect.y = (int) entity.getPos().y * 4;

    destRect.w = srcRect.w;
    destRect.h = srcRect.h;

    SDL_RenderCopy(renderer, entity.tex, &srcRect, &destRect);
}