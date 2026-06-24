#include "proyectil.h"

proyectil::proyectil(Rectangle _hitbox, Vector2 _direccion, bool _puede_destruir,bool _puede_crear)
{
    hitbox.x = _hitbox.x;
    hitbox.y = _hitbox.y;
    hitbox.width = 20;
    hitbox.height = 20;
    velocidad.x = 0;
    velocidad.y = 0;
    esta_colisionando = false;
    direccion = _direccion;
    puede_crear = _puede_crear;
    puede_destruir = _puede_destruir;
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