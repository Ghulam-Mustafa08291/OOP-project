#ifndef ARMOUR_HPP
#define ARMOUR_HPP
#include <SDL.h>
#include <SDL_image.h>


class Armour{
    private:
        int defence;
        int damage_reduction;

    public:
        int get_defence();
        void set_defence(int inp_def);

        int get_damage_reduction();
        void set_damage_reduction(int s);

        Armour();
        ~Armour();
        
};


#endif