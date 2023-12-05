#include "enemy.hpp"
#include <iostream>

#include <SDL.h>
#include <SDL_image.h>
#include <cmath>


bool operator==(const SDL_Rect& e, const SDL_Rect& p) {
    return (e.x == p.x && e.y == p.y);
}

void Enemy::setHealth(int h){
    this->health=h;
}

void Enemy::setSpeed(int s){
    this->speed=s;
}

void Enemy::setDamage(int d){
    this->damage=d;
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
    this->position.x=x;
    this->position.y=y;
}


 

void Enemy::deal_damage(Player& p){
    if(p.get_is_alive()==true){
    p.setHealth((p.getHealth()-this->damage)); //subtracting the amount by health
    std::cout<<"Player health falling,health: "<<p.getHealth()<<std::endl;
    }
    else{
        std::cout<<"Enemy killed player!"<<std::endl;
        //show the end screen below
    }
}



void Enemy::go_to_player(Player& p,int grid[64][36]){
    

    int enemy_x=this->getPosition().x; //position in terms of pixel
    int enemy_y=this->getPosition().y;


    int grid_player_x=(p.getPosition().x)/20; //position in terms of grid cordinates
    int grid_player_y=(p.getPosition().y)/20;

    int grid_enemy_x=(this->getPosition().x)/20;
    int grid_enemy_y=(this->getPosition().y)/20;

    if ((this->getPosition() == p.getPosition())==false) { //did its operator overloading
    //will check for all possible conditions reltated to the player and enemies movement
        if (grid_player_x<grid_enemy_x && grid_player_y<grid_enemy_y){
            while (grid_enemy_x!=grid_player_x || grid_enemy_y!=grid_player_y){
                if (grid_enemy_x!=grid_player_x){
                    grid_enemy_x=grid_enemy_x-1;
                    this->setPosition(enemy_x-20,enemy_y);
                    // std::cout<<"i com hard for u"<<std::endl;
                }

                if (grid_enemy_y!=grid_player_y){
                    grid_enemy_y=grid_enemy_y-1;
                    this->setPosition(enemy_x,enemy_y-20);
                }
            }
        }
        if (grid_enemy_x==grid_player_x && grid_player_y<grid_enemy_y){
            while(grid_enemy_y!=grid_player_y){
                grid_enemy_y=grid_enemy_y-1;
                this->setPosition(enemy_x,enemy_y-20);
                // std::cout<<"i com hard for u"<<std::endl;
            }
        }
        if (grid_player_x>grid_enemy_x && grid_player_y<grid_enemy_y){
            while(grid_enemy_x!=grid_player_x){
                grid_enemy_x+=1;
                this->setPosition(enemy_x+20,enemy_y);
                // std::cout<<"i com hard for u"<<std::endl;
            }
            while(grid_enemy_y!=grid_player_y){
                grid_enemy_y-=1;
                this->setPosition(enemy_x,enemy_y-20);
                // std::cout<<"i com hard for u"<<std::endl;
            }
        }
        if (grid_player_x>grid_enemy_x && grid_player_y==grid_enemy_y){
            while(grid_enemy_x!=grid_player_x){
                grid_enemy_x+=1;
                this->setPosition(enemy_x+20,enemy_y);
                // std::cout<<"i com hard for u"<<std::endl;
            }
        }

        if (grid_player_x>grid_enemy_x && grid_player_y>grid_enemy_y){
            while(grid_enemy_x!=grid_player_x){
                grid_enemy_x+=1;
                this->setPosition(enemy_x+20,enemy_y);
                // std::cout<<"i com hard for u"<<std::endl;
            }
            while(grid_enemy_y!=grid_player_y){
                grid_enemy_y+=1;
                this->setPosition(enemy_x,enemy_y+20);
                // std::cout<<"i com hard for u"<<std::endl;
            }
        }

        if (grid_player_x==grid_enemy_x && grid_player_y>grid_enemy_y){
            while(grid_enemy_y!=grid_player_y){
                grid_enemy_y+=1;
                this->setPosition(enemy_x,enemy_y+20);
                // std::cout<<"i com hard for u"<<std::endl;
            }
        }

        if (grid_player_x<grid_enemy_x && grid_player_y>grid_enemy_y){
            while(grid_enemy_x!=grid_player_x){
                grid_enemy_x-=1;
                this->setPosition(enemy_x-20,enemy_y);
                // std::cout<<"i com hard for u"<<std::endl;
            }
            while(grid_enemy_y!=grid_player_y){
                grid_enemy_y+=1;
                this->setPosition(enemy_x,enemy_y+20);
                // std::cout<<"i com hard for u"<<std::endl;
            }
        }

        if (grid_player_x<grid_enemy_x && grid_player_y==grid_enemy_y){
            while(grid_enemy_x!=grid_player_x){
                grid_enemy_x-=1;
                this->setPosition(enemy_x-20,enemy_y);
                // std::cout<<"i com hard for u"<<std::endl;
            }
        }
    }
    else{
        this->deal_damage(p);
    }


}

