#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

int main(int argc, char* args[]) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) { //if values is less than 0 then initialization has failed
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1; //returning here make the program exitt
    }

    // Create a window
    SDL_Window* window = SDL_CreateWindow("sample game screen", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    if (window == NULL) { //if the creating of a window fails then program is exitted by returninf 1
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0); //renderer is used for graphics on the window

    // Main loop flag
    bool quit = false;

    // Event handler for handling events
    SDL_Event e;

    // Main loop
    while (!quit) {
        // Handle events on queue
        while (SDL_PollEvent(&e) != 0) {
            // User requests quit
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        // Clear the screen (black)
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); //sets the color of the screen to black
        SDL_RenderClear(renderer);

        // Present the renderer
        SDL_RenderPresent(renderer);
    }

    // Destroy window
    SDL_DestroyWindow(window);

    // Quit SDL subsystems
    SDL_Quit();

    return 0;
}