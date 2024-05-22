#include "EnemyBlast.hpp"

EnemyBlast::EnemyBlast(int grid[64][36], Enemy* newEnemy, SDL_Renderer* renderer) {
    enemy_blast_position.x = 100; // Fixing these values for now
    enemy_blast_position.y = 120;
    enemy_blast_position.w = 20;
    enemy_blast_position.h = 20;

    SDL_Surface* EnemyBlast_Surface = IMG_Load("fireball.png");
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
    std::cout << "enemy blast destroyed" << std::endl;
}

void EnemyBlast::render(SDL_Renderer* renderer) {
    std::cout<<"in enemyblast render function"<<std::endl;
    SDL_RenderCopy(renderer, enemy_blast_texture, nullptr, &enemy_blast_position);
}
