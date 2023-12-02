#include "Trap.hpp"
#include <iostream>

int Trap::get_time_interval(){return this->time_interval;}
void Trap::set_time_interval(int inp_time){this->time_interval=inp_time;}

int Trap::get_damage(){return this->damage;}
void Trap::set_damage(int inp_damage){this->damage=inp_damage;}

int Trap::get_range(){return this->range;}
void Trap::set_range(int inp_range){this->range=inp_range;}

void Trap::trigger_trap(){std::cout<<"trap triggered!!"<<std::endl;}
void Trap::check_enemy_health(){std::cout<<"checking enemy health now!"<<std::endl;}

Trap::Trap(){std::cout<<"Trap type plant has been planted!"<<std::endl;}
Trap::~Trap(){std::cout<<"bye bye Trap type plant"<<std::endl;}

