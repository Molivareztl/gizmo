#include "ladrillo.h"

ladrillo::ladrillo(int posx,int posy,int ancho, int alto, Color _color, Texture2D _textura, bool _es_puerta, bool _lastima, bool _destruible){
    color = _color;
    textura = _textura;
    hitbox.x = posx;
    hitbox.y = posy;
    hitbox.height = alto;
    hitbox.width = ancho;
    es_puerta = _es_puerta;
    lastima = _lastima;
    destruible = _destruible;
    transicion.x = 0;
    transicion.y = 0;
    velocidad.x = 0;
    velocidad.y = 0;
}
void ladrillo::dibujar(){
    
    DrawTexturePro(textura, Rectangle{hitbox.x ,hitbox.y,hitbox.width/2,hitbox.height/2}, Rectangle{hitbox.x + transicion.x , hitbox.y + transicion.y, hitbox.width, hitbox.height},Vector2{0,0},0,color);
}

bool ladrillo::puede_lastimar()
{
    return lastima;
}

bool ladrillo::puede_pasar()
{
    return es_puerta;
}

bool ladrillo::se_puede_destruir()
{
    return destruible;
}

void ladrillo::definir_animacion(int posx, int posy)
{
    
    transicion.y = posy;
    transicion.x = posx;
}

void ladrillo::animacion()
{
    
    if (transicion.y > 0)
    {
        transicion.y -= 16;
    }
    if (transicion.y < 0)
    {
        transicion.y += 16;
    }
    if (transicion.x > 0)
    {
        transicion.x -= 16;
    }
    if (transicion.x < 0)
    {
        transicion.x += 16;
    }

}
