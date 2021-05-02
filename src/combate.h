#ifndef COMBATE_H
#define COMBATE_H
#include <raylib.h>
//Structs necessarias para os combates
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

void MenudeRubens(ataques_rubens ataques, int *vida_estudante, int vida_Rubens, int *opRubens,int posx,int posy);
void MenuCombatFreddy(ataques_rubens ataques, int *vida_estudante, int vida_Rubens, int *opRubens, int opFreddy,int posx,int posy);
void Combat_LeaoNidas(int *vida_de_rubens);
void Combat_RoBrigo(int *vida_de_rubens);
void Combat_MuLittle(int *vida_de_rubens);
void Combat_XAnny(int *vida_de_rubens);
void Combat_Freddy(int *vida_de_rubens);
player CarregaSpriteRubens(player rbs);
mus CarregaMusicas(mus Song);
void TrocaMusicaCombate(Sound musica_anterior, Sound musica_proxima);
	


#endif
