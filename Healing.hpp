#ifndef HEALING_HPP
#define HEALING_HPP
#include "PowerUps.hpp"
#include "player.hpp"
#include <SDL.h>
#include <SDL_image.h>

class Healing: public Powerups{
    public:
        void help_player(Player& p) override;
        Healing();
        ~Healing();


};


#endif




