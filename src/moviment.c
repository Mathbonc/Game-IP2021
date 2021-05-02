#include "moviment.h"
#include "raylib.h"
#include <math.h>

//-----------------------------------------------------------------------------------------------------------------------------------

void generateEnemies(Enemies *guard, Enemies *storm){
    int i;
    for(i=0; i<10; i++){
        guard[i].position = (Vector2){GetRandomValue(500, 1700), GetRandomValue(0, 350)};
        guard[i].speed = (GetRandomValue(3, 5) * 0.1f);
        guard[i].life = 20;
        guard[i].died = 0;
        guard[i].damage = GetRandomValue(1, 3);
        guard[i].bound = (Rectangle){guard[i].position.x+7, guard[i].position.y-5, 30, 44};
        guard[i].atkbound = (Rectangle){guard[i].position.x-60, guard[i].position.y, 170, 44};
    }
    
    for(i=0; i<5; i++){
        storm[i].position = (Vector2){GetRandomValue(500, 1700), GetRandomValue(0, 350)};
        storm[i].speed = (GetRandomValue(3, 5) * 0.1f);
        storm[i].life = 40;
        storm[i].died = 0;
        storm[i].damage = GetRandomValue(3, 5);
        storm[i].bound = (Rectangle){guard[i].position.x+7, guard[i].position.y-5, 30, 44};
        storm[i].atkbound = (Rectangle){guard[i].position.x+7, guard[i].position.y-5, 100, 44};
    }
}
//-----------------------------------------------------------------------------------------------------------------------------------

