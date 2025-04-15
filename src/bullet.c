#include "bullet.h"

Bullet bullets[MAX_BULLETS];

void initBullets() {
    for (int i = 0; i < MAX_BULLETS; i++) {
        bullets[i].alive = 0;
    }
}

void shootBullet(int x, int y, SDL_PixelFormat *fmt) {
    for (int i = 0; i < MAX_BULLETS; i++) {
        if (!bullets[i].alive) {
            bullets[i].x = x;
            bullets[i].y = y;
            bullets[i].w = 4;
            bullets[i].h = 10;
            bullets[i].alive = 1;
            bullets[i].speed = 10;
            bullets[i].color = SDL_MapRGB(fmt, 255, 0, 0);
            break;
        }
    }
}

void updateBullets() {
    for (int i = 0; i < MAX_BULLETS; i++) {
        if (bullets[i].alive) {
            bullets[i].y -= bullets[i].speed;
            if (bullets[i].y + bullets[i].h < 0) {
                bullets[i].alive = 0;
            }
        }
    }
}

void drawBullets(SDL_Surface *window) {
    for (int i = 0; i < MAX_BULLETS; i++) {
        if (bullets[i].alive) {
            SDL_Rect rect = { bullets[i].x, bullets[i].y, bullets[i].w, bullets[i].h };
            SDL_FillRect(window, &rect, bullets[i].color);
        }
    }
}