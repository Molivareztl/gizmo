#include "ladrillo.h"

ladrillo::ladrillo(int posx,int posy,int ancho, int alto, Color _color, Texture2D _textura){
    color = _color;
    textura = _textura;
    hitbox.x = posx;
    hitbox.y = posy;
    hitbox.height = alto;
    hitbox.width = ancho;
}
void ladrillo::dibujar(){
    DrawTexturePro(textura, hitbox, hitbox,Vector2{0,0},0,color);
    //DrawRectangle(posicion.x, posicion.y, tamaño.x, tamaño.y, color);
}