#include "enemy_bullet.h"

EnemyBullet enemyBullets[MAX_EBULLETS];

void initEnemyBullets(SDL_PixelFormat *fmt) {
    for (int i = 0; i < MAX_EBULLETS; i++) {
        enemyBullets[i].alive = 0;
    }
}

void shootEnemyBullet(int x, int y, SDL_PixelFormat *fmt) {
    for (int i = 0; i < MAX_EBULLETS; i++) {
        if (!enemyBullets[i].alive) {
            enemyBullets[i].x = x;
            enemyBullets[i].y = y;
            enemyBullets[i].w = 8;
            enemyBullets[i].h = 8;
            enemyBullets[i].alive = 1;
            enemyBullets[i].speed = 5;
            enemyBullets[i].color = SDL_MapRGB(fmt, 255, 255, 0);
            break;
        }
    }
}

void updateEnemyBullets() {
    for (int i = 0; i < MAX_EBULLETS; i++) {
        if (enemyBullets[i].alive) {
            enemyBullets[i].y += enemyBullets[i].speed;
            if (enemyBullets[i].y > 720) {
                enemyBullets[i].alive = 0;
            }
        }
    }
}

void drawEnemyBullets(SDL_Surface *window) {
    for (int i = 0; i < MAX_EBULLETS; i++) {
        if (enemyBullets[i].alive) {
            SDL_Rect rect = { enemyBullets[i].x, enemyBullets[i].y, enemyBullets[i].w, enemyBullets[i].h };
            SDL_FillRect(window, &rect, enemyBullets[i].color);
        }
    }
}