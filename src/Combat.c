#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "combate.h"

int main(){
    int vida_de_Rubens=200; //nao necessariamente a vida eh 200 *foi só um valor representativo para testar a lib*
    Combat_LeaoNidas(&vida_de_Rubens);
    Combat_RoBrigo(&vida_de_Rubens);
    Combat_MuLittle(&vida_de_Rubens);
    Combat_XAnny(&vida_de_Rubens);
    Combat_Freddy(&vida_de_Rubens);
}
