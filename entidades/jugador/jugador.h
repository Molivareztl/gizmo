#pragma once
#include <raylib.h>
class jugador
{
private:
    Vector2 posicion;
    Vector2 velocidad;
    int gravedad;
    bool esta_colisionando;
    Texture2D sprite;
    Rectangle hitbox;
    Vector2 tamaño;
public:
    jugador();
    ~jugador();
    void cargar();
    void dibujar();
    void actualizar();
    void colisiona(Rectangle collision);
};

