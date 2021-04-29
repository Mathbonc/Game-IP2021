#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    float BGC; 
    float FC1; 
    float FC2;
    float FC3;
}scrolling;
typedef struct{
    Texture2D BackGroundSky;
    Texture2D Mountains;
    Texture2D CloudsBG;
    Texture2D CloudLone;
    Texture2D MainTitle;
}Parallax;
typedef struct{
    Texture2D ButtonLong;
    Texture2D OptFrame;
    Font Alagard;
    Sound Click;
}UI;

void ParallaxMenu(float BGC, float FC1, float FC2, float FC3, float MenuScale, Texture2D *Cloud, Parallax Menu,UI button);
void MenuSelect(UI button,bool *OptWindow);

int main(){
    const int WindowWidth = 1280;
    const int WindowHeight = 720;
    InitWindow(WindowWidth,WindowHeight,"MainMenu");
    InitAudioDevice();
    SetTargetFPS(60);
    
    int i;
    float MenuScale=3.333;
    //PARALLAX
    Parallax Menu;
    Menu.BackGroundSky = (Texture2D)LoadTexture("../Assets/UI/Parallax/sky_lightened.png");
    Menu.Mountains = (Texture2D)LoadTexture("../Assets/UI/Parallax/glacial_mountains_lightened.png");
    Menu.CloudsBG = (Texture2D)LoadTexture("../Assets/UI/Parallax/clouds_bg.png");
    Menu.CloudLone = (Texture2D)LoadTexture("../Assets/UI/Parallax/cloud_lonely.png");
    Texture2D Cloud[3];
            Cloud[0] = (Texture2D)LoadTexture("../Assets/UI/Parallax/clouds_mg_1_lightened.png");
            Cloud[1] = (Texture2D)LoadTexture("../Assets/UI/Parallax/clouds_mg_2.png");
            Cloud[2] = (Texture2D)LoadTexture("../Assets/UI/Parallax/clouds_mg_3.png");
    Menu.MainTitle = (Texture2D)LoadTexture("../Assets/UI/Title.png");
    //UI
    UI button;
    button.ButtonLong = LoadTexture("../Assets/UI/ButtonLong.png");
    button.OptFrame = LoadTexture("../Assets/UI/frame.png");
    button.Alagard = LoadFont("../fonts/alagard.ttf");
    button.Click = LoadSound("../Assets/Sample/back_style_2_004.wav");
    bool OptWindow = false;
    //SCROLL
    scrolling cloudsScroll;
    cloudsScroll.BGC = 0.0f;
    cloudsScroll.FC1 = 0.0f;
    cloudsScroll.FC2 = 0.0f;
    cloudsScroll.FC3 = 0.0f;
    //MSUICS
    Music MenuMusic = LoadMusicStream("../Assets/Sample/Ludum Dare 38 - Track 2.wav");
    PlayMusicStream(MenuMusic);
    SetMusicVolume(MenuMusic,0.1);
    
    while(!WindowShouldClose()){
        UpdateMusicStream(MenuMusic);
        //Scrolling
        cloudsScroll.BGC-=0.2f;
        cloudsScroll.FC1+=0.4f;
        cloudsScroll.FC2-=0.3f;
        cloudsScroll.FC3+=0.2f;
        ParallaxMenu(cloudsScroll.BGC,cloudsScroll.FC1,cloudsScroll.FC2,cloudsScroll.FC3,MenuScale,Cloud,Menu,button);
        MenuSelect(button,&OptWindow);
    

    }
    
    StopMusicStream(MenuMusic);
    UnloadMusicStream(MenuMusic);
    CloseAudioDevice();
    
    for(i=0;i<2;i++){UnloadTexture(Cloud[i]);}
    UnloadTexture(Menu.BackGroundSky);
    UnloadTexture(Menu.Mountains);
    UnloadTexture(Menu.CloudsBG);
    UnloadTexture(Menu.CloudLone);
    UnloadTexture(Menu.MainTitle);
    UnloadTexture(button.ButtonLong);
    UnloadFont(button.Alagard);
    UnloadSound(button.Click);
    UnloadTexture(button.OptFrame);
    CloseWindow();
    return 0;
}

