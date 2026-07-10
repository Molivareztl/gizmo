#pragma once
#include "raylib.h"

class boton
{
private:
    Rectangle hitbox;
    Texture2D textura;
public:
    boton(int posx, int posy, int ancho, int alto, Texture2D textura);;
    void dibujar( const char* texto);
    bool presionado(Vector2 raton, bool es_presionado);
};

