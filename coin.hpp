#ifndef COIN_HPP
#define COIN_HPP
#include <SDL.h>
#include <SDL_image.h>
#include "enemy.hpp"
#include <iostream>

class coin{
    public:
        SDL_Rect coin_position;
        SDL_Texture* coin_texture;
        coin(Player& player, Enemy* newEnemy,int grid[64][36],SDL_Renderer* renderer);
        ~coin();
        int generate_random_cordinates(int min,int max);
        void render(SDL_Renderer* renderer);


};


#endif 