// author: Joan A. Pinol  (japinol)

#include <SDL.h>
#include <SDL_log.h>
#include <SDL_image.h>

const int W_WIDTH = 1280;
const int W_HEIGHT = 900;


int main(int argc, char *argv[]) {
    SDL_LogInfo(NULL, "Start App\n");
    SDL_Window *window = nullptr;
    SDL_Surface *screen;

    SDL_LogInfo(NULL, "Initialize SDL\n");
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_LogInfo(NULL, "Error. SDL could not be initialized: %s", SDL_GetError());
    }
    window = SDL_CreateWindow(
            "SDL2 ex_01",
            0, 200,
            W_WIDTH, W_HEIGHT,
            SDL_WINDOW_SHOWN);
    screen = SDL_GetWindowSurface(window);

    SDL_Surface *image;
    image = IMG_Load("assets/img/backgrounds/background_06.png");
    SDL_BlitSurface(image, NULL, screen, NULL);
    SDL_FreeSurface(image);
    SDL_UpdateWindowSurface(window);

    // Game loop
    bool done = false;
    while (!done) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                done = true;
            }
            if (event.type == SDL_MOUSEMOTION) {
            }
            if (event.type == SDL_KEYDOWN) {
            }
            const Uint8 *state = SDL_GetKeyboardState(NULL);
            if (state[SDL_SCANCODE_RIGHT]) {
                SDL_LogInfo(NULL, "right arrow key is pressed\n");
            }
        }
    }

    SDL_DestroyWindow(window);

    SDL_Quit();
    SDL_LogInfo(NULL, "End App\n");
    return EXIT_SUCCESS;
}
