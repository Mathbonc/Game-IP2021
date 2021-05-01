#include "assets.h"
#include "raylib.h"
#include <stdio.h>

UI LoadUIAssets(){
    UI UIAssets;
    
    UIAssets.ButtonLong = (Texture2D) LoadTexture("../bin/UI/ButtonLong.png");
    UIAssets.OptFrame = (Texture2D) LoadTexture("../bin/UI/frame.png");
    UIAssets.Alagard = (Font) LoadFont("../fonts/alagard.ttf");
    UIAssets.Click =(Sound) LoadSound("../bin/Sample/Interface/Back_tones/style2/back_style_2_004.wav");
    UIAssets.ConfirmClick = (Sound) LoadSound("../bin/Sample/Interface/Confirm_tones/style2/confirm_style_2_echo_001.wav");
    
    return UIAssets;
}
void UnloadUIAssets(UI UIAssets){
    UnloadTexture(UIAssets.ButtonLong);
    UnloadTexture(UIAssets.OptFrame);
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
}
//INCLUIR VIDA NESSA FUNÇÃO!!!
void DrawGameUI(bool *GamePause, UIIG InGameUI){
    int soundButton = 0;
    if(CheckCollisionPointRec((Vector2)GetMousePosition(),(Rectangle){1224,24,InGameUI.Pause.width*2.2,InGameUI.Pause.height*2.2})){
        if(IsMouseButtonReleased(MOUSE_LEFT_BUTTON)){*GamePause = !*GamePause;soundButton=1;}
    }
    if(soundButton==1){PlaySound(InGameUI.PauseSound);}
    DrawTexturePro(InGameUI.HealthBar,
                    (Rectangle){0,0,InGameUI.HealthBar.width,InGameUI.HealthBar.height},
                    (Rectangle){80,40,InGameUI.HealthBar.width*2,InGameUI.HealthBar.height*2},
                    (Vector2){InGameUI.HealthBar.width/2,InGameUI.HealthBar.height/2},
                    0.0f,RAYWHITE);
    
    Rectangle GreenBar = {44.5,37,InGameUI.HealthBar.width*1.82*(Health/200),InGameUI.HealthBar.height*1.6};
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
        
    }
}