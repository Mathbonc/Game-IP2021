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

void MenudeRubens(ataques_rubens ataques, int *vida_estudante, int vida_Rubens, int *opRubens);
void Combat_LeaoNidas(int *vida_de_rubens);
void Combat_RoBrigo(int *vida_de_rubens);
void Combat_MuLittle(int *vida_de_rubens);
void Combat_XAnny(int *vida_de_rubens);
void Combat_Freddy(int *vida_de_rubens);

#endif
