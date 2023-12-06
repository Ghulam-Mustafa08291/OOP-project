#include "Defence.hpp"
#include <iostream>

int Defence::get_hits_until_attack(){return this->hits_until_attack;}
void Defence::set_hits_until_attack(int inp_hits)
{
    if(inp_hits>0){
        this->hits_until_attack=inp_hits;
        }

    else{
        std::cout<<"number of hits must be more than 0"<<std::endl;
    }

    
}
void Defence::Deflect(){std::cout<<"i do be deflecting"<<std::endl;}

Defence::Defence(){std::cout<<"Defence type plant has been planted!"<<std::endl;}
Defence::~Defence(){std::cout<<"bye Defence type plant! (sed noises)"<<std::endl;}

