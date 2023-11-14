#include "player.hpp"
#include <iostream>

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

Player::~Player(){


}
    void Player::setHealth(int h) {this->health = h;}
    void Player::setAttack(int a) {this->attack = a;}
    void Player::setGold(int g) {this->gold = g;}   
    void Player::setMagicBeans(int mb) {this->magicBeans = mb;}
    void Player::setArmour(int ar) {this->armour = ar;}
    void Player::setSpeed(float s) {this->speed = s;}
    void Player::setPosition(int x, int y){
        this->position.x=x;
        this->position.y=y; ///hehehehehehehehehehhe

        
    }