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

        void in_contact(); 
        void get_position(); 
        void deal_damage();

        Projectiles();
        ~Projectiles();

};



#endif
