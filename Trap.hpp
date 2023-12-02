#ifndef Trap_HPP
#define Trap_HPP
#include "Plants.hpp"


#include <SDL.h>
#include <SDL_image.h>



class Trap:public Plants{
    private:
        int time_interval;
        int damage;
        int range;

    public:
        int get_time_interval();
        void set_time_interval(int inp_time);

        int get_damage();
        void set_damage(int inp_damage);

        int get_range();
        void set_range(int inp_range);

        void trigger_trap();
        void check_enemy_health();
        
        Trap();
        ~Trap();
};




#endif