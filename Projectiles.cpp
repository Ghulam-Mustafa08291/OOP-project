#include "Projectiles.hpp"
#include <iostream>

int Projectiles::get_damage(){return this->damage;}
void Projectiles::set_damage(int d){ this->damage=d;}

int Projectiles::get_speed(){return this->speed;}
void Projectiles::set_speed(int s){ this->speed=s;}

int Projectiles::get_time(){return this->time;}
void Projectiles::set_time(int s){this->time=s;}


void in_contact(){std::cout<<"how tf am i supposed to know that i am in contact?!"<<std::endl;}
void get_positon(){std::cout<<"getting position"<<std::endl;}
void deal_damage(){std::cout<<"dealing damage now jhehe"<<std::endl;}

Projectiles::Projectiles(){std::cout<<"hello Projectiles the base class!"<<std::endl;}
Projectiles::~Projectiles(){std::cout<<"bye mr Projectiles base class"<<std::endl;}