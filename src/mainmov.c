#include "raylib.h"
#include "moviment.h"
#include "assets.h"
#include <stdlib.h>

int Game(){
    //Iniciando Game
    int const windowWidth = 1260;
    int const windowHeight = 720;
    char last = 'd';
    int i;
    
    InitWindow(windowWidth, windowHeight, "A Jornada de Rubens");
    if(!IsWindowReady()) exit(1);
    SetTargetFPS(60);
    //-----------------------------------------------------------------------------------------------------------------------------------
    
    //Gerando Elementos
    Player rbns = {0};
    rbns.position = (Vector2){300.0f, 175.0f};
    rbns.speed = 2.0;
    rbns.life = 200;
    rbns.damage = 10;
    rbns.bound = (Rectangle){315, 180, 30, 44};
    rbns.atkbound = (Rectangle){315, 180, 60, 44};
    
    Enemies guard[10] = {0};
    Enemies storm[3] = {0};
    generateEnemies(guard, storm);
    
    Itens extras[5] = {0};
    generateItens(extras, rbns);
    
    Rectangle obst[] = {
        {154, 90, 85, 60},
        {1325, 40, 85, 70},
        {1260, 300, 85, 70},
        {2783, 318, 85, 70},
        {3010, 260, 85, 70},
        {6060, 41, 85, 70},
        {6110, 200, 85, 70},
        {9390, 26, 85, 70},
    };
    
    Student lnidas = {0};
    lnidas.life = 200;
    lnidas.position = (Vector2){1750.0f, 175.0f};
    lnidas.texture = LoadTexture("../bin/Characters/Students/Leao Nidas/frente_ruivo.png");
    
    Student robrigo = {0};
    robrigo.life = 200;
    robrigo.position = (Vector2){4330.0f, 175.0f};
    robrigo.texture = LoadTexture("../bin/Characters/Students/Ro Brigo/frente_loiro.png");
    
    Student mulittle = {0};
    mulittle.life = 200;
    mulittle.position = (Vector2){6920.0f, 175.0f};
    mulittle.texture = LoadTexture("../bin/Characters/Students/MuLittle/frente_moreno.png");
    
    Student xanny = {0};
    xanny.life = 200;
    xanny.position = (Vector2){9610.0f, 175.0f};
    xanny.texture = LoadTexture("../bin/Characters/Students/X Anny/fem_frente.png");
    
    Student freddy = {0};
    freddy.life = 300;
    freddy.position = (Vector2){12260.0f, 175.0f};
    freddy.texture = LoadTexture("../bin/Characters/Students/Freddy Rico/noBKG_KnightIdle_strip.png");
    //-----------------------------------------------------------------------------------------------------------------------------------
    
    //Texturas Mapa
    Texture2D background = LoadTexture("../bin/Map/fullmap.png");
    //-----------------------------------------------------------------------------------------------------------------------------------
    
    //Texturas Rubens
    Texture2D rbnsTex[5] = {0};
    rbnsTex[0] = LoadTexture("../bin/Characters/Rubens/SpriteSheet/Warrior_Idle.png"); //Idle Texture
    rbnsTex[1] = LoadTexture("../bin/Characters/Rubens/SpriteSheet/Warrior_Run.png"); //Run Texture
    rbnsTex[2] = LoadTexture("../bin/Characters/Rubens/SpriteSheet/Warrior_Die.png"); //Die Texture
    rbnsTex[3] = LoadTexture("../bin/Characters/Rubens/SpriteSheet/Warrior_AttackLtt.png"); //Attack Texture
    rbnsTex[4] = LoadTexture("../bin/Characters/Rubens/SpriteSheet/Warrior_AttackLtt2.png"); //Attack Texture 2
    //-----------------------------------------------------------------------------------------------------------------------------------
    
    //Texturas Inimigos
    Texture2D guardTex[4] = {0};
    guardTex[0] = LoadTexture("../bin/Characters/Enemies/Guardian/Guardian_Move.png"); //Run/Idle Texture
    guardTex[1] = LoadTexture("../bin/Characters/Enemies/Guardian/Guardian_Die.png"); //Die Texture
    guardTex[2] = LoadTexture("../bin/Characters/Enemies/Guardian/Guardian_Attack.png"); //Attack Texture
    guardTex[3] = LoadTexture("../bin/Characters/Enemies/Guardian/Guardian_Hit.png"); //Hit Texture
    
    Texture2D stormTex[4] = {0};
    stormTex[0] = LoadTexture("../bin/Characters/Enemies/Stormhead/run.png"); //Run/Idle Texture
    stormTex[1] = LoadTexture("../bin/Characters/Enemies/Stormhead/death.png"); //Die Texture
    stormTex[2] = LoadTexture("../bin/Characters/Enemies/Stormhead/attack.png"); //Attack Texture
    stormTex[3] = LoadTexture("../bin/Characters/Enemies/Stormhead/damaged.png"); //Hit Texture
    //-----------------------------------------------------------------------------------------------------------------------------------
    
    //Texturas Itens
    Texture2D itensTex = LoadTexture("../bin/Itens/canetaverm.png");
    //-----------------------------------------------------------------------------------------------------------------------------------
    
    float timer = 0.0f;
    int frame = 0, frameDie = 0, frameAtk = 0;
   
   //Setup Camera
    Camera2D camera;
    camera.target = (Vector2){rbns.position.x + 20.0f,rbns.position.y + 20.0f};
    camera.offset = (Vector2){windowWidth/2.0f, windowHeight/2.0f};
    camera.rotation = 0.0f;
    camera.zoom = 2.0f;
    //-----------------------------------------------------------------------------------------------------------------------------------
    
    while(!WindowShouldClose()){
        //Sistema de FullScreen ao apertar F
        if(!IsWindowFullscreen() && IsKeyPressed(KEY_F)) ToggleFullscreen();
        else if(IsWindowFullscreen() && IsKeyPressed(KEY_F)) ToggleFullscreen();
        //-----------------------------------------------------------------------------------------------------------------------------------
        
        timer += GetFrameTime();
        if(timer >= 0.15f){
            timer = 0.0f;
            frame += 1;
            frameDie += 1;
            frameAtk += 1;
        }
        frame = frame % 11;
        frameDie = frameDie % 11;
        frameAtk = frameAtk % 12;
        
        //Gerenciando Camera
        cameraUpdate(&camera, rbns);
        //-----------------------------------------------------------------------------------------------------------------------------------
        
        //Gerenciando Bosses
        studentFight(&rbns);
        //-----------------------------------------------------------------------------------------------------------------------------------
        
        BeginDrawing();
            ClearBackground(RAYWHITE); //(Color){255, 0, 255, 255} -> forma alternativa
            
            BeginMode2D(camera);
                //Lidando com o Mapa
                DrawTexture(background, 0, 0, RAYWHITE);
                //-----------------------------------------------------------------------------------------------------------------------------------
                
                //Acoes Player
                if(!IsKeyDown(KEY_K) && !IsKeyDown(KEY_L)) moveCharacter(&rbns, background, obst, rbnsTex, frame, frameDie, &last);
                attackCharacter(guard, storm, rbns, rbnsTex, guardTex, stormTex, last, frameAtk);
                //-----------------------------------------------------------------------------------------------------------------------------------
                
                //for(i=0; i<8; i++) DrawRectangleRec(obst[i], GREEN);
                //for(i=0; i<10; i++) DrawRectangleRec(guard[i].atkbound, PINK);
                //for(i=0; i<5; i++) DrawRectangleRec(storm[i].atkbound, RED);
                //DrawRectangleRec(rbns.bound, RED);
                
                //Acoes Inimigos
                moveEnemie(guard, storm, rbns, obst, guardTex, stormTex, frame);
                attackEnemie(guard, storm, &rbns, guardTex, stormTex, frame);
                //resetEnemies(guard, storm, rbns);
                //-----------------------------------------------------------------------------------------------------------------------------------
                
                //Desenhando Estudantes
                studentPlace(lnidas, robrigo, mulittle, xanny, freddy, frame);
                //-----------------------------------------------------------------------------------------------------------------------------------
                
                //Gerenciando Itens
                getItens(&rbns, extras, itensTex);
                //-----------------------------------------------------------------------------------------------------------------------------------
                
            EndMode2D();
            
            //Player Stats
            DrawText(TextFormat("Life: %d", rbns.life), 20, 10, 10, RED);
            DrawText(TextFormat("x: %.2f, y: %.2f", rbns.position.x, rbns.position.y), 20, 20, 10, RED);
            //-----------------------------------------------------------------------------------------------------------------------------------
            
        EndDrawing();
    }
    UnloadTexture(background);
    for(i=0; i<5; i++) UnloadTexture(rbnsTex[i]);
    for(i=0; i<4; i++) UnloadTexture(guardTex[i]);
    for(i=0; i<4; i++) UnloadTexture(stormTex[i]);
    UnloadTexture(lnidas.texture);
    UnloadTexture(itensTex);
    
    CloseWindow();
    return 0;
}