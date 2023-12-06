#include "plants.hpp"
#include <iostream>

void Plants::setHealth(int h){
    if(h>0){this->health=h;}
    else{
        std::cout<<"health must be more than 0"<<std::endl;
    }
}

void Plants::setCost(int c){
    if(c>0){this->cost=c;}
    else{
        std::cout<<"cost must be more than 0"<<std::endl;
    }
}

int Plants::getCost(){
    return this->cost;
}

int Plants::getHealth(){
    return this->health;
}

void Plants::decrease_from_cost(int s){this->cost=this->cost-5;}

void Plants::setPosition(int x,int y){
    if(x>=0 && y>=0){
    this->position.x=x;
    this->position.y=y;
    this->position.w=20;
    this->position.h=20;}

    else{
        std::cout << "coordinates cannot be negative!" << std::endl;
    }
}
Plants::Plants()
:health{100},cost{50} //assuming random values for them now
{}

Plants::~Plants(){} 
