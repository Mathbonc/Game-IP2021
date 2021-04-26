#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int Questao_complicada, Correção_errada, Nota_Errada, Questão_Oral;
} ataques_rubens;

typedef struct{
    int acertar_questao, discutir_questao;
} ataques_aluno;

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
    ataqueRubens.Questao_complicada = 10; ataqueRubens.Correção_errada = 30;
    ataqueRubens.Nota_Errada = 40; ataqueRubens.Questão_Oral = 70;
    //iniciar musica combat
    //dialogo entre Leao Nidas e Rubens
    while(vida_de_leao > 0 && vida_de_rubens > 0){
        if(flag == 0) /*menu de opcoes para Rubens de 1 a 2*/;
        scanf("%d", &opRubens);
        switch (opRubens){
        case 1:
            vida_de_leao -= ataqueRubens.Questao_complicada;
            break;
        case 2:
            vida_de_leao -= ataqueRubens.Correção_errada;
            break;
        case 3:
            vida_de_leao -= ataqueRubens.Nota_Errada;
            break;
        case 4:
            vida_de_leao -= ataqueRubens.Questão_Oral;
            break;
        default:
            break;
        }
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
}

void Combat_RoBrigo(int *vida_de_rubens){

}

void Combat_MuLittle(int *vida_de_rubens){

}

void Combat_XAnny(int *vida_de_rubens){

}

void Combat_Freddy(int *vida_de_rubens){

}

int main(){
    int vida_de_Rubens;
    Combat_LeaoNidas(&vida_de_Rubens);
    Combat_RoBrigo(&vida_de_Rubens);
    Combat_MuLittle(&vida_de_Rubens);
    Combat_XAnny(&vida_de_Rubens);
    Combat_Freddy(&vida_de_Rubens);
}
