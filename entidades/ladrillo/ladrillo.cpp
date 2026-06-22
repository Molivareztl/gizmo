#include "ladrillo.h"

ladrillo::ladrillo(int posx,int posy,int ancho, int alto, Color _color, Texture2D _textura){
    posicion.x = posx;
    posicion.y = posy;
    tamaño.y = alto;
    tamaño.x = ancho;
    color = _color;
    textura = _textura;
    hitbox.x = posicion.x;
    hitbox.y = posicion.y;
    hitbox.height = tamaño.y;
    hitbox.width = tamaño.x;
}
void ladrillo::dibujar(){
    DrawTexturePro(textura, hitbox, hitbox,Vector2{0,0},0,color);
    //DrawRectangle(posicion.x, posicion.y, tamaño.x, tamaño.y, color);
}