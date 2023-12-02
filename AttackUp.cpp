#include "AttackUp.hpp"
#include <iostream>

void AttackUp::increase_attack(Player& p){
    p.add_to_attack(20);
    std::cout<<"increasing attack! new attack power: "<<p.getAttack()<<std::endl;
}

AttackUp::AttackUp(){
    std::cout<<"created a AttackUp powerup!"<<std::endl;
}

AttackUp::~AttackUp(){
    std::cout<<"goodbye AttackUp type powerup!"<<std::endl;
}