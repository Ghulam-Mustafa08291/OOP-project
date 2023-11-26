#include "enemy.hpp"
#include <iostream>

void Enemy::setHealth(int h){
    this->health=h;
}

void Enemy::setSpeed(int s){
    this->speed=s;
}

void Enemy::setDamage(int d){
    this->damage=d;
}

int Enemy::getHealth(){
    return this->health;
}

int Enemy::getSpeed(){
    return this->speed;
}

int Enemy::getDamage(){
    return this->damage;
}

Enemy::Enemy()
:health{100},speed{1},damage{5} //assuming random values for them now
{}

Enemy::~Enemy(){} 
