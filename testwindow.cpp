#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "player.hpp"

int main(int argc, char* args[]) {
    // Initializing SDL

    Player player;

    



    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError()); 
        return 1; //returning for stopping
    }

    // Creating  a window
    SDL_Window* window = SDL_CreateWindow("Sample Game Screen", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
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
    SDL_Surface* maze1 = IMG_Load("map1.png");
    if (imageSurface == NULL) {
        printf("Unable to load image! SDL_image Error: %s\n", IMG_GetError());
        return 1;
    }

    if (maze1 == NULL) {
        printf("Unable to load image! SDL_image Error: %s\n", IMG_GetError());
        return 1;
    }

    // Creating a texture from the image surface
    SDL_Texture* imageTexture = SDL_CreateTextureFromSurface(renderer, imageSurface);
    SDL_Texture* map1Texture = SDL_CreateTextureFromSurface(renderer, maze1);




    // Free the surface since we have the texture now
    SDL_FreeSurface(imageSurface);
    SDL_FreeSurface(maze1);



      SDL_Surface* playerSurface = IMG_Load("temp_player.png");
      std::cout<<"hello player"<<std::endl;
    if (playerSurface == NULL) {
        printf("Unable to load player image! SDL_image Error: %s\n", IMG_GetError());
        return 1;
    }

        // Create a texture from the player image surface
    SDL_Texture* playerTexture = SDL_CreateTextureFromSurface(renderer, playerSurface);
    SDL_FreeSurface(playerSurface); // Free the surface as the texture is created








   // Main loop flag
bool quit = false;

bool startGame = false; // Flag to control the game start

// Event handler for handling events
SDL_Event e;

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
        }
        else if (e.type == SDL_KEYDOWN) {
            // Call move() function for player movement
            player.move(e); // Pass the event to the player's move function
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
        player.move(e); // Assuming the player continuously moves once the game starts
        SDL_RenderCopy(renderer, map1Texture, NULL, NULL);

        SDL_Rect playerRect = player.getPosition();
        SDL_RenderCopy(renderer, playerTexture, NULL, &playerRect);
    }

    SDL_RenderPresent(renderer);

    // SDL_Rect playerRect = player.getPosition();
    // SDL_RenderCopy(renderer, playerTexture, NULL, &playerRect); 

    // // Present the renderer
    // SDL_RenderPresent(renderer);
}
    // Destroy texture
    SDL_DestroyTexture(imageTexture);

    SDL_DestroyTexture(playerTexture);

    // Destroy window
    SDL_DestroyWindow(window);

    // Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();

    return 0;
}