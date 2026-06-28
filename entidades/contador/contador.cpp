#include "contador.h"

contador::contador()
{
    contadorTiempo = 0.0f;
    segundosTranscurridos = 60;
}

void contador::contar()
{
    contadorTiempo += GetFrameTime(); 
        
    if (contadorTiempo >= 6.0f) {
        segundosTranscurridos -= 1;
        contadorTiempo -= 6.0f; // Reiniciamos el residuo
    }
}

void contador::dibujar()
{
    int tamaño = MeasureText(TextFormat("%i", segundosTranscurridos), 128);
    DrawText(TextFormat("%i", segundosTranscurridos), (256 - tamaño / 2) , 64, 128, GRAY);
}

void contador::sumar()
{
    segundosTranscurridos +=10;
}
