#include "player.hpp"
#include <iostream>

//below are the setters and constructor and destructor
Player::Player(int h, int a, int g, int mb, int ar, float s, int x, int y,
char* ew, char* ea){
    this->health = h;
    this->attack = a;
    this->gold = g;
    this->magicBeans = mb;
    this->armour = ar;
    this->speed = s;
    this->position.x = x;
    this->position.y = y;
    this->equippedWeapon = ew;
    this->equippedArmour = ea;
    }

Player::~Player(){}
void Player::setHealth(int h) {this->health = h;}
void Player::setAttack(int a) {this->attack = a;}
void Player::setGold(int g) {this->gold = g;}   
void Player::setMagicBeans(int mb) {this->magicBeans = mb;}
void Player::setArmour(int ar) {this->armour = ar;}
void Player::setSpeed(float s) {this->speed = s;}
void Player::setPosition(int x, int y){
    this->position.x=x;
    this->position.y=y; 
}
void Player::setEquippedWeapon(char* inp_weapon){
    this->equippedWeapon=inp_weapon;
}

void Player::setEquippedArmour(char* inp_armour){
    this->equippedArmour=inp_armour;
    }


//below are the getters
int Player::getHealth() {return this->health;}
int Player::getAttack(){return this->attack;}
int Player::getGold() {return this->gold;}
int Player::getMagicBeans() {return this->magicBeans;}
int Player::getArmour() {return this->armour;}
float Player::getSpeed() {return this->speed;}
SDL_Rect Player::getPosition(){return this->position;}
const char* Player::getEquippedWeapon(){
    return this->equippedWeapon;
}
const char* Player::getEquippedArmour(){
    return this->equippedArmour;
}
