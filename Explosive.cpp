#include "Explosive.hpp"
#include <iostream>

int Explosive::get_time(){return this->time;}
void Explosive::set_time(int inp_time){this->time = inp_time;}

void Explosive::scan_range(){std::cout<<"scaning range "<<std::endl;}
void Explosive::detonate(){std::cout<<"BOOM!"<<std::endl;}

Explosive::Explosive(){std::cout<<"explosive type plant has been planted!"<<std::endl;}
Explosive::~Explosive(){std::cout<<"bye explsoive type plant"<<std::endl;}