#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <SDL.h>
#include <SDL_image.h>
#include "Player.hpp" // Include the Player class header

class Enemy {
private:
    int health;
    int speed;
    int damage;
    SDL_Rect position;

public:
    // Getters and setters
    void setHealth(int h);
    void setSpeed(int s);
    void setDamage(int d);
    int getHealth();
    int getSpeed();
    int getDamage();

    // Method to track the player
    void trackPlayer(const Player& player);

    // Constructors and destructor
    Enemy();
    ~Enemy();
};

#endif // ENEMY_HPP
