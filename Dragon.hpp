#ifndef DRAGON_HPP
#define DRAGON_HPP
#include "Bosses.hpp"
#include <SDL.h>
#include <SDL_image.h>
class Dragon:public Bosses{
    public:
        void attack1();
        void attack2();
        void attack3();

        Dragon();
        ~Dragon();
};


#endif
