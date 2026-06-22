#include "puerta.h"

puerta::puerta(int posx, int posy, int ancho, int alto, Texture2D _textura)
{
    dimension.x = posx;
    dimension.y = posy;
    dimension.height = alto;
    dimension.width = ancho;
    textura = _textura;
}
bool puerta::llevar()
{
    habitación_pasada = true;
    return habitación_pasada;
}
void puerta::dibujar()
{
    DrawTexturePro(textura, dimension, dimension,Vector2{0,0},0,WHITE);
}