#ifndef ASSETS_H
#define ASSETS_H
void carregamapa1(Texture2D mapa){
	DrawTexture(mapa,0,0,RAYWHITE);
}
void Mudamapa( Texture2D mapa_Anterior, Texture2D mapa_Proximo){
    UnloadTexture(mapa_Anterior);
    DrawTexture(mapa_Proximo,0,0,RAYWHITE);
}

#endif
