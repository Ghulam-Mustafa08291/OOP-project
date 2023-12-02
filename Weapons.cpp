#include "Weapons.hpp"
#include <iostream>


int Weapons::get_damage(){return this->damage;}
void Weapons::set_damage(int d){this->damage=d;}

int Weapons::get_range(){return this->range;}
void Weapons::set_range(int r){this->range=r;}

int Weapons::get_attack_speed(){return this->attack_speed;}
void Weapons::set_attack_speed(int s){this->attack_speed=s;}

Weapons::Weapons(){
    std::cout<<"Weapon base class created!"<<std::endl;

}

Weapons::~Weapons(){
    std::cout<<"goodbye my weapon ,rip"<<std::endl;
}
