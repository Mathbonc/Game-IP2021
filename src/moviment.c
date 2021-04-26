#include "moviment.h"
#include "raylib.h"
#include <math.h>

void generateEnemies(Enemies *guard, Enemies *storm);
void moveCharacter(Player *rbns, Texture2D background, Rectangle obst[]);
void moveEnemie(Enemies *guard, Enemies *storm, Player rbns);

void generateEnemies(Enemies *guard, Enemies *storm){
    int i;
    for(i=0; i<10; i++){
        guard[i].position = (Vector2){GetRandomValue(500, 1700), GetRandomValue(0, 350)};
        guard[i].speed = (GetRandomValue(5, 9) * 0.1);
        guard[i].life = 3;
    }
    
    for(i=0; i<5; i++){
        storm[i].position = (Vector2){GetRandomValue(500, 1700), GetRandomValue(0, 350)};
        storm[i].speed = (GetRandomValue(3, 5) * 0.1);
        storm[i].life = 7;
    }
}

void moveCharacter(Player *rbns, Texture2D background, Rectangle obst[]){
    int i;
    if(rbns->position.x < background.width && rbns->position.x > 0 && rbns->position.y < background.height-50 && rbns->position.y > 0){
        if (IsKeyDown(KEY_D)) rbns->position.x += 1.0f * rbns->speed; 
        if (IsKeyDown(KEY_A)) rbns->position.x -= 1.0f * rbns->speed; 
        if (IsKeyDown(KEY_W)) rbns->position.y -= 1.0f * rbns->speed; 
        if (IsKeyDown(KEY_S)) rbns->position.y += 1.0f * rbns->speed; 
    }
    else{
        if(rbns->position.x >= background.width-70) rbns->position.x -= 1.0f * rbns->speed; 
        if(rbns->position.x <= 0) rbns->position.x += 1.0f * rbns->speed; 
        if(rbns->position.y >= background.height-50) rbns->position.y -= 1.0f * rbns->speed;
        if(rbns->position.y <= 0) rbns->position.y += 1.0f * rbns->speed; 
    }
    rbns->bound.x = rbns->position.x+12;
    rbns->bound.y = rbns->position.y;
    for(i=0; i<3; i++){
        if(CheckCollisionRecs(rbns->bound, obst[i])){
            if(rbns->position.x >= obst[i].x) rbns->position.x += 1.0f * rbns->speed; 
            if(rbns->position.x <= obst[i].x) rbns->position.x -= 1.0f * rbns->speed; 
            if(rbns->position.y >= obst[i].y) rbns->position.y += 1.0f * rbns->speed;
            if(rbns->position.y <= obst[i].y) rbns->position.y -= 1.0f * rbns->speed;
        }
    }
}

void moveEnemie(Enemies *guard, Enemies *storm, Player rbns){
    int i;
    for(i=0; i<5; i++){
        storm[i].dist = sqrt(pow((storm[i].position.x-rbns.position.x),2) + pow((storm[i].position.y-rbns.position.y),2));
        if(storm[i].dist > 31){ //Atacam de perto, para se apoximarem mais
            if(storm[i].position.x+25 > rbns.position.x) storm[i].position.x -= 1.0f * storm[i].speed;
            if(storm[i].position.x+25 < rbns.position.x) storm[i].position.x += 1.0f * storm[i].speed;
            if(storm[i].position.y+83 > rbns.position.y) storm[i].position.y -= 1.0f * storm[i].speed;
            if(storm[i].position.y+83 < rbns.position.y) storm[i].position.y += 1.0f * storm[i].speed;
        }
        else if(storm[i].dist < 29){
            if(storm[i].position.x > rbns.position.x) storm[i].position.x += 1.0f * storm[i].speed;
            if(storm[i].position.x < rbns.position.x) storm[i].position.x -= 1.0f * storm[i].speed;
            if(storm[i].position.y > rbns.position.y) storm[i].position.y += 1.0f * storm[i].speed;
            if(storm[i].position.y < rbns.position.y) storm[i].position.y -= 1.0f * storm[i].speed;
        }
    }
    
    //Movimento do Guardian
    for(i=0; i<10; i++){
        guard[i].dist = sqrt(pow((guard[i].position.x-rbns.position.x),2) + pow((guard[i].position.y-rbns.position.y),2));
        if(guard[i].dist > 71){ //Atacam de longe, para nenhum se apoximar demais
            if(guard[i].position.x > rbns.position.x) guard[i].position.x -= 1.0f * guard[i].speed;
            if(guard[i].position.x < rbns.position.x) guard[i].position.x += 1.0f * guard[i].speed;
            if(guard[i].position.y > rbns.position.y) guard[i].position.y -= 1.0f * guard[i].speed;
            if(guard[i].position.y < rbns.position.y) guard[i].position.y += 1.0f * guard[i].speed;
        }
        else if(guard[i].dist < 69){
            if(guard[i].position.x > rbns.position.x) guard[i].position.x += 1.0f * guard[i].speed;
            if(guard[i].position.x < rbns.position.x) guard[i].position.x -= 1.0f * guard[i].speed;
            if(guard[i].position.y > rbns.position.y) guard[i].position.y += 1.0f * guard[i].speed;
            if(guard[i].position.y < rbns.position.y) guard[i].position.y -= 1.0f * guard[i].speed;
        }
    }
}
