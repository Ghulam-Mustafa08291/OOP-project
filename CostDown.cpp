#include "CostDown.hpp"
#include <iostream>

void CostDown::decrease_cost(Plants& p){
    p.decrease_from_cost(5);
    std::cout<<"decreasing the prize of plants! new price: "<<p.getCost()<<std::endl;
}

void CostDown::help_player(Player& p){
    std::cout<<"giving a basic implementation for this method so that this class wont become an abstract class"<<std::endl;
}

CostDown::CostDown(){
    std::cout<<"created a costdown type powerup!"<<std::endl;
}

CostDown::~CostDown(){
    std::cout<<"goodbye costdown type plants:(( "<<std::endl;
}

