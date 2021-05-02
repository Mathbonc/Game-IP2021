#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include "moviment.h"
#include "assets.h"

void ParallaxMenu(float BGC, float FC1, float FC2, float FC3, Parallax Menu,UI UIAssets);
int MenuSelect(UI UIAssets, bool *OptWindow, float *SoundVolume);

int main(){
    const int WindowWidth = 1280;
    const int WindowHeight = 720;
    
    InitWindow(WindowWidth,WindowHeight,"MainMenu");
    InitAudioDevice();
    SetTargetFPS(60);
  
    Parallax Menu = LoadMenu();
    UI UIAssets = LoadUIAssets();
    UIIG InGameUI = LoadUIIG();
    UIRECS MenuRects = DefineUIRECTS();
    
    bool OptWindow = false;
    bool GamePause = 0;
    int GameStage = 0;
    float SoundVolume = 0.1;
    //SCROLL
    scrolling cloudsScroll;
    cloudsScroll.BGC = 0.0f;
    cloudsScroll.FC1 = 0.0f;
    cloudsScroll.FC2 = 0.0f;
    cloudsScroll.FC3 = 0.0f;
    //MUSICS
    PlayMusicStream(Menu.Music);
    
    while(GameStage==0){
        SetMusicVolume(Menu.Music,SoundVolume);
        UpdateMusicStream(Menu.Music);
        //Scrolling
        cloudsScroll.BGC-=0.2f;
        cloudsScroll.FC1+=0.4f;
        cloudsScroll.FC2-=0.3f;
        cloudsScroll.FC3+=0.2f;
        ParallaxMenu(cloudsScroll.BGC,cloudsScroll.FC1,cloudsScroll.FC2,cloudsScroll.FC3,Menu,UIAssets);
        GameStage = MenuSelect(UIAssets,&OptWindow,&SoundVolume);
    }
    if(GameStage==1){
        MudaMusica(Menu.Music,InGameUI.GameMusic1);
        
        SoundVolume=0;
        char last = 'd';
        
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
    
        Texture2D rbnsTex[5] = {0};
        rbnsTex[0] = LoadTexture("../bin/Characters/Rubens/SpriteSheet/Warrior_Idle.png"); //Idle Texture
        rbnsTex[1] = LoadTexture("../bin/Characters/Rubens/SpriteSheet/Warrior_Run.png"); //Run Texture
        rbnsTex[2] = LoadTexture("../bin/Characters/Rubens/SpriteSheet/Warrior_Die.png"); //Die Texture
        rbnsTex[3] = LoadTexture("../bin/Characters/Rubens/SpriteSheet/Warrior_AttackLtt.png"); //Attack Texture
        rbnsTex[4] = LoadTexture("../bin/Characters/Rubens/SpriteSheet/Warrior_AttackLtt2.png"); //Attack Texture 2
        
        Texture2D guardTex[4] = {0};
        guardTex[0] = LoadTexture("../bin/Characters/Enemies/Guardian/Guardian_Move.png"); //Run/Idle Texture
        guardTex[1] = LoadTexture("../bin/Characters/Enemies/Guardian/Guardian_Die.png"); //Die Texture
        guardTex[2] = LoadTexture("../bin/Characters/Enemies/Guardian/Guardian_Attack.png"); //Attack Texture
        guardTex[3] = LoadTexture("../bin/Characters/Enemies/Guardian/Guardian_Hit.png"); //Hit Texture
        
        Texture2D stormTex[4] = {0};
        stormTex[0] = LoadTexture("../bin/Characters/Enemies/Stormhead/run.png"); //Run/Idle Texture
        stormTex[1] = LoadTexture("../bin/Characters/Enemies/Stormhead/death.png"); //Die Texture
        stormTex[2] = LoadTexture("../bin/Characters/Enemies/Stormhead/attack.png"); //Attack Texture
        stormTex[3] = LoadTexture("../bin/Characters/Enemies/Stormhead/damaged.png");
        
        Student stud[5] = {0};
        stud[0].life = 200; //Leao Nidas
        stud[0].position = (Vector2){1750.0f, 175.0f};
        stud[0].texture = LoadTexture("../bin/Characters/Students/Leao Nidas/frente_ruivo.png");
        stud[1].life = 200; //Ro Brigo
        stud[1].position = (Vector2){4330.0f, 175.0f};
        stud[1].texture = LoadTexture("../bin/Characters/Students/Ro Brigo/frente_loiro.png");
        stud[2].life = 200; //MuLittle
        stud[2].position = (Vector2){6920.0f, 175.0f};
        stud[2].texture = LoadTexture("../bin/Characters/Students/MuLittle/frente_moreno.png");
        stud[3].life = 200;
        stud[3].position = (Vector2){9610.0f, 175.0f};
        stud[3].texture = LoadTexture("../bin/Characters/Students/X Anny/fem_frente.png");
        stud[4].life = 300;
        stud[4].position = (Vector2){12260.0f, 175.0f};
        stud[4].texture = LoadTexture("../bin/Characters/Students/Freddy Rico/noBKG_KnightIdle_strip.png");
        
        Texture2D itensTex = LoadTexture("../bin/Itens/canetaverm.png");
        
        Texture2D background = LoadTexture("../bin/Map/fullmap.png");
        
        float timer = 0.0f;
        int frame = 0, frameDie = 0, frameAtk = 0, text_cont=1, text_aux=0;
        
        Camera2D camera;
        camera.target = (Vector2){rbns.position.x + 20.0f,rbns.position.y + 20.0f};
        camera.offset = (Vector2){WindowWidth/2.0f, WindowHeight/2.0f};
        camera.rotation = 0.0f;
        camera.zoom = 2.0f;
        
        while(GameStage==1){
            SetMusicVolume(InGameUI.GameMusic1,SoundVolume);
            UpdateMusicStream(InGameUI.GameMusic1);
            BeginDrawing();
            Game(&rbns, guard, storm, extras, obst, rbnsTex, guardTex, stormTex, itensTex, &camera, &frame, &last, &timer, background, &text_cont, &text_aux, stud);
            DrawGameUI(&GamePause, InGameUI, MenuRects, rbns, &SoundVolume, UIAssets,&OptWindow);
            EndDrawing();
        }
    }   
    UnloadUIAssets(UIAssets);
    UnloadMenu(Menu);
    UnloadUIIG(InGameUI);
    
    CloseAudioDevice();
    CloseWindow();
    return 0;
}

