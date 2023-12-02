#ifndef Defence_HPP
#define Defence_HPP
#include "plants.hpp"

#include <SDL.h>
#include <SDL_image.h>

class Defence:public Plants{
    private:
        int hits_until_attack;

    public:
        //getters and setters and other functions
        int get_hits_until_attack();
        void set_hits_until_attack(int hits);

        void Deflect();

        Defence();
        ~Defence();
};



#endif 