#ifndef PROJECTILES_HPP
#define PROJECTILES_HPP

#include <SDL.h>
#include <SDL_image.h>

class Projectiles{
    private:
        int speed;
        int damage;
        int time;

    public:
        int get_speed();
        void set_speed(int s);

        int get_damage();
        void set_damage(int d);

        int get_time();
        void set_time(int t);

        void in_contact(); //this prob will be of return type bool but for now keeping it void
        void get_position(); //return type void for now, will change it later
        void deal_damage();

        Projectiles();
        ~Projectiles();

};



#endif
