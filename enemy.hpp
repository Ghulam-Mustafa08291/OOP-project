#define ENEMY_HPP


#include <SDL.h>
#include <SDL_image.h>

class Enemy{
    private:
        int health;
        int speed;
        int damage;
    
    public:
        //getters,setters,constructors,destructors
        void setHealth(int h);
        void setSpeed(int s);
        void setDamage(int d);
        int getHealth();
        int getSpeed();
        int getDamage();
        Enemy();
        ~Enemy();
};