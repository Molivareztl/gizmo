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
    direccion = _direccion;
    tipo = _tipo;
}
void proyectil::dibujar(){
    DrawRectangle(hitbox.x,hitbox.y,hitbox.width,hitbox.height,RED);
}
void proyectil::mover(){
    hitbox.x += velocidad.x;
    hitbox.y += velocidad.y;
    velocidad.x = direccion.x; 
    velocidad.y = direccion.y;

}
void proyectil::colisiona(Rectangle collision){
    if(CheckCollisionRecs(hitbox, collision) == true){
        esta_colisionando = true;
    }else{esta_colisionando = false;}
}

Rectangle proyectil::devolver_hitbox()
{
    return hitbox;
}
