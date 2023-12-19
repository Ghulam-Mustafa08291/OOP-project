#include "Defence.hpp"
#include <iostream>

int Defence::get_hits_until_attack(){return this->hits_until_attack;}
void Defence::set_hits_until_attack(int inp_hits)
{
    if(inp_hits>0 || inp_hits<10){
        this->hits_until_attack=inp_hits;
        }

    else{
        std::cout<<"number of hits must be more than 0"<<std::endl;
    }

    
}
void Defence::Deflect(){std::cout<<"deflecting attack"<<std::endl;}

Defence::Defence(){std::cout<<"Defence type plant has been planted!"<<std::endl;}
Defence::~Defence(){std::cout<<"Defence type plant destroyed"<<std::endl;}

