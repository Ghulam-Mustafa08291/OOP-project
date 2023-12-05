#include "enemy.hpp"
#include <iostream>

#include <SDL.h>
#include <SDL_image.h>

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
    p.setHealth((p.getHealth()-this->damage)); //subtracting the amount by health
    std::cout<<"Player health falling,health: "<<p.getHealth()<<std::endl;
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
            }
        }
        if (grid_player_x>grid_enemy_x && grid_player_y<grid_enemy_y){
            while(grid_enemy_x!=grid_player_x){
                grid_enemy_x+=1;
                this->setPosition(enemy_x+20,enemy_y);
            }
            while(grid_enemy_y!=grid_player_y){
                grid_enemy_y-=1;
                this->setPosition(enemy_x,enemy_y-20);
            }
        }
        if (grid_player_x>grid_enemy_x && grid_player_y==grid_enemy_y){
            while(grid_enemy_x!=grid_player_x){
                grid_enemy_x+=1;
                this->setPosition(enemy_x+20,enemy_y);
            }
        }

        if (grid_player_x>grid_enemy_x && grid_player_y>grid_enemy_y){
            while(grid_enemy_x!=grid_player_x){
                grid_enemy_x+=1;
                this->setPosition(enemy_x+20,enemy_y);
            }
            while(grid_enemy_y!=grid_player_y){
                grid_enemy_y+=1;
                this->setPosition(enemy_x,enemy_y+20);
            }
        }

        if (grid_player_x==grid_enemy_x && grid_player_y>grid_enemy_y){
            while(grid_enemy_y!=grid_player_y){
                grid_enemy_y+=1;
                this->setPosition(enemy_x,enemy_y+20);
            }
        }

        if (grid_player_x<grid_enemy_x && grid_player_y>grid_enemy_y){
            while(grid_enemy_x!=grid_player_x){
                grid_enemy_x-=1;
                this->setPosition(enemy_x-20,enemy_y);
            }
            while(grid_enemy_y!=grid_player_y){
                grid_enemy_y+=1;
                this->setPosition(enemy_x,enemy_y+20);
            }
        }

        if (grid_player_x<grid_enemy_x && grid_player_y==grid_enemy_y){
            while(grid_enemy_x!=grid_player_x){
                grid_enemy_x-=1;
                this->setPosition(enemy_x-20,enemy_y);
            }
        }
    }


}







Enemy::Enemy()
:health{100},speed{1},damage{5},position{1240,60,20,20} //assuming random values for them now
{}

Enemy::~Enemy(){} 
