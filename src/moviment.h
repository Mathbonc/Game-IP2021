#ifndef MOVIMENT_H
#define MOVIMENT_H

#include "raylib.h"

typedef struct{
    int life;
    Vector2 position;
    float speed;
} Player;

typedef struct{
    int life;
    Vector2 position;
    float speed;
    float dist;
} Enemies;

void generateEnemies(Enemies *guard, Enemies *storm);

void moveCharacter(Player *rbns, Texture2D background);

void moveEnemie(Enemies *guard, Enemies *storm, Player rbns);

#endif