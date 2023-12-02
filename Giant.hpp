#ifndef GIANT_HPP
#define GIANT_HPP

#include <SDL.h>
#include <SDL_image.h>
#include "Bosses.hpp"

class Giant:public Bosses{
    public:
        void attack1();
        void attack2();
        void attack3();

        Giant();
        ~Giant();      
};



#endif