#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct{
    int Questao_complicada, Correcao_errada, Nota_Errada, Questao_Oral;
} ataques_rubens;

typedef struct{
    int acertar_questao, discutir_questao;
} ataques_aluno;
 //tive que colocar as teclas de ataque como j,k,l,m.... pois nao tava conseguindo identificar as teclas 1,2,3....
void MenudeRubens(ataques_rubens ataques, int *vida_estudante, int vida_Rubens){
    int valorizador = 1;
    if(vida_Rubens >= 50) valorizador = 1.5;
    if(vida_Rubens >= 30) valorizador = 2;
    if(IsKeyPressed(KEY_J))vida_estudante -= valorizador * ataques.Questao_complicada;
    if(IsKeyPressed(KEY_K))vida_estudante -= valorizador * ataques.Correcao_errada;
    if(IsKeyPressed(KEY_L))vida_estudante -= valorizador * ataques.Nota_Errada;
    if(IsKeyPressed(KEY_M))vida_estudante -= valorizador * ataques.Questao_Oral;
    else {
    //DrawText("invalido, bla bla bla...."); <-apareceria na tela... // mas onde? 
   }
}
void TrocaMusicaCombate(Sound musica_anterior, Sound musica_proxima){
    StopSound(musica_anterior);
    PlaySound(musica_proxima);       
}

void Rubens_atack(Texture2D warrior, Vector2 position, int frame, float timer, float framewidth, float frameheight, float cordx, float *cordy, int *cont, int maxFrames){ 
    //O usuário deve executar o comando BeginDrawing antes de chamar a função   
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
    /*Escrever o seguinte código na main antes de chamar a função:
    timer += GetFrameTime();
    if(timer>=0.01f){
        timer =0.0f;
        frame+=1;
    }*/
}


void Combat_LeaoNidas(int *vida_de_rubens){
    int vida_de_leao = 70, opRubens, opAluno, flag = 0;
    ataques_rubens ataqueRubens; ataques_aluno ataqueLeao;
    ataqueRubens.Questao_complicada = 10; ataqueRubens.Correcao_errada = 10;
    ataqueRubens.Nota_Errada = 20; ataqueRubens.Questao_Oral = 30;
    //iniciar musica combat
    //PlaySound(...);
    //dialogo entre Leao Nidas e Rubens
    while(vida_de_leao > 0 && vida_de_rubens > 0){
        if(flag == 0) /*menu de opcoes para Rubens de 1 a 2*/;
        MenudeRubens(ataqueRubens,&vida_de_leao, *vida_de_rubens);
        //menu de opcoes para aluno
        srand((unsigned)time(NULL));
        do{
            opAluno =  (rand() % 10);
        }while(opAluno < 1 || opAluno > 2);
        switch (opAluno){
        case 1:
            vida_de_rubens -= ataqueLeao.acertar_questao;
            break;
        case 2:
            vida_de_rubens -= ataqueLeao.discutir_questao;
            break;
        default:
            break;
        }
    }
    if(vida_de_rubens <= 0){
        
        //animacao rubia morrendo
    }
}

void Combat_RoBrigo(int *vida_de_rubens){
    int vida_de_Robrigo= 80, opRubens, opAluno, flag = 0;
    ataques_rubens ataqueRubens; ataques_aluno ataqueRobrigo;
    ataqueRubens.Questao_complicada = 10; ataqueRubens.Correcao_errada = 10;
    ataqueRubens.Nota_Errada = 20; ataqueRubens.Questao_Oral = 30;
    //musica de combate
    //PlaySound(...);
    //dialogo
    while(vida_de_Robrigo > 0 && vida_de_rubens > 0){
        if(flag == 0) /*menu de opcoes para Rubens de 1 a 2*/;
        MenudeRubens(ataqueRubens,&vida_de_Robrigo, *vida_de_rubens);
        //menu de opcoes para aluno
        srand((unsigned)time(NULL));
        do{
            opAluno =  (rand() % 10);
        }while(opAluno < 1 || opAluno > 2);
        if(vida_de_Robrigo >= 40) opAluno = 3;
        switch (opAluno){
        case 1:
            vida_de_rubens -= ataqueRobrigo.acertar_questao;
            break;
        case 2:
            vida_de_rubens -= ataqueRobrigo.discutir_questao;
            break;
        case 3:
            vida_de_rubens -= 50; //ESPECIAL TERMO TECNICO-CIENTIFICO
        default:
            break;
        }
    }
    if(vida_de_rubens <= 0){
        
        //animacao rubia morrendo
    }
    
}

