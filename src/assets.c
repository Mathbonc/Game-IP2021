#include "assets.h"
#include "raylib.h"
#include "moviment.h"
#include <stdio.h>

UI LoadUIAssets(){
    UI UIAssets;
    
    UIAssets.ButtonLong = (Texture2D) LoadTexture("../bin/UI/ButtonLong.png");
    UIAssets.OptFrame = (Texture2D) LoadTexture("../bin/UI/frame.png");
    UIAssets.Arrows = (Texture2D) LoadTexture("../bin/UI/Arrows.png");
    UIAssets.SoundBar = (Texture2D) LoadTexture("../bin/UI/SoundBar.png");
    UIAssets.Alagard = (Font) LoadFont("../fonts/alagard.ttf");
    UIAssets.Click =(Sound) LoadSound("../bin/Sample/Interface/Back_tones/style2/back_style_2_004.wav");
    UIAssets.ConfirmClick = (Sound) LoadSound("../bin/Sample/Interface/Confirm_tones/style2/confirm_style_2_echo_001.wav");
    
    return UIAssets;
}
void UnloadUIAssets(UI UIAssets){
    UnloadTexture(UIAssets.ButtonLong);
    UnloadTexture(UIAssets.OptFrame);
    UnloadTexture(UIAssets.Arrows);
    UnloadTexture(UIAssets.SoundBar);
    UnloadFont(UIAssets.Alagard);
    UnloadSound(UIAssets.Click);
    UnloadSound(UIAssets.ConfirmClick);
}

Parallax LoadMenu(){
    Parallax Menu;
    
    Menu.BackGroundSky = (Texture2D)LoadTexture("../bin/UI/Parallax/sky_lightened.png");
    Menu.Mountains = (Texture2D)LoadTexture("../bin/UI/Parallax/glacial_mountains_lightened.png");
    Menu.CloudsBG = (Texture2D)LoadTexture("../bin/UI/Parallax/clouds_bg.png");
    Menu.CloudLone = (Texture2D)LoadTexture("../bin/UI/Parallax/cloud_lonely.png");
    Menu.Cloud[0] = (Texture2D)LoadTexture("../bin/UI/Parallax/clouds_mg_1_lightened.png");
    Menu.Cloud[1] = (Texture2D)LoadTexture("../bin/UI/Parallax/clouds_mg_2.png");
    Menu.Cloud[2] = (Texture2D)LoadTexture("../bin/UI/Parallax/clouds_mg_3.png");
    Menu.MainTitle = (Texture2D)LoadTexture("../bin/UI/Title.png");
    Menu.Music = (Music) LoadMusicStream("../bin/Sample/Music/Ludum Dare 38 - Track 2.wav");
    
    return Menu;
}
void UnloadMenu(Parallax Menu){
    int i;
    for(i=0;i<2;i++){UnloadTexture(Menu.Cloud[i]);}
    UnloadTexture(Menu.BackGroundSky);
    UnloadTexture(Menu.Mountains);
    UnloadTexture(Menu.CloudsBG);
    UnloadTexture(Menu.CloudLone);
    UnloadTexture(Menu.MainTitle);
    UnloadMusicStream(Menu.Music);
}

