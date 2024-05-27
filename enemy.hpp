#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <SDL.h>
#include <SDL_image.h>
#include "player.hpp"
#include "EnemyBlast.hpp"
#include <vector>

class Player;
class EnemyBlast;

class Enemy {
private:
    int health;
    int speed;
    int damage;
    SDL_Rect position;

public:
    float enemy_x;
    float enemy_y;
    int blast_creation_speed;
    int blast_create_max_time;
    int total_time_passed;
    std::vector<EnemyBlast*> enemyBlasts;
    SDL_Texture* texture;

    Enemy();
    Enemy(int i, int j);
    ~Enemy();

    void setHealth(int h);
    void setSpeed(int s);
    void setDamage(int d);
    int getHealth();
    int getSpeed();
    int getDamage();
    SDL_Rect& getPosition();
    void setPosition(int x, int y);
    bool isValidMove(int x, int y, int grid[64][36]);
    void go_to_player(Player& p, int grid[64][36], SDL_Renderer* renderer);
    void deal_damage(Player& p);
    void deal_damage(Plants& pl);
    void update(Player& p, int grid[64][36]);
    void update(Player& p, int grid[64][36], Plants& pl);
};

bool operator==(const SDL_Rect& e, const SDL_Rect& p);
bool operator==(const Enemy& e, const Plants& p);
bool operator==(const Enemy& e, const Player& p);

#endif // ENEMY_HPP
