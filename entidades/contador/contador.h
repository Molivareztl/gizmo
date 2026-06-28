#pragma once
#include <raylib.h>

class contador
{
private:
    float tiempo;
    int tiempo_actual;
    int duracion;
public:
    contador();
    void contar();
    void dibujar();
    void sumar();
    bool fin();
    void reiniciar();
    int tiempo_partida();
};