void MudaMusica(Music song_anterior, Music song_proximo){
	StopMusicStream(song_anterior);
	PlayMusicStream(song_proximo);
}
UIIG LoadUIIG(){
    UIIG InGameUI;
    
    InGameUI.HealthBar = (Texture2D) LoadTexture("../bin/UI/graybar.png");
    InGameUI.Pause = (Texture2D) LoadTexture("../bin/UI/pause_button.png");
    InGameUI.MenuPause = (Texture2D) LoadTexture("../bin/UI/pause_menu.png");
    InGameUI.PauseSound = (Sound) LoadSound("../bin/Sample/Interface/Cursor_tones/cursor_style_2.wav");
    InGameUI.Attack = (Sound) LoadSound("../bin/Sample/Music/Sword Hit.wav");
    InGameUI.GameMusic1 = (Music) LoadMusicStream("../bin/Sample/Music/DavidKBD - HexaPuppies Pack - 02 - Meet the HexaPuppies - 1.ogg");
    InGameUI.GameMusic2 = (Music) LoadMusicStream("../bin/Sample/Music/Ludum Dare 38 - Track 8.wav");
    InGameUI.FredTheme = (Music) LoadMusicStream("../bin/Sample/Music/Ludum Dare 38 - Track 10.wav");
    InGameUI.GameCombat = (Music) LoadMusicStream("../bin/Sample/Music/Ludum Dare 38 - Track 4.wav");
    
    return InGameUI;
}
void UnloadUIIG(UIIG InGameUI){
    UnloadTexture(InGameUI.HealthBar);
    UnloadTexture(InGameUI.Pause);
    UnloadTexture(InGameUI.MenuPause);
    UnloadSound(InGameUI.PauseSound);
    UnloadSound(InGameUI.Attack);
    UnloadMusicStream(InGameUI.GameMusic1);
    UnloadMusicStream(InGameUI.GameMusic2);
    UnloadMusicStream(InGameUI.FredTheme);
    UnloadMusicStream(InGameUI.GameCombat);
}
//INCLUIR VIDA NESSA FUNÇÃO!!!
void DrawGameUI(bool *GamePause, UIIG InGameUI,UIRECS MenuRects, Player rbns, float *SoundVolume, UI UIAssets, bool *OptWindow){
    int soundButton = 0;
    if(IsKeyPressed(KEY_K) || IsKeyPressed(KEY_L)){PlaySound(InGameUI.Attack);}
    if(CheckCollisionPointRec((Vector2)GetMousePosition(),(Rectangle){1224,24,InGameUI.Pause.width*2.2,InGameUI.Pause.height*2.2})){
        if(IsMouseButtonReleased(MOUSE_LEFT_BUTTON)){*GamePause = !*GamePause;soundButton=1;}
    }
    DrawTexturePro(InGameUI.HealthBar,
                    (Rectangle){0,0,InGameUI.HealthBar.width,InGameUI.HealthBar.height},
                    (Rectangle){80,40,InGameUI.HealthBar.width*2,InGameUI.HealthBar.height*2},
                    (Vector2){InGameUI.HealthBar.width/2,InGameUI.HealthBar.height/2},
                    0.0f,RAYWHITE);
    
    Rectangle GreenBar = {44.5,37,InGameUI.HealthBar.width*1.82*(rbns.life/200.0),InGameUI.HealthBar.height*1.6};
    DrawRectangleRec(GreenBar,GREEN);
    
    DrawTexturePro(InGameUI.Pause,
                    (Rectangle){0,0,InGameUI.Pause.width,InGameUI.Pause.height},
                    (Rectangle){1230,30,InGameUI.Pause.width*2.2,InGameUI.Pause.height*2.2},
                    (Vector2){InGameUI.Pause.width/2,InGameUI.Pause.height/2},
                    0.0f, RAYWHITE);
    if(*GamePause){
        DrawTexturePro(InGameUI.MenuPause,
                        (Rectangle){0,0,InGameUI.MenuPause.width,InGameUI.MenuPause.height},
                        (Rectangle){640-(InGameUI.MenuPause.width),360-(InGameUI.MenuPause.height),InGameUI.MenuPause.width*4,InGameUI.MenuPause.height*4},
                        (Vector2){InGameUI.MenuPause.width,InGameUI.MenuPause.height},
                        0.0f,RAYWHITE);
        if(CheckCollisionPointRec((Vector2)GetMousePosition(),MenuRects.START)){
            if(IsMouseButtonReleased(MOUSE_LEFT_BUTTON)){*GamePause = !*GamePause;soundButton=1;}
        }
        if(CheckCollisionPointRec((Vector2)GetMousePosition(),MenuRects.OPT)){
            if(IsMouseButtonReleased(MOUSE_LEFT_BUTTON)){*OptWindow = !*OptWindow;}
        }        
        if(CheckCollisionPointRec((Vector2)GetMousePosition(),MenuRects.EXIT)){
            if(IsMouseButtonReleased(MOUSE_LEFT_BUTTON)){
                exit(0);
            }
        }
        if(*OptWindow){
            DrawOpt(UIAssets,SoundVolume);
            ChangeVolume(SoundVolume, UIAssets);
            DrawTextEx(UIAssets.Alagard,"Musica",(Vector2){581,314},30,1,RAYWHITE);
        }
    }
    if(soundButton==1){PlaySound(InGameUI.PauseSound);}
}

