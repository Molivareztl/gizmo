#include "proyectil.h"

proyectil::proyectil(Rectangle _hitbox, Vector2 _direccion, int _tipo)
{
    hitbox.x = _hitbox.x;
    hitbox.y = _hitbox.y;
    hitbox.width = 20;
    hitbox.height = 20;
    velocidad.x = 0;
    velocidad.y = 0;
    esta_colisionando = false;
    puede_destruir = false;
    direccion = _direccion;
    tipo = _tipo;
}
void proyectil::dibujar(){
    DrawRectangle(hitbox.x,hitbox.y,hitbox.width,hitbox.height,YELLOW);
}
void proyectil::mover(){
    hitbox.x += velocidad.x;
    hitbox.y += velocidad.y;
    velocidad.x = direccion.x; 
    velocidad.y = direccion.y;
    direccion.y += 0.1;
}
void proyectil::colisiona(ladrillo collision){
    if(CheckCollisionRecs(hitbox, collision.hitbox) == true){
            switch (tipo)
            {
            case 0:
                if (collision.se_puede_destruir() == true)
                {
                puede_destruir = true;
                puede_crear = false;
                }else{puede_destruir = false;}
            break;
            case 1:
                puede_crear = true;
                puede_destruir = false;
            break;
            }
        esta_colisionando = true;
    }else{esta_colisionando = false;}
}

bool proyectil::destruir()
{
    return puede_destruir;
}
bool proyectil::crear()
{
    return puede_crear;
}

Rectangle proyectil::devolver_hitbox()
{
    return hitbox;
}

bool proyectil::estado_colision()
{
    return esta_colisionando;
}

int proyectil::mostrar_tipo()
{
    return tipo;
}
