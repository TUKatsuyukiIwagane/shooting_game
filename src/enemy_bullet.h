#ifndef ENEMY_BULLET_C
#define ENEMY_BULLET_C
#include <SDL/SDL.h>
#define MAX_EBULLETS 100

typedef struct {
    int x, y;
    int w, h;
    int alive;
    int speed;
    Uint32 color;
} EnemyBullet;

extern EnemyBullet enemyBullets[MAX_EBULLETS];

void initEnemyBullets(SDL_PixelFormat *fmt);
void shootEnemyBullet(int x, int y, SDL_PixelFormat *fmt);
void updateEnemyBullets();
void drawEnemyBullets(SDL_Surface *window);

#endif