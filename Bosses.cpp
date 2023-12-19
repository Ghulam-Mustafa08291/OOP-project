#include "Bosses.hpp"
#include <iostream>

int Bosses::get_health(){return this->health;}
void Bosses::set_health(int h)
{
    if(h>0){this->health=h;}
    else{
        std::cout<<"health must be more than 0!"<<std::endl;
    }
}

int Bosses::get_range(){return this->range;}
void Bosses::set_range(int r)
{
    if(r>0){this->range=r;}
    else{
        std::cout<<"range must be more than 0"<<std::endl;
    }
}

int Bosses::get_defence(){return this->defence;}
void Bosses::set_defence(int d)
{
    if(d>0){this->defence=d;}
    else{
        std::cout<<"defence must be more than 0"<<std::endl;
    }
}

int Bosses::get_speed(){return this->speed;}
void Bosses::set_speed(int s)
{
    if(s>0){this->speed=s;}
    else{
        std::cout<<"speed must be more than 0!"<<std::endl;
    }
}

int Bosses::get_phase(){
    std::cout<<"getting the phase!"<<std::endl;
    return this->phases;
}

void Bosses::trigger_phase(){std::cout<<"triggering phase " << this->get_phase() << std::endl;}

Bosses::Bosses()
{
        std::cout<<"boss spawned"<<std::endl;
        this->health=100;
        this->range=100;
        this->defence=100;
        this->speed=111;
        this->phases=34;
    }
Bosses::~Bosses(){std::cout<<"boss destroyed"<<std::endl;}