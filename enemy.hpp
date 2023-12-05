#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <SDL.h>
#include <SDL_image.h>
#include "player.hpp"

class Enemy{
    private:
        int health;
        int speed;
        int damage;
        SDL_Rect position;

    
    public:
        //getters,setters,constructors,destructors
        void setHealth(int h);
        void setSpeed(int s);
        void setDamage(int d);
        int getHealth();
        int getSpeed();
        int getDamage();
        void go_to_player(Player& p,int grid[64][36]);
        SDL_Rect& getPosition();
        void setPosition(int x,int y);
        void deal_damage(Player& p);

        Enemy();
        ~Enemy();
        friend bool operator==(const SDL_Rect& e, const SDL_Rect& p);
};

bool operator==(const SDL_Rect& e, const SDL_Rect& p);


#endif // ENEMY_HPP
