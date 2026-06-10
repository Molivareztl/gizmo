#include "ladrillo.h"

ladrillo::ladrillo(int posx,int posy,int ancho, int alto, Color _color){
    posicion.x = posx;
    posicion.y = posy;
    tamaño.y = alto;
    tamaño.x = ancho;
    color = _color;
    hitbox.x = posicion.x;
    hitbox.y = posicion.y;
    hitbox.height = tamaño.y;
    hitbox.width = tamaño.x;
}
void ladrillo::dibujar(){
    DrawRectangle(posicion.x, posicion.y, tamaño.x, tamaño.y, color);
}