#include <stdio.h>
#include <stdbool.h>
#include "SDL2\include\SDL2\SDL.h"

const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;

int main(int argc, char *argv[])
{
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER | SDL_INIT_JOYSTICK) < 0)
  {
    printf("Error initializing SDL: %s\n", SDL_GetError());
    return 1;
  }

  SDL_Window *window = SDL_CreateWindow("Gamepad Latency Test",
                                        SDL_WINDOWPOS_UNDEFINED,
                                        SDL_WINDOWPOS_UNDEFINED,
                                        WINDOW_WIDTH, WINDOW_HEIGHT,
                                        SDL_WINDOW_SHOWN);
  if (!window)
  {
    printf("Error creating window: %s\n", SDL_GetError());
    SDL_Quit();
    return 1;
  }

  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (!renderer)
  {
    printf("Error creating renderer: %s\n", SDL_GetError());
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 1;
  }

  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_RenderClear(renderer);
  SDL_RenderPresent(renderer);

  bool running = true;
  SDL_Event event;
  SDL_Joystick *joystick = NULL;

  if (SDL_NumJoysticks() > 0)
  {
    joystick = SDL_JoystickOpen(0);
    if (!joystick)
    {
      printf("Error opening joystick: %s\n", SDL_GetError());
    }
  }

  while (running)
  {
    while (SDL_PollEvent(&event))
    {
      if (event.type == SDL_QUIT)
      {
        running = false;
      }
      else if (event.type == SDL_JOYBUTTONDOWN || event.type == SDL_CONTROLLERBUTTONDOWN || event.type == SDL_KEYDOWN || event.type == SDL_MOUSEBUTTONDOWN)
      {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
      }
      else if (event.type == SDL_JOYBUTTONUP || event.type == SDL_CONTROLLERBUTTONDOWN || event.type == SDL_KEYUP || event.type == SDL_MOUSEBUTTONUP)
      {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
      }
    }
  }

  if (joystick)
  {
    SDL_JoystickClose(joystick);
  }
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
