#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "player.hpp"
#include <vector>
#include "Plants.hpp"
#include "enemy.hpp"
#include "shooter.hpp"

int changeMap (int* g[64][36], int* m[64][36]) {
    for (int i = 0; i < 64; i++) {
        for (int j = 0; j < 36; j++) {
            g[i][j] = m[i][j];
        }
    }
    return 0;
}

std::vector<Enemy*> enemies;

int initMixer = Mix_Init(0);

int main(int argc, char* args[]) {
    // Initializing SDL

    Player player;
    
    // Enemy enemy;
    std::vector<Plants*> PlantObject; //will store all the plant type objects

    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);

    Mix_Music* battle_music = Mix_LoadMUS("audio/gohan_theme.wav");
    Mix_Music* menu_music = Mix_LoadMUS("audio/pain_theme.wav");

    if (!battle_music) {
        std::cout << "Battle Music Error" << Mix_GetError() << std::endl << std::endl << std::endl;
    }
    
    if (!menu_music) {
        std::cout << "Menu Music Error" << Mix_GetError() << std::endl << std::endl << std::endl;
    }


    Mix_Chunk* damage_sound = Mix_LoadWAV("audio/oof.wav");
    Mix_Chunk* room_change_sound = Mix_LoadWAV("audio/room_change_noise.wav");
    Mix_Chunk* projectile_sound = Mix_LoadWAV("audio/projectile_noise.wav");

    Mix_PlayMusic(menu_music, -1);

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError()); 
        return 1; //returning for stopping
    }

    

    // Creating  a window
    SDL_Window* window = SDL_CreateWindow("Sample Game Screen", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }


    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Initialize SDL_image
    if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG) {
        printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
        return 1;
    }

    // Loading the start screen PNG image
    SDL_Surface* imageSurface = IMG_Load("main_window.png");
    if (imageSurface == NULL) {
        printf("Unable to load image! SDL_image Error: %s\n", IMG_GetError());
        return 1;
    }

    // Creating a texture from the image surface
    SDL_Texture* imageTexture = SDL_CreateTextureFromSurface(renderer, imageSurface);




    // Free the surface since we have the texture now
    SDL_FreeSurface(imageSurface);



      SDL_Surface* playerSurface = IMG_Load("temp_player.png");
      SDL_Surface* enemySurface = IMG_Load("temp_player.jpg");
      SDL_Surface* plantSurface = IMG_Load("sunflower.png");
      std::cout<<"hello player"<<std::endl;
    if (playerSurface == NULL) {
        printf("Unable to load player image! SDL_image Error: %s\n", IMG_GetError());
        return 1;
    }

    if (plantSurface == NULL) {
        printf("Unable to load plant image! SDL_image Error: %s\n", IMG_GetError());
        return 1;
    }

        // Create a texture from the player image surface
    SDL_Texture* playerTexture = SDL_CreateTextureFromSurface(renderer, playerSurface);
    SDL_FreeSurface(playerSurface); // Free the surface as the texture is created


    SDL_Texture* enemyTexture = SDL_CreateTextureFromSurface(renderer, enemySurface);
    SDL_FreeSurface(enemySurface); // Free the surface as the texture is created

    SDL_Texture* plantTexture = SDL_CreateTextureFromSurface(renderer, plantSurface);
    SDL_FreeSurface(plantSurface); // Free the surface as the texture is created






   // Main loop flag
bool quit = false;

bool startGame = false; // Flag to control the game start

// Event handler for handling events
SDL_Event e;

