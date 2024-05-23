#include "EnemyBlast.hpp"
#include "player.hpp"

EnemyBlast::EnemyBlast(int grid[64][36], Enemy* newEnemy, SDL_Renderer* renderer) {
    std::cout<<"eneterd the enemyblast constructor"<<std::endl;
    enemy_blast_position.x = newEnemy->getPosition().x; // Start at enemy's position
    enemy_blast_position.y = newEnemy->getPosition().y;
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

    if (grid[cellX][cellY] == 1 || grid[cellX][cellY] == 3) {
        return false; // Collides with a wall
    }

    return true; // Position is valid
}

void EnemyBlast::go_to_player(Player& player, int grid[64][36]) {
    int grid_player_x = player.getPosition().x / 20;
    int grid_player_y = player.getPosition().y / 20;

    int enemyblast_x = enemy_blast_position.x / 20;
    int enemyblast_y = enemy_blast_position.y / 20;

    int new_x = enemy_blast_position.x;
    int new_y = enemy_blast_position.y;

    if (enemyblast_x != grid_player_x || enemyblast_y != grid_player_y) {
        if (grid_player_x < enemyblast_x && isValidMove(enemy_blast_position.x - 20, enemy_blast_position.y, grid)) {
            new_x -= 20;
        } else if (grid_player_x > enemyblast_x && isValidMove(enemy_blast_position.x + 20, enemy_blast_position.y, grid)) {
            new_x += 20;
        }

        if (grid_player_y < enemyblast_y && isValidMove(enemy_blast_position.x, enemy_blast_position.y - 20, grid)) {
            new_y -= 20;
        } else if (grid_player_y > enemyblast_y && isValidMove(enemy_blast_position.x, enemy_blast_position.y + 20, grid)) {
            new_y += 20;
        }

        enemy_blast_position.x = new_x;
        enemy_blast_position.y = new_y;
    }
}

void EnemyBlast::render(SDL_Renderer* renderer) {
    SDL_RenderCopy(renderer, enemy_blast_texture, nullptr, &enemy_blast_position);
}
