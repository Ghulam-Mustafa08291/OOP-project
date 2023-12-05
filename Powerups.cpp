#include "Powerups.hpp"
#include <iostream>

int Powerups::get_duration(){return this->duration;}
void Powerups::set_duration(int inp_duration){this->duration=inp_duration;}
void Powerups::decrease_cost(Plants& pl){
    std::cout<<"decreasing the cost of the plant"<<std::endl;
}

Powerups::Powerups(){std::cout<<"powerup parent class object made!"<<std::endl;}
Powerups::~Powerups(){std::cout<<"goodbye powerup parent class object!"<<std::endl;}