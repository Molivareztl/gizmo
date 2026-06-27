#include "jugador.h"

jugador::jugador(){
    esta_colisionando = false;
    en_el_suelo = false;
    velocidad.x = 0;
    velocidad.y = 0;
    gravedad = 0;
    opcion = 0;
    direccion = {2,0};
    direccion_sprite = 16;
    velocidad_disparo = 1;
    habitaciones_pasadas = 0;
    tamaño.x = 32;
    tamaño.y = 32;
    hitbox = {posicion.x, posicion.y, tamaño.x, tamaño.y};
    puede_disparar = false;
    municion ={5, 2};
};
void jugador::ubicar(int posx, int posy){
    posicion.x = posx; 
    posicion.y = posy;
}
void jugador::cargar( Texture2D textura){
    sprite = textura;
}
void jugador::dibujar(){
    DrawTexturePro(sprite, Rectangle{0,0,direccion_sprite,16},hitbox,Vector2{0,0},0,WHITE);
    DrawText(TextFormat("%i", municion[opcion]),hitbox.x + hitbox.width/2,hitbox.y - hitbox.width/2,32,WHITE);
}
void jugador::disparar(){
    proyectiles.emplace_back(hitbox, direccion,opcion);
}
void jugador::actualizar(){
    posicion.x += velocidad.x;
    posicion.y += velocidad.y;
    hitbox.x = posicion.x;
    hitbox.y = posicion.y;
    direccion.x = velocidad.x;
    direccion.y = velocidad.y;

    if(IsKeyPressed(KEY_ONE)){
        opcion = 0;
    }else if(IsKeyPressed(KEY_TWO)){
        opcion = 1;
    }

    if(IsKeyDown(KEY_RIGHT)){
        velocidad.x = 3;
        direccion_sprite = 16;
    }else if(IsKeyDown(KEY_LEFT)){
        velocidad.x = -3;
        direccion_sprite = -16;
    }else {velocidad.x = 0;
    }
    if(IsKeyDown(KEY_UP) && en_el_suelo == true){
        velocidad.y = -3;
    }else if (!IsKeyDown(KEY_UP) && en_el_suelo == true){
        velocidad.y = 0;
    }else{
        velocidad.y += 0.1;
    }
    if(IsKeyDown(KEY_SPACE) && puede_disparar == true){
        puede_disparar = false;
        disparar();
    }else if (!IsKeyDown(KEY_SPACE)){
        puede_disparar = true;
    }
    en_el_suelo = false;

}
bool jugador::estado_colision(Rectangle collision){
    if(CheckCollisionRecs(hitbox, collision) == true){
        return esta_colisionando;
    }
    return false;
}

void jugador::colisiona(Rectangle collision){
    if(CheckCollisionRecs(hitbox, collision) == true){
        esta_colisionando = true;
        Rectangle overlap = GetCollisionRec(hitbox, collision);
        if (overlap.width < overlap.height)
        {
            if (posicion.x < collision.x){
                posicion.x -= overlap.width;
            }else{
                posicion.x += overlap.width;
            }
        }
        if (overlap.width > overlap.height){
            if (posicion.y < collision.y){
                posicion.y -= overlap.height;
                en_el_suelo = true;
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

void jugador::sumar_punto()
{
    habitaciones_pasadas = habitaciones_pasadas +1;
}
int jugador::mostrar_punto()
{
    return habitaciones_pasadas;
}