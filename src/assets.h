#ifndef ASSETS_H
#define ASSETS_H

#include <raylib.h>
#include "moviment.h"
#define MenuScale 3.333
#define HITS 80
#define Health 200

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

typedef struct{
    Texture2D HealthBar;
    Texture2D Pause;
    Texture2D MenuPause;
    Sound PauseSound;
    Music GameMusic1;
    Music GameMusic2;
    Music FredTheme;
    Music GameCombat;
}UIIG;

typedef struct{
    Rectangle START;
    Rectangle OPT;
    Rectangle EXIT;
}UIRECS;

UI LoadUIAssets();
void UnloadUIAssets (UI UIAssets);

Parallax LoadMenu();
void UnloadMenu(Parallax Menu);

void MudaMusica(Music song_anterior, Music song_proximo);

UIIG LoadUIIG();
void UnloadUIIG(UIIG InGameUI);

UIRECS DefineUIRECTS();

void DrawGameUI(bool *GamePause, UIIG InGameUI, UIRECS MenuRects, Player rbns);
#endif