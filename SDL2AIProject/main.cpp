#include <iostream>
#define SDL_MAIN_HANDLED
#include <queue>
#include <vector>

#include "CActor.h"
#include "CAIController.h"
#include "CCharacter.h"
#include "CTarget.h"
#include "SDL2/SDL.h"

using namespace std;

#define TICK_INTERVAL 16

int main(int argc, char* argv[])
{
    std::vector<CActor*> actors;
    std::vector<CTarget*> targets;

    CAIController* AIController = new CAIController();

    CCharacter* InitialCharacter = new CCharacter();
    actors.push_back(InitialCharacter);
    AIController->SetControlledCharacter(InitialCharacter);

    for(int i = 0; i < 20; i++)
    {targets.push_back(new CTarget());}

    if (SDL_Init(SDL_INIT_VIDEO) == 0) {
        SDL_Window* window = NULL;
        SDL_Renderer* renderer = NULL;

        if (SDL_CreateWindowAndRenderer(640, 480, 0, &window, &renderer) == 0) {
            SDL_bool done = SDL_FALSE;

            int PrevTick = 0;

            while (!done)
            {
                SDL_Event event;

                int CurrentTick = SDL_GetTicks();
                int Delta = CurrentTick - PrevTick;
                if (Delta < TICK_INTERVAL)
                {
                    int WaitTicks = TICK_INTERVAL - Delta;
                    SDL_Delay(WaitTicks);
                }
                int DeleteAfterWait = SDL_GetTicks() - PrevTick;
                PrevTick = CurrentTick;
                float DeltaTime = 0.001f * (float)DeleteAfterWait;

                SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
                SDL_RenderClear(renderer);

                SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);


                InitialCharacter->Update(DeltaTime);
                AIController->Update(DeltaTime, targets);

                for (std::vector<CTarget*>::iterator ItTargets = targets.begin(); ItTargets != targets.end();)
                    {
                        if(InitialCharacter->GetPickUpCollider().IsColliding((*ItTargets)->GetPickUpCollider()))
                        {
                            delete (*ItTargets);
                            ItTargets = targets.erase(ItTargets);
                        }

                        else ItTargets++;
                    }

                for (std::vector<CActor*>::iterator it = actors.begin(); it != actors.end(); it++)
                {
                    (*it)->Render(*renderer);
                }

                for (std:: vector<CTarget*>::iterator it = targets.begin(); it != targets.end(); it++)
                {
                    (*it)->Render(*renderer);
                }


                SDL_RenderPresent(renderer);

                while (SDL_PollEvent(&event))
                {
                    if (event.type == SDL_QUIT)
                    {
                        done = SDL_TRUE;
                    }
                }
            }
        }

        if (renderer)
        {
            SDL_DestroyRenderer(renderer);
        }

        if (window)
        {
            SDL_DestroyWindow(window);
        }
    }
    SDL_Quit();
    return 0;
}