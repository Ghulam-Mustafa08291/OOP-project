#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SDL.h>
#include <SDL_image.h>
#include "plants.hpp"
#include <vector>
#include "Armour.hpp"
#include "Weapons.hpp"
#include <string>  // Include the string header


//health,attack,gold,magicbeans,armour,speed,position,equipped weapon,equipped armour

// std::vector<Plants*> plantObjects; //will store objects pf plant and its inherited data types here

class Player{
    private:
        int health;
        int attack;
        int gold;
        int magicBeans;
        int armour;
        float speed;
        bool is_alive;
        SDL_Rect position;
        
        Armour* playerArmour;
        Weapons* playerWeapon;

    public:
        //getters,setters,constructors,destructors
        std::string direction_facing;
        void updateKiBlasts(int grid[64][36]);
        std::vector<Weapons*> active_ki_blasts;
        void setHealth(int h);
        void setAttack(int a);
        void setGold(int g);
        void setMagicBeans(int mb);
        void setArmour(int ar);
        void setSpeed(float s);
        void setPosition(int x, int y);
        void setEquippedWeapon(char* ew);
        void setEquippedArmour(char* ea);
        bool get_is_alive();
        int getHealth();
        int getAttack();
        int getGold();
        int getMagicBeans();
        int getArmour();
        float getSpeed();
        SDL_Rect& getPosition();
        SDL_Rect getFuturePosition(SDL_Event& e);
        const char* getEquippedWeapon();
        const char* getEquippedArmour();
        Player();
        Player(int h, int a, int g, int mb, int ar, float s, int x, int y, char* ew, char* ea);
        ~Player();
        void move(SDL_Event& event, int grid[64][36]);
        void add_to_health(int inp_health);
        void add_to_attack(int inp_attack);
        void add_to_speed(int inp_speed);
       

        
    };















#endif PLAYER_HPP