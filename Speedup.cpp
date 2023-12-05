#include "Speedup.hpp"
#include <iostream>

void SpeedUp::help_player(Player& p)
    {   
        p.add_to_speed(10);
        std::cout<<"inreasing the players speed! new Speed: "<<p.getSpeed()<<std::endl;
        
    }

SpeedUp::SpeedUp(){std::cout<<"Speedup powerup created"<<std::endl;}
SpeedUp::~SpeedUp(){std::cout<<"goodbye speed up power up"<<std::endl;}
