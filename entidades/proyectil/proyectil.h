#pragma once
#include <raylib.h>

class proyectil
{
private:
    Rectangle hitbox;
    Vector2 velocidad;
    Vector2 direccion;
    Texture2D textura;
    bool puede_destruir;
    bool puede_crear;
public:
    bool esta_colisionando;
    proyectil(Rectangle hitbox, Vector2 direccion, bool puede_destruir,bool puede_crear);
    void dibujar();
    void mover();
    void colisiona(Rectangle collision);
};
