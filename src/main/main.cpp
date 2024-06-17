#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keyboard.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_timer.h>
#include <iostream>
#include <ostream>

#include "../../include/Utils.hpp"
#include "../../include/Entity.hpp"
#include "../../include/Player.hpp"
#include "../../include/RenderWindow.hpp"

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) > 0) {        
        std::cout << "SDL_INIT FAILED" << SDL_GetError() << '\n';
    }

    if (IMG_Init(IMG_INIT_PNG) == 0) {
        std::cout << "IMG_INITs FAILED" << SDL_GetError() << '\n';
    }

    RenderWindow window("v1.0", SCREEN_WIDTH, SCREEN_HEIGHT);

    SDL_Texture* grassTexture = window.loadTexture("src/assets/grass.png");
    SDL_Texture* playerTexture = window.loadTexture("src/assets/player.png");

    //std::vector<Entity> entities = {
    //   Entity(Vector2f(0, 0), grassTexture),
    //   Entity(Vector2f(1, 0), grassTexture),
    //   Entity(Vector2f(1, 1), grassTexture)
    //};

    //entities.emplace_back(Vector2f(2, 0), grassTexture);

    Player player(playerTexture);

    bool gameRunning = true;

    SDL_Event event;

    const float deltaTime = 0.001F;
    float accumulator = 0.0F;   
    float currentTime = utils::hireTimeInSeconds();

    int minimumTicks = 1000 / window.getRefreshRate();

    while (gameRunning) {
        Uint32 startTicks = SDL_GetTicks();

        float newTime = utils::hireTimeInSeconds();
        float frameTime = newTime - currentTime;

        currentTime = newTime;
        accumulator += frameTime;

        while (accumulator >= deltaTime) {  
            while (SDL_PollEvent(&event) != 0) {
                if (event.type == SDL_QUIT) {
                    gameRunning = false;
                }

                player.handleEvent(event);
            }

            accumulator -= deltaTime;
        }

        const float alpha = accumulator / deltaTime;

        player.update(frameTime);
        window.clear();

       // for (Entity& instance : entities) {
          //  window.render(instance);
        //}

        window.render(player);

        window.display();

        Uint32 frameTicks = SDL_GetTicks() - startTicks;

        if (frameTicks < minimumTicks) {
            SDL_Delay(minimumTicks - frameTicks);
        }
    }

    window.cleanUp();
    SDL_Quit();

    return 0;
}
