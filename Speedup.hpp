#ifndef SPEEDUP_HPP
#define SPEEDUP_HPP
#include "Powerups.hpp"
#include "player.hpp"
#include <SDL.h>
#include <SDL_image.h>

class SpeedUp : public Powerups {
    public:
        void increase_speed(Player& p);
        SpeedUp();
        ~SpeedUp();

};


#endif