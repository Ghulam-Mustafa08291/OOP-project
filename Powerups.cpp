#include "Powerups.hpp"
#include <iostream>

int Powerups::get_duration(){return this->duration;}
void Powerups::set_duration(int inp_duration)
{
    if(inp_duration>0){
    this->duration=inp_duration;
    }
    else{
        std::cout<<"duration must be more than 0"<<std::endl;
    }
}
void Powerups::decrease_cost(Plants& pl){
    std::cout<<"decreasing the cost of the plant"<<std::endl;
}

Powerups::Powerups(){std::cout<<"powerup parent class object made!"<<std::endl;}
Powerups::~Powerups(){std::cout<<"goodbye powerup parent class object!"<<std::endl;}