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
    std::cout<<"Weapon base class created!"<<std::endl;

}

Weapons::~Weapons(){
    std::cout<<"goodbye my weapon ,rip"<<std::endl;
}
