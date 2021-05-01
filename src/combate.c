#include "raylib.h"
#include "combate.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
player CarregaSpriteRubens(player rbs){
	rbs.Rubens[0]=LoadTexture("./bin/Characters/Enemies/Guardian/rubiaAtk1.png");
	rbs.Rubens[1]=LoadTexture("./bin/Characters/Enemies/Guardian/rubiaAtk2.png");
	rbs.Rubens[2]=LoadTexture("./bin/Characters/Enemies/Guardian/rubiadeath.png");
	rbs.Rubens[3]=LoadTexture("./bin/Characters/Enemies/Guardian/rubia_recebe_dano.png");
	return rbs;
}

mus CarregaMusicas(mus Song){
	Song.musica[0]=LoadSound("./bin/Sample/Music/Ludum Dare - Track 1.wav");  
	Song.musica[1]=LoadSound("./bin/Sample/Music/Ludum Dare - Track 3.wav");  
	Song.musica[2]=LoadSound("./bin/Sample/Music/Ludum Dare - Track 4.wav");  
	Song.musica[3]=LoadSound("./bin/Sample/Music/Ludum Dare - Track 5.wav");  
	Song.musica[4]=LoadSound("./bin/Sample/Music/Ludum Dare - Track 6.wav");
	Song.musica[5]=LoadSound("./bin/Sample/Music/Ludum Dare - Track 7.wav");  
	Song.musica[6]=LoadSound("./bin/Sample/Music/Ludum Dare - Track 8.wav");  
	Song.musica[7]=LoadSound("./bin/Sample/Music/Ludum Dare - Track 9.wav");  
	Song.musica[8]=LoadSound("./bin/Sample/Music/Ludum Dare - Track 10.wav");
    Song.musica[9]=LoadSound("./bin/Sample/Music/10-Fight.wav");
	return Song;  
}
void MenudeRubens(ataques_rubens ataques, int *vida_estudante, int vida_Rubens, int *opRubens){
    int valorizador = 1;
    if(vida_Rubens >= 50) valorizador = 1.5;
    if(vida_Rubens >= 30) valorizador = 2;
    if(IsKeyPressed(KEY_J)){
        *vida_estudante -= valorizador * ataques.Questao_complicada;
        *opRubens = 1;
    }
    if(IsKeyPressed(KEY_K)){
        *vida_estudante -= valorizador * ataques.Correcao_errada;
        *opRubens = 2;
    }
    if(IsKeyPressed(KEY_L)){
        *vida_estudante -= valorizador * ataques.Nota_Errada;
        *opRubens = 3;
    }
    if(IsKeyPressed(KEY_M)){
        *vida_estudante -= valorizador * ataques.Questao_Oral;
        *opRubens = 4;
    }
    else {
    //DrawText("invalido, bla bla bla...."); <-apareceria na tela... // mas onde? 
   }
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
void Combat_LeaoNidas(int *vida_de_rubens){
    int vida_de_leao = 70, opRubens, opAluno, flag = 0, contra_ataque1, contra_ataque2, contra_ataque3;
    ataques_rubens ataqueRubens; ataques_aluno ataqueLeao;
    ataqueRubens.Questao_complicada = 10; ataqueRubens.Correcao_errada = 10;
    ataqueRubens.Nota_Errada = 20; ataqueRubens.Questao_Oral = 30;
    ataqueLeao.acertar_questao = 10; ataqueLeao.discutir_questao = 15;
    ataqueLeao.chamar_no_zap = 20;
    //dialogo entre Leao Nidas e Rubens
    //iniciar musica combat
    mus Musica=CarregaMusicas(Musica);
    PlaySound(Musica.musica[2]);
    while(vida_de_leao > 0 && *vida_de_rubens > 0){
        contra_ataque1 = 1; contra_ataque2 = 1; contra_ataque3 = 1;
        if(flag == 0) /*menu de opcoes para Rubens de 1 a 2*/;
        MenudeRubens(ataqueRubens,&vida_de_leao, *vida_de_rubens, &opRubens);
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
        srand((unsigned)time(NULL));
        do{
            opAluno =  (rand() % 10);
        }while(opAluno < 1 || opAluno > 2);
        switch (opAluno){
        case 1:
            *vida_de_rubens -= contra_ataque1 * ataqueLeao.acertar_questao;
            //aparece na tela o ataque
            break;
        case 2:
            *vida_de_rubens -= contra_ataque2 * ataqueLeao.discutir_questao;
            //aparece na tela o ataque
            break;
        case 3:
            *vida_de_rubens -= contra_ataque3 * ataqueLeao.chamar_no_zap;
            //aparece na tela o ataque
            break;
        default:
            break;
        }
    }
    if(*vida_de_rubens <= 0){
        
        //animacao rubia morrendo
    }
    if(vida_de_leao<=0 || *vida_de_rubens<=0){
        StopSound(Musica.musica[2]);
    }
}
//Combate Ro Brigo
void Combat_RoBrigo(int *vida_de_rubens){
    int vida_de_Robrigo= 80, opRubens, opAluno, flag = 0, contra_ataque1, contra_ataque2, contra_ataque3;
    ataques_rubens ataqueRubens; ataques_aluno ataqueRobrigo;
    ataqueRubens.Questao_complicada = 10; ataqueRubens.Correcao_errada = 10;
    ataqueRubens.Nota_Errada = 20; ataqueRubens.Questao_Oral = 30;
    ataqueRobrigo.acertar_questao = 15; 
    ataqueRobrigo.discutir_questao = 20;
    ataqueRobrigo.chamar_no_zap = 10;
    mus Musica=CarregaMusicas(Musica);
    //dialogo
    
    //musica de combate
    PlaySound(Musica.musica[2]);
    
    while(vida_de_Robrigo > 0 && *vida_de_rubens > 0){
        contra_ataque1 = 1; contra_ataque2 = 1; contra_ataque3 = 1;
        if(flag == 0) /*menu de opcoes para Rubens de 1 a 2*/;
        MenudeRubens(ataqueRubens,&vida_de_Robrigo, *vida_de_rubens, &opRubens);
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
        srand((unsigned)time(NULL));
        do{
            opAluno =  (rand() % 10);
        }while(opAluno < 1 || opAluno > 2);
        if(vida_de_Robrigo >= 40) opAluno = 4;
        switch (opAluno){
        case 1:
            *vida_de_rubens -= contra_ataque1 * ataqueRobrigo.acertar_questao;
            //aparece na tela o ataque
            break;
        case 2:
            *vida_de_rubens -= contra_ataque2 * ataqueRobrigo.discutir_questao;
            //aparece na tela o ataque
            break;
        case 3:
            *vida_de_rubens -= contra_ataque3 * ataqueRobrigo.chamar_no_zap;
            break;
        case 4:
            *vida_de_rubens -= 50; //ESPECIAL TERMO TECNICO-CIENTIFICO
            break;
        default:
            break;
        }
    }
    if(*vida_de_rubens <= 0){
        
        //animacao rubia morrendo
    }
    if(vida_de_Robrigo<=0 || *vida_de_rubens<=0){
        StopSound(Musica.musica[2]);
}
}
//Combate MuLittle
void Combat_MuLittle(int *vida_de_rubens){
    int vida_de_MuLittle = 85, opRubens, opAluno, flag = 0, contra_ataque1, contra_ataque2, contra_ataque3;
    ataques_rubens ataqueRubens; ataques_aluno ataqueMuLittle;
    ataqueRubens.Questao_complicada = 10; ataqueRubens.Correcao_errada = 10;
    ataqueRubens.Nota_Errada = 20; ataqueRubens.Questao_Oral = 30;
    ataqueMuLittle.acertar_questao = 30; ataqueMuLittle.discutir_questao = 15;
    ataqueMuLittle.chamar_no_zap = 10;
    mus Musica=CarregaMusicas(Musica);
   
    //dialogo entre MuLittle e Rubens
    //iniciar musica combat
    PlaySound(Musica.musica[2]);
    
    while(vida_de_MuLittle > 0 && *vida_de_rubens > 0){
        contra_ataque1 = 1; contra_ataque2 = 1; contra_ataque3 = 1;
        if(flag == 0) /*menu de opcoes para Rubens de 1 a 2*/;
        MenudeRubens(ataqueRubens,&vida_de_MuLittle, *vida_de_rubens, &opRubens);
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
        srand((unsigned)time(NULL));
        do{
            opAluno =  (rand() % 10);
        }while(opAluno < 1 || opAluno > 3);
        if(vida_de_MuLittle >= 40) opAluno = 4;
        switch (opAluno){
        case 1:
            *vida_de_rubens -= contra_ataque1 * ataqueMuLittle.acertar_questao;
            //aparece na tela o ataque
            break;
        case 2:
            *vida_de_rubens -= contra_ataque2 * ataqueMuLittle.discutir_questao;
            //aparece na tela o ataque
            break;
        case 3:
            *vida_de_rubens -= contra_ataque3 * ataqueMuLittle.chamar_no_zap;
            //aparece na tela o ataque
            break;
        case 4:
            *vida_de_rubens -= 50; //ESPECIAL HIDRATACAO PROFUNDA
            break;
        default:
            break;
        }
    }
    if(*vida_de_rubens <= 0){
       
        //animacao rubia morrendo
    }
    if(*vida_de_rubens<=0 || vida_de_MuLittle>0){
       StopSound(Musica.musica[2]);
    }
}
    
//Combate Anny

void Combat_XAnny(int *vida_de_rubens){
    int vida_de_XAnny = 90, opRubens, opAluno, flag = 0, contra_ataque1, contra_ataque2, contra_ataque3;
    ataques_rubens ataqueRubens; 
    ataques_aluno ataqueXAnny;
    ataqueRubens.Questao_complicada = 10; ataqueRubens.Correcao_errada = 10;
    ataqueRubens.Nota_Errada = 20; ataqueRubens.Questao_Oral = 30;
    ataqueXAnny.acertar_questao = 30; ataqueXAnny.discutir_questao = 15;
    ataqueXAnny.chamar_no_zap = 10;
    mus Musica=CarregaMusicas(Musica);
    
    //iniciar musica combat
    PlaySound(Musica.musica[2]);
    //dialogo entre XAnny e Rubens
    while(vida_de_XAnny > 0 && *vida_de_rubens > 0){
        contra_ataque1 = 1; contra_ataque2 = 1; contra_ataque3 = 1;
        if(flag == 0) /*menu de opcoes para Rubens de 1 a 2*/;
        MenudeRubens(ataqueRubens,&vida_de_XAnny, *vida_de_rubens, &opRubens);
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
        srand((unsigned)time(NULL));
        do{
            opAluno =  (rand() % 10);
        }while(opAluno < 1 || opAluno > 2);
        if(vida_de_XAnny > 40) opAluno = 4;
        switch (opAluno){
        case 1:
            *vida_de_rubens -= contra_ataque1 * ataqueXAnny.acertar_questao;
            //aparece na tela o ataque
            break;
        case 2:
            *vida_de_rubens -= contra_ataque2 * ataqueXAnny.discutir_questao;
            //aparece na tela o ataque
            break;
        case 3:
            *vida_de_rubens -= contra_ataque3 * ataqueXAnny.chamar_no_zap;
            //aparece na tela o ataque
            break;
        case 4:
            //invocacao da h'(x)
            *vida_de_rubens -= 60; //ESPECIAL H'(X)
            break;
        default:
            break;
        }
    }
    if(*vida_de_rubens <= 0){
        
        //animacao rubia morrendo
    }
    
    if(*vida_de_rubens<=0 ||vida_de_XAnny<=0){
       StopSound(Musica.musica[2]);
    }

}
//Combate do Freddy
void Combat_Freddy(int *vida_de_rubens){
    mus Musica=CarregaMusicas(Musica);
    //int vida_de_Freddy = ?, opRubens, opAluno, flag = 0;
    //dialogo entre Freddy e Rubens
    PlaySound(Musica.musica[8]);
    //combate Freddy x Rubens:
    TrocaMusicaCombate(Musica.musica[8],Musica.musica[9]);
    ataques_rubens ataqueRubens; ataques_aluno ataqueFreddy;
    ataqueRubens.Questao_complicada = 10; ataqueRubens.Correcao_errada = 10;
    ataqueRubens.Nota_Errada = 20; ataqueRubens.Questao_Oral = 30;
    
   /* if(vida_de_Freddy<=0 && *vida_de_rubens<=0){
        StopSound(Musica.musica[9]);
   }*/
}
