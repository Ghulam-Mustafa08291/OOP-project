#include "Defence.hpp"
#include <iostream>

int Defence::get_hits_until_attack(){return this->hits_until_attack;}
void Defence::set_hits_until_attack(int inp_hits){this->hits_until_attack=inp_hits;}
void Defence::Deflect(){std::cout<<"i do be deflecting"<<std::endl;}

Defence::Defence(){std::cout<<"Defence type plant has been planted!"<<std::endl;}
Defence::~Defence(){std::cout<<"bye Defence type plant! (sed noises)"<<std::endl;}

