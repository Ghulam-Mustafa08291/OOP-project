#include "player.hpp"
#include "plants.hpp"
#include "enemy.hpp"
#include <iostream>
#include <vector>
std::vector<Plants*> PlantObject; //will store all the plant type objects
std::vector<Enemy*> Enemyobjects; //will store the enemy type objects

//below are the setters and constructor and destructor
Player::Player(){
    this->health=100;
    this->attack=50;
    this->gold=0;
    this->magicBeans;
    this->armour=20;
    this->speed=1;
    this->position.x=20;
    this->position.y=20;
    this->position.h=20;
    this->position.w=20;
    this->equippedWeapon="deezFists";
    this->equippedArmour="clothesheheh";
}

void Player::add_to_health(int inp_h){this->health=this->health+inp_h;}
void Player::add_to_attack(int inp_attack){this->attack=this->attack+inp_attack;}
void Player::add_to_speed(int inp_speed){this->speed=this->speed+inp_speed;}

Player::Player(int h, int a, int g, int mb, int ar, float s, int x, int y, char* ew, char* ea){
    this->health = h;
    this->attack = a;
    this->gold = g;
    this->magicBeans = mb;
    this->armour = ar;
    this->speed = s;
    this->position.x = x;
    this->position.y = y;
    this->position.h=20;
    this->position.w=20;
    this->equippedWeapon = ew;
    this->equippedArmour = ea;
    }

Player::~Player(){
    std::cout<<"Goodbye Player!"<<std::endl;
}
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
SDL_Rect& Player::getPosition(){return this->position;}
const char* Player::getEquippedWeapon(){
    return this->equippedWeapon;
}
const char* Player::getEquippedArmour(){
    return this->equippedArmour;
}

// this function controls player movement

void Player::move(SDL_Event& event, int grid[64][36]) {
    const int BLOCK_SIZE = 20; // Size of each block in the grid

    switch (event.type) {
        case SDL_KEYDOWN:
            // Get current player position
            int currentX = position.x;
            int currentY = position.y;

            // Calculate the grid position based on the player's current position
            int gridX = currentX / BLOCK_SIZE;
            int gridY = currentY / BLOCK_SIZE;

            // Check the key pressed
            switch (event.key.keysym.sym) {
                case SDLK_UP:
                    // Check if the grid position above the player is not blocked
                    if (gridY - 1 >= 0 && grid[gridX][gridY - 1] != 1) {
                        position.y -= BLOCK_SIZE;
                        std::cout << "Moving player up" << std::endl;
                    }
                    break;
                case SDLK_DOWN:
                    // Check if the grid position below the player is not blocked
                    if (gridY + 1 < 36 && grid[gridX][gridY + 1] != 1) {
                        position.y += BLOCK_SIZE;
                        std::cout << "Moving player down" << std::endl;
                    }
                    break;
                case SDLK_LEFT:
                    // Check if the grid position to the left of the player is not blocked
                    if (gridX - 1 >= 0 && grid[gridX - 1][gridY] != 1) {
                        position.x -= BLOCK_SIZE;
                        std::cout << "Moving player left" << std::endl;
                    }
                    break;
                case SDLK_RIGHT:
                    // Check if the grid position to the right of the player is not blocked
                    if (gridX + 1 < 64 && grid[gridX + 1][gridY] != 1) {
                        position.x += BLOCK_SIZE;
                        std::cout << "Moving player right" << std::endl;
                    }
                    break;
                case SDLK_q:
                    // Check if the grid position to the right of the player is not blocked
                    if (grid[gridX][gridY] == 0) {
                        grid[gridX][gridY] = 3;
                        std::cout << "Planting Sunflower" << std::endl;
                    }
                    break;
                // Add more cases for other keys if needed
            }
            break;
        // Add more cases for other events if needed
    }
}


