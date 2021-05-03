#include "raylib.h"
#include "combate.h"
#include "moviment.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
typedef struct{ //Struct para os ataques de Rubens
    int Questao_complicada, Correcao_errada, Nota_Errada, Questao_Oral;
} ataques_rubens;

typedef struct{ //Struct para os ataques do aluno
    int acertar_questao, discutir_questao, chamar_no_zap;
} ataques_aluno;

typedef struct {
	Sound musica[10];
}mus;

typedef struct{
    Texture2D Rubens[4];
}player;
*/

void MenudeRubens(ataques_rubens ataques, int *vida_estudante, int vida_Rubens, int *opRubens,Player rbns){
    int valorizador = 1;
    
    DrawText("Escolha um ataque: \nQuestao_Complicada(J)\nCorrecao Errada(K)\nNota Errada(L)\nQuestao Oral(M)\n",rbns.position.x-200,rbns.position.y+100,12,DARKBLUE);
    if(vida_Rubens <= 100) valorizador = 1.2;
    if(vida_Rubens <= 50) valorizador = 1.5;
    if(vida_Rubens <= 30) valorizador = 2;
    
    if(IsKeyPressed(KEY_J)){
        *vida_estudante -= valorizador * ataques.Questao_complicada;
        *opRubens = 1;
    }else if(IsKeyPressed(KEY_K)){
        *vida_estudante -= valorizador * ataques.Correcao_errada;
        *opRubens = 2;
        
    }else if(IsKeyPressed(KEY_L)){
        *vida_estudante -= valorizador * ataques.Nota_Errada;
        *opRubens = 3;

    }else if(IsKeyPressed(KEY_M)){
        *vida_estudante -= valorizador * ataques.Questao_Oral;
        *opRubens = 4;
    }else *opRubens = 0;
}

void MenuCombatFreddy(ataques_rubens ataques, int *vida_estudante, int vida_Rubens, int *opRubens, int opFreddy,Player rbns){
    int valorizador = 1; int contra_ataque1 = 1, contra_ataque2 = 1, contra_ataque3 = 1, contra_ataque4 = 1;
    DrawText("Escolha um ataque: \nQuestao_Complicada(J)\nCorrecao Errada(K)\nNota Errada(L)\nQuestao Oral(M)\n",rbns.position.x,rbns.position.y,8,DARKBLUE);
    if(vida_Rubens <= 100) valorizador = 1.2;
    if(vida_Rubens <= 50) valorizador = 1.5;
    if(vida_Rubens <= 30) valorizador = 2;
    switch (opFreddy){
        case 1:
            contra_ataque2 = 1.5;
            contra_ataque3 = 1.6;
            break;
        case 2:
            contra_ataque4 = 1.3;
            break;
        case 3:
            contra_ataque4 = 1.3;
            break;
        default:
            break;
        }
    if(IsKeyPressed(KEY_J)){
        *vida_estudante -= valorizador * ataques.Questao_complicada * contra_ataque1;
        *opRubens = 1;   
    }else if(IsKeyPressed(KEY_K)){
        *vida_estudante -= valorizador * ataques.Correcao_errada * contra_ataque2;
        *opRubens = 2;
    }else if(IsKeyPressed(KEY_L)){
        *vida_estudante -= valorizador * ataques.Nota_Errada * contra_ataque3;
        *opRubens = 3;
    }else if(IsKeyPressed(KEY_M)){
        *vida_estudante -= valorizador * ataques.Questao_Oral * contra_ataque4;
        *opRubens = 4;
    }else *opRubens = 0;
}

//Funcao de trocar a musica de combate (Vai ser utilizada quando chamar a funcao de combate do freddy

void TrocaMusicaCombate(Sound musica_anterior, Sound musica_proxima){
    StopSound(musica_anterior);
    PlaySound(musica_proxima);       
}