void ParallaxMenu(float BGC, float FC1, float FC2, float FC3, Parallax Menu,UI UIAssets){
    if(BGC <= -Menu.CloudsBG.width*MenuScale){BGC=0;}
    if(FC1 >= Menu.Cloud[0].width*MenuScale){FC1=0;}
    if(FC2 <= -Menu.Cloud[1].width*MenuScale){FC2=0;}
    if(FC1 >= Menu.Cloud[2].width*MenuScale){FC3=0;}
    
    BeginDrawing();
        ClearBackground(RAYWHITE);
        
        DrawTextureEx(Menu.BackGroundSky,(Vector2){0,0},0.0f,MenuScale,RAYWHITE);
        
        //PRIMEIRA PARTE
        DrawTextureEx(Menu.CloudsBG,(Vector2){BGC,0},0.0f,MenuScale,RAYWHITE);
        DrawTextureEx(Menu.CloudLone,(Vector2){BGC,0},0.0f,MenuScale,RAYWHITE);
        //SEGUNDA PARTE
        DrawTextureEx(Menu.CloudsBG,(Vector2){(Menu.CloudsBG.width*MenuScale)+ BGC,0},0.0f,MenuScale,RAYWHITE);
        DrawTextureEx(Menu.CloudLone,(Vector2){(Menu.CloudLone.width*MenuScale)+ BGC,0},0.0f,MenuScale,RAYWHITE);
    
        DrawTextureEx(Menu.Mountains,(Vector2){0,0},0.0f,MenuScale,RAYWHITE);
        //BACK CLLOUDS
        DrawTextureEx(Menu.Cloud[2],(Vector2){FC3,0},0.0f,MenuScale,RAYWHITE);
        DrawTextureEx(Menu.Cloud[2],(Vector2){(-Menu.Cloud[2].width*MenuScale)+FC3,0},0.0f,MenuScale,RAYWHITE);
        //MID CLOUDS
        DrawTextureEx(Menu.Cloud[1],(Vector2){FC2,0},0.0f,MenuScale,RAYWHITE);
        DrawTextureEx(Menu.Cloud[1],(Vector2){(Menu.Cloud[1].width*MenuScale)+FC2,0},0.0f,MenuScale,RAYWHITE);
        //FRONT CLOUDS
        DrawTextureEx(Menu.Cloud[0],(Vector2){FC1,0},0.0f,MenuScale,RAYWHITE);
        DrawTextureEx(Menu.Cloud[0],(Vector2){(-Menu.Cloud[0].width*MenuScale)+FC1,0},0.0f,MenuScale,RAYWHITE);
        //TITLE
        DrawTextureEx(Menu.MainTitle,(Vector2){640-Menu.MainTitle.width*1.25,-50},0.0f,2.5,RAYWHITE);
        //UI
        DrawTextureEx(UIAssets.ButtonLong,(Vector2){640-UIAssets.ButtonLong.width*2.5,400},0.0f,5,RAYWHITE);
        DrawTextEx(UIAssets.Alagard,"Comecar",(Vector2){544,415},48,1,ORANGE);
       
        DrawTextureEx(UIAssets.ButtonLong,(Vector2){640-UIAssets.ButtonLong.width*2.5,480},0.0f,5,RAYWHITE);
        DrawTextEx(UIAssets.Alagard,"Opcoes",(Vector2){562,495},50,1,ORANGE);
        
        DrawTextureEx(UIAssets.ButtonLong,(Vector2){640-UIAssets.ButtonLong.width*2.5,560},0.0f,5,RAYWHITE);
        DrawTextEx(UIAssets.Alagard,"Sair",(Vector2){594,575},50,1,ORANGE);
        
}