Texture2D *LoadrbnsTex(){
    Texture2D rbnsTex[5];
    rbnsTex[0] = LoadTexture("../bin/Characters/Rubens/SpriteSheet/Warrior_Idle.png"); //Idle Texture
    rbnsTex[1] = LoadTexture("../bin/Characters/Rubens/SpriteSheet/Warrior_Run.png"); //Run Texture
    rbnsTex[2] = LoadTexture("../bin/Characters/Rubens/SpriteSheet/Warrior_Die.png"); //Die Texture
    rbnsTex[3] = LoadTexture("../bin/Characters/Rubens/SpriteSheet/Warrior_AttackLtt.png"); //Attack Texture
    rbnsTex[4] = LoadTexture("../bin/Characters/Rubens/SpriteSheet/Warrior_AttackLtt2.png"); //Attack Texture 2
    
    return rbnsTex;
}
UIRECS DefineUIRECTS(){
    UIRECS MenuRects;
    MenuRects.EXIT = (Rectangle){580,400,120,50};
    MenuRects.OPT = (Rectangle){580,335,120,50};
    MenuRects.START = (Rectangle){580,270,120,50};
    return MenuRects;
}
void DrawOpt(UI UIAssets,float *SoundVolume){
    DrawTexturePro(UIAssets.OptFrame,
                    (Rectangle){0,0,UIAssets.OptFrame.width,UIAssets.OptFrame.height},
                    (Rectangle){(640-UIAssets.OptFrame.width*5), (360-UIAssets.OptFrame.height*3), (UIAssets.OptFrame.width*10),(UIAssets.OptFrame.height*6)},
                    (Vector2){0,0},   
                    0.0f,RAYWHITE);
    DrawTexturePro(UIAssets.SoundBar,
                    (Rectangle){0,0,UIAssets.SoundBar.width,UIAssets.SoundBar.height/2},
                    (Rectangle){640-UIAssets.SoundBar.width*2.5,360-(UIAssets.SoundBar.height/2),UIAssets.SoundBar.width*5,(UIAssets.SoundBar.height*4/2)},
                    (Vector2){(UIAssets.SoundBar.width/2.5)-10,UIAssets.SoundBar.height/4},
                    0.0f,RAYWHITE);  
    DrawTexturePro(UIAssets.SoundBar,
                    (Rectangle){0,UIAssets.SoundBar.height/2,UIAssets.SoundBar.width*(*SoundVolume/0.5),UIAssets.SoundBar.height/2},
                    (Rectangle){640-UIAssets.SoundBar.width*2.5,360-(UIAssets.SoundBar.height/2)-8,UIAssets.SoundBar.width*5*(*SoundVolume/0.5),(UIAssets.SoundBar.height*4/2)},
                    (Vector2){(UIAssets.SoundBar.width/2.5)-10,UIAssets.SoundBar.height/4},
                    0.0f,RAYWHITE);
    DrawTexturePro(UIAssets.Arrows,
                    (Rectangle){0,0,UIAssets.Arrows.width/3,UIAssets.Arrows.height},
                    (Rectangle){570-(UIAssets.Arrows.width*8/4),372-(UIAssets.Arrows.height*10/4),UIAssets.Arrows.width*2,UIAssets.Arrows.height*6},
                    (Vector2){UIAssets.Arrows.width*8/4,UIAssets.Arrows.height*6/4},
                    0.0f,RAYWHITE);
    DrawTexturePro(UIAssets.Arrows,
                    (Rectangle){UIAssets.Arrows.width*2/3,0,UIAssets.Arrows.width/3,UIAssets.Arrows.height},
                    (Rectangle){749+(UIAssets.Arrows.width*8/4),372-(UIAssets.Arrows.height*10/4),UIAssets.Arrows.width*2,UIAssets.Arrows.height*6},
                    (Vector2){UIAssets.Arrows.width*8/4,UIAssets.Arrows.height*6/4},
                    0.0f,RAYWHITE);
}
void ChangeVolume(float *SoundVolume, UI UIAssets){
    bool soundButton =0;
    Rectangle VolumeDown = {475,345,40,40};
    Rectangle VolumeUp = {755,345,40,40};
    if(CheckCollisionPointRec((Vector2)GetMousePosition(),VolumeDown)){
        if(IsMouseButtonReleased(MOUSE_LEFT_BUTTON)){
            soundButton = !soundButton;
            (*SoundVolume)-=0.1;
            if((*SoundVolume)<=0.0){(*SoundVolume)=0.0;}
        }
    }
    if(CheckCollisionPointRec((Vector2)GetMousePosition(),VolumeUp)){
        if(IsMouseButtonReleased(MOUSE_LEFT_BUTTON)){
            soundButton = !soundButton;
            (*SoundVolume)+=0.1;
            if((*SoundVolume)>=0.5){(*SoundVolume)=0.5;}
        }
    }
    if(soundButton){PlaySound(UIAssets.Click);}
}

