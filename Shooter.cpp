#include "shooter.hpp"
#include <iostream>

int Shooter::get_attack_freq(){return this->attack_freq;}
void Shooter::set_attack_freq(int inp_AF){this->attack_freq=inp_AF;}

int Shooter::get_damage(){return this->damage;}
void Shooter::set_damage(int inp_damage){this->damage=inp_damage;}

int Shooter::get_range(){return this->range;}
void Shooter::set_range(int inp_range){this->range=inp_range;}

void Shooter::shoot_projectile(Enemy& e){
    std::cout<<"imma shoot hehe"<<std::endl;
    e.setHealth(e.getHealth()-this->get_damage()); //decreasing the health of the enemy
    std::cout<<"shooting enemy! enemy health: "<<e.getHealth()<<std::endl;
}

Shooter::Shooter(){this->attack_freq=5; this->damage=10; this->range=20;this->setPosition(20,20); std::cout<<"Shooter type plant has been planted!"<<std::endl;}
Shooter::Shooter(int row,int col){
    this->attack_freq=5; this->damage=10; this->range=20;
    this->setPosition(row*20,col*20);
}
Shooter::~Shooter(){std::cout<<"bye bye shooter:("<<std::endl;}