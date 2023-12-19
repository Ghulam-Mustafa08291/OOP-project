#ifndef PLANTS_HPP
#define PLANTS_HPP


#include <SDL.h>
#include <SDL_image.h>

class Plants{
    private:
        int health;
        int cost;
        SDL_Rect position;
    
    public:
        //getters,setters,constructors,destructors
        void setHealth(int h);
        void setCost(int c);
        int getHealth();
        int getCost();
        Plants();
        virtual ~Plants(); //keeping the destructor here virtual since this class will be the parent class for other classes
        void decrease_from_cost(int p);
        void setPosition(int x,int y);
        SDL_Rect getposition();
        //virtual void affirmation()=0;
};


#endif // PLANTS_HPP