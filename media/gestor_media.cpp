#include "gestor_media.h"

gestor_media::gestor_media(){
    imagenes.reserve(5);
    imagenes.push_back(LoadTexture("media/jugador_Pholder.png"));//0
    imagenes.push_back(LoadTexture("media/meteoro.png"));//1
    imagenes.push_back(LoadTexture("media/ladrillo.png"));//2
    imagenes.push_back(LoadTexture("media/puerta.png"));//3
    imagenes.push_back(LoadTexture("media/fondo.png"));//4
    imagenes.push_back(LoadTexture("media/perder.png"));//5
}
Texture2D gestor_media::buscar( int id){
    return imagenes[id];
}
void gestor_media::vaciar(){
    for (size_t i = 0; i < imagenes.size(); i++)
    {
        UnloadTexture(imagenes[i]);
    }
    imagenes.clear();
}

