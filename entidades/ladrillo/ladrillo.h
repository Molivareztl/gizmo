#pragma once
#include <raylib.h>
class ladrillo
{
public:
    Rectangle hitbox;
    Color color;
    Vector2 posicion;
    Vector2 tamaño;
    ladrillo(int posx,int posy,int ancho, int alto, Color _color);
    void dibujar();
};

