#include "contador.h"

contador::contador()
{
    tiempo = 0.0f;
    tiempo_original = 60;
    tiempo_actual = tiempo_original;
    duracion = 0;
}

void contador::contar()
{
    tiempo += GetFrameTime(); 
        
    if (tiempo >= 10.0f) {
        tiempo_actual -= 1;
        duracion += 1;
        tiempo -= 10.0f; // Reiniciamos el residuo
    }
}

void contador::dibujar()
{
    int tamaño = MeasureText(TextFormat("%i", tiempo_actual), 128);
    DrawText(TextFormat("%i", tiempo_actual), (256 - tamaño / 2) , 64, 128, GRAY);
}

void contador::modificar(int num)
{
    tiempo_actual += num;
}

bool contador::fin()
{
    if (tiempo_actual <= 0){return true;}
    return false;
}

void contador::reiniciar()
{
    tiempo_actual = tiempo_original;
    duracion = 0;
}

int contador::tiempo_partida()
{
    return duracion;
}
