#include "plants.hpp"
#include <iostream>

void Plants::setHealth(int h){
    this->health=h;
}

void Plants::setCost(int c){
    this->cost=c;
}

int Plants::getCost(){
    return this->cost;
}

int Plants::getHealth(){
    return this->health;
}

void Plants::decrease_from_cost(int s){this->cost=this->cost-5;}

void Plants::setPosition(int x,int y){
    this->position.x=x;
    this->position.y=y;
    this->position.w=20;
    this->position.h=20;
}
Plants::Plants()
:health{100},cost{50} //assuming random values for them now
{}

Plants::~Plants(){} 
