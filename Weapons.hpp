#ifndef WEAPONS_HPP
#define WEAPONS_HPP
#include <SDL.h>
#include <SDL_image.h>



class Weapons{
    int damage;
    int range;
    int attack_speed;

    public:
        int get_damage();
        void set_damage(int d);

        int get_range();
        void set_range(int r);

        int get_attack_speed();
        void set_attack_speed(int s);

        Weapons();
        ~Weapons();
};





#endif