#include "Weapons.hpp"
#include <iostream>


int Weapons::get_damage(){return this->damage;}
void Weapons::set_damage(int d)
{
    if(d>0){
    this->damage=d;
    }
    else{
        std::cout<<"damage must be more than 0"<<std::endl;
    }
}

int Weapons::get_range(){return this->range;}
void Weapons::set_range(int r)
{
    if(r>0){
    this->range=r;
    }
    else{
        std::cout<<"rrange must be more than 0"<<std::endl;
    }
}

int Weapons::get_attack_speed(){return this->attack_speed;}
void Weapons::set_attack_speed(int s)
{
    if(s>0){
    this->attack_speed=s;
    }
    else{
        std::cout<<"attack speed must be more than 0"<<std::endl;
    }
}

Weapons::Weapons(){
    std::cout<<"Weapon created!"<<std::endl;


}

Weapons::~Weapons(){
    std::cout<<"goodbye my weapon"<<std::endl;
}


bool Weapons::check_weapon_collision_enemy(Enemy* enemy){
    if(enemy->getPosition().x==this->weapon_position.x && enemy->getPosition().y==this->weapon_position.y){
        return true;
        std::cout<<"the weapon collided with the enemy"<<std::endl;
    }
    else{
        return false;
    }
}
void Weapons::kill_enemy(Enemy* enemy,int grid[64][36]){
    grid[enemy->getPosition().x][enemy->getPosition().y]=0;
}
void Weapons::weapon_damage_enemy(Enemy* enemy,int grid[64][36]){
    if(enemy->getHealth()<=0){
        kill_enemy(enemy,grid);
    }
    else{
        enemy->setHealth(enemy->getHealth()-this->get_damage());
        std::cout<<"the enemy was damaged"<<std::endl;
    }
    
}