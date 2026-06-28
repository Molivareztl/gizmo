#include "contador.h"

contador::contador()
{
    tiempo = 0.0f;
    tiempo_actual = 5;
    duracion = 0;
}

void contador::contar()
{
    tiempo += GetFrameTime(); 
        
    if (tiempo >= 6.0f) {
        tiempo_actual -= 1;
        duracion += 1;
        tiempo -= 6.0f; // Reiniciamos el residuo
    }
}

void contador::dibujar()
{
    int tamaño = MeasureText(TextFormat("%i", tiempo_actual), 128);
    DrawText(TextFormat("%i", tiempo_actual), (256 - tamaño / 2) , 64, 128, GRAY);
}

void contador::sumar()
{
    tiempo_actual +=10;
}

bool contador::fin()
{
    if (tiempo_actual <= 0){return true;}
    return false;
}

void contador::reiniciar()
{
    tiempo_actual = 5;
    duracion = 0;
}

int contador::tiempo_partida()
{
    return duracion;
}
