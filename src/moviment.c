#include "moviment.h"
#include "raylib.h"
#include <math.h>

typedef struct{
    int life;
    int damage, hits;
    Vector2 position;
    Rectangle bound, atkbound;
    float speed;
} Player;

typedef struct{
    int life;
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
} Student;

typedef struct{
    int lifeboost;
    Vector2 position;
    Rectangle bound;
} Itens;

typedef struct{
    Texture2D texture;
    float frameWidth;
    int maxFrames;
}TexturePack;

void generateEnemies(Enemies *guard, Enemies *storm);
void moveCharacter(Player *rbns, Texture2D background, Rectangle obst[], Texture2D rbnsTexIdle, Texture2D rbnsTexRun, Texture2D rbnsTexDie, int frame, int frameDie, char *last);
void resetCharacter(Player *rbns);
void attackCharacter(Enemies *guard, Enemies *storm, Player rbns, Texture2D rbnsTexAtk, char last, int frameAtk);
void moveEnemie(Enemies *guard, Enemies *storm, Player rbns, Rectangle obst[], Texture2D guardTex, Texture2D stormTex, int frame);
void attackEnemie(Enemies *guard, Enemies *storm, Player *rbns, Texture2D guardTex, Texture2D stormTex);
void generateItens(Itens extras[]);
void getItens(Player *rbns, Itens extras[], Texture2D itensTex);
void cameraUpdate(Camera2D *camera, Player rbns);

void generateEnemies(Enemies *guard, Enemies *storm){
    int i;
    for(i=0; i<10; i++){
        guard[i].position = (Vector2){GetRandomValue(500, 1700), GetRandomValue(0, 350)};
        guard[i].speed = (GetRandomValue(5, 9) * 0.1);
        guard[i].life = 3;
        guard[i].damage = GetRandomValue(1, 1);
        guard[i].bound = (Rectangle){guard[i].position.x+7, guard[i].position.y-5, 30, 44};
        //guard[i].atkbound = (Rectangle){guard[i].position.x-60, guard[i].position.y, 128, 44};
    }
    
    for(i=0; i<5; i++){
        storm[i].position = (Vector2){GetRandomValue(500, 1700), GetRandomValue(0, 350)};
        storm[i].speed = (GetRandomValue(3, 5) * 0.1);
        storm[i].life = 7;
        storm[i].damage = GetRandomValue(3, 3);
        storm[i].bound = (Rectangle){guard[i].position.x+7, guard[i].position.y-5, 30, 44};
        //storm[i].atkbound = (Rectangle){guard[i].position.x+7, guard[i].position.y-5, 30, 44};
    }
}

