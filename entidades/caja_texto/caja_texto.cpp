#include "caja_texto.h"

caja_texto::caja_texto(int posx, int posy, int ancho, int alto, Color _color)
{
    hitbox.width = ancho;
    hitbox.height = alto;
    hitbox.x = posx - hitbox.width / 2;
    hitbox.y = posy - hitbox.height / 2;
    cantidad = 0;
    caracteres[9] = '\0';
}
void caja_texto::escribir()
{
    int tecla = GetCharPressed();
    while (tecla > 0)
    {
        if ((tecla >= 5)&&(tecla <= 125) && cantidad <9)
        {
           caracteres[cantidad] =(char) tecla;
           cantidad++;
           caracteres[cantidad] = '\0';
        }
        tecla = GetCharPressed();
    }
    if (IsKeyPressed(KEY_BACKSPACE))
    {
        caracteres[cantidad] =(char) tecla;
        cantidad--;
        if (cantidad < 0)
        {
            cantidad = 0;
        }
        caracteres[cantidad] = '\0';
    }
}
void caja_texto::dibujar()
{
    int tamaño_texto = MeasureText(caracteres,32);
    DrawRectangle(hitbox.x,hitbox.y,hitbox.width,hitbox.height,RED);
    DrawText(caracteres,hitbox.x, hitbox.y,32,WHITE);
}

const char* caja_texto::datos()
{
    const char* nombre = caracteres;
    return nombre;
}
