#include "enemy.h"
#include "bullet.h"
#include <SDL/SDL.h>

Enemy enemies[MAX_ENEMIES];

void initEnemies(SDL_PixelFormat *fmt) {
    for (int i = 0; i < MAX_ENEMIES; i++) {
        enemies[i].x = rand() % 600;
        enemies[i].y = rand() % 200;
        enemies[i].w = 32;
        enemies[i].h = 32;
        enemies[i].alive = 1;
        enemies[i].speed = 1 + rand() % 2;
        enemies[i].color = SDL_MapRGB(fmt, 0, 255, 0);
    }
}

void updateEnemies() {
    for (int i = 0; i < MAX_ENEMIES; i++) {
        if (enemies[i].alive) {
            enemies[i].y += enemies[i].speed;
            if (enemies[i].y > 480) {
                enemies[i].y = -32;
                enemies[i].x = rand() % 600;
            }
        }
    }
}

void drawEnemies(SDL_Surface *window) {
    for (int i = 0; i < MAX_ENEMIES; i++) {
        if (enemies[i].alive) {
            SDL_Rect rect = { enemies[i].x, enemies[i].y, enemies[i].w, enemies[i].h };
            SDL_FillRect(window, &rect, enemies[i].color);
        }
    }
}

int checkCollision(int ax, int ay, int aw, int ah, int bx, int by, int bw, int bh) {
    return (ax < bx + bw) && (bx < ax + aw) && (ay < by + bh) && (by < ay + ah);
}

void checkBulletEnemyCollision() {
    for (int i = 0; i < MAX_BULLETS; i++) {
        if (bullets[i].alive) {
            for (int j = 0; j < MAX_ENEMIES; j++) {
                if (enemies[j].alive && checkCollision(bullets[i].x, bullets[i].y, bullets[i].w, bullets[i].h,
                                                        enemies[j].x, enemies[j].y, enemies[j].w, enemies[j].h)) {
                    bullets[i].alive = 0;
                    enemies[j].alive = 0;
                    break;
                }
            }
        }
    }
}