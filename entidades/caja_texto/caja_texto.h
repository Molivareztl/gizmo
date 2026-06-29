#pragma once
#include <raylib.h>

class caja_texto
{
private:
    Rectangle hitbox;
    char caracteres[9];
    int cantidad;
public:
    caja_texto(int posx, int posy, int ancho, int alto, Color color);
    void escribir();
    void dibujar();
};
