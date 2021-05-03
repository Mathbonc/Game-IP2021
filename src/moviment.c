#include "moviment.h"
#include "combate.h"
#include "raylib.h"
#include "falas.h"
#include <math.h>

int Game(Player *rbns, Enemies guard[], Enemies storm[], Itens extras[], Rectangle obst[], Texture2D rbnsTex[], Texture2D guardTex[], Texture2D stormTex[], Texture2D itensTex, Camera2D *camera, int *frame, char *last, float *timer, Texture2D background, int *text_cont, int *text_aux, Student stud[],int *GameStage){
    static int i;
    static int Falas = 0;
    charcont[1]=1;
    //Sistema de FullScreen ao apertar F
    if(!IsWindowFullscreen() && IsKeyPressed(KEY_F)) ToggleFullscreen();
    else if(IsWindowFullscreen() && IsKeyPressed(KEY_F)) ToggleFullscreen();
    //-----------------------------------------------------------------------------------------------------------------------------------
    
    *timer += GetFrameTime();
    if((*timer) >= 0.15f){
        *timer = 0.0f;
        *frame += 1;
        //frameDie += 1;
        //frameAtk += 1;
    }
    *frame = *frame % 11;
    //frameDie = frameDie % 11;
    //frameAtk = frameAtk % 12;
    
    
    
    ClearBackground(RAYWHITE); //(Color){255, 0, 255, 255} -> forma alternativa
    
    BeginMode2D(*camera);
        //Lidando com o Mapa
        DrawTexture(background, 0, 0, RAYWHITE);
        //-----------------------------------------------------------------------------------------------------------------------------------
        i+=GetFrameTime();
        //Escrevendo as TODAS falas iniciais
        if(charcont[(*text_cont)]!=0)
            charcont[(*text_cont)] += 8;

        DrawText(TextFormat("%s", fala01), 1280/4.0f-90, 720/2.0f-60, 10, BLACK);
        DrawText(TextSubtext(fala02, 0, charcont[2]/10), rbns->position.x-70, rbns->position.y+50, 10, BLACK);
        DrawText(TextSubtext(fala03, 0, charcont[3]/10), rbns->position.x-70, rbns->position.y+50, 10, BLACK);
        DrawText(TextSubtext(fala04, 0, charcont[4]/10), rbns->position.x-70, rbns->position.y+50, 10, BLACK);
        DrawText(TextSubtext(fala05, 0, charcont[5]/10), stud[0].position.x-70, stud[0].position.y+50, 10, BLACK);
        if(Falas==1){
            DrawText(TextSubtext(fala06, 0, charcont[6]/10), rbns->position.x-70, rbns->position.y+50, 10, BLACK);
            DrawText(TextSubtext(fala07, 0, charcont[7]/10), stud[0].position.x-70, stud[0].position.y+50, 10, BLACK);
            DrawText(TextSubtext(fala08, 0, charcont[8]/10), 1280/4.0f-90, 720/2.0f-60, 10, BLACK);
            DrawText(TextSubtext(fala09, 0, charcont[9]/10), rbns->position.x-70, rbns->position.y+50, 10, BLACK);
        }
        DrawText(TextSubtext(fala10, 0, charcont[10]/10), stud[1].position.x-70, stud[1].position.y+50, 10, BLACK);
        DrawText(TextSubtext(fala11, 0, charcont[11]/10), rbns->position.x-70, rbns->position.y+50, 10, BLACK);
        DrawText(TextSubtext(fala12, 0, charcont[12]/10), stud[1].position.x-70, stud[1].position.y+50, 10, BLACK);
        if(Falas==2){
            DrawText(TextSubtext(fala13, 0, charcont[13]/10), rbns->position.x-70, rbns->position.y+50, 10, BLACK);
            DrawText(TextSubtext(fala14, 0, charcont[14]/10), stud[1].position.x-70, stud[1].position.y+50, 10, BLACK);
            DrawText(TextSubtext(fala15, 0, charcont[15]/10), 1280/4.0f-90, 720/2.0f-60, 10, BLACK);
            DrawText(TextSubtext(fala16, 0, charcont[16]/10), rbns->position.x-70, rbns->position.y+50, 10, BLACK);
        }
        DrawText(TextSubtext(fala17, 0, charcont[17]/10), stud[2].position.x-70, stud[2].position.y+50, 10, BLACK);
        DrawText(TextSubtext(fala18, 0, charcont[18]/10), rbns->position.x-70, rbns->position.y+50, 10, BLACK);
        DrawText(TextSubtext(fala19, 0, charcont[19]/10), stud[2].position.x-70, stud[2].position.y+50, 10, BLACK);
        if(Falas==3){
            DrawText(TextSubtext(fala20, 0, charcont[20]/10), rbns->position.x-70, rbns->position.y+50, 10, BLACK);
            DrawText(TextSubtext(fala21, 0, charcont[21]/10), stud[2].position.x-70, stud[2].position.y+50, 10, BLACK);
            DrawText(TextSubtext(fala22, 0, charcont[22]/10), 1280/4.0f-90, 720/2.0f-60, 10, BLACK);
            DrawText(TextSubtext(fala23, 0, charcont[23]/10), rbns->position.x-70, rbns->position.y+50, 10, BLACK);
        }
        DrawText(TextSubtext(fala24, 0, charcont[24]/10), stud[3].position.x-70, stud[3].position.y+50, 10, BLACK);
        DrawText(TextSubtext(fala25, 0, charcont[25]/10), rbns->position.x-70, rbns->position.y+50, 10, BLACK);
        DrawText(TextSubtext(fala26, 0, charcont[26]/10), stud[3].position.x-70, stud[3].position.y+50, 10, BLACK);
        if(Falas==4){
            DrawText(TextSubtext(fala27, 0, charcont[27]/10), rbns->position.x-70, rbns->position.y+50, 10, BLACK);
            DrawText(TextSubtext(fala28, 0, charcont[28]/10), stud[3].position.x-70, stud[3].position.y+50, 10, BLACK);
            DrawText(TextSubtext(fala29, 0, charcont[29]/10), 1280/4.0f-90, 720/2.0f-60, 10, BLACK);
            DrawText(TextSubtext(fala30, 0, charcont[30]/10), rbns->position.x-70, rbns->position.y+50, 10, BLACK);
        }
        
        DrawText(TextSubtext(fala31, 0, charcont[31]/10), rbns->position.x-70, rbns->position.y+50, 10, BLACK);
        DrawText(TextSubtext(fala32, 0, charcont[32]/10), stud[4].position.x-70, stud[4].position.y+50, 10, BLACK);
        DrawText(TextSubtext(fala33, 0, charcont[33]/10), rbns->position.x-70, rbns->position.y+50, 10, BLACK);
        DrawText(TextSubtext(fala34, 0, charcont[34]/10), stud[4].position.x-70, stud[4].position.y+50, 10, BLACK);
        DrawText(TextSubtext(fala35, 0, charcont[35]/10), rbns->position.x-70, rbns->position.y+50, 10, BLACK);
        DrawText(TextSubtext(fala36, 0, charcont[36]/10), stud[4].position.x-70, stud[4].position.y+50, 10, BLACK);
        DrawText(TextSubtext(fala37, 0, charcont[37]/10), rbns->position.x-70, rbns->position.y+50, 10, BLACK);
        DrawText(TextSubtext(fala38, 0, charcont[38]/10), stud[4].position.x-70, stud[4].position.y+50, 10, BLACK);
        DrawText(TextSubtext(fala39, 0, charcont[39]/10), rbns->position.x-70, rbns->position.y+50, 10, BLACK);
        DrawText(TextSubtext(fala40, 0, charcont[40]/10), stud[4].position.x-70, stud[4].position.y+50, 10, BLACK);
        if(Falas==5){
            DrawText(TextSubtext(fala41, 0, charcont[41]/10), stud[4].position.x-70, stud[4].position.y+50, 10, BLACK);
            DrawText(TextSubtext(fala42, 0, charcont[42]/10), rbns->position.x-70, rbns->position.y+50, 10, BLACK);
            DrawText(TextSubtext(fala43, 0, charcont[43]/10), stud[4].position.x-70, stud[4].position.y+50, 10, BLACK);
            DrawText(TextSubtext(fala44, 0, charcont[44]/10), 1280/4.0f-90, 720/2.0f-60, 10, BLACK);
        }
        /*
        DrawText(TextSubtext(fala45, 0, charcont[45]/10), rbns->position.x-70, rbns->position.y+50, 10, BLACK);
        DrawText(TextSubtext(fala46, 0, charcont[46]/10), rbns->position.x-70, rbns->position.y+50, 10, BLACK);
        DrawText(TextSubtext(fala47, 0, charcont[47]/10), rbns->position.x-70, rbns->position.y+50, 10, BLACK);
        DrawText(TextSubtext(fala48, 0, charcont[48]/10), rbns->position.x-70, rbns->position.y+50, 10, BLACK);*/
        if(IsKeyPressed(KEY_SPACE)){
            charcont[(*text_cont)]=0;
            if(Falas==0 && (*text_aux)<5){
              (*text_cont)++;
              charcont[(*text_cont)]=1;
              (*text_aux)++;
            }
            else if(Falas==1 && (*text_aux)<12){
              (*text_cont)++;
              charcont[(*text_cont)]=1;
              (*text_aux)++;
            }
            else if(Falas==2 && (*text_aux)<19){
              (*text_cont)++;
              charcont[(*text_cont)]=1;
              (*text_aux)++;
            }
            else if(Falas==3 && (*text_aux)<26){
              (*text_cont)++;
              charcont[(*text_cont)]=1;
              (*text_aux)++;
            }
            else if(Falas==4 && (*text_aux)<41){
              (*text_cont)++;
              charcont[(*text_cont)]=1;
              (*text_aux)++;
            }
            else if(Falas==5 && (*text_aux)<47){
              (*text_cont)++;
              charcont[(*text_cont)]=1;
              (*text_aux)++;
            }
        }
        /*if(charcont[2]>256){
            *text_aux=48;
        }
        if(IsKeyPressed(KEY_J)){
            *text_aux=2;
        }*/
        //-----------------------------------------------------------------------------------------------------------------------------------
        
        //Acoes Player
        if(!IsKeyDown(KEY_K) && !IsKeyDown(KEY_L)) moveCharacter(rbns, background, obst, rbnsTex, *frame, *frame, last);
        attackCharacter(guard, storm, *rbns, rbnsTex, guardTex, stormTex, *last, *frame);
        //-----------------------------------------------------------------------------------------------------------------------------------
        
        //for(i=0; i<8; i++) DrawRectangleRec(obst[i], GREEN);
        //for(i=0; i<10; i++) DrawRectangleRec(guard[i].atkbound, PINK);
        //for(i=0; i<5; i++) DrawRectangleRec(storm[i].atkbound, RED);
        //DrawRectangleRec(rbns.bound, RED);
        
        //Acoes Inimigos
        moveEnemie(guard, storm, *rbns, obst, guardTex, stormTex, *frame);
        attackEnemie(guard, storm, rbns, guardTex, stormTex, *frame);
        //resetEnemies(guard, storm, rbns);
        //-----------------------------------------------------------------------------------------------------------------------------------
        
        //Desenhando Estudantes
        studentPlace(stud, *frame);
        //-----------------------------------------------------------------------------------------------------------------------------------
        
        //Gerenciando Itens
        getItens(rbns, extras, itensTex);
        //-----------------------------------------------------------------------------------------------------------------------------------
        
        //Gerenciando Bosses
        studentFight(rbns,guard,storm,extras, camera, &Falas,GameStage); 
        //-----------------------------------------------------------------------------------------------------------------------------------
        
        //Gerenciando Camera
        cameraUpdate(camera, *rbns);
        //-----------------------------------------------------------------------------------------------------------------------------------
        
    EndMode2D();
            
           
}

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
    float frameWidthRun = (float)(rbnsTexRun.width/8);;
    float frameWidthDie = (float)(rbnsTexDie.width/11);
    
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
        
        if(rbns->position.x > 12300) rbns->position.x = 12300; 
        if(rbns->position.x <= 0) rbns->position.x += 1.0f * rbns->speed; 
        if(rbns->position.y >= background.height-50) rbns->position.y -= 1.0f * rbns->speed;
        if(rbns->position.y <= 0) rbns->position.y += 1.0f * rbns->speed; 
                  
        if(rbns->position.x < 1830){
            if(rbns->position.x > 1820.0f) rbns->position.x = 1820.0f;
        }
        if(rbns->position.x > 1830 && rbns->position.x <= 4370){
            if(rbns->position.x < 2650.0f) rbns->position.x = 2650.0f;
            if(rbns->position.x > 4360.0f) rbns->position.x = 4360.0f;
        }
        if(rbns->position.x > 4370 && rbns->position.x <= 7030){
            if(rbns->position.x < 5550.0f) rbns->position.x = 5600.0f;
            if(rbns->position.x > 7020.0f) rbns->position.x = 7020.0f;
        }
        if(rbns->position.x > 7030 && rbns->position.x <= 9730){
            if(rbns->position.x < 8150.0f) rbns->position.x = 8200.0f;
            if(rbns->position.x > 9720.0f) rbns->position.x = 9720.0f;
        }
        if(rbns->position.x > 9730){
            if(rbns->position.x < 10890.0f) rbns->position.x = 10900.0f;
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
    rbns->life = 130;
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
    float frameWidthAtk2 = (float)(rbnsTexAtk2.width/3);
    
    float guardframeHeightHit = (float)(guardTexHit.height/3);
    float stormframeHeightHit = (float)(stormTexHit.height/2);
    
    if(IsKeyDown(KEY_K)){
        if(last=='d') DrawTextureRec(rbnsTexAtk, (Rectangle){frameWidthAtk*frameAtk, 0, frameWidthAtk, (float)rbnsTexAtk.height}, (Vector2){rbns.position.x, rbns.position.y}, RAYWHITE);
        if(last!='d') DrawTextureRec(rbnsTexAtk, (Rectangle){frameWidthAtk*frameAtk, 0, -frameWidthAtk, (float)rbnsTexAtk.height}, (Vector2){rbns.position.x, rbns.position.y}, RAYWHITE);
    }
    if(IsKeyDown(KEY_L)){
        if(last=='d') DrawTextureRec(rbnsTexAtk2, (Rectangle){frameWidthAtk2*frameAtk, 0, frameWidthAtk2, (float)rbnsTexAtk2.height}, (Vector2){rbns.position.x, rbns.position.y}, RAYWHITE);
        if(last!='d') DrawTextureRec(rbnsTexAtk2, (Rectangle){frameWidthAtk2*frameAtk, 0, -frameWidthAtk2, (float)rbnsTexAtk2.height}, (Vector2){rbns.position.x, rbns.position.y}, RAYWHITE);
    }
    for(i=0; i<10; i++){
        if((IsKeyPressed(KEY_K) || IsKeyPressed(KEY_L)) && CheckCollisionRecs(rbns.atkbound, guard[i].bound) && guard[i].life>0){
            DrawTextureRec(guardTexHit, (Rectangle){0, guardframeHeightHit*frameAtk, guardframeHeightHit, (float)guardframeHeightHit*1}, (Vector2){guard[i].position.x, guard[i].position.y}, RAYWHITE);
            guard[i].life -= rbns.damage;
        }
    }
    for(i=0; i<5; i++){
        if((IsKeyPressed(KEY_K) || IsKeyPressed(KEY_L)) && CheckCollisionRecs(rbns.atkbound, storm[i].bound) && storm[i].life>0){
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
    float guardframeHeightDie = (float)(guardTexDie.height/10);
    
    float stormframeHeightMove = (float)(stormTexMove.height/10);
    float stormframeHeightDie = (float)(stormTexDie.height/9);
    
    for(i=0; i<10; i++){
        if(guard[i].life>0 && guard[i].position.x > rbns.position.x) DrawTextureRec(guardTexMove, (Rectangle){0, guardframeHeightMove*frame, -guardframeHeightMove, (float)guardframeHeightMove*1}, (Vector2){guard[i].position.x, guard[i].position.y}, RAYWHITE);
        if(guard[i].life>0 && guard[i].position.x < rbns.position.x) DrawTextureRec(guardTexMove, (Rectangle){0, guardframeHeightMove*frame, guardframeHeightMove, (float)guardframeHeightMove*1}, (Vector2){guard[i].position.x, guard[i].position.y}, RAYWHITE);
    }
    for(i=0; i<5; i++){
        if(storm[i].life>0 && storm[i].position.x+30 > rbns.position.x) DrawTextureRec(stormTexMove, (Rectangle){0, stormframeHeightMove*frame, -stormframeHeightMove, (float)stormframeHeightMove*1}, (Vector2){storm[i].position.x, storm[i].position.y}, RAYWHITE);
        if(storm[i].life>0 && storm[i].position.x+30 < rbns.position.x) DrawTextureRec(stormTexMove, (Rectangle){0, stormframeHeightMove*frame, stormframeHeightMove, (float)stormframeHeightMove*1}, (Vector2){storm[i].position.x, storm[i].position.y}, RAYWHITE);
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
    float stormframeHeightAtk = (float)(stormTexAtk.height/21);
    
    int i;
    for(i=0; i<10; i++){
        if(guard[i].life>0){
            if(CheckCollisionRecs(guard[i].atkbound, rbns->bound)){
                if(guard[i].position.x < rbns->position.x) DrawTextureRec(guardTexAtk, (Rectangle){0, guardframeHeightAtk*frame, guardTex->width, (float)guardframeHeightAtk*1}, (Vector2){guard[i].position.x, guard[i].position.y}, RAYWHITE);
                else DrawTextureRec(guardTexAtk, (Rectangle){0, guardframeHeightAtk*frame, -guardTex->width, (float)guardframeHeightAtk*1}, (Vector2){guard[i].position.x, guard[i].position.y}, RAYWHITE);
                if(GetRandomValue(1, 25)==1){
                    rbns->life -= guard[i].damage;
                    rbns->hits += 1;
                }
            }
        }
    }
    
    for(i=0; i<5; i++){
        if(storm[i].life>0){
            if(CheckCollisionRecs(storm[i].atkbound, rbns->bound)){
                if(storm[i].position.x+30 < rbns->position.x) DrawTextureRec(stormTexAtk, (Rectangle){0, stormframeHeightAtk*frame, stormframeHeightAtk, (float)stormframeHeightAtk*1}, (Vector2){storm[i].position.x, storm[i].position.y}, RAYWHITE);
                else DrawTextureRec(stormTexAtk, (Rectangle){0, stormframeHeightAtk*frame, -stormframeHeightAtk, (float)stormframeHeightAtk*1}, (Vector2){storm[i].position.x, storm[i].position.y}, RAYWHITE);
                if(GetRandomValue(1, 25)==1){
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
        guard[i].died = 0;
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
        extras[i].lifeboost = GetRandomValue(40, 60);
        if(rbns.position.x <= 1830) extras[i].position = (Vector2){GetRandomValue(500, 1700), GetRandomValue(0, 350)};
        if(rbns.position.x > 2600 && rbns.position.x <= 4370) extras[i].position = (Vector2){GetRandomValue(3000, 4200), GetRandomValue(0, 350)};
        if(rbns.position.x > 5300 && rbns.position.x <= 7030) extras[i].position = (Vector2){GetRandomValue(5700, 8900), GetRandomValue(0, 350)};
        if(rbns.position.x > 7900 && rbns.position.x <= 9730) extras[i].position = (Vector2){GetRandomValue(8300, 9600), GetRandomValue(0, 350)};
        if(rbns.position.x > 10500) extras[i].position = (Vector2){GetRandomValue(10900, 12000), GetRandomValue(0, 350)};
        extras[i].bound = (Rectangle){extras[i].position.x+10, extras[i].position.y+40, 10, 10};
    }
}
//-----------------------------------------------------------------------------------------------------------------------------------

void getItens(Player *rbns, Itens extras[], Texture2D itensTex){
    int i;
    for(i=0; i<5; i++){
        if(CheckCollisionRecs(rbns->bound, extras[i].bound) && rbns->life<200){
            rbns->life += extras[i].lifeboost;
            extras[i].lifeboost = 0;
            if(rbns->life > 200) rbns->life = 200;
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
    if(camera->zoom > 2.5f) camera->zoom = 2.5f;
    if(camera->zoom < 2.0f) camera->zoom = 2.0f;
    //Limitando o deslocamento da camera
    if(camera->target.x<320) camera->target.x = 320;
    if(camera->target.x>12050) camera->target.x = 12050;
    if(camera->target.y<180) camera->target.y = 180;
    if(camera->target.y>270) camera->target.y = 270;
}
//-----------------------------------------------------------------------------------------------------------------------------------
void studentPlace(Student stud[], int frame){
    Student lnidas = stud[0];
    Student robrigo = stud[1];
    Student mulittle = stud[2];
    Student xanny = stud[3];
    Student freddy = stud[4];
    
    float lnidasframeWidth = (float)(lnidas.texture.width/6);
    float robrigoframeWidth = (float)(robrigo.texture.width/6);
    float mulittleframeWidth = (float)(mulittle.texture.width/6);
    float xannyframeWidth = (float)(xanny.texture.width/6);
    float freddyframeWidth = (float)(freddy.texture.width/15);
    
    
    if(lnidas.life > 0) DrawTextureRec(lnidas.texture, (Rectangle){lnidasframeWidth*frame, 0, lnidasframeWidth, lnidas.texture.height}, (Vector2){lnidas.position.x, lnidas.position.y}, RAYWHITE);
    if(robrigo.life > 0) DrawTextureRec(robrigo.texture, (Rectangle){robrigoframeWidth*frame, 0, robrigoframeWidth, robrigo.texture.height}, (Vector2){robrigo.position.x, robrigo.position.y}, RAYWHITE);
    if(robrigo.life> 0) DrawTextureRec(mulittle.texture, (Rectangle){mulittleframeWidth*frame, 0, mulittleframeWidth, mulittle.texture.height}, (Vector2){mulittle.position.x, mulittle.position.y}, RAYWHITE);
    if(robrigo.life> 0) DrawTextureRec(xanny.texture, (Rectangle){xannyframeWidth*frame, 0, xannyframeWidth, xanny.texture.height}, (Vector2){xanny.position.x, xanny.position.y}, RAYWHITE);
    if(robrigo.life> 0) DrawTextureRec(freddy.texture, (Rectangle){freddyframeWidth*frame, 0, -freddyframeWidth, freddy.texture.height}, (Vector2){freddy.position.x, freddy.position.y}, RAYWHITE);
}
//-----------------------------------------------------------------------------------------------------------------------------------   
void studentFight(Player *rbns,Enemies guard[],Enemies storm[],Itens extras[], Camera2D *camera,int *Falas,int *GameStage){
    if(rbns->position.x > 1720 && rbns->position.x < 1830){
        //camera->zoom = 10.0f;
        Combat_LeaoNidas(rbns, Falas);
        if(*Falas==1){
            resetEnemies(guard, storm, *rbns);
            generateItens(extras,*rbns);
        }
    }
    if(rbns->position.x > 4300 && rbns->position.x < 4370){
        //camera->zoom = 10.0f;
        Combat_RoBrigo(rbns ,Falas);
        if(*Falas==2){
            resetEnemies(guard, storm, *rbns);
            generateItens(extras,*rbns);
        }
    } 
    if(rbns->position.x > 6910 && rbns->position.x < 7030){
        //camera->zoom = 10.0f;
        Combat_MuLittle(rbns ,Falas);
        if(*Falas==3){
            resetEnemies(guard, storm, *rbns);
            generateItens(extras,*rbns);
        }
    }
    if(rbns->position.x > 9600 && rbns->position.x < 9730){
        //camera->zoom = 10.0f;
        Combat_XAnny(rbns , Falas);
        if(*Falas==4){
            resetEnemies(guard, storm, *rbns);
            generateItens(extras,*rbns);
        }
    }
    if(rbns->position.x > 12250){
        //camera->zoom = 10.0f;
        Combat_Freddy(rbns, Falas);
        if(*Falas==5){
            *GameStage=2;
        }
    } 
}
//-----------------------------------------------------------------------------------------------------------------------------------