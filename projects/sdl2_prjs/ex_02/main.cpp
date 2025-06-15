// author: Joan A. Pinol  (japinol)

#include <SDL.h>
#include <SDL_log.h>
#include <SDL_image.h>

const int W_WIDTH = 1280;
const int W_HEIGHT = 900;


int main(int argc, char *argv[]) {
    SDL_LogInfo(NULL, "Start App\n");
    SDL_Window *window = nullptr;
    SDL_Renderer* renderer;
    SDL_Surface *screen;

    SDL_LogInfo(NULL, "Initialize SDL\n");
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_LogInfo(NULL, "Error. SDL could not be initialized: %s", SDL_GetError());
    }
    window = SDL_CreateWindow(
            "SDL2 ex_01",
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            W_WIDTH, W_HEIGHT,
            SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(
            window, -1,
            SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);

    SDL_Surface *bmpSurf = IMG_Load("assets/img/backgrounds/background_with_arrow.png");
    SDL_Texture *bmpTex = SDL_CreateTextureFromSurface(renderer, bmpSurf);
    SDL_FreeSurface(bmpSurf);

    // Make a target texture to render too
    SDL_Texture *texTarget = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,
                                               SDL_TEXTUREACCESS_TARGET,
                                               W_WIDTH, W_HEIGHT);
    // Render to the texture
    SDL_SetRenderTarget(renderer, texTarget);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, bmpTex, NULL, NULL);
    // Detach the texture
    SDL_SetRenderTarget(renderer, NULL);

    // Render the texture target to our screen, but upside down
    SDL_RenderClear(renderer);
    SDL_RenderCopyEx(renderer, texTarget, NULL, NULL, 0, NULL, SDL_FLIP_VERTICAL);
    SDL_RenderPresent(renderer);

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

    SDL_DestroyTexture(texTarget);
    SDL_DestroyTexture(bmpTex);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
    SDL_LogInfo(NULL, "End App\n");
    return EXIT_SUCCESS;
}
