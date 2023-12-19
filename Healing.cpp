#include "Healing.hpp"
#include <iostream>

void Healing::help_player(Player& p){ //overriding this method here
    p.add_to_health(20);
    std::cout<<"increasing the player's health! new health: "<<p.getHealth()<<std::endl;
    
}
Healing::Healing(){
    std::cout<<"healing powerup spawned"<<std::endl;
}

Healing::~Healing(){
    std::cout<<"healing powerup destroyed"<<std::endl;
}