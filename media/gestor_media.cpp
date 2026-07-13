#include "gestor_media.h"

gestor_media::gestor_media(){
    imagenes.reserve(5);
    imagenes.push_back(LoadTexture("media/jugador_Pholder.png"));//0
    imagenes.push_back(LoadTexture("media/meteoro.png"));//1
    imagenes.push_back(LoadTexture("media/ladrillo.png"));//2
    imagenes.push_back(LoadTexture("media/puerta.png"));//3
    imagenes.push_back(LoadTexture("media/fondo.png"));//4
    imagenes.push_back(LoadTexture("media/titulo.png"));//5
    imagenes.push_back(LoadTexture("media/hacer.png"));//6
    imagenes.push_back(LoadTexture("media/deshacer.png"));//7
    imagenes.push_back(LoadTexture("media/malo.png"));//8

    sonidos.reserve(5);
    sonidos.push_back(LoadSound("media/salto.ogg"));//0
    sonidos.push_back(LoadSound("media/disparo.ogg"));//1
    sonidos.push_back(LoadSound("media/win.ogg"));//2
    sonidos.push_back(LoadSound("media/lose.ogg"));//3

}
Texture2D gestor_media::buscar( int id){
    return imagenes[id];
}
Sound gestor_media::buscar_audio(int id)
{
    return sonidos[id];
}
void gestor_media::vaciar()
{
    for (size_t i = 0; i < imagenes.size(); i++)
    {
        UnloadTexture(imagenes[i]);
    }
    for (size_t i = 0; i < sonidos.size(); i++)
    {
        UnloadSound(sonidos[i]);
    }
    sonidos.clear();
    imagenes.clear();
}