int MenuSelect(UI UIAssets,bool *OptWindow,float *SoundVolume){
    
    Rectangle StartGame = {640-UIAssets.ButtonLong.width*2.5,400,UIAssets.ButtonLong.width*5,UIAssets.ButtonLong.height*5};
    Rectangle Options =   {640-UIAssets.ButtonLong.width*2.5,480,UIAssets.ButtonLong.width*5,UIAssets.ButtonLong.height*5};
    Rectangle EndGame =   {640-UIAssets.ButtonLong.width*2.5,560,UIAssets.ButtonLong.width*5,UIAssets.ButtonLong.height*5};

    Vector2 Pointer = GetMousePosition();
    
    if(CheckCollisionPointRec(Pointer,StartGame)){
        if(IsMouseButtonReleased(MOUSE_LEFT_BUTTON)){
            PlaySound(UIAssets.ConfirmClick);
            return 1;
            //COMEÇAR JOGO
        }
    }
    if(CheckCollisionPointRec(Pointer,Options)){
        if(IsMouseButtonReleased(MOUSE_LEFT_BUTTON)){*OptWindow = !*OptWindow;PlaySound(UIAssets.Click);}
    }if(*OptWindow){
        DrawOpt(UIAssets,SoundVolume);
        ChangeVolume(SoundVolume, UIAssets);
        DrawTextEx(UIAssets.Alagard,"Musica",(Vector2){581,314},30,1,RAYWHITE);
    }
    if(CheckCollisionPointRec(Pointer,EndGame)){
        if(IsMouseButtonReleased(MOUSE_LEFT_BUTTON)){
            //FINALIZAR JOGO
            PlaySound(UIAssets.Click);
            exit(0);
        }
    }
    EndDrawing();
    return 0;
}