#include "enemy.hpp"
#include <iostream>

#include <SDL.h>
#include <SDL_image.h>
#include <cmath>
#include <SDL_mixer.h>


bool operator==(const SDL_Rect& e, const SDL_Rect& p) { //overloaded the == operator
    return (e.x == p.x && e.y == p.y);
}

bool operator==( Enemy& e,Player& p){ //another overload for the == operator
    return e.getPosition().x == p.getPosition().x && e.getPosition().y == p.getPosition().y;
}

bool operator==( Enemy& e,Plants& p){ //another overload for the == operator
    return e.getPosition().x == p.getPosition().x && e.getPosition().y == p.getPosition().y;
}

void Enemy::setHealth(int h){
    if(h>0){
        this->health=h;
    }
    else{
        this->health=h;
        std::cout<<"the enemy health must be more than 0"<<std::endl;
        std::cout<<"the new enemy health: "<<h<<std::endl;
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


void Enemy::go_to_player(Player& p, int grid[64][36],SDL_Renderer* renderer) {
    if(total_time_passed%blast_create_max_time==0){
        // std::cout<<"entered the if condition for enemyblast creation in enemy class, gotoplayer function"<<std::endl;
        EnemyBlast* blast=new EnemyBlast(grid,this,renderer);
        blast->blast_x=static_cast<float>(blast->enemy_blast_position.x);
        blast->blast_y=static_cast<float>(blast->enemy_blast_position.y);
        this->enemyBlasts.push_back(blast);
    }
    total_time_passed=total_time_passed+blast_creation_speed;
    if(this->getHealth()>0){
        int grid_player_x = p.getPosition().x / 20;
        int grid_player_y = p.getPosition().y / 20;

        int grid_enemy_x = position.x / 20;
        int grid_enemy_y = position.y / 20;

        float new_x = position.x;  
        float new_y = position.y;  
        if((*this==p)==false){

            

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
                std::cout<<"enemy x pos: "<<this->getPosition().x<<" enemy y pos: "<<this->getPosition().y<<std::endl;
            }

        }
    }
}

// void Enemy::update(Player& p, int grid[64][36], Plants& pl) {
//     // if(total_time_passed%blast_create_max_time==0){
//     //     EnemyBlast* blast=new EnemyBlast(grid,this,)
//     // }
//     if (this->getPosition() == p.getPosition()) {
//         this->deal_damage(p);
//     } else {

//         if((*this==pl)==false){ //if the positions do not match then check for collision with the plants
//             if(pl.getPosition().x==this->getPosition().x && pl.getPosition().y==this->getPosition().y-20){
//                 this->deal_damage(pl);
//             }

//             if(pl.getPosition().x==this->getPosition().x+20 && pl.getPosition().y==this->getPosition().y){
//                 this->deal_damage(pl);
//             }

//             if(pl.getPosition().x==this->getPosition().x && pl.getPosition().y==this->getPosition().y+20){
//                 this->deal_damage(pl);
//             }

//             if(pl.getPosition().x==this->getPosition().x-20 && pl.getPosition().y==this->getPosition().y){
//                 this->deal_damage(pl);
//             }


//         }
//         go_to_player(p, grid);
//     }
// }

// void Enemy::update(Player& p, int grid[64][36]) {
//     if (position == p.getPosition()) {
//         this->deal_damage(p);
//     } else {
//         go_to_player(p, grid);
//     }
// }



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
{
    blast_creation_speed=0.1f;
    blast_create_max_time=2;
    total_time_passed=0.1f;
}

Enemy::Enemy(int i, int j)
:health{100},speed{1},damage{5},position{i*20,j*20,20,20}
{
     blast_creation_speed=0.1f;
    blast_create_max_time=200;
    total_time_passed=0.1f;
}

Enemy::~Enemy(){}
