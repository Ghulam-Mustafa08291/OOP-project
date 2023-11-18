#ifndef PLANTS_HPP
#define PLANTS_HPP


#include <SDL.h>
#include <SDL_image.h>

class Plants{
    private:
        int health;
        int cost;
    
    public:
        //getters,setters,constructors,destructors
        void setHealth(int h);
        void setCost(int c);
        int getHealth();
        int getCost();
        Plants();
        ~Plants();
};


















#endif PLANTS_HPP