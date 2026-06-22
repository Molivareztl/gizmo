#pragma once
#include <raylib.h>

class puerta
{
private:
    Rectangle dimension;
    Texture2D textura;
    bool habitación_pasada;
public:
    puerta(int posx, int posy, int ancho, int alto, Texture2D textura);
    void dibujar();
    bool llevar();
};
