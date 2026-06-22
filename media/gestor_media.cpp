#include "gestor_media.h"

gestor_media::gestor_media(){
    imagenes.reserve(2);
    imagenes.push_back(LoadTexture("media/jugador_Pholder.png"));
    imagenes.push_back(LoadTexture("media/ladrillo.png"));
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

