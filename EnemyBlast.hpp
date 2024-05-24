#ifndef ENEMYBLAST_HPP
#define ENEMYBLAST_HPP

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "enemy.hpp"

class Player;
class Enemy;

class EnemyBlast {
public:
    SDL_Rect enemy_blast_position;
    SDL_Texture* enemy_blast_texture;
    int damage;
    bool collided;
    void damage_player(Player& p);
    void kill_enemyblast();
    bool collided_with_player(Player& p);
    EnemyBlast(int grid[64][36], Enemy* enemy, SDL_Renderer* renderer);
    ~EnemyBlast();
    float blast_x;
    float blast_y;

    bool isValidMove(int x, int y, int grid[64][36]);
    void go_to_player(Player& player, int grid[64][36]);
    void render(SDL_Renderer* renderer);
};

#endif // ENEMYBLAST_HPP
