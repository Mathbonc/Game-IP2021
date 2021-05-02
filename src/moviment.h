#ifndef MOVIMENT_H
#define MOVIMENT_H

#include <raylib.h>
#include <math.h>


#define numObjs 8

typedef struct{
    int life;
    int damage, hits;
    Vector2 position;
    Rectangle bound, atkbound;
    float speed;
} Player;

typedef struct{
    int life;
    int died;
    int damage;
    Vector2 position;
    Rectangle bound, atkbound;
    float speed;
    float dist;
} Enemies;

typedef struct{
    int life;
    Vector2 position;
    Rectangle bound;
    Texture2D texture;
} Student;

typedef struct{
    int lifeboost;
    Vector2 position;
    Rectangle bound;
} Itens;
//-----------------------------------------------------------------------------------------------------------------------------------

void generateEnemies(Enemies *guard, Enemies *storm);
void moveCharacter(Player *rbns, Texture2D background, Rectangle obst[], Texture2D rbnsTex[], int frame, int frameDie, char *last);
void resetCharacter(Player *rbns);
void attackCharacter(Enemies *guard, Enemies *storm, Player rbns, Texture2D rbnsTex[], Texture2D guardTex[], Texture2D stormTex[], char last, int frameAtk);
void moveEnemie(Enemies *guard, Enemies *storm, Player rbns, Rectangle obst[], Texture2D guardTex[], Texture2D stormTex[], int frame);
void resetEnemies(Enemies *guard, Enemies *storm, Player rbns);
void attackEnemie(Enemies *guard, Enemies *storm, Player *rbns, Texture2D guardTex[], Texture2D stormTex[], int frame);
void generateItens(Itens extras[], Player rbns);
void getItens(Player *rbns, Itens extras[], Texture2D itensTex);
void cameraUpdate(Camera2D *camera, Player rbns);
void studentPlace(Student lnidas, Student robrigo, Student mulittle, Student xanny, Student freddy, int frame);
void studentFight(Player *rbns);
int Game(Player *rbns, Enemies guard[], Enemies storm[], Itens extras[], Rectangle obst[], Texture2D rbnsTex[], Texture2D guardTex[], Texture2D stormTex[], Texture2D itensTex, Camera2D *camera, int *frame, char *last, float *timer, Texture2D background, int *text_cont, int *text_aux);
Player Setrbns();
Student Setlnidas(); 
Student Setrobrigo(); 
Student Setmulittle();
Student Setxanny (); 
Student Setfreddy();
Texture2D *LoadRubensTexture(); 
Texture2D *LoadGuardTex();
Texture2D *LoadStormTex();

#endif