#ifndef POWERUPS_HPP
#define POWERUPS_HPP

#include <SDL.h>
#include <SDL_image.h>



class Powerups{
    private:
        int duration;

    public:
        int get_duration();
        void set_duration(int inp_duration);

        Powerups();
        ~Powerups();
};

#endif