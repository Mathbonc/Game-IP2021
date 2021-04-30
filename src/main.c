#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include "assets.h"

void ParallaxMenu(float BGC, float FC1, float FC2, float FC3, Parallax Menu,UI UIAssets);
void MenuSelect(UI UIAssets,bool *OptWindow);

int main(){
    const int WindowWidth = 1280;
    const int WindowHeight = 720;
    InitWindow(WindowWidth,WindowHeight,"MainMenu");
    InitAudioDevice();
    SetTargetFPS(60);
    
    int i;
    
    //PARALLAX
    Parallax Menu;
    Menu.BackGroundSky = (Texture2D)LoadTexture("../Assets/UI/Parallax/sky_lightened.png");
    Menu.Mountains = (Texture2D)LoadTexture("../Assets/UI/Parallax/glacial_mountains_lightened.png");
    Menu.CloudsBG = (Texture2D)LoadTexture("../Assets/UI/Parallax/clouds_bg.png");
    Menu.CloudLone = (Texture2D)LoadTexture("../Assets/UI/Parallax/cloud_lonely.png");
    Menu.Cloud[0] = (Texture2D)LoadTexture("../Assets/UI/Parallax/clouds_mg_1_lightened.png");
    Menu.Cloud[1] = (Texture2D)LoadTexture("../Assets/UI/Parallax/clouds_mg_2.png");
    Menu.Cloud[2] = (Texture2D)LoadTexture("../Assets/UI/Parallax/clouds_mg_3.png");
    Menu.MainTitle = (Texture2D)LoadTexture("../Assets/UI/Title.png");
    //UI
    UI UIAssets = LoadUIAssets();
    bool OptWindow = false;
    //SCROLL
    scrolling cloudsScroll;
    cloudsScroll.BGC = 0.0f;
    cloudsScroll.FC1 = 0.0f;
    cloudsScroll.FC2 = 0.0f;
    cloudsScroll.FC3 = 0.0f;
    //MUSICS
    Menu.Music = (Music)LoadMusicStream("../Assets/Sample/Ludum Dare 38 - Track 2.wav");
    PlayMusicStream(Menu.Music);
    SetMusicVolume(Menu.Music,0.1);
    
    while(!WindowShouldClose()){
        UpdateMusicStream(Menu.Music);
        //Scrolling
        cloudsScroll.BGC-=0.2f;
        cloudsScroll.FC1+=0.4f;
        cloudsScroll.FC2-=0.3f;
        cloudsScroll.FC3+=0.2f;
        ParallaxMenu(cloudsScroll.BGC,cloudsScroll.FC1,cloudsScroll.FC2,cloudsScroll.FC3,Menu,UIAssets);
        MenuSelect(UIAssets,&OptWindow);
    }
    
    StopMusicStream(Menu.Music);
    UnloadMusicStream(Menu.Music);
    
    for(i=0;i<2;i++){UnloadTexture(Menu.Cloud[i]);}
    UnloadTexture(Menu.BackGroundSky);
    UnloadTexture(Menu.Mountains);
    UnloadTexture(Menu.CloudsBG);
    UnloadTexture(Menu.CloudLone);
    UnloadTexture(Menu.MainTitle);
    UnloadTexture(UIAssets.ButtonLong);
    UnloadFont(UIAssets.Alagard);
    UnloadSound(UIAssets.Click);
    UnloadTexture(UIAssets.OptFrame);
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
        DrawTextEx(UIAssets.Alagard,"Start",(Vector2){582,415},50,1,ORANGE);
       
        DrawTextureEx(UIAssets.ButtonLong,(Vector2){640-UIAssets.ButtonLong.width*2.5,480},0.0f,5,RAYWHITE);
        DrawTextEx(UIAssets.Alagard,"Options",(Vector2){555,495},50,1,ORANGE);
        
        DrawTextureEx(UIAssets.ButtonLong,(Vector2){640-UIAssets.ButtonLong.width*2.5,560},0.0f,5,RAYWHITE);
        DrawTextEx(UIAssets.Alagard,"Leave",(Vector2){573,575},50,1,ORANGE);
        
}

void MenuSelect(UI UIAssets,bool *OptWindow){
    
    Rectangle StartGame = {640-UIAssets.ButtonLong.width*2.5,400,UIAssets.ButtonLong.width*5,UIAssets.ButtonLong.height*5};
    Rectangle Options =   {640-UIAssets.ButtonLong.width*2.5,480,UIAssets.ButtonLong.width*5,UIAssets.ButtonLong.height*5};
    Rectangle EndGame =   {640-UIAssets.ButtonLong.width*2.5,560,UIAssets.ButtonLong.width*5,UIAssets.ButtonLong.height*5};

    Vector2 Pointer = GetMousePosition();
    
    if(CheckCollisionPointRec(Pointer,StartGame)){
        if(IsMouseButtonReleased(MOUSE_LEFT_BUTTON)){
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
        DrawTextEx(UIAssets.Alagard,"   Nothing\n to see here",(Vector2){549,328},30,1,RAYWHITE);
    }
    if(CheckCollisionPointRec(Pointer,EndGame)){
        if(IsMouseButtonReleased(MOUSE_LEFT_BUTTON)){
            //FINALIZAR JOGO
            PlaySound(UIAssets.Click);
            exit(0);
        }
    }
    EndDrawing();
}