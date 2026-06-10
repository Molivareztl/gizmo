#include "jugador.h"

jugador::jugador()
{
    esta_colisionando = false;
    posicion.x = 100;
    posicion.y = 100;
    velocidad.x = 0;
    velocidad.y = 0;
    gravedad = 0;
    tamaño.x = 20;
    tamaño.y = 20;
    hitbox = {posicion.x, posicion.y, tamaño.x, tamaño.y};
};
jugador::~jugador()
{
    UnloadTexture(sprite);
};
void jugador::cargar()
{
    sprite = LoadTexture("media/jugador_Pholder.png");
}
void jugador::dibujar()
{
    DrawTextureEx(sprite, posicion, 0, 1.2, WHITE);
}
void jugador::actualizar()
{
    posicion.x += velocidad.x;
    posicion.y += velocidad.y;
    hitbox.x = posicion.x;
    hitbox.y = posicion.y;

    if(IsKeyDown(KEY_RIGHT))
    {
        velocidad.x = 3;
    }else if(IsKeyDown(KEY_LEFT))
    {
        velocidad.x = -3;
    }else {velocidad.x = 0;}

        if(IsKeyDown(KEY_UP) && esta_colisionando == true){
            velocidad.y = -3;
        }else if (!IsKeyDown(KEY_UP) && esta_colisionando == true)
        {
            velocidad.y = 0;
        }else{
            velocidad.y += 0.1;
        }
        esta_colisionando = false;
}
void jugador::colisiona(Rectangle collision)
{
    if(CheckCollisionRecs(hitbox, collision) == true){
        Rectangle overlap = GetCollisionRec(hitbox, collision);
        if (overlap.width < overlap.height)
        {
            if (posicion.x < collision.x)
            {
                posicion.x -= overlap.width;
            }else{
                posicion.x += overlap.width;
            }
        }
        if (overlap.width > overlap.height)
        {
            if (posicion.y < collision.y)
            {
                posicion.y -= overlap.height;
                esta_colisionando = true;
            }else{
                posicion.y += overlap.height;
            }
        }
    }
}