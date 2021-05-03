#ifndef COMBATE_H
#define COMBATE_H
#include "moviment.h"
#include <raylib.h>
//Structs necessarias para os combates
typedef struct{ //Struct para os ataques de Rubens
    int Questao_complicada, Correcao_errada, Nota_Errada, Questao_Oral;
} ataques_rubens;

typedef struct{ //Struct para os ataques do aluno
    int acertar_questao, discutir_questao, chamar_no_zap;
} ataques_aluno;

typedef struct {
	Sound musica[3];
}mus;

typedef struct{
    Texture2D Rubens[4];
}player;

void MenudeRubens(ataques_rubens ataques, int *vida_estudante, int vida_Rubens, int *opRubens,Player rbns);
void MenuCombatFreddy(ataques_rubens ataques, int *vida_estudante, int vida_Rubens, int *opRubens, int opFreddy,Player rbns);
void Combat_LeaoNidas(Player *rbns,int *Falas, int *INIMIGOS);
void Combat_RoBrigo(Player *rbns,int *Falas, int *INIMIGOS);
void Combat_MuLittle(Player *rbns,int *Falas, int *INIMIGOS);
void Combat_XAnny(Player *rbns,int *Falas, int *INIMIGOS);
void Combat_Freddy(Player *rbns,int *Falas, int *INIMIGOS);
player CarregaSpriteRubens(player rbs);
mus CarregaMusicas(mus Song);
void TrocaMusicaCombate(Sound musica_anterior, Sound musica_proxima);
	


#endif
