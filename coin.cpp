#include "coin.hpp"

#include <random>

int coin::generate_random_cordinates(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

coin::coin(Player& player, Enemy* newEnemy,int grid[64][36],SDL_Renderer* renderer){

    this->collected=false;
    int coinX=0;
    int coinY=0;

    int playerX=player.getPosition().x/20;
    int playerY=player.getPosition().y/20;

    int enemyX=newEnemy->getPosition().x/20;
    int enemyY=newEnemy->getPosition().y/20;

    while (grid[coinX][coinY]!=0 || (coinX==playerX && coinY==playerY) || (coinX==enemyX && coinY==enemyY)){
       coinX = generate_random_cordinates(0, 63);
        coinY = generate_random_cordinates(0, 35);

    }
    coin_position.x=coinX*20;
    coin_position.y=coinY*20;
    coin_position.w = 20;
    coin_position.h = 20;

    SDL_Surface* coin_surface = IMG_Load("Gold_coin.png");
    if (coin_surface == nullptr) {
        std::cout << "Unable to load coin image! SDL_image Error: " << IMG_GetError() << std::endl;
        return;
    }

    coin_texture = SDL_CreateTextureFromSurface(renderer, coin_surface);
    SDL_FreeSurface(coin_surface);
    std::cout<<"coinX="<<coinX<<" coinY="<<coinY<<std::endl;

    
}

void coin::render(SDL_Renderer* renderer) {
    SDL_RenderCopy(renderer, coin_texture, nullptr, &coin_position);
}

coin::~coin() {
    if (coin_texture) {
        SDL_DestroyTexture(coin_texture);
    }
    std::
    cout << "coin destroyed" << std::endl;
}

bool coin::check_coint_collision_with_player(Player& player){
    int coinX=coin_position.x/20;
    int coinY=coin_position.y/20;

     int playerX=player.getPosition().x/20;
    int playerY=player.getPosition().y/20;

    if(coinX==playerX && coinY==playerY){
        // std::cout<<"player and coin collided"<<std::endl;
    
        return true;
        
    }
    else{
        return false;
    }
}

void coin::kill_coin(){
    SDL_DestroyTexture(this->coin_texture);
    std::cout<<"in kill coin function, i deleted the texture"<<std::endl;
}


void coin::player_colllect_coin(Player& player){
    if(collected==false){
        player.setGold(player.getGold()+1);
        std::cout<<"new player gold is:"<<player.getGold()<<std::endl;
        kill_coin();
        collected=true;
    }
   
}



