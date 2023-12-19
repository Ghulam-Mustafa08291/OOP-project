#ifndef POWERUPS_HPP
#define POWERUPS_HPP

#include <SDL.h>
#include <SDL_image.h>
#include "player.hpp"
#include "plants.hpp"



class Powerups{
    private:
        int duration;

    public:
        int get_duration();
        void set_duration(int inp_duration);
        virtual void help_player(Player& p)=0;
       virtual void help_plant(Plants& p)=0;

        Powerups();
        ~Powerups();
};

#endif