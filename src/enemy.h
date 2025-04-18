#ifndef ENEMY_H
#define ENEMY_H
#include <SDL/SDL.h>

#define MAX_ENEMIES 10

typedef struct {
    int x, y;
    int w, h;
    int alive;
    int speed;
    int hitpoints;
    Uint32 color;
} Enemy;

extern Enemy enemies[MAX_ENEMIES];
void initEnemies(SDL_PixelFormat *fmt);
void updateEnemies(SDL_PixelFormat *fmt);
void drawEnemies(SDL_Surface *window);
int checkCollision(int ax, int ay, int aw, int ah, int bx, int by, int bw, int bh);
void checkBulletEnemyCollision();

#endif