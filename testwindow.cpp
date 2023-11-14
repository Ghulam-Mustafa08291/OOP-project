#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

int main(int argc, char* args[]) {
    // Initializing SDL
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
    SDL_Surface* imageSurface = IMG_Load("C:\\Users\\MAUSTAFA\\OneDrive - Habib University\\sem 3\\oop\\oop project\\OOP-project\\main_window.png");
    if (imageSurface == NULL) {
        printf("Unable to load image! SDL_image Error: %s\n", IMG_GetError());
        return 1;
    }

    // Creating a texture from the image surface
    SDL_Texture* imageTexture = SDL_CreateTextureFromSurface(renderer, imageSurface);

    // Free the surface since we have the texture now
    SDL_FreeSurface(imageSurface);

    // Main loop flag
    bool quit = false;

    // Event handler for handling events
    SDL_Event e;

    //our main loop
    while (!quit) {
        // Handle events on the queue
        while (SDL_PollEvent(&e) != 0) {
            // User requests quit
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        // Clear the screen (black)
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); //gives black color initially
        SDL_RenderClear(renderer);

        // Render the texture
        SDL_RenderCopy(renderer, imageTexture, NULL, NULL);

        // Present the renderer
        SDL_RenderPresent(renderer);
    }

    // Destroy texture
    SDL_DestroyTexture(imageTexture);

    // Destroy window
    SDL_DestroyWindow(window);

    // Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();

    return 0;
}
