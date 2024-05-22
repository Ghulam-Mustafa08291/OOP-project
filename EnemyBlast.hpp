#ifndef ENEMYBLAST_HPP
#define ENEMYBLAST_HPP

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "enemy.hpp"


class EnemyBlast{
    public:
        SDL_Rect enemy_blast_position;
        SDL_Texture* enemy_blast_texture;
        void go_to_player(Player& player);
        void render(SDL_Renderer* renderer);

        EnemyBlast(int grid[64][36],Enemy* enen,SDL_Renderer* renderer);
        ~EnemyBlast();
};




#endif // ENEMY_HPP