void moveCharacter(Player *rbns, Texture2D background, Rectangle obst[], Texture2D rbnsTex[], int frame, int frameDie, char *last){
    int i;
    static int cont=0;
    
    Texture2D rbnsTexIdle = rbnsTex[0];
    Texture2D rbnsTexRun = rbnsTex[1];
    Texture2D rbnsTexDie = rbnsTex[2];
    
    float frameWidthIdle = (float)(rbnsTexIdle.width/6);
    int maxFramesIdle = (int)(rbnsTexIdle.width/(int)frameWidthIdle);
    float frameWidthRun = (float)(rbnsTexRun.width/8);
    int maxFramesRun = (int)(rbnsTexRun.width/(int)frameWidthRun);
    float frameWidthDie = (float)(rbnsTexDie.width/11);
    int maxFramesDie = (int)(rbnsTexDie.width/(int)frameWidthDie);
    
    if(rbns->life > 0){
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
            if(rbns->position.x > 12300) rbns->position.x = 12300; 
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
        
        for(i=0; i<8; i++){
            if(CheckCollisionRecs(rbns->bound, obst[i])){
                if(rbns->position.x >= obst[i].x) rbns->position.x += 1.0f * rbns->speed; 
                if(rbns->position.x <= obst[i].x) rbns->position.x -= 1.0f * rbns->speed; 
                if(rbns->position.y >= obst[i].y) rbns->position.y += 1.0f * rbns->speed;
                if(rbns->position.y <= obst[i].y) rbns->position.y -= 1.0f * rbns->speed;
            }
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------------------------

void resetCharacter(Player *rbns){
    rbns->life = 200;
    if(rbns->position.x <= 1830) rbns->position = (Vector2){300.0f, 175.0f};
    if(rbns->position.x > 1830 && rbns->position.x <= 4370) rbns->position = (Vector2){2700.0f, 175.0f};
    if(rbns->position.x > 4370 && rbns->position.x <= 7030) rbns->position = (Vector2){5600.0f, 175.0f};
    if(rbns->position.x > 7030 && rbns->position.x <= 9730) rbns->position = (Vector2){8200.0f, 175.0f};
    if(rbns->position.x > 9730) rbns->position = (Vector2){10900.0f, 175.0f};
}
//-----------------------------------------------------------------------------------------------------------------------------------

void attackCharacter(Enemies *guard, Enemies *storm, Player rbns, Texture2D rbnsTex[], Texture2D guardTex[], Texture2D stormTex[], char last, int frameAtk){
    int i;
    Texture2D rbnsTexAtk = rbnsTex[3];
    Texture2D rbnsTexAtk2 = rbnsTex[4];
    
    Texture2D guardTexHit = guardTex[3];
    Texture2D stormTexHit = stormTex[3];
    
    float frameWidthAtk = (float)(rbnsTexAtk.width/3);
    int maxFramesAtk = (int)(rbnsTexAtk.width/(int)frameWidthAtk);
    float frameWidthAtk2 = (float)(rbnsTexAtk2.width/3);
    int maxFramesAtk2 = (int)(rbnsTexAtk2.width/(int)frameWidthAtk2);
    
    float guardframeHeightHit = (float)(guardTexHit.height/3);
    int guardmaxFramesHit = (int)(guardTexHit.width/(int)guardframeHeightHit);
    float stormframeHeightHit = (float)(stormTexHit.height/2);
    int stormmaxFramesHit = (int)(stormTexHit.width/(int)stormframeHeightHit);
    
    if(IsKeyDown(KEY_K)){
        if(last=='d') DrawTextureRec(rbnsTexAtk, (Rectangle){frameWidthAtk*frameAtk, 0, frameWidthAtk, (float)rbnsTexAtk.height}, (Vector2){rbns.position.x, rbns.position.y}, RAYWHITE);
        if(last!='d') DrawTextureRec(rbnsTexAtk, (Rectangle){frameWidthAtk*frameAtk, 0, -frameWidthAtk, (float)rbnsTexAtk.height}, (Vector2){rbns.position.x, rbns.position.y}, RAYWHITE);
    }
    if(IsKeyDown(KEY_L)){
        if(last=='d') DrawTextureRec(rbnsTexAtk2, (Rectangle){frameWidthAtk2*frameAtk, 0, frameWidthAtk2, (float)rbnsTexAtk2.height}, (Vector2){rbns.position.x, rbns.position.y}, RAYWHITE);
        if(last!='d') DrawTextureRec(rbnsTexAtk2, (Rectangle){frameWidthAtk2*frameAtk, 0, -frameWidthAtk2, (float)rbnsTexAtk2.height}, (Vector2){rbns.position.x, rbns.position.y}, RAYWHITE);
    }
    for(i=0; i<10; i++){
        if((IsKeyPressed(KEY_K) || IsKeyPressed(KEY_L)) && CheckCollisionRecs(rbns.atkbound, guard[i].bound)){
            DrawTextureRec(guardTexHit, (Rectangle){0, guardframeHeightHit*frameAtk, guardframeHeightHit, (float)guardframeHeightHit*1}, (Vector2){guard[i].position.x, guard[i].position.y}, RAYWHITE);
            guard[i].life -= rbns.damage;
        }
    }
    for(i=0; i<5; i++){
        if((IsKeyPressed(KEY_K) || IsKeyPressed(KEY_L)) && CheckCollisionRecs(rbns.atkbound, storm[i].bound)){
            DrawTextureRec(stormTexHit, (Rectangle){0, stormframeHeightHit*frameAtk, stormframeHeightHit, (float)stormframeHeightHit*1}, (Vector2){storm[i].position.x, storm[i].position.y}, RAYWHITE);
            storm[i].life -= rbns.damage;
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------------------------

void moveEnemie(Enemies *guard, Enemies *storm, Player rbns, Rectangle obst[], Texture2D guardTex[], Texture2D stormTex[], int frame){
    int i, j, cont=0;
    
    Texture2D guardTexMove = guardTex[0];
    Texture2D guardTexDie = guardTex[1];
    Texture2D stormTexMove = stormTex[0];
    Texture2D stormTexDie = stormTex[1];
    
    float guardframeHeightMove = (float)(guardTexMove.height/12);
    int guardmaxFramesMove = (int)(guardTexMove.width/(int)guardframeHeightMove);
    float guardframeHeightDie = (float)(guardTexDie.height/10);
    int guardmaxFramesDie = (int)(guardTexDie.width/(int)guardframeHeightDie);
    
    float stormframeHeightMove = (float)(stormTexMove.height/10);
    int stormmaxFramesMove = (int)(stormTexMove.width/(int)stormframeHeightMove);
    float stormframeHeightDie = (float)(stormTexDie.height/9);
    int stormmaxFramesDie = (int)(stormTexDie.width/(int)stormframeHeightDie);
    
    for(i=0; i<10; i++){
        if(guard[i].life>0) DrawTextureRec(guardTexMove, (Rectangle){0, guardframeHeightMove*frame, guardframeHeightMove, (float)guardframeHeightMove*1}, (Vector2){guard[i].position.x, guard[i].position.y}, RAYWHITE);
    }
    for(i=0; i<5; i++){
        if(storm[i].life>0) DrawTextureRec(stormTexMove, (Rectangle){0, stormframeHeightMove*frame, stormframeHeightMove, (float)stormframeHeightMove*1}, (Vector2){storm[i].position.x, storm[i].position.y}, RAYWHITE);
    }
    
    for(i=0; i<10; i++){
        if(guard[i].life<=0 && guard[i].died<11){
            DrawTextureRec(guardTexDie, (Rectangle){0, guardframeHeightDie*frame, guardframeHeightDie, (float)guardframeHeightDie*1}, (Vector2){guard[i].position.x, guard[i].position.y}, RAYWHITE);
            guard[i].died ++;
        }
    }
    for(i=0; i<5; i++){
        if(storm[i].life<=0 && storm[i].died<10){
            DrawTextureRec(stormTexDie, (Rectangle){0, stormframeHeightDie*frame, stormframeHeightDie, (float)stormframeHeightDie*1}, (Vector2){storm[i].position.x, storm[i].position.y}, RAYWHITE);
            storm[i].died ++;
        }
    }
    
    //Movimento do Guardian
    for(i=0; i<10; i++){
        if(guard[i].life > 0 && CheckCollisionRecs(guard[i].atkbound, rbns.bound)==0){
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
            guard[i].atkbound.x = guard[i].position.x-60;
            guard[i].atkbound.y = guard[i].position.y;
        }
    }
    for(i=0; i<8; i++){
        for(j=0; j<10; j++){
            if(CheckCollisionRecs(guard[j].bound, obst[i])){
                if(guard[j].position.x+7 >= obst[i].x) guard[j].position.x += 1.0f * guard[j].speed; 
                if(guard[j].position.x+7 <= obst[i].x) guard[j].position.x -= 1.0f * guard[j].speed; 
                if(guard[j].position.y-5 >= obst[i].y) guard[j].position.y += 1.0f * guard[j].speed;
                if(guard[j].position.y-5 <= obst[i].y) guard[j].position.y -= 1.0f * guard[j].speed;
            }
        }
    }
    
    //Movimento do Stormhead
    for(i=0; i<5; i++){
        if(storm[i].life > 0 && CheckCollisionRecs(storm[i].atkbound, rbns.bound)==0){
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
            storm[i].atkbound.x = storm[i].position.x+5;
            storm[i].atkbound.y = storm[i].position.y+85;
        }
    }
    for(i=0; i<8; i++){
        for(j=0; j<5; j++){
            if(CheckCollisionRecs(storm[i].bound, obst[i])){
                if(storm[j].position.x+30 >= obst[i].x) storm[j].position.x += 1.0f * storm[j].speed; 
                if(storm[j].position.x+30 <= obst[i].x) storm[j].position.x -= 1.0f * storm[j].speed; 
                if(storm[j].position.y+85 >= obst[i].y) storm[j].position.y += 1.0f * storm[j].speed;
                if(storm[j].position.y+85 <= obst[i].y) storm[j].position.y -= 1.0f * storm[j].speed;
            }
        }
    }
    
}
//-----------------------------------------------------------------------------------------------------------------------------------

void attackEnemie(Enemies *guard, Enemies *storm, Player *rbns, Texture2D guardTex[], Texture2D stormTex[], int frame){
    Texture2D guardTexAtk = guardTex[2];
    Texture2D stormTexAtk = stormTex[2];
    
    float guardframeHeightAtk = (float)(guardTexAtk.height/9);
    int guardmaxFramesAtk = (int)(guardTexAtk.width/(int)guardframeHeightAtk);
    float stormframeHeightAtk = (float)(stormTexAtk.height/21);
    int stormmaxFramesAtk = (int)(stormTexAtk.width/(int)stormframeHeightAtk);
    
    int i;
    for(i=0; i<10; i++){
        if(guard[i].life>0){
            if(CheckCollisionRecs(guard[i].atkbound, rbns->bound)){
                if(GetRandomValue(1, 25)==1){
                    //DrawTextureRec(guardTexAtk, (Rectangle){0, guardframeHeightAtk*frame, -guardframeHeightAtk, (float)guardframeHeightAtk*1}, (Vector2){guard[i].position.x, guard[i].position.y}, RAYWHITE);
                    rbns->life -= guard[i].damage;
                    rbns->hits += 1;
                }
            }
        }
    }
    
    for(i=0; i<5; i++){
        if(storm[i].life>0){
            if(CheckCollisionRecs(storm[i].atkbound, rbns->bound)){
                if(GetRandomValue(1, 25)==1){
                    DrawTextureRec(stormTexAtk, (Rectangle){0, stormframeHeightAtk*frame, stormframeHeightAtk, (float)stormframeHeightAtk*1}, (Vector2){storm[i].position.x, storm[i].position.y}, RAYWHITE);
                    rbns->life -= storm[i].damage;
                    rbns->hits += 1;
                }
            }
        }
    } 
}
//-----------------------------------------------------------------------------------------------------------------------------------

void resetEnemies(Enemies *guard, Enemies *storm, Player rbns){
    int i;
    for(i=0; i<10; i++){
        guard[i].life = 20;
        guard[i].life = 0;
        //if(rbns.position.x <= 1830) guard[i].position = (Vector2){GetRandomValue(500, 1700), GetRandomValue(0, 350)};
        if(rbns.position.x > 2600 && rbns.position.x <= 4370) guard[i].position = (Vector2){GetRandomValue(3000, 4200), GetRandomValue(0, 350)};
        if(rbns.position.x > 5300 && rbns.position.x <= 7030) guard[i].position = (Vector2){GetRandomValue(5700, 8900), GetRandomValue(0, 350)};
        if(rbns.position.x > 7900 && rbns.position.x <= 9730) guard[i].position = (Vector2){GetRandomValue(8300, 9600), GetRandomValue(0, 350)};
        if(rbns.position.x > 10500) guard[i].position = (Vector2){GetRandomValue(10900, 12000), GetRandomValue(0, 350)};
    }
    
    for(i=0; i<5; i++){
        storm[i].life = 40;
        storm[i].died = 0;
        //if(rbns.position.x <= 1830) storm[i].position = (Vector2){GetRandomValue(500, 1700), GetRandomValue(0, 350)};
        if(rbns.position.x > 1830 && rbns.position.x <= 4370) storm[i].position = (Vector2){GetRandomValue(3000, 4200), GetRandomValue(0, 350)};
        if(rbns.position.x > 4370 && rbns.position.x <= 7030) storm[i].position = (Vector2){GetRandomValue(5700, 8900), GetRandomValue(0, 350)};
        if(rbns.position.x > 7900 && rbns.position.x <= 9730) storm[i].position = (Vector2){GetRandomValue(8300, 9600), GetRandomValue(0, 350)};
        if(rbns.position.x > 10500) storm[i].position = (Vector2){GetRandomValue(10900, 12000), GetRandomValue(0, 350)};
    }
}
//-----------------------------------------------------------------------------------------------------------------------------------

void generateItens(Itens extras[], Player rbns){
    int i;
    for(i=0; i<5; i++){
        extras[i].lifeboost = GetRandomValue(20, 30);
        if(rbns.position.x <= 1830) extras[i].position = (Vector2){GetRandomValue(500, 1700), GetRandomValue(0, 350)};
        if(rbns.position.x > 2600 && rbns.position.x <= 4370) extras[i].position = (Vector2){GetRandomValue(3000, 4200), GetRandomValue(0, 350)};
        if(rbns.position.x > 5300 && rbns.position.x <= 7030) extras[i].position = (Vector2){GetRandomValue(5700, 8900), GetRandomValue(0, 350)};
        if(rbns.position.x > 7900 && rbns.position.x <= 9730) extras[i].position = (Vector2){GetRandomValue(8300, 9600), GetRandomValue(0, 350)};
        if(rbns.position.x > 10500) extras[i].position = (Vector2){GetRandomValue(10900, 12000), GetRandomValue(0, 350)};
        extras[i].bound = (Rectangle){extras[i].position.x, extras[i].position.y, 10, 10};
    }
}
//-----------------------------------------------------------------------------------------------------------------------------------

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
//-----------------------------------------------------------------------------------------------------------------------------------

void cameraUpdate(Camera2D *camera, Player rbns){
    //Atualizando os parametros da camera
    camera->target = (Vector2){rbns.position.x + 20, rbns.position.y + 20};
    camera->zoom += ((float)GetMouseWheelMove()*0.05f);
    //Limitando o zoom da camera
    if (camera->zoom > 3.0f) camera->zoom = 3.0f;
    else if (camera->zoom < 2.0f) camera->zoom = 2.0f;
    //Limitando o deslocamento da camera
    if(camera->target.x<320) camera->target.x = 320;
    if(camera->target.x>12050) camera->target.x = 12050;
    if(camera->target.y<180) camera->target.y = 180;
    if(camera->target.y>270) camera->target.y = 270;
}
//-----------------------------------------------------------------------------------------------------------------------------------
void studentPlace(Student lnidas, Student robrigo, Student mulittle, Student xanny, Student freddy, int frame){
    float lnidasframeWidth = (float)(lnidas.texture.width/6);
    int maxFramesLnidas = (int)(lnidas.texture.width/(int)lnidasframeWidth);
    
    float robrigoframeWidth = (float)(robrigo.texture.width/6);
    int maxFramesrobrigo = (int)(robrigo.texture.width/(int)robrigoframeWidth);
    
    float mulittleframeWidth = (float)(mulittle.texture.width/6);
    int maxFramesmulittle = (int)(mulittle.texture.width/(int)mulittleframeWidth);
    
    float xannyframeWidth = (float)(xanny.texture.width/6);
    int maxFramesxanny = (int)(xanny.texture.width/(int)xannyframeWidth);
    
    float freddyframeWidth = (float)(freddy.texture.width/15);
    int maxFramesfreddy = (int)(freddy.texture.width/(int)freddyframeWidth);
    
    
    if(lnidas.life > 0) DrawTextureRec(lnidas.texture, (Rectangle){lnidasframeWidth*frame, 0, lnidasframeWidth, lnidas.texture.height}, (Vector2){lnidas.position.x, lnidas.position.y}, RAYWHITE);
    if(robrigo.life> 0) DrawTextureRec(robrigo.texture, (Rectangle){robrigoframeWidth*frame, 0, robrigoframeWidth, robrigo.texture.height}, (Vector2){robrigo.position.x, robrigo.position.y}, RAYWHITE);
    if(robrigo.life> 0) DrawTextureRec(mulittle.texture, (Rectangle){mulittleframeWidth*frame, 0, mulittleframeWidth, mulittle.texture.height}, (Vector2){mulittle.position.x, mulittle.position.y}, RAYWHITE);
    if(robrigo.life> 0) DrawTextureRec(xanny.texture, (Rectangle){xannyframeWidth*frame, 0, xannyframeWidth, xanny.texture.height}, (Vector2){xanny.position.x, xanny.position.y}, RAYWHITE);
    if(robrigo.life> 0) DrawTextureRec(freddy.texture, (Rectangle){freddyframeWidth*frame, 0, -freddyframeWidth, freddy.texture.height}, (Vector2){freddy.position.x, freddy.position.y}, RAYWHITE);
}
    
void studentFight(Player *rbns){
    //if(rbns->position.x > 1720 && rbns->position.x < 1830) //chama combate 1
    //if(rbns->position.x > 4300 && rbns->position.x < 4370) //chama combate 2
    //if(rbns->position.x > 6910 && rbns->position.x < 7030) //chama combate 3
    //if(rbns->position.x > 9600 && rbns->position.x < 9730) //chama combate 4
    //if(rbns->position.x > 12250) //chama combate 5
}
//-----------------------------------------------------------------------------------------------------------------------------------
