#ifndef COSTDOWN_HPP
#define COSTDOWN_HPP
#include "Plants.hpp"
#include "Powerups.hpp"

#include <SDL.h>
#include <SDL_image.h>



class CostDown: public Powerups{
    public:
        void decrease_cost(Plants& p) override;
        void help_player (Player& p) override;
        CostDown();
        ~CostDown();
};
#endif