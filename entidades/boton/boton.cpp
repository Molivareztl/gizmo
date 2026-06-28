#include "boton.h"

boton::boton(int posx, int posy, int ancho, int alto, Texture2D _textura)
{
    hitbox.width = ancho;
    hitbox.height = alto;
    hitbox.x = posx - hitbox.width / 2;
    hitbox.y = posy - hitbox.height / 2;
    textura = _textura;
}

void boton::dibujar( const char* texto)
{
    int tamaño_texto = MeasureText(texto,32);
    DrawTexturePro(textura, hitbox,hitbox,Vector2{0,0},0,WHITE);
    DrawText(texto,hitbox.x, hitbox.y,32,WHITE);
}

bool boton::presionado(Vector2 raton, bool es_presionado)
{
    if(CheckCollisionPointRec(raton,hitbox) == true && es_presionado == true){
        return true;
    }
    return false;
}
