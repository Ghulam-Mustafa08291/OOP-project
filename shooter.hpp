#ifndef SHOOTER_HPP
#define SHOOTER_HPP

#include "plants.hpp"
#include "enemy.hpp"
#include <SDL.h>
#include <SDL_image.h>

class Shooter : public Plants {
private:
    int attack_freq;
    int damage;
    int range;

public:
    //getters and setters and other functions
    int get_attack_freq();
    void set_attack_freq(int freq);
    int get_damage();
    void set_damage(int dmg);
    int get_range();
    void set_range(int rng);
    void shoot_projectile(Enemy& e);
    //constructor and destructor
    Shooter();
    Shooter(int row,int col);
    ~Shooter();
};

#endif // SHOOTER_HPP
