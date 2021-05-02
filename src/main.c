#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include "moviment.h"
#include "assets.h"

void ParallaxMenu(float BGC, float FC1, float FC2, float FC3, Parallax Menu,UI UIAssets);
int MenuSelect(UI UIAssets,bool *OptWindow);

int main(){
    const int WindowWidth = 1280;
    const int WindowHeight = 720;
    const int windowWidth = 1280;
    const int windowHeight = 720;
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
    //SCROLL
    scrolling cloudsScroll;
    cloudsScroll.BGC = 0.0f;
    cloudsScroll.FC1 = 0.0f;
    cloudsScroll.FC2 = 0.0f;
    cloudsScroll.FC3 = 0.0f;
    //MUSICS
    PlayMusicStream(Menu.Music);
    SetMusicVolume(Menu.Music,0.1);
    
    while(GameStage==0){
        UpdateMusicStream(Menu.Music);
        //Scrolling
        cloudsScroll.BGC-=0.2f;
        cloudsScroll.FC1+=0.4f;
        cloudsScroll.FC2-=0.3f;
        cloudsScroll.FC3+=0.2f;
        ParallaxMenu(cloudsScroll.BGC,cloudsScroll.FC1,cloudsScroll.FC2,cloudsScroll.FC3,Menu,UIAssets);
        GameStage = MenuSelect(UIAssets,&OptWindow);
    }
    if(GameStage==1){
        MudaMusica(Menu.Music,InGameUI.GameMusic1);
        SetMusicVolume(InGameUI.GameMusic1,0.1);
        
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
        
        Texture2D itensTex = LoadTexture("../bin/Itens/canetaverm.png");
        
        Texture2D background = LoadTexture("../bin/Map/fullmap.png");
        
        float timer = 0.0f;
        int frame = 0, frameDie = 0, frameAtk = 0;
        
        Camera2D camera;
        camera.target = (Vector2){rbns.position.x + 20.0f,rbns.position.y + 20.0f};
        camera.offset = (Vector2){windowWidth/2.0f, windowHeight/2.0f};
        camera.rotation = 0.0f;
        camera.zoom = 2.0f;
        
        while(GameStage==1){
            UpdateMusicStream(InGameUI.GameMusic1);
            BeginDrawing();
            Game(&rbns, guard, storm, extras, obst, rbnsTex, guardTex, stormTex, itensTex, &camera, &frame, &last, &timer, background);
            DrawGameUI(&GamePause, InGameUI, MenuRects, rbns);
            EndDrawing();
        }
    }
    
    
    StopMusicStream(Menu.Music);
    
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

int MenuSelect(UI UIAssets,bool *OptWindow){
    
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
        DrawTexturePro(UIAssets.OptFrame,
                        (Rectangle){0,0,UIAssets.OptFrame.width,UIAssets.OptFrame.height},
                        (Rectangle){(640-UIAssets.OptFrame.width*3), (360-UIAssets.OptFrame.height*2), (UIAssets.OptFrame.width*6),(UIAssets.OptFrame.height*4)},
                        (Vector2){0,0},   
                        0.0f,RAYWHITE);
        DrawTextEx(UIAssets.Alagard,"  Nada pra\n  ver aqui",(Vector2){549,328},30,1,RAYWHITE);
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