int grid[64][36] =
{
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,1}, // 1
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1}, // 2
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1}, // 3
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1}, // 4
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1}, // 5
    {1,0,0,0,0,0,0,0,0,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1}, // 6
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1}, // 7
    {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1}, // 8
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1}, // 9
    {1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1}, // 10
    {1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1}, // 11
    {1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1}, // 12
    {1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1}, // 13
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1}, // 14
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1}, // 15
    {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1}, // 16
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,1}, // 17
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,1}, // 18
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,0,0,0,1}, // 19
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,1,0,0,0,1}, // 20
    {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1}, // 21
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1}, // 22
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1}, // 23
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1}, // 24
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1}, // 25
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1}, // 26
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1}, // 27
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1}, // 28
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1}, // 29
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1}, // 30
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1}, // 31
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1}, // 32
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1}, // 33
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1}, // 34
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1}, // 35
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1}, // 36
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1}, // 37
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1}, // 38
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1}, // 39
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1}, // 40
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1}, // 41
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1}, // 42
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1}, // 43
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1}, // 44
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1}, // 45
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1}, // 46
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1}, // 47
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1}, // 48
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1}, // 49
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1}, // 50
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1}, // 51
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1}, // 52
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1}, // 53
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1}, // 54
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1}, // 55
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1}, // 56
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1}, // 57
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1}, // 58
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1}, // 59
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1}, // 60
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, // 61
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, // 62
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, // 63
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, // 64
};

// for (int i = 0; i < 64; i++) {
//     for (int j = 0; j < 36; j++) {
//         // if (j == 10) {
//         //     grid[i][j] = 1;
//         //     std::cout << "1";
//         // }
//         if (i == 0 || i == 63 || j == 0 || j == 35) {
//             grid[i][j] = 1;
//             std::cout << "1";
//         }
//         else {
//             grid[i][j] = 0; 
//             std::cout << "0";
//         }
//     }
//     std::cout << std::endl;
// }

int time = 0;

