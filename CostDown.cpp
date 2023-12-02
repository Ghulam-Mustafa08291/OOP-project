#include "CostDown.hpp"
#include <iostream>

void CostDown::decrease_cost(Plants& p){
    p.decrease_from_cost(5);
    std::cout<<"decreasing the prize of plants! new price: "<<p.getCost()<<std::endl;
}

CostDown::CostDown(){
    std::cout<<"created a costdown type powerup!"<<std::endl;
}

CostDown::~CostDown(){
    std::cout<<"goodbye costdown type plants:(( "<<std::endl;
}

