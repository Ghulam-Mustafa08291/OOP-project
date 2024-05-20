#include "Weapons.hpp"
#include <iostream>
#include <cstdlib>


int Weapons::get_damage(){return this->damage;}
void Weapons::set_damage(int d)
{
    if(d>0){
    this->damage=d;
    }
    else{
        std::cout<<"damage must be more than 0"<<std::endl;
    }
}

int Weapons::get_range(){return this->range;}
void Weapons::set_range(int r)
{
    if(r>0){
    this->range=r;
    }
    else{
        std::cout<<"rrange must be more than 0"<<std::endl;
    }
}

int Weapons::get_attack_speed(){return this->attack_speed;}
void Weapons::set_attack_speed(int s)
{
    if(s>0){
    this->attack_speed=s;
    }
    else{
        std::cout<<"attack speed must be more than 0"<<std::endl;
    }
}

Weapons::Weapons(){
    std::cout<<"Weapon created!"<<std::endl;
    damage=105;


}

Weapons::~Weapons(){
    std::cout<<"goodbye my weapon"<<std::endl;
}


bool Weapons::check_weapon_collision_enemy(Enemy* enemy) {
    if (enemy == nullptr) {
        std::cerr << "Error: enemy is nullptr!" << std::endl;
        return false;
    }

    int deltaX = enemy->getPosition().x - this->weapon_position.x;
    int deltaY = enemy->getPosition().y - this->weapon_position.y;

    if (std::abs(deltaX) == 1 || std::abs(deltaY) == 1) {
        std::cout << "The weapon collided with the enemy" << std::endl;

        
        this->weapon_position.x=0;
        this->weapon_position.y=0;
        std::cout<<"in check_weapon_collision_enemy, changed the position of the weapon to 0"<<std::endl;
        return true;
    }
    
    return false;
}

void Weapons::kill_enemy(Enemy* enemy, int grid[64][36]) {
    std::cout << "Entered the kill_enemy method!" << std::endl;

    if (enemy == nullptr) {
        std::cerr << "Error: enemy is nullptr!" << std::endl;
        return;
    }
    if (enemy->getHealth() <= 0) {
        std::cout << "Enemy is already dead!" << std::endl;
        return;
    }

    int enemyPosX = enemy->getPosition().x/20;
    int enemyPosY = enemy->getPosition().y/20;

    std::cout << "In the kill_enemy method, " << "enemy->getPosition().x=" << enemyPosX << ", enemy->getPosition().y=" << enemyPosY << std::endl;

    if (enemyPosX >= 0 && enemyPosX < 64 && enemyPosY >= 0 && enemyPosY < 36) {
        // grid[enemyPosX][enemyPosY] = 0;
        if (enemy->texture) {
            SDL_DestroyTexture(enemy->texture);
        }
    } else {
        std::cerr << "Error: enemy position out of bounds: (" << enemyPosX << ", " << enemyPosY << ")" << std::endl;
    }

    int weaponPosX = this->weapon_position.x/20;
    int weaponPosY = this->weapon_position.y/20;

    std::cout << "In the kill_enemy method, " << "this->weapon_position.x=" << weaponPosX << ", this->weapon_position.y=" << weaponPosY << std::endl;

    if (weaponPosX >= 0 && weaponPosX < 64 && weaponPosY >= 0 && weaponPosY < 36) {
        grid[weaponPosX][weaponPosY] = 0;
    } else {
        std::cerr << "Error: weapon position out of bounds: (" << weaponPosX << ", " << weaponPosY << ")" << std::endl;
    }

    // Assuming you want to delete the enemy if it is killed
    // delete enemy;
}

void Weapons::weapon_damage_enemy(Enemy* enemy, int grid[64][36]) {
    if (enemy == nullptr) {
        std::cerr << "Error: enemy is nullptr!" << std::endl;
        return;
    }
    enemy->setHealth(enemy->getHealth() - this->get_damage());
    if (enemy->getHealth() <= 0) {
        std::cout << "Will call the kill_enemy method now" << std::endl;
        kill_enemy(enemy, grid);
    } else {
        std::cout << "In weapon_damage_enemy method, enemy->getHealth()=" << enemy->getHealth() << ", this->get_damage()=" << this->get_damage() << std::endl;
        std::cout << "In weapon_damage_enemy method, enemy->getHealth() - this->get_damage()=" << enemy->getHealth() - this->get_damage() << std::endl;
        // enemy->setHealth(enemy->getHealth() - this->get_damage());
        std::cout << "The enemy was damaged" << std::endl;
         int weaponPosX = this->weapon_position.x/20;
        int weaponPosY = this->weapon_position.y/20;

        std::cout << "In the weapon_damage_enemy method, " << "this->weapon_position.x=" << weaponPosX << ", this->weapon_position.y=" << weaponPosY << std::endl;

        if (weaponPosX >= 0 && weaponPosX < 64 && weaponPosY >= 0 && weaponPosY < 36) {
            // grid[weaponPosX][weaponPosY] = 0;
            this->weapon_direction="NULL";
            std::cout<<"In the weapon_damage_enemy method, weapon_direction: "<<this->weapon_direction<<std::endl;
        }
    }
}