void Combat_MuLittle(int *vida_de_rubens){
    int vida_de_MuLittle = 85, opRubens, opAluno, flag = 0;
    ataques_rubens ataqueRubens; ataques_aluno ataqueMuLittle;
    ataqueRubens.Questao_complicada = 10; ataqueRubens.Correcao_errada = 10;
    ataqueRubens.Nota_Errada = 20; ataqueRubens.Questao_Oral = 30;
    //PlaySound(Sound sound);  //iniciar musica combat
    //dialogo entre MuLittle e Rubens
    while(vida_de_MuLittle > 0 && vida_de_rubens > 0){
        if(flag == 0) /*menu de opcoes para Rubens de 1 a 2*/;
        MenudeRubens(ataqueRubens,&vida_de_MuLittle, *vida_de_rubens);
        //menu de opcoes para aluno
        srand((unsigned)time(NULL));
        do{
            opAluno =  (rand() % 10);
        }while(opAluno < 1 || opAluno > 2);
        switch (opAluno){
        case 1:
            vida_de_rubens -= ataqueMuLittle.acertar_questao;
            break;
        case 2:
            vida_de_rubens -= ataqueMuLittle.discutir_questao;
            break;
        default:
            break;
        }
    }
    if(vida_de_rubens <= 0){
        
        //animacao rubia morrendo
    }
}
    


void Combat_XAnny(int *vida_de_rubens){
    int vida_de_XAnny = 90, opRubens, opAluno, flag = 0;
    ataques_rubens ataqueRubens; ataques_aluno ataqueXAnny;
    ataqueRubens.Questao_complicada = 10; ataqueRubens.Correcao_errada = 10;
    ataqueRubens.Nota_Errada = 20; ataqueRubens.Questao_Oral = 30;
    //PlaySound(Sound sound);  //iniciar musica combat
    //dialogo entre XAnny e Rubens
    while(vida_de_XAnny > 0 && vida_de_rubens > 0){
        if(flag == 0) /*menu de opcoes para Rubens de 1 a 2*/;
        MenudeRubens(ataqueRubens,&vida_de_XAnny, *vida_de_rubens);
        //menu de opcoes para aluno
        srand((unsigned)time(NULL));
        do{
            opAluno =  (rand() % 10);
        }while(opAluno < 1 || opAluno > 2);
        if(vida_de_XAnny > 40) opAluno = 3;
        switch (opAluno){
        case 1:
            vida_de_rubens -= ataqueXAnny.acertar_questao;
            break;
        case 2:
            vida_de_rubens -= ataqueXAnny.discutir_questao;
            break;
        case 3:
            //invocacao da h'(x)
            vida_de_rubens -= 60; //ESPECIAL H'(X)
        default:
            break;
        }
    }
    if(vida_de_rubens <= 0){
        
        //animacao rubia morrendo
    }
}

void Combat_Freddy(int *vida_de_rubens){
   //TrocaMusicaCombate()...
   //int vida_de_Freddy = ?, opRubens, opAluno, flag = 0;
   //dialogo entre Freddy e Rubens
   ataques_rubens ataqueRubens; ataques_aluno ataqueFreddy;
    
}

int main(){
    int vida_de_Rubens;
    Combat_LeaoNidas(&vida_de_Rubens);
    Combat_RoBrigo(&vida_de_Rubens);
    Combat_MuLittle(&vida_de_Rubens);
    Combat_XAnny(&vida_de_Rubens);
    Combat_Freddy(&vida_de_Rubens);
}