void Rubens_atack(Texture2D warrior, Vector2 position, int frame, float timer, float framewidth, float frameheight, float cordx, float *cordy, int *cont, int maxFrames){ 
    //O usu?rio deve executar o comando BeginDrawing antes de chamar a fun??o   
    frame= frame % maxFrames;
    cordx=(framewidth*frame);
    Rectangle framerec = {cordx, (*cordy), (float)framewidth, (float)frameheight};
    if(frame==5){
        *cordy=(*cordy)+frameheight;
        
    }
    if(((*cordy)/frameheight)==4){
        (*cont)++;
        if(*cont==3){
            frame = 2;
            *cont= 0;
            *cordy= frameheight*2;
        }
    }
    DrawTextureRec(warrior, framerec ,position, RAYWHITE);
    /*Escrever o seguinte c?digo na main antes de chamar a fun??o:
    timer += GetFrameTime();
    if(timer>=0.01f){
        timer =0.0f;
        frame+=1;
    }*/
}
//combate leonidas
void Combat_LeaoNidas(Player *rbns,int *Falas, int *INIMIGOS){
    int vida_de_rubens = rbns->life;
    static int i=0;
    static int vida_de_leao = 200, opRubens, opAluno, contra_ataque1, contra_ataque2, contra_ataque3;
    ataques_rubens ataqueRubens; ataques_aluno ataqueLeao;
    ataqueRubens.Questao_complicada = 30; ataqueRubens.Correcao_errada = 20;
    ataqueRubens.Nota_Errada = 20; ataqueRubens.Questao_Oral = 10;
    ataqueLeao.acertar_questao = 10; ataqueLeao.discutir_questao = 15;
    ataqueLeao.chamar_no_zap = 20;
    
    if(i!=0){
        if(i==1){
            DrawText("Acertei a questao!",1750.0f,175.0f,8,RED);
        }else if(i==2){
            DrawText("Discuti questao!",1750.0f,175.0f,8,BLUE);    
        }else if(i==3){
            DrawText("Chamei no Zap!",1750.0f,175.0f,8,GREEN);
        }
    }
        
    if(vida_de_leao > 0 && vida_de_rubens > 0){
        contra_ataque1 = 1; contra_ataque2 = 1; contra_ataque3 = 1;       
        MenudeRubens(ataqueRubens,&vida_de_leao, vida_de_rubens, &opRubens, *rbns);
        switch (opRubens){
        case 1: 
            contra_ataque2 = 1.3;
            break;
        case 2:
            contra_ataque3 = 1.4;
            break;
        case 3:
            contra_ataque3 = 1.5;
            break;
        default:
            break;
        }
        if(vida_de_leao>0 && (opRubens)!=0){
            //menu de opcoes para aluno
            //srand((unsigned)time(NULL));
            /*do{
                opAluno =  (rand() % 10);
            }while(opAluno < 1 || opAluno > 3);*/
            opAluno=GetRandomValue(1, 3);
            switch (opAluno){
            case 1:
                vida_de_rubens -= contra_ataque1 * ataqueLeao.acertar_questao;
                i=1;
                break;
            case 2:
                vida_de_rubens -= contra_ataque2 * ataqueLeao.discutir_questao;
                i=2;           
                break;
            case 3:
                vida_de_rubens -= contra_ataque3 * ataqueLeao.chamar_no_zap;               
                i=3;
                break;
            default:
                break;
            }
            
        }
    }
    DrawText(TextFormat("Vida de Leao Nidas: %d", vida_de_leao),1750.0f, 165.0f,8,SKYBLUE);
    rbns->life = vida_de_rubens;
    if(vida_de_rubens>0 && vida_de_leao<=0){
        *Falas=1;
        DrawText("Pressione T para passar de fase, após o diálogo",rbns->position.x-100,rbns->position.y-80,8,DARKGREEN);
        if(IsKeyPressed(KEY_T)){
            *INIMIGOS=1;
            rbns->position.x=2700;
            rbns->position.y=175;
        }
    }
}

