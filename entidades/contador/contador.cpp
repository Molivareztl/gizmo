#include "contador.h"

contador::contador()
{
    contadorTiempo = 0.0f;
    segundosTranscurridos = 0;
}

void contador::contar()
{
    contadorTiempo += GetFrameTime(); 
        
    if (contadorTiempo >= 3.0f) {
        segundosTranscurridos++;
        contadorTiempo -= 3.0f; // Reiniciamos el residuo
    }
}

void contador::dibujar()
{

    DrawText(TextFormat("%i", segundosTranscurridos),64, 64, 32, WHITE);
}