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

void MudaMusica(Sound song_anterior, Sound song_proximo){
	StopSound(song_anterior);
	PlaySound(song_proximo);
}