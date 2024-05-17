#ifndef WEAPONS_HPP
#define WEAPONS_HPP
#include <SDL.h>
#include <SDL_image.h>
#include <string>



class Weapons{
    int damage;
    int range;
    int attack_speed;


    public:
        SDL_Rect weapon_position;
        float weapon_position_x;
        float weapon_position_y;
        std::string weapon_direction;

        float speed;
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