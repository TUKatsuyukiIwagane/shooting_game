#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>

int main(int argc, char *argv[]){
    SDL_Surface *window;

    if (SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("SDL初期化失敗\n");
        exit(-1);
    }

    if ((window = SDL_SetVideoMode(320, 240, 32, SDL_SWSURFACE)) == NULL){
        printf("VideoMode初期化失敗\n");
        exit(-1);
    }
    SDL_WM_SetCaption("SDL Game", "Software Exp");
    // SDL_WM_SetIcon(SDL_LoadBMP("icon.bmp"), NULL);
    SDL_FillRect(window, NULL, SDL_MapRGB(window->format, 0, 0, 0));
    SDL_Flip(window);
    SDL_Delay(2000);

    SDL_Quit();
    return 0;
}