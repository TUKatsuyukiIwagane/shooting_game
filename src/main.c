#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include "player.h"
#include "bullet.h"


int main(int argc, char *argv[]){
    SDL_Surface *window;
    SDL_Event event;
    int running = 1;
    int shootCooldown = 0;

    if (SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("SDL初期化失敗\n");
        exit(-1);
    }

    if ((window = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE)) == NULL){
        printf("VideoMode初期化失敗\n");
        exit(-1);
    }
    Player player;
    initPlayer(&player, window);
    initBullets();

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
        updatePlayer(&player, keystate);
        if (keystate[SDLK_SPACE] && shootCooldown == 0) {
            shootBullet(player.x + player.w / 2 - 2, player.y, window->format);
            shootCooldown = 10; // クールダウン設定
        }
        if (shootCooldown > 0) shootCooldown--;
        
        SDL_WM_SetCaption("SDL Game", "Software Exp");
        // SDL_WM_SetIcon(SDL_LoadBMP("icon.bmp"), NULL);
        SDL_FillRect(window, NULL, SDL_MapRGB(window->format, 0, 0, 0));
        drawPlayer(window, &player);
        updateBullets();
        drawBullets(window);
        SDL_Flip(window);
        SDL_Delay(16);
    }



    SDL_Quit();
    return 0;
}