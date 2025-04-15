#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>

typedef struct {
    int x, y, w, h;
    Uint32 color;
} Player;

void drawPlayer(SDL_Surface *window, Player *player){
    SDL_Rect rect = {player->x, player->y, player->w, player->h};
    SDL_FillRect(window, &rect, player->color);
}

int main(int argc, char *argv[]){
    SDL_Surface *window;
    SDL_Event event;
    int running = 1;

    if (SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("SDL初期化失敗\n");
        exit(-1);
    }

    if ((window = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE)) == NULL){
        printf("VideoMode初期化失敗\n");
        exit(-1);
    }
    Player player = {300, 400, 32, 32, SDL_MapRGB(window->format, 255, 255, 255)};
    
    while (running){
        while(SDL_PollEvent(&event)){
            if (event.type == SDL_QUIT){
                running = 0;
            }
            if (event.type == SDL_KEYDOWN){
                switch (event.key.keysym.sym) {
                case SDLK_ESCAPE:
                    running = 0;
                    break;
                }
            }
        }
        Uint8 *keystate = SDL_GetKeyState(NULL);
        if (keystate[SDLK_a]){
            player.x -= 5;
        }
        if (keystate[SDLK_d]){
            player.x += 5;
        }
        if (keystate[SDLK_w]){
            player.y -= 5;
        }
        if (keystate[SDLK_s]){
            player.y += 5;
        }
        
        SDL_WM_SetCaption("SDL Game", "Software Exp");
        // SDL_WM_SetIcon(SDL_LoadBMP("icon.bmp"), NULL);
        SDL_FillRect(window, NULL, SDL_MapRGB(window->format, 0, 0, 0));
        drawPlayer(window, &player);
        SDL_Flip(window);
        SDL_Delay(16);
    }



    SDL_Quit();
    return 0;
}