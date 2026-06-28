#pragma once
#include <raylib.h>

class contador
{
private:
    float contadorTiempo;
    int segundosTranscurridos;
public:
    contador();
    void contar();
    void dibujar();
    void sumar();
};
