#include "Speedup.hpp"
#include <iostream>

void SpeedUp::increase_speed(Player& p)
    {
        std::cout<<"inreasing the players speed!"<<std::endl;
        p.setSpeed(10);
    }

SpeedUp::SpeedUp(){std::cout<<"Speedup powerup created"<<std::endl;}
SpeedUp::~SpeedUp(){std::cout<<"goodbye speed up power up"<<std::endl;}
