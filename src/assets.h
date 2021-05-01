#ifndef ASSETS_H
#define ASSETS_H
#define MenuScale 3.333
#include <raylib.h>

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
    Texture2D Cloud[3];
    Music Music;
}Parallax;
typedef struct{
    Texture2D ButtonLong;
    Texture2D OptFrame;
    Font Alagard;
    Sound Click;
    Sound ConfirmClick;
}UI;

UI LoadUIAssets();
void UnloadUIAssets (UI UIAssets);

Parallax LoadMenu();
void UnloadMenu(Parallax Menu);

void MudaMusica(Sound song_anterior, Sound song_proximo);


#endif