void ParallaxMenu(float BGC, float FC1, float FC2, float FC3, float MenuScale, Texture2D *Cloud, Parallax Menu,UI button){
    if(BGC <= -Menu.CloudsBG.width*MenuScale){BGC=0;}
    if(FC1 >= Cloud[0].width*MenuScale){FC1=0;}
    if(FC2 <= -Cloud[1].width*MenuScale){FC2=0;}
    if(FC1 >= Cloud[2].width*MenuScale){FC3=0;}
    
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
        DrawTextureEx(Cloud[2],(Vector2){FC3,0},0.0f,MenuScale,RAYWHITE);
        DrawTextureEx(Cloud[2],(Vector2){(-Cloud[2].width*MenuScale)+FC3,0},0.0f,MenuScale,RAYWHITE);
        //MID CLOUDS
        DrawTextureEx(Cloud[1],(Vector2){FC2,0},0.0f,MenuScale,RAYWHITE);
        DrawTextureEx(Cloud[1],(Vector2){(Cloud[1].width*MenuScale)+FC2,0},0.0f,MenuScale,RAYWHITE);
        //FRONT CLOUDS
        DrawTextureEx(Cloud[0],(Vector2){FC1,0},0.0f,MenuScale,RAYWHITE);
        DrawTextureEx(Cloud[0],(Vector2){(-Cloud[0].width*MenuScale)+FC1,0},0.0f,MenuScale,RAYWHITE);
        //TITLE
        DrawTextureEx(Menu.MainTitle,(Vector2){640-Menu.MainTitle.width*1.25,-50},0.0f,2.5,RAYWHITE);
        //UI
        DrawTextureEx(button.ButtonLong,(Vector2){640-button.ButtonLong.width*2.5,400},0.0f,5,RAYWHITE);
        DrawTextEx(button.Alagard,"Start",(Vector2){582,415},50,1,ORANGE);
       
        DrawTextureEx(button.ButtonLong,(Vector2){640-button.ButtonLong.width*2.5,480},0.0f,5,RAYWHITE);
        DrawTextEx(button.Alagard,"Options",(Vector2){555,495},50,1,ORANGE);
        
        DrawTextureEx(button.ButtonLong,(Vector2){640-button.ButtonLong.width*2.5,560},0.0f,5,RAYWHITE);
        DrawTextEx(button.Alagard,"Leave",(Vector2){573,575},50,1,ORANGE);
        
}

void MenuSelect(UI button,bool *OptWindow){
    
    Rectangle StartGame = {640-button.ButtonLong.width*2.5,400,button.ButtonLong.width*5,button.ButtonLong.height*5};
    Rectangle Options =   {640-button.ButtonLong.width*2.5,480,button.ButtonLong.width*5,button.ButtonLong.height*5};
    Rectangle EndGame =   {640-button.ButtonLong.width*2.5,560,button.ButtonLong.width*5,button.ButtonLong.height*5};

    Vector2 Pointer = GetMousePosition();
    
    if(CheckCollisionPointRec(Pointer,StartGame)){
        if(IsMouseButtonReleased(MOUSE_LEFT_BUTTON)){
            //COMEÇAR JOGO
        }
    }
    if(CheckCollisionPointRec(Pointer,Options)){
        if(IsMouseButtonReleased(MOUSE_LEFT_BUTTON)){*OptWindow = !*OptWindow;}
    }if(*OptWindow){
        DrawTexturePro(button.OptFrame,
                        (Rectangle){0,0,button.OptFrame.width,button.OptFrame.height},
                        (Rectangle){(640-button.OptFrame.width*3), (360-button.OptFrame.height*2), (button.OptFrame.width*6),(button.OptFrame.height*4)},
                        (Vector2){0,0},   
                        0.0f,RAYWHITE);
        DrawTextEx(button.Alagard,"   Nothing\n to see here",(Vector2){549,328},30,1,RAYWHITE);
    }
    if(CheckCollisionPointRec(Pointer,EndGame)){
        if(IsMouseButtonReleased(MOUSE_LEFT_BUTTON)){
            //FINALIZAR JOGO
            PlaySound(button.Click);
            exit(0);
        }
    }
    EndDrawing();
}