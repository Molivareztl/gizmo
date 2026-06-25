#pragma once
#include <raylib.h>

class proyectil
{
private:
    Rectangle hitbox;
    Vector2 velocidad;
    Vector2 direccion;
    Texture2D textura;
public:
    bool esta_colisionando;
    int tipo;
    proyectil(Rectangle hitbox, Vector2 direccion, int tipo);
    void dibujar();
    void mover();
    void colisiona(Rectangle collision);
    Rectangle devolver_hitbox();
};
