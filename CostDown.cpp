#include "CostDown.hpp"
#include <iostream>

void CostDown::help_plant(Plants& p) {
    p.setCost(p.getCost() - (p.getCost()*0.15));
    std::cout<<"decreasing the price of plants! new price: "<<p.getCost()<<std::endl;
}

CostDown::CostDown(){
    std::cout<<"created a costdown type powerup!"<<std::endl;
}

CostDown::~CostDown(){
    std::cout<<"CostDown destructor"<<std::endl;
}

