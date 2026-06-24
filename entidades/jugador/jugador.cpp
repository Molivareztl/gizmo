#include "jugador.h"

jugador::jugador()
{
    esta_colisionando = false;
    velocidad.x = 0;
    velocidad.y = 0;
    gravedad = 0;
    direccion = {0.1,0};
    velocidad_disparo = 1;
    tamaño.x = 32;
    tamaño.y = 32;
    hitbox = {posicion.x, posicion.y, tamaño.x, tamaño.y};
    puede_disparar = false;
};
void jugador::ubicar(int posx, int posy){
    posicion.x = posx; 
    posicion.y = posy;
}
void jugador::cargar( Texture2D textura)
{
    sprite = textura;
}
void jugador::dibujar()
{
    DrawTextureEx(sprite, posicion, 0, 2, WHITE);
}

void jugador::disparar(){
    proyectiles.emplace_back(hitbox, direccion,false,false);
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
        direccion.x = 0.1;
    }else if(IsKeyDown(KEY_LEFT))
    {
        velocidad.x = -3;
        direccion.x = -0.1;
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
    
    if(IsKeyDown(KEY_SPACE) && puede_disparar == true)
    {
        puede_disparar = false;
        disparar();
    }else if (!IsKeyDown(KEY_SPACE)){puede_disparar = true;}
    
}
bool jugador::estado_colision(Rectangle collision){
    if(CheckCollisionRecs(hitbox, collision) == true){
        return esta_colisionando;
    }
    return false;
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
void jugador::vaciar()
{
    proyectiles.clear();
}