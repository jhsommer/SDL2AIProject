#include <iostream>
#define SDL_MAIN_HANDLED
#include <vector>

#include "CActor.h"
#include "CCharacter.h"
#include "CTarget.h"
#include "SDL2/SDL.h"
using namespace std;
int main(int argc, char* argv[])
{
    std::vector<CActor*> actors;

    CCharacter* InitialCharacter = new CCharacter();
    actors.push_back(InitialCharacter);

    CTarget* TestTarget = new CTarget();
    actors.push_back(TestTarget);

    if (SDL_Init(SDL_INIT_VIDEO) == 0) {
        SDL_Window* window = NULL;
        SDL_Renderer* renderer = NULL;
        if (SDL_CreateWindowAndRenderer(640, 480, 0, &window, &renderer) == 0) {
            SDL_bool done = SDL_FALSE;
            while (!done) {
                SDL_Event event;
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
                SDL_RenderClear(renderer);
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

                for (std::vector<CActor*>::iterator it = actors.begin(); it != actors.end(); it++) {
                    (*it)->Render(*renderer);
                }



                SDL_RenderPresent(renderer);
                while (SDL_PollEvent(&event)) {
                    if (event.type == SDL_QUIT) {
                        done = SDL_TRUE;
                    }
                }
            }
        }
        if (renderer) {
            SDL_DestroyRenderer(renderer);
        }
        if (window) {
            SDL_DestroyWindow(window);
        }
    }
    SDL_Quit();
    return 0;
}