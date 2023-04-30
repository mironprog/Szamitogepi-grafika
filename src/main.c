#include <stdio.h>
#include <SDL.h>

int main (int argc, char* argv[])
{
    SDL_Window* window = NULL;

    //inicializáljuk az SDL-t
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("Nem sikerült az SDL inicializálása: %s\n", SDL_GetError());
        return 1;
    }

    //hozzuk létre egy ablakot
    window = SDL_CreateWindow("Hello world!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        printf("Nem sikerült az ablak létrehozása: %s\n", SDL_GetError());
        return 1;
    }

    //várjunk, amíg az ablak bezáródik
    SDL_Event e;
    while (1)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                SDL_DestroyWindow(window);
                SDL_Quit();
                return 0;
            }
        }
    }

    return 0;
}