// void Enemy::update(const SDL_Rect& playerPosition) {
//     // Calculate the vector from the enemy to the player
//     float deltaX = static_cast<float>(playerPosition.x - this->getPosition().x);
//     float deltaY = static_cast<float>(playerPosition.y - this->getPosition().y);

//     // Calculate the distance between the enemy and the player
//     float distance = std::sqrt(deltaX * deltaX + deltaY * deltaY);

//     // Normalize the direction vector
//     float directionX = deltaX / distance;
//     float directionY = deltaY / distance;

//     // Move the enemy based on the normalized direction and speed
//     this->setPosition(this->getPosition().x += static_cast<int>(speed * directionX), this->getPosition().y += static_cast<int>(speed * directionY));
// }


// Inside the Enemy class
void Enemy::update(const SDL_Rect& playerPosition, int grid[64][36]) {
    // Calculate the vector from the enemy to the player
    float deltaX = static_cast<float>(playerPosition.x - this->getPosition().x);
    float deltaY = static_cast<float>(playerPosition.y - this->getPosition().y);

    // Calculate the distance between the enemy and the player
    float distance = std::sqrt(deltaX * deltaX + deltaY * deltaY);

    // Normalize the direction vector (avoid division by zero)
    float directionX = 0.0f;
    float directionY = 0.0f;
    if (distance != 0.0f) {
        directionX = deltaX / distance;
        directionY = deltaY / distance;
    }

    // Move the enemy based on the normalized direction and speed
    int newPosX = static_cast<int>(this->getPosition().x + this->getSpeed() * directionX);
    int newPosY = static_cast<int>(this->getPosition().y + this->getSpeed() * directionY);

    // Update the position if the movement is valid within the grid
    if (isValidMove(newPosX, newPosY, grid)) {
        this->setPosition(newPosX, newPosY);
    }
}

// bool Enemy::isValidMove(int x, int y) {
//     // Check if the new position is within the boundaries of the grid
//     const int GRID_WIDTH = 64; // Replace with your actual grid width
//     const int GRID_HEIGHT = 36; // Replace with your actual grid height

//     if (x < 0 || x >= GRID_WIDTH * 20 || y < 0 || y >= GRID_HEIGHT * 20) {
//         return false; // Position is out of grid boundaries
//     }

//     // Implement additional checks if needed based on your game logic
//     // For example, collision detection with obstacles

//     return true; // Position is valid
// }

bool Enemy::isValidMove(int x, int y, int grid[64][36]) {
    // Check if the new position is within the boundaries of the grid
    const int GRID_WIDTH = 64; // Replace with your actual grid width
    const int GRID_HEIGHT = 36; // Replace with your actual grid height

    if (x < 0 || x >= GRID_WIDTH * 20 || y < 0 || y >= GRID_HEIGHT * 20) {
        return false; // Position is out of grid boundaries
    }

    // Check if the new position collides with a wall
    int cellX = x / 20; // Convert pixel coordinates to grid cell coordinates
    int cellY = y / 20;

    if (grid[cellX][cellY] == 1) {
        return false; // Collides with a wall
    }

    // Add additional collision checks here if needed

    return true; // Position is valid
}








Enemy::Enemy()
:health{100},speed{1},damage{10},position{1240,60,20,20} //assuming random values for them now
{}

Enemy::Enemy(int i, int j)
:health{100},speed{1},damage{5},position{i*20,j*20,20,20}
{}

Enemy::~Enemy(){} 
