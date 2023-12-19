#include "enemy.hpp"
#include <iostream>

#include <SDL.h>
#include <SDL_image.h>
#include <cmath>
#include <SDL_mixer.h>


bool operator==(const SDL_Rect& e, const SDL_Rect& p) { //overloaded the == operator
    return (e.x == p.x && e.y == p.y);
}

void Enemy::setHealth(int h){
    if(h>0){
        this->health=h;
    }
    else{
        std::cout<<"the health must be more than 0"<<std::endl;
    }
}

void Enemy::setSpeed(int s){
    if(s>0){
        this->speed=s;
    }
    else{
        std::cout<<"speed must be more than 0"<<std::endl;
    }
}

void Enemy::setDamage(int d){
    if(d>0){
        this->damage=d;
    }
    else{
        std::cout<<"damage must be more than 0"<<std::endl;
    }
}

int Enemy::getHealth(){
    return this->health;
}

int Enemy::getSpeed(){
    return this->speed;
}

int Enemy::getDamage(){
    return this->damage;
}
SDL_Rect& Enemy::getPosition(){
    return this->position;
}
void Enemy::setPosition(int x,int y){
    if(x>=0 && y>=0){
        this->position.x=x;
        this->position.y=y;
    }
    else{
        std::cout<<"the cordinates can not be less than 0"<<std::endl;
    }
}


void Enemy::deal_damage(Plants& pl){
    if (pl.getHealth()>0){
        std::cout<<"fighting with shooter plant! plant health: "<<pl.getHealth()<<" enemy health: "<<this->getHealth()<<std::endl;;
        pl.setHealth((pl.getHealth()-this->damage));//subtracting the amount by health
    }
    else{
        std::cout<<"enemy destroyed plant!"<<std::endl;
    }
}


void Enemy::deal_damage(Player& p){
    if(p.get_is_alive()==true){
    p.setHealth((p.getHealth()-this->damage)); //subtracting the amount by health
    std::cout<<"Player health falling,health: "<<p.getHealth()<<std::endl;
    int initMixer = Mix_Init(0);

    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);

    Mix_Chunk* damage_sound = Mix_LoadWAV("audio/oof.wav");
    Mix_PlayChannel(-1, damage_sound, 0);
    }
    else{
        std::cout<<"Enemy killed player!"<<std::endl;
    }
}


void Enemy::go_to_player(Player& p, int grid[64][36]) {
    int grid_player_x = p.getPosition().x / 20;
    int grid_player_y = p.getPosition().y / 20;

    int grid_enemy_x = position.x / 20;
    int grid_enemy_y = position.y / 20;

    int new_x = position.x;  
    int new_y = position.y;  

    if (grid_player_x < grid_enemy_x && isValidMove(position.x - 20, position.y, grid)) {
        new_x -= 20;
    } else if (grid_player_x > grid_enemy_x && isValidMove(position.x + 20, position.y, grid)) {
        new_x += 20;
    }

    if (grid_player_y < grid_enemy_y && isValidMove(position.x, position.y - 20, grid)) {
        new_y -= 20;
    } else if (grid_player_y > grid_enemy_y && isValidMove(position.x, position.y + 20, grid)) {
        new_y += 20;
    }

    if (isValidMove(new_x, new_y, grid)) { 
        position.x = new_x;
        position.y = new_y;
    }
}

void Enemy::update(Player& p, int grid[64][36]) {
    if (position == p.getPosition()) {
        this->deal_damage(p);
    } else {
        go_to_player(p, grid);
    }
}




//////////

bool Enemy::isValidMove(int x, int y, int grid[64][36]) {
    const int GRID_WIDTH = 64;
    const int GRID_HEIGHT = 36;

    if (x < 0 || x >= GRID_WIDTH * 20 || y < 0 || y >= GRID_HEIGHT * 20) {
        return false;
    }

    int cellX = x / 20;
    int cellY = y / 20;

    if (grid[cellX][cellY] == 1 || grid[cellX][cellY] == 3) {
        return false; // Collides with a wall
    }

    return true; // Position is valid
}






////////////////////////////////
Enemy::Enemy()
:health{100},speed{1},damage{10},position{1240,60,20,20} 
{}

Enemy::Enemy(int i, int j)
:health{100},speed{1},damage{5},position{i*20,j*20,20,20}
{}

Enemy::~Enemy(){}
