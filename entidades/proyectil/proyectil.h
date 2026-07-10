#pragma once
#include <raylib.h>
#include "../ladrillo/ladrillo.h"

class proyectil
{
private:
    Rectangle hitbox;
    Vector2 velocidad;
    Vector2 direccion;
    Texture2D textura;
    bool puede_destruir;
    bool puede_crear;
    int tipo;
public:
    bool esta_colisionando;
    proyectil(Rectangle hitbox, Vector2 direccion, int tipo);
    void dibujar();
    void mover();
    void colisiona(ladrillo collision);
    bool destruir();
    bool crear();
    Rectangle devolver_hitbox();
    bool estado_colision();
    int mostrar_tipo();
};