// Main loop
while (!quit) {
    // Handle events on the queue
    while (SDL_PollEvent(&e) != 0) {
        // User requests quit
        if (e.type == SDL_QUIT) {
            quit = true;
        }
        if (e.key.keysym.sym == SDLK_SPACE) { // Assuming space key starts the game
            startGame = true; // Set the flag to start the game
            Mix_PauseMusic();
            Mix_PlayChannel(-1, room_change_sound, 0);
            Mix_PlayMusic(battle_music, -1);
        }
        else if (e.type == SDL_KEYDOWN) {
            // Call move() function for player movement
            if (e.type == SDLK_q) {
                Shooter* shooter_plant = new Shooter{player.getPosition().x,player.getPosition().y};
                PlantObject.push_back(shooter_plant);
            }
            player.move(e, grid); // Pass the event to the player's move function
        }
        // Handle other types of events here if needed
    }

    // Clear the screen (black)
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Render the texture (background)
    SDL_RenderCopy(renderer, imageTexture, NULL, NULL);

    // Render the player texture at the updated position adfter the move function is called
    if (startGame) {
        time++;
        player.move(e, grid); // Assuming the player continuously moves once the game starts

        
        for (int i = 0; i < 64; ++i) {
            for (int j = 0; j < 36; ++j) {
                // Define rectangle positions based on grid position and block size
                SDL_Rect blockRect = { i * 20, j * 20, 20, 20 }; // Adjust block size as needed

                // Render grey block for value 1 and brown block for value 0
                if (grid[i][j] == 1) {
                    SDL_SetRenderDrawColor(renderer, 150, 150, 150, 255); // Grey color
                } 
                else if (grid[i][j] == 0) {
                    SDL_SetRenderDrawColor(renderer, 139, 69, 19, 255); // Brown color
                }
                else if (grid[i][j] == 2) {
                    SDL_SetRenderDrawColor(renderer, 128, 69, 128, 255); // Purple color
                    // if (time % 120 == 0) {
                    //     SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red color
                    //     grid[i + 1][j] = 4;
                    // }
                    // else {
                    //     SDL_SetRenderDrawColor(renderer, 128, 69, 128, 255); // Purple color
                    // }

                    // Create a new enemy every 100 ticks
                    if (time % 1000 == 0) {
                        // Create a new enemy on the heap
                        Enemy* newEnemy = new Enemy(i, j);
                        //time=0;

                        // Add the new enemy to the vector
                        enemies.push_back(newEnemy);
                    }
                }
                else if (grid[i][j] == 3) { //plants will be stationary
                    SDL_SetRenderDrawColor(renderer, 0, 128, 0, 255); // Green color, shooter plant
                    
                    // Shooter* shooter_plant = new Shooter{i,j};//have to push in vector
                    // SDL_Rect plantRect = shooter_plant->getposition();
                    // SDL_RenderCopy(renderer, plantTexture, NULL, &plantRect);
                }
                // else if (grid[i][j] == 4) {
                //     SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red color, enemy
                //     grid[i+1][j] == 4;
                //     grid[i][j] == 0;
                // }
                SDL_RenderFillRect(renderer, &blockRect);
            }
        }

        // for (int i = 0; i < 64; i++) {
        //     for (int j = 0; j < 36; j++) {
        //         if (grid[i][j] == 1) {
        //             std::cout << "1";
        //         }
        //         else if (grid[i][j] == 0) {
        //             std::cout << "0";
        //         }
        //         else if (grid[i][j] == 2) {
        //             std::cout << "2";
        //         }
        //         else if (grid[i][j] == 3) {
        //             std::cout << "3";
        //         }
        //         else if (grid[i][j] == 4) {
        //             std::cout << "4";
        //         }
        //     }
        //     std::cout << std::endl;
        // }

        // std::cout << std::endl << std::endl << std::endl << std::endl;

        // Update and render existing enemies
        for (int i=0;i<enemies.size();i++) {
            
            // Update enemy logic (e.g., chasing the player)
            // For now, assuming a simple update function in the Enemy class
            if(i<PlantObject.size()){
            SDL_Rect plantRect= PlantObject[i]->getPosition();
            SDL_RenderCopy(renderer, plantTexture, NULL, &plantRect);
            enemies[i]->update(player,grid,*PlantObject[i]);
            }
            else{
                enemies[i]->update(player,grid);
            }
            
           

            // Render enemy on the grid
            // For now, assuming a simple render function in the Enemy class
            SDL_Rect enemyRect= enemies[i]->getPosition();
            SDL_RenderCopy(renderer, enemyTexture, NULL, &enemyRect);
        }

        // for (int i=0;i<PlantObject.size();i++) {
        //     // Render plant on the grid
        //     // For now, assuming a simple render function in the Plant class
        //     SDL_Rect plantRect= PlantObject[i]->getPosition();
        //     SDL_RenderCopy(renderer, plantTexture, NULL, &plantRect);
        


        // for (int i=0;i<enemies.size();i++) {
        //     // Update enemy logic (e.g., chasing the player)
        //     // For now, assuming a simple update function in the Enemy class
        //     enemies[i]->update(player,grid);

        //     // Render enemy on the grid
        //     // For now, assuming a simple render function in the Enemy class
        //     SDL_Rect enemyRect= enemies[i]->getPosition();
        //     SDL_RenderCopy(renderer, enemyTexture, NULL, &enemyRect);
        // }

        SDL_Rect playerRect = player.getPosition();
        // SDL_Rect enemyRect= enemy.getPosition();
        SDL_RenderCopy(renderer, playerTexture, NULL, &playerRect);
        // SDL_RenderCopy(renderer, enemyTexture, NULL, &enemyRect);

    }

    if (player.get_is_alive() == false) {
        break;
    }

    // Present the renderer
    SDL_RenderPresent(renderer);
}

    SDL_RenderClear(renderer);
    // Destroy texture
    SDL_DestroyTexture(imageTexture);

    SDL_DestroyTexture(playerTexture);
    SDL_DestroyTexture(enemyTexture);
    SDL_DestroyTexture(plantTexture);

    for (int i=0;i<PlantObject.size();i++) {
        delete PlantObject[i];
        PlantObject[i] = nullptr;
    }

    for (int i=0;i<enemies.size();i++) {
        delete enemies[i];
        enemies[i] = nullptr;
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    std::cin;

    SDL_RenderClear(renderer);

    // Destroy window
    SDL_DestroyWindow(window);

    // Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();

    return 0;
}