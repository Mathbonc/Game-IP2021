#include "raylib.h"

typedef struct{
    int life;
    Vector2 position;
    float speed;
} Player;

int main(){
    int const windowWidth = 1260;
    int const windowHeight = 720;
    char last = ' ';
    
    InitWindow(windowWidth, windowHeight, "moviment");
    SetTargetFPS(60);
    
    Player rbns = {0};
    rbns.position = (Vector2){300.0f, 175.0f};
    rbns.speed = 5.4;
    rbns.life = 3;
    
    Texture2D background = LoadTexture("../bin/Map/map1.png");
    
    Texture2D rbnsTex = LoadTexture("../bin/Characters/Rubens/SpriteSheet/Warrior_SheetnoEffect.png");
    Texture2D rbnsTexRev = LoadTexture("../bin/Characters/Rubens/SpriteSheet/Warrior_SheetnoEffectRev.png");
    float frameWidth = (float)(rbnsTex.width/6);
    float frameHeight = (float)(rbnsTex.height/17);
    int maxFrames = (int)(rbnsTex.width/(int)frameWidth);
    
    float timer = 0.0f;
    int frame = 0;
   
    Camera2D camera;
    camera.target = (Vector2){rbns.position.x + 20.0f,rbns.position.y + 20.0f};
    camera.offset = (Vector2){windowWidth/2.0f, windowHeight/2.0f};
    camera.rotation = 0.0f;
    camera.zoom = 2.0f;
    
    while(!WindowShouldClose()){
        
        //Recebendo input do teclado e limitando input maximo
        if(rbns.position.x < background.width && rbns.position.x > 0 && rbns.position.y < background.height-50 && rbns.position.y > 0){
            if (IsKeyDown(KEY_D)) rbns.position.x += 1.0f * rbns.speed; 
            if (IsKeyDown(KEY_A)) rbns.position.x -= 1.0f * rbns.speed; 
            if (IsKeyDown(KEY_W)) rbns.position.y -= 1.0f * rbns.speed; 
            if (IsKeyDown(KEY_S)) rbns.position.y += 1.0f * rbns.speed; 
        }
        else{
            if(rbns.position.x >= background.width-70) rbns.position.x = 1780; 
            if(rbns.position.x <= 0) rbns.position.x = 1; 
            if(rbns.position.y >= background.height-50) rbns.position.y = 399;
            if(rbns.position.y <= 0) rbns.position.y = 1; 
        }
        
        timer += GetFrameTime();
        if(timer >= 0.2f){
            timer = 0.0f;
            frame += 1;
        }
        frame = frame % maxFrames;
        
        //Atualizando os parametros da camera
        camera.target = (Vector2){rbns.position.x + 20, rbns.position.y + 20};
        camera.zoom += ((float)GetMouseWheelMove()*0.05f);
        
        //Limitando o zoom da camera
        if (camera.zoom > 3.0f) camera.zoom = 3.0f;
        else if (camera.zoom < 2.0f) camera.zoom = 2.0f;
        //Limitando o deslocamento da camera
        if(camera.target.x<320) camera.target.x = 320;
        if(camera.target.x>1510) camera.target.x = 1510;
        if(camera.target.y<180) camera.target.y = 180;
        if(camera.target.y>270) camera.target.y = 270;
        
        BeginDrawing();
            ClearBackground(RAYWHITE); //(Color){255, 0, 255, 255} -> forma alternativa
            
            BeginMode2D(camera);
            
                DrawTexture(background, 0, 0, RAYWHITE);
                
                // 2 segundo parametro o Rectangle é a linha que vai ser desenhada, e o 4 a quantidade de linhas
                if (IsKeyDown(KEY_D)) {DrawTextureRec(rbnsTex, (Rectangle){frameWidth*frame, frameHeight*1, frameWidth, (float)frameHeight*1}, (Vector2){rbns.position.x, rbns.position.y}, RAYWHITE); last='d';}
                else if (IsKeyDown(KEY_A)) {DrawTextureRec(rbnsTexRev, (Rectangle){frameWidth*frame, frameHeight*1, frameWidth, (float)frameHeight*1}, (Vector2){rbns.position.x, rbns.position.y}, RAYWHITE); last='a';}
                else if (IsKeyDown(KEY_W) && last=='a') {DrawTextureRec(rbnsTexRev, (Rectangle){frameWidth*frame, frameHeight*1, frameWidth, (float)frameHeight*1}, (Vector2){rbns.position.x, rbns.position.y}, RAYWHITE); last='a';}
                else if (IsKeyDown(KEY_W) && !(last=='a')) {DrawTextureRec(rbnsTex, (Rectangle){frameWidth*frame, frameHeight*1, frameWidth, (float)frameHeight*1}, (Vector2){rbns.position.x, rbns.position.y}, RAYWHITE); last='d';}
                else if (IsKeyDown(KEY_S) && last=='a') {DrawTextureRec(rbnsTexRev, (Rectangle){frameWidth*frame, frameHeight*1, frameWidth, (float)frameHeight*1}, (Vector2){rbns.position.x, rbns.position.y}, RAYWHITE); last='a';}
                else if (IsKeyDown(KEY_S) && !(last=='a')) {DrawTextureRec(rbnsTex, (Rectangle){frameWidth*frame, frameHeight*1, frameWidth, (float)frameHeight*1}, (Vector2){rbns.position.x, rbns.position.y}, RAYWHITE); last='d';}
                else{
                    if(last=='a') DrawTextureRec(rbnsTexRev, (Rectangle){frameWidth*frame, frameHeight*0, frameWidth, (float)frameHeight*1}, (Vector2){rbns.position.x, rbns.position.y}, RAYWHITE);
                    else DrawTextureRec(rbnsTex, (Rectangle){frameWidth*frame, frameHeight*0, frameWidth, (float)frameHeight*1}, (Vector2){rbns.position.x, rbns.position.y}, RAYWHITE);
                }
            EndMode2D();
            
        EndDrawing();
    }
    UnloadTexture(background);
    UnloadTexture(rbnsTex);
    CloseWindow();
    return 0;
}