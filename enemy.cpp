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

void Enemy::trackPlayer(const Player& player) {
    // Get player and enemy positions
    int playerX = player.getPosition().x;
    int playerY = player.getPosition().y;
    int enemyX = this->position.x;
    int enemyY = this->position.y;

    // Calculate the direction towards the player
    float dx = static_cast<float>(playerX - enemyX);
    float dy = static_cast<float>(playerY - enemyY);

    // Normalize the direction vector
    float length = std::sqrt(dx * dx + dy * dy);
    if (length != 0) {
        dx /= length;
        dy /= length;
    }

    // Update enemy position to move towards the player
    // Adjust the enemy's position based on its speed
    float speed = this->getSpeed(); // Get the enemy's speed
    this->position.x += static_cast<int>(dx * speed);
    this->position.y += static_cast<int>(dy * speed);
}

Enemy::Enemy()
:health{100},speed{1},damage{5} //assuming random values for them now
{}

Enemy::~Enemy(){} 
