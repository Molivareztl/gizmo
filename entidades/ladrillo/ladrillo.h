#pragma once
#include <raylib.h>
class ladrillo
{
public:
    int id_textura = 1;
    Rectangle hitbox;
    Color color;
    Texture2D textura;
    bool es_puerta;
    bool lastima;
    bool destruible;
    ladrillo(int posx,int posy,int ancho, int alto, Color _color, Texture2D textura, bool es_puerta, bool lastima, bool destruible);
    void dibujar();
};

