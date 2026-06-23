#include "ladrillo.h"

ladrillo::ladrillo(int posx,int posy,int ancho, int alto, Color _color, Texture2D _textura, bool _es_puerta){
    color = _color;
    textura = _textura;
    hitbox.x = posx;
    hitbox.y = posy;
    hitbox.height = alto;
    hitbox.width = ancho;
    es_puerta = _es_puerta;
}
void ladrillo::dibujar(){
    DrawTexturePro(textura, hitbox, hitbox,Vector2{0,0},0,color);
}