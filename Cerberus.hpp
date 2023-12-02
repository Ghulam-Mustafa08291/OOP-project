#ifndef CERBERUS_HPP
#define CERBERUS_HPP

#include <SDL.h>
#include <SDL_image.h>
#include "Bosses.hpp"
class Cerberus:public Bosses{
    public:
        void attack1();
        void attack2();
        void attack3();

        Cerberus();
        ~Cerberus();      
};


#endif