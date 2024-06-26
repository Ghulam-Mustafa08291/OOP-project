#include "EnemyBlast.hpp"
#include "player.hpp"

EnemyBlast::EnemyBlast(int grid[64][36], Enemy* newEnemy, SDL_Renderer* renderer) {
    // std::cout<<"eneterd the enemyblast constructor"<<std::endl;
    enemy_blast_position.x = newEnemy->getPosition().x; // Start at enemy's position
    enemy_blast_position.y = newEnemy->getPosition().y;
    enemy_blast_position.w = 20;
    enemy_blast_position.h = 20;
    damage=10;
    collided=false;

    SDL_Surface* EnemyBlast_Surface = IMG_Load("bluefireball.png");
    if (EnemyBlast_Surface == nullptr) {
        std::cout << "Unable to load fireball image! SDL_image Error: " << IMG_GetError() << std::endl;
        return;
    }

    enemy_blast_texture = SDL_CreateTextureFromSurface(renderer, EnemyBlast_Surface);
    SDL_FreeSurface(EnemyBlast_Surface);

    if (enemy_blast_texture == nullptr) {
        std::cout << "Unable to create texture from fireball image! SDL Error: " << SDL_GetError() << std::endl;
    }
}

EnemyBlast::~EnemyBlast() {
    if (enemy_blast_texture != nullptr) {
        SDL_DestroyTexture(enemy_blast_texture);
    }
    std::cout << "Enemy blast destroyed" << std::endl;
}

bool EnemyBlast::isValidMove(int x, int y, int grid[64][36]) {
    const int GRID_WIDTH = 64;
    const int GRID_HEIGHT = 36;

    if (x < 0 || x >= GRID_WIDTH * 20 || y < 0 || y >= GRID_HEIGHT * 20) {
        return false;
    }

    int cellX = x / 20;
    int cellY = y / 20;

    // if (grid[cellX][cellY] == 1 || grid[cellX][cellY] == 3) {
    //      // Collides with a wall
    //      grid[cellX][cellY] = 0; 
    // }

    return true; // Position is valid
}

void EnemyBlast::go_to_player(Player& player, int grid[64][36]) {
    if(collided_with_player(player)==true && collided==true){
        damage_player(player);
    }
    int grid_player_x = player.getPosition().x / 20;
    int grid_player_y = player.getPosition().y / 20;

    int enemyblast_x = enemy_blast_position.x / 20;
    int enemyblast_y = enemy_blast_position.y / 20;

    float new_x = 0;
    float new_y = 0;

    if (enemyblast_x != grid_player_x || enemyblast_y != grid_player_y) {
        if (grid_player_x < enemyblast_x ) {
            new_x =- 0.1f;
        } else if (grid_player_x > enemyblast_x) {
            new_x = 0.1f;
        }

        if (grid_player_y < enemyblast_y ) {
            new_y =- 0.1f;
        } else if (grid_player_y > enemyblast_y) {
            new_y = 0.1f;
        }
        blast_x+=new_x;
        blast_y+=new_y;
        enemy_blast_position.x = static_cast<int>(blast_x);
        enemy_blast_position.y = static_cast<int>(blast_y);
        if(grid[enemyblast_x][enemyblast_y]==1){
            grid[enemyblast_x][enemyblast_y]=0;
        }
        
    }
}

void EnemyBlast::render(SDL_Renderer* renderer) {
    SDL_RenderCopy(renderer, enemy_blast_texture, nullptr, &enemy_blast_position);
}


void EnemyBlast::kill_enemyblast(){
    SDL_DestroyTexture(this->enemy_blast_texture);

}
bool EnemyBlast::collided_with_player(Player& player){
    int grid_player_x = player.getPosition().x / 20;
    int grid_player_y = player.getPosition().y / 20;

    int grid_enemyblast_x=enemy_blast_position.x/20;
    int grid_enemyblast_y=enemy_blast_position.y/20;
    std::cout<<"grid_player_x:"<<grid_player_x<<", grid_player_y:"<<grid_player_y<<" ,grid_enemyblast_x: "<<grid_enemyblast_x<<" ,grid_enemyblast_y: "<<grid_enemyblast_y<<std::endl;
    if(grid_enemyblast_x==grid_player_x && grid_enemyblast_y==grid_player_y){
        std::cout<<"enemy blast collided with the player!"<<std::endl;
        collided=true;
        return true;
    }
    else{
        return false;
    }
}

void EnemyBlast::damage_player(Player& player){
    
    player.setHealth(player.getHealth()-damage);
    collided=false;
    kill_enemyblast();
    std::cout<<"player damaged, new player health: "<<player.getHealth()<<std::endl; 
}
