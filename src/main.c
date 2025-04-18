#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include "player.h"
#include "bullet.h"
#include "enemy.h"
#include "enemy_bullet.h"


int main(int argc, char *argv[]){
    SDL_Surface *window;
    SDL_Event event;
    int running = 1;
    int shootCooldown = 0;

    // 初期化処理
    if (SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("SDL初期化失敗\n");
        exit(-1);
    }

    if ((window = SDL_SetVideoMode(1080, 720, 32, SDL_SWSURFACE)) == NULL){
        printf("VideoMode初期化失敗\n");
        exit(-1);
    }
    Player player;
    initPlayer(&player, window);
    initBullets();
    initEnemies(window->format);
    initEnemyBullets(window->format);

    // ゲームループ
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

        // 画面の更新
        SDL_FillRect(window, NULL, SDL_MapRGB(window->format, 0, 0, 0));
        drawPlayer(window, &player);
        updateEnemies(window->format);
        updateBullets();
        updateEnemyBullets();
        drawBullets(window);
        drawEnemies(window);
        drawEnemyBullets(window);
        checkBulletEnemyCollision();
        SDL_Flip(window);
        SDL_Delay(16);
    }



    SDL_Quit();
    return 0;
}