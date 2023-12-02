#include "Bosses.hpp"
#include <iostream>

int Bosses::get_health(){return this->health;}
void Bosses::set_health(int h){this->health=h;}

int Bosses::get_range(){return this->range;}
void Bosses::set_range(int r){this->range=r;}

int Bosses::get_defence(){return this->defence;}
void Bosses::set_defence(int d){this->defence=d;}

int Bosses::get_speed(){return this->speed;}
void Bosses::set_speed(int s){this->speed=s;}

void Bosses::get_phase(){std::cout<<"getting the phase!"<<std::endl;}
void Bosses::trigger_phase(){std::cout<<"triggering the phase rn my king"<<std::endl;}

Bosses::Bosses()
{
        std::cout<<"allo mr BOss :)"<<std::endl;
        this->health=100;
        this->range=100;
        this->defence=100;
        this->speed=111;
        this->phases=34;
    }
Bosses::~Bosses(){std::cout<<"bye Bossman"<<std::endl;}