//Combate Ro Brigo
void Combat_RoBrigo(Player *rbns, int *Falas, int *INIMIGOS){
    int vida_de_rubens = rbns->life;
    static int i=0;
    static int vida_de_Robrigo= 210, opRubens, opAluno, contra_ataque1, contra_ataque2, contra_ataque3;
    ataques_rubens ataqueRubens; ataques_aluno ataqueRobrigo;
    ataqueRubens.Questao_complicada = 10; ataqueRubens.Correcao_errada = 10;
    ataqueRubens.Nota_Errada = 20; ataqueRubens.Questao_Oral = 30;
    ataqueRobrigo.acertar_questao = 15; 
    ataqueRobrigo.discutir_questao = 20;
    ataqueRobrigo.chamar_no_zap = 10;
    
    if(i!=0){
        if(i==1){
            DrawText("Acertei a questao!",4330.0f,175.0f,8,RED);
        }else if(i==2){
            DrawText("Discuti questao!",4330.0f,175.0f,8,BLUE);    
        }else if(i==3){
            DrawText("Chamei no Zap!",4330.0f,175.0f,8,GREEN);
        }else if(i==4){
            DrawText("ESPECIAL TERMO TECNICO-CIENTIFICO!",4330.0f,175.0f,8,YELLOW);    
        }
    }
    
    if(vida_de_Robrigo > 0 && vida_de_rubens > 0){
        contra_ataque1 = 1; contra_ataque2 = 1; contra_ataque3 = 1;
        MenudeRubens(ataqueRubens , &vida_de_Robrigo, vida_de_rubens, &opRubens,*rbns);
        switch (opRubens){
        case 1:
            contra_ataque2 = 1.3;
            break;
        case 2:
            contra_ataque3 = 1.4;
            break;
        case 3:
            contra_ataque3 = 1.5;
            break;
        default:
            break;
        }
        //menu de opcoes para aluno
        /*srand((unsigned)time(NULL));
        do{
            opAluno =  (rand() % 10);
        }while(opAluno < 1 || opAluno > 3);*/
        opAluno=GetRandomValue(1, 3);
        if(vida_de_Robrigo>0 && opRubens!=0){
            if(vida_de_Robrigo <= 40) opAluno = 4;
            switch (opAluno){
            case 1:
                vida_de_rubens -= contra_ataque1 * ataqueRobrigo.acertar_questao;
                i=1;
                break;
            case 2:
                vida_de_rubens -= contra_ataque2 * ataqueRobrigo.discutir_questao;
                i=2;
                break;
            case 3:
                vida_de_rubens -= contra_ataque3 * ataqueRobrigo.chamar_no_zap;
                i=3;
                break;
            case 4:
                vida_de_rubens -= 50; //ESPECIAL TERMO TECNICO-CIENTIFICO
                i=4;
                break;
            default:
                break;
            }
        }
    }
    DrawText(TextFormat("Vida de Ro Brigo: %d", vida_de_Robrigo),4330.0f, 165.0f,8,SKYBLUE);
    rbns->life = vida_de_rubens;
    if(vida_de_rubens>0 && vida_de_Robrigo<=0){
        *Falas=2;
        DrawText("Pressione T para passar de fase, após o diálogo",rbns->position.x-100,rbns->position.y-80,8,DARKGREEN);
        if(IsKeyPressed(KEY_T)){
            *INIMIGOS=2;
            rbns->position.x=5600;
            rbns->position.y=175;
        }
    }
}
//Combate MuLittle
void Combat_MuLittle(Player *rbns, int *Falas, int *INIMIGOS){
    int vida_de_rubens = rbns->life;
    static int i=0;
    static int vida_de_MuLittle = 220, opRubens, opAluno, contra_ataque1, contra_ataque2, contra_ataque3;
    ataques_rubens ataqueRubens; ataques_aluno ataqueMuLittle;
    ataqueRubens.Questao_complicada = 5; ataqueRubens.Correcao_errada = 15;
    ataqueRubens.Nota_Errada = 30; ataqueRubens.Questao_Oral = 20;
    ataqueMuLittle.acertar_questao = 30; ataqueMuLittle.discutir_questao = 15;
    ataqueMuLittle.chamar_no_zap = 10;
    
    if(i!=0){
        if(i==1){
            DrawText("Acertei a questao!",6920.0f,175.0f,8,RED);
        }else if(i==2){
            DrawText("Discuti questao!",6920.0f,175.0f,8,BLUE);    
        }else if(i==3){
            DrawText("Chamei no Zap!",6920.0f,175.0f,8,GREEN);
        }else if(i==4){
            DrawText("ESPECIAL HIDRATACAO PROFUNDA!",6920.0f,175.0f,8,BLUE);    
        }
    }
    
    if(vida_de_MuLittle > 0 && vida_de_rubens > 0){
        contra_ataque1 = 1; contra_ataque2 = 1; contra_ataque3 = 1;
        MenudeRubens(ataqueRubens,&vida_de_MuLittle, vida_de_rubens, &opRubens,*rbns);
        switch (opRubens){
        case 1:
            contra_ataque2 = 1.3;
            break;
        case 2:
            contra_ataque3 = 1.4;
            break;
        case 3:
            contra_ataque3 = 1.5;
            break;
        default:
            break;
        }
        //menu de opcoes para aluno
        /*srand((unsigned)time(NULL));
        do{
            opAluno =  (rand() % 10);
        }while(opAluno < 1 || opAluno > 3);*/
        opAluno=GetRandomValue(1, 3);
        if(vida_de_MuLittle>40 && opRubens!=0){   
            if(vida_de_MuLittle <= 40) opAluno = 4;
            switch (opAluno){
            case 1:
                vida_de_rubens -= contra_ataque1 * ataqueMuLittle.acertar_questao;
                i=1;
                break;
            case 2:
                vida_de_rubens -= contra_ataque2 * ataqueMuLittle.discutir_questao;
                i=2;
                break;
            case 3:
                vida_de_rubens -= contra_ataque3 * ataqueMuLittle.chamar_no_zap;
                i=3;                
                break;
            case 4:
                vida_de_rubens -= 50; //ESPECIAL HIDRATACAO PROFUNDA
                i=4;
                break;
            default:
                break;
            }
        }
    }
    DrawText(TextFormat("Vida de MuLittle: %d", vida_de_MuLittle),6920.0f, 165.0f,8,SKYBLUE);
    rbns->life = vida_de_rubens;
    if(vida_de_rubens>0 && vida_de_MuLittle<=0){
        *Falas=3;
        DrawText("Pressione T para passar de fase, após o diálogo",rbns->position.x-100,rbns->position.y-80,8,DARKGREEN);
        if(IsKeyPressed(KEY_T)){
            *INIMIGOS=3;
            rbns->position.x=8200;
            rbns->position.y=175;
        }
    }
}
  