void moveCharacter(Player *rbns, Texture2D background, Rectangle obst[], Texture2D rbnsTexIdle, Texture2D rbnsTexRun, Texture2D rbnsTexDie, int frame, int frameDie, char *last){
    int i;
    static int cont=0;
    float frameWidthIdle = (float)(rbnsTexIdle.width/6);
    int maxFramesIdle = (int)(rbnsTexIdle.width/(int)frameWidthIdle);
    float frameWidthRun = (float)(rbnsTexRun.width/8);
    int maxFramesRun = (int)(rbnsTexRun.width/(int)frameWidthRun);
    float frameWidthDie = (float)(rbnsTexDie.width/11);
    int maxFramesDie = (int)(rbnsTexDie.width/(int)frameWidthDie);
    
    if(rbns->life > 0 && !IsKeyDown(KEY_C)){
        // 2 segundo parametro o Rectangle é a linha que vai ser desenhada, e o 4 a quantidade de linhas
        if(IsKeyDown(KEY_D)){
            DrawTextureRec(rbnsTexRun, (Rectangle){frameWidthRun*frame, 0, frameWidthRun, (float)rbnsTexRun.height}, (Vector2){rbns->position.x, rbns->position.y}, RAYWHITE); 
            *last='d';
            }
        else if(IsKeyDown(KEY_A)){
            DrawTextureRec(rbnsTexRun, (Rectangle){frameWidthRun*frame, 0, -frameWidthRun, (float)rbnsTexRun.height}, (Vector2){rbns->position.x, rbns->position.y}, RAYWHITE); 
            *last='a';
            }
        else if(IsKeyDown(KEY_W) && *last=='a'){
            DrawTextureRec(rbnsTexRun, (Rectangle){frameWidthRun*frame, 0, -frameWidthRun, (float)rbnsTexRun.height}, (Vector2){rbns->position.x, rbns->position.y}, RAYWHITE); 
            *last='a';
            }
        else if(IsKeyDown(KEY_W) && !(*last=='a')){
            DrawTextureRec(rbnsTexRun, (Rectangle){frameWidthRun*frame, 0, frameWidthRun, (float)rbnsTexRun.height}, (Vector2){rbns->position.x, rbns->position.y}, RAYWHITE);
            *last='d';
            }
        else if(IsKeyDown(KEY_S) && *last=='a'){
            DrawTextureRec(rbnsTexRun, (Rectangle){frameWidthRun*frame, 0, -frameWidthRun, (float)rbnsTexRun.height}, (Vector2){rbns->position.x, rbns->position.y}, RAYWHITE);
            *last='a';
            }
        else if(IsKeyDown(KEY_S) && !(*last=='a')){
            DrawTextureRec(rbnsTexRun, (Rectangle){frameWidthRun*frame, 0, frameWidthRun, (float)rbnsTexRun.height}, (Vector2){rbns->position.x, rbns->position.y}, RAYWHITE); 
            *last='d';
        }
        else{ //DrawTextureRec(rbnsTexRun, (Rectangle){frameWidth*frame, 0, frameWidth, (float)rbnsTexRun.height}, (Vector2){rbns.position.x, rbns.position.y}, RAYWHITE);
            if(*last=='a') DrawTextureRec(rbnsTexIdle, (Rectangle){frameWidthIdle*frame, 0, -frameWidthIdle, (float)rbnsTexIdle.height}, (Vector2){rbns->position.x, rbns->position.y}, RAYWHITE);
            else DrawTextureRec(rbnsTexIdle, (Rectangle){frameWidthIdle*frame, 0, frameWidthIdle, (float)rbnsTexIdle.height}, (Vector2){rbns->position.x, rbns->position.y}, RAYWHITE);
        }
    }
    if(rbns->life<=0){
        DrawTextureRec(rbnsTexDie, (Rectangle){frameWidthDie*frameDie, 0, frameWidthDie, (float)rbnsTexDie.height}, (Vector2){rbns->position.x, rbns->position.y}, RAYWHITE);
        cont++;
        if(cont>70){
            resetCharacter(rbns);
            cont=0;
        }
    }
    
    if(rbns->life > 0){
        if(rbns->position.x < background.width && rbns->position.x > 0 && rbns->position.y < background.height-50 && rbns->position.y > -9){
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
        
        if (IsKeyDown(KEY_D))rbns->bound.x = rbns->position.x+12;
        if (IsKeyDown(KEY_A))rbns->bound.x = rbns->position.x+24;
        rbns->bound.y = rbns->position.y;
        if (IsKeyDown(KEY_D))rbns->atkbound.x = rbns->position.x+12;
        if (IsKeyDown(KEY_A))rbns->atkbound.x = rbns->position.x;
        rbns->atkbound.y = rbns->position.y;
        
        for(i=0; i<5; i++){
            if(CheckCollisionRecs(rbns->bound, obst[i])){
                if(rbns->position.x >= obst[i].x) rbns->position.x += 1.0f * rbns->speed; 
                if(rbns->position.x <= obst[i].x) rbns->position.x -= 1.0f * rbns->speed; 
                if(rbns->position.y >= obst[i].y) rbns->position.y += 1.0f * rbns->speed;
                if(rbns->position.y <= obst[i].y) rbns->position.y -= 1.0f * rbns->speed;
            }
        }
    }
}

void resetCharacter(Player *rbns){
    rbns->life = 20;
    rbns->position = (Vector2){300.0f, 175.0f};
}

void attackCharacter(Enemies *guard, Enemies *storm, Player rbns, Texture2D rbnsTexAtk, char last, int frameAtk){
    int i;
    float frameWidthAtk = (float)(rbnsTexAtk.width/12);
    int maxFramesAtk = (int)(rbnsTexAtk.width/(int)frameWidthAtk);
    
    if(IsKeyDown(KEY_C)){
        if(last=='d') DrawTextureRec(rbnsTexAtk, (Rectangle){frameWidthAtk*frameAtk, 0, frameWidthAtk, (float)rbnsTexAtk.height}, (Vector2){rbns.position.x, rbns.position.y}, RAYWHITE);
        if(last!='d') DrawTextureRec(rbnsTexAtk, (Rectangle){frameWidthAtk*frameAtk, 0, -frameWidthAtk, (float)rbnsTexAtk.height}, (Vector2){rbns.position.x, rbns.position.y}, RAYWHITE);
    }
    for(i=0; i<10; i++){
        if(IsKeyPressed(KEY_C) && CheckCollisionRecs(rbns.atkbound, guard[i].bound)){
            guard[i].life -= rbns.damage;
        }
    }
    for(i=0; i<5; i++){
        if(IsKeyPressed(KEY_C) && CheckCollisionRecs(rbns.atkbound, storm[i].bound)){
            storm[i].life -= rbns.damage;
        }
    }
}

void moveEnemie(Enemies *guard, Enemies *storm, Player rbns, Rectangle obst[], Texture2D guardTex, Texture2D stormTex, int frame){
    int i, j;
    float guardframeHeight = (float)(guardTex.height/39);
    int guardmaxFrames = (int)(guardTex.width/(int)guardframeHeight);
    float stormframeHeight = (float)(stormTex.height/10);
    int stormmaxFrames = (int)(stormTex.width/(int)stormframeHeight);
    
    for(i=0; i<10; i++){
        if(guard[i].life>0) DrawTextureRec(guardTex, (Rectangle){0, guardframeHeight*frame, guardframeHeight, (float)guardframeHeight*1}, (Vector2){guard[i].position.x, guard[i].position.y}, RAYWHITE);
    }
    for(i=0; i<5; i++){
        if(storm[i].life>0) DrawTextureRec(stormTex, (Rectangle){0, stormframeHeight*frame, stormframeHeight, (float)stormframeHeight*1}, (Vector2){storm[i].position.x, storm[i].position.y}, RAYWHITE);
    }
    //Movimento do Stormhead
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
        storm[i].bound.x = storm[i].position.x+30;
        storm[i].bound.y = storm[i].position.y+85;
    }
    for(i=0; i<3; i++){
        for(j=0; j<5; j++){
            if(CheckCollisionRecs(storm[i].bound, obst[i])){
                if(storm[j].position.x+30 >= obst[i].x) storm[j].position.x += 1.0f * storm[j].speed; 
                if(storm[j].position.x+30 <= obst[i].x) storm[j].position.x -= 1.0f * storm[j].speed; 
                if(storm[j].position.y+85 >= obst[i].y) storm[j].position.y += 1.0f * storm[j].speed;
                if(storm[j].position.y+85 <= obst[i].y) storm[j].position.y -= 1.0f * storm[j].speed;
            }
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
        guard[i].bound.x = guard[i].position.x+7;
        guard[i].bound.y = guard[i].position.y-5;
        guard[i].atkbound.x = guard[i].position.x+7;
        guard[i].atkbound.y = guard[i].position.y-5;
    }
    for(i=0; i<3; i++){
        for(j=0; j<10; j++){
            if(CheckCollisionRecs(guard[j].bound, obst[i])){
                if(guard[j].position.x+7 >= obst[i].x) guard[j].position.x += 1.0f * guard[j].speed; 
                if(guard[j].position.x+7 <= obst[i].x) guard[j].position.x -= 1.0f * guard[j].speed; 
                if(guard[j].position.y-5 >= obst[i].y) guard[j].position.y += 1.0f * guard[j].speed;
                if(guard[j].position.y-5 <= obst[i].y) guard[j].position.y -= 1.0f * guard[j].speed;
            }
        }
    }
}

void attackEnemie(Enemies *guard, Enemies *storm, Player *rbns, Texture2D guardTex, Texture2D stormTex){
    int i;
    for(i=0; i<5; i++){
        if(storm[i].life>0){
            storm[i].dist = sqrt(pow((storm[i].position.x-rbns->position.x),2) + pow((storm[i].position.y-rbns->position.y),2));
            if(storm[i].dist < 31){
                if(GetRandomValue(1, 5)==1){
                    rbns->life -= storm[i].damage;
                }
            }
        }
    }
    for(i=0; i<10; i++){
        if(guard[i].life>0){
            guard[i].dist = sqrt(pow((guard[i].position.x-rbns->position.x),2) + pow((guard[i].position.y-rbns->position.y),2));
            if(guard[i].dist < 31){
                if(GetRandomValue(1, 5)==1){
                    rbns->life -= guard[i].damage;
                }
            }
        }
    }
}

void generateItens(Itens extras[]){
    int i;
    for(i=0; i<5; i++){
        extras[i].lifeboost = GetRandomValue(5, 10);
        extras[i].position = (Vector2){GetRandomValue(500, 1700), GetRandomValue(0, 350)};
        extras[i].bound = (Rectangle){extras[i].position.x, extras[i].position.y, 10, 10};
    }
}

void getItens(Player *rbns, Itens extras[], Texture2D itensTex){
    int i;
    for(i=0; i<5; i++){
        if(CheckCollisionRecs(rbns->bound, extras[i].bound)){
            rbns->life += extras[i].lifeboost;
            extras[i].lifeboost = 0;
        }
    }
    for(i=0; i<5; i++) if(extras[i].lifeboost > 0) DrawTextureEx(itensTex, (Vector2){extras[i].position.x, extras[i].position.y}, 0.0f, 0.50f, RAYWHITE); 
}

void cameraUpdate(Camera2D *camera, Player rbns){
    //Atualizando os parametros da camera
    camera->target = (Vector2){rbns.position.x + 20, rbns.position.y + 20};
    camera->zoom += ((float)GetMouseWheelMove()*0.05f);
    //Limitando o zoom da camera
    if (camera->zoom > 3.0f) camera->zoom = 3.0f;
    else if (camera->zoom < 2.0f) camera->zoom = 2.0f;
    //Limitando o deslocamento da camera
    if(camera->target.x<320) camera->target.x = 320;
    //if(camera->target.x>1510) camera->target.x = 1510;
    if(camera->target.y<180) camera->target.y = 180;
    if(camera->target.y>270) camera->target.y = 270;
}

