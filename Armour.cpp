#include "Armour.hpp"
#include <iostream>

int Armour::get_defence(){return this->defence;}
void Armour::set_defence(int def)
    {
        if (def >= 0 || def <= 100) {this->defence = def;}
        else{
            std::cout<<"invalid input!"<<std::endl;
        }
    }

int Armour::get_damage_reduction(){return this->damage_reduction;}
void Armour::set_damage_reduction(int dr)
        {if(dr>=0 || dr<=30){this->damage_reduction=dr;}
        else{
            std::cout<<"invalid input for damage reduction!"<<std::endl;
        }
    }

Armour::Armour(){
    std::cout<<"armour created!"<<std::endl;
}

Armour::~Armour(){
    std::cout<<"goodbye my expensive armour:("<<std::endl;
}