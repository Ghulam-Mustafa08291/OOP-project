#ifndef Explosive_HPP
#define Explosive_HPP
#include "plants.hpp"

#include <SDL.h>
#include <SDL_image.h>


class Explosive: public Plants{
    private:
        int time;

    public:
        int get_time();
        void set_time(int inp_time);

        void scan_range();
        void detonate();

        Explosive();
        ~Explosive();
};

#endif