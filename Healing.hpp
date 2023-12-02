#ifndef HEALING_HPP
#define HEALING_HPP
#include "PowerUps.hpp"
#include "player.hpp"
#include <SDL.h>
#include <SDL_image.h>

class Healing: public Powerups{
    public:
        void increase_health(Player& p);
        Healing();
        ~Healing();


};


#endif




