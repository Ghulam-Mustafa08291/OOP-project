#ifndef BOSSES_HPP
#define BOSSES_HPP

#include <SDL.h>
#include <SDL_image.h>

class Bosses{
    private:
        int health;
        int range;
        int defence;
        int speed;
        int phases;

    public:

        //now i need getters and setters and the constructor and the destructor
        int get_health();
        void set_health(int hh);

        int get_range();
        void set_range(int r);

        int get_defence();
        void set_defence(int d);

        int get_speed();
        void set_speed(int s);

        

        void get_phase(); //will change return type later on
        void trigger_phase();

        Bosses();
        virtual ~Bosses(); //keeping it virtual cuz this is a parent class
};


#endif
