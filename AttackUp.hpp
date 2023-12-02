#ifndef ATTACKUP_HPP
#define ATTACKUP_HPP
#include "Powerups.hpp"
#include "player.hpp"

#include <SDL.h>
#include <SDL_image.h>

class AttackUp: public Powerups{
    public:
        void increase_attack(Player& p);
        AttackUp();
        ~AttackUp();
};


#endif