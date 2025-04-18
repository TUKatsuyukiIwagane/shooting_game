#ifndef BULLET_H
#define BULLET_H

#include <SDL/SDL.h>
#define MAX_BULLETS 100

typedef struct {
    int x, y;
    int w, h;
    int alive;
    int speed;
    Uint32 color;
} Bullet;

extern Bullet bullets[MAX_BULLETS];

void initBullets();
void shootBullet(int x, int y, SDL_PixelFormat *fmt);
void updateBullets();
void drawBullets(SDL_Surface *window);
#endif