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

Plants::Plants()
:health{100},cost{50} //assuming random values for them now
{}

Plants::~Plants(){} 
