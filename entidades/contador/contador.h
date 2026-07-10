#pragma once
#include <raylib.h>

class contador
{
private:
    float tiempo;
    int tiempo_actual;
    int duracion;
    int tiempo_original;
public:
    contador();
    void contar();
    void dibujar();
    void modificar( int num);
    bool fin();
    void reiniciar();
    int tiempo_partida();
};
