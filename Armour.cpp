#include "Armour.hpp"
#include <iostream>

int Armour::get_defence(){return this->defence;}
void Armour::set_defence(int def){this->defence=def;}

int Armour::get_damage_reduction(){return this->damage_reduction;}
void Armour::set_damage_reduction(int dr){this->damage_reduction=dr;}

Armour::Armour(){
    std::cout<<"armour created!"<<std::endl;
}

Armour::~Armour(){
    std::cout<<"goodbye my expensive armour:("<<std::endl;
}