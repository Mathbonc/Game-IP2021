#include <raylib.h>
#include <stdio.h>

typedef struct{
    int Questao_complicada, Correção_errada, Nota_Errada, Questão_Oral;
} ataques_rubens;

typedef struct{
    int acertar_questao, discutir_questao;
} ataques_aluno;


void Combat_LeaoNidas(int *vida_de_rubens){
    int vida_de_leao = 70, opRubens, opAluno;
    ataques_rubens ataqueRubens; ataques_aluno ataqueLeao;
    ataqueRubens.Questao_complicada = 10; ataqueRubens.Correção_errada = 30;
    ataqueRubens.Nota_Errada = 40; ataqueRubens.Questão_Oral = 70;
    //iniciar musica combat
    //dialogo entre Leao Nidas e Rubens
    while(vida_de_leao > 0 && vida_de_rubens > 0){
        //menu de opcoes para Rubens de 1 a 2 no primeiro ataque
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
        scanf("%d", &opAluno);
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

int main(){
    int *vida_de_Rubens;
    Combat_LeaoNidas(&vida_de_Rubens);
}
