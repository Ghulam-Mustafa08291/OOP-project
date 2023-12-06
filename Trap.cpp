#include "Trap.hpp"
#include <iostream>

int Trap::get_time_interval(){return this->time_interval;}
void Trap::set_time_interval(int inp_time)
{
    if(inp_time>0){
    this->time_interval=inp_time;
    }
    else{
        std::cout<<"time interval must be more than 0"<<std::endl;
    }
}

int Trap::get_damage(){return this->damage;}
void Trap::set_damage(int inp_damage)
{
    if(inp_damage>0){
    this->damage=inp_damage;
    }
    else{
        std::cout<<"damage must be more than 0"<<std::endl;
    }
}

int Trap::get_range(){return this->range;}
void Trap::set_range(int inp_range)
{
    if(inp_range>0){
    this->range=inp_range;
    }
    else{
        std::cout<<"range must be more than 0"<<std::endl;
    }
}

void Trap::trigger_trap(){std::cout<<"trap triggered!!"<<std::endl;}
void Trap::check_enemy_health(){std::cout<<"checking enemy health now!"<<std::endl;}

Trap::Trap(){std::cout<<"Trap type plant has been planted!"<<std::endl;}
Trap::~Trap(){std::cout<<"bye bye Trap type plant"<<std::endl;}

