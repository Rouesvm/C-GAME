#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>

#include "Entity.hpp"
#include "Math.hpp"

class Player : public Entity {
    public:
        static const int SPEED = 10;
        Player(SDL_Texture* p_tex);

        void jump();
        void update(float frameTime);
        void handleEvent(SDL_Event& event);
    private:
        Vector2f pos;
        Vector2f velocity;
        bool grounded{};
};