//Combate Anny

void Combat_XAnny(Player *rbns, int *Falas, int *INIMIGOS){
    int vida_de_rubens = rbns->life;
    static int i=0;
    static int vida_de_XAnny = 230, opRubens, opAluno, contra_ataque1, contra_ataque2, contra_ataque3;
    ataques_rubens ataqueRubens; 
    ataques_aluno ataqueXAnny;
    ataqueRubens.Questao_complicada = 20; ataqueRubens.Correcao_errada = 10;
    ataqueRubens.Nota_Errada = 20; ataqueRubens.Questao_Oral = 25;
    ataqueXAnny.acertar_questao = 30; ataqueXAnny.discutir_questao = 15;
    ataqueXAnny.chamar_no_zap = 10;
    
    if(i!=0){
        if(i==1){
            DrawText("Acertei a questao!",9610.0f,175.0f,8,RED);
        }else if(i==2){
            DrawText("Discuti questao!",9610.0f,175.0f,8,BLUE);    
        }else if(i==3){
            DrawText("Chamei no Zap!",9610.0f,175.0f,8,GREEN);
        }else if(i==4){
            DrawText("H'(x)!!!",9610.0f,175.0f,8,YELLOW);    
        }
    }
    
    if(vida_de_XAnny > 0 && vida_de_rubens > 0){
        contra_ataque1 = 1; contra_ataque2 = 1; contra_ataque3 = 1;
        MenudeRubens(ataqueRubens,&vida_de_XAnny, vida_de_rubens, &opRubens,*rbns);
        switch (opRubens){
        case 1:
            contra_ataque2 = 1.3;
            break;
        case 2:
            contra_ataque3 = 1.4;
            break;
        case 3:
            contra_ataque3 = 1.5;
            break;
        default:
            break;
        }
        //menu de opcoes para aluno
        /*srand((unsigned)time(NULL));
        *do{
            opAluno =  (rand() % 10);
        }while(opAluno < 1 || opAluno > 3);*/ 
        opAluno=GetRandomValue(1, 3);        
        if(vida_de_XAnny>0 && opRubens!=0){    
            if(vida_de_XAnny <= 40) opAluno = 4;
            switch (opAluno){
            case 1:
                vida_de_rubens -= contra_ataque1 * ataqueXAnny.acertar_questao;
                i=1;
                break;
            case 2:
                vida_de_rubens -= contra_ataque2 * ataqueXAnny.discutir_questao;
                i=2;
                break;
            case 3:
                vida_de_rubens -= contra_ataque3 * ataqueXAnny.chamar_no_zap;
                i=3;
                break;
            case 4:
                //invocacao da h'(x)
                vida_de_rubens -= 60; //ESPECIAL H'(X)
                i=4;
                break;
            default:
                break;
            }
        }
    }
    DrawText(TextFormat("Vida de X Anny: %d", vida_de_XAnny),9610.0f, 165.0f,8,SKYBLUE);
    rbns->life = vida_de_rubens;
    if(vida_de_rubens>0 && vida_de_XAnny<=0){
        *Falas=4;
        DrawText("Pressione T para passar de fase, após o diálogo",rbns->position.x-100,rbns->position.y-80,8,DARKGREEN);
        if(IsKeyPressed(KEY_T)){
            *INIMIGOS=4;
            rbns->position.x=10900;
            rbns->position.y=175;
        }
    }
}
//Combate do Freddy
void Combat_Freddy(Player *rbns, int *Falas,int *INIMIGOS){
    //MAPA DE FREDERICO
    int vida_de_rubens = rbns->life;
    int opAluno = GetRandomValue(1, 3);
    static int i=0;
    static int vida_de_Freddy = 250, opRubens, flag = 0, contra_ataque1, contra_ataque2, contra_ataque3;
    //combate Freddy x Rubens:
    ataques_rubens ataqueRubens; ataques_aluno ataqueFreddy;
    ataqueRubens.Questao_complicada = 15; ataqueRubens.Correcao_errada = 15;
    ataqueRubens.Nota_Errada = 25; ataqueRubens.Questao_Oral = 20;
    ataqueFreddy.acertar_questao = 20; ataqueFreddy.discutir_questao = 25;
    ataqueFreddy.chamar_no_zap = 35;
    
    if(i!=0){
        if(i==1){
            DrawText("Acertei a questao!",12260.0f,175.0f,8,RED);
        }else if(i==2){
            DrawText("Discuti questao!",12260.0f,175.0f,8,BLUE);    
        }else if(i==3){
            DrawText("Chamei no Zap!",12260.0f,175.0f,8,GREEN);
        }
    }
    
    if(vida_de_Freddy > 0 && vida_de_rubens > 0){
        contra_ataque1 = 1; contra_ataque2 = 1; contra_ataque3 = 1;
        MenuCombatFreddy(ataqueRubens, &vida_de_Freddy, vida_de_rubens, &opRubens, opAluno, *rbns);
        switch (opRubens){
        case 1:
            contra_ataque2 = 1.3;
            break;
        case 2:
            contra_ataque3 = 1.4;
            break;
        case 3:
            contra_ataque3 = 1.5;
            break;
        default:
            break;
        }
        //menu de opcoes para aluno
        /*srand((unsigned)time(NULL));
        do{
            opAluno =  (rand() % 10);
        }while(opAluno < 1 || opAluno > 3);*/        
        if(vida_de_Freddy>0 && opRubens!=0){
            switch (opAluno){
            case 1:
                vida_de_rubens -= contra_ataque1 * ataqueFreddy.acertar_questao;
                i=1;
                break;
            case 2:
                vida_de_rubens -= contra_ataque2 * ataqueFreddy.discutir_questao;
                i=2;
                break;
            case 3:
                vida_de_rubens -= contra_ataque3 * ataqueFreddy.chamar_no_zap;
                i=3;
                break;
            default:
                break;
            }
        }    
    }
    DrawText(TextFormat("Vida de Fred Rico: %d", vida_de_Freddy),12260.0f, 165.0f,8,SKYBLUE);
    rbns->life = vida_de_rubens;
    if(vida_de_rubens>0 && vida_de_Freddy<=0){
       *Falas=5; 
       DrawText("Pressione T para finalizar, após o diálogo",rbns->position.x-100,rbns->position.y-80,8,DARKGREEN);
        if(IsKeyPressed(KEY_T)){
            *INIMIGOS=5;
        }
    }
}
