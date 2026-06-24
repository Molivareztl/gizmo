#pragma once
#include <raylib.h>
#include <vector>
#include "../proyectil/proyectil.h"
class jugador
{
private:
    Vector2 posicion;
    Vector2 velocidad;
    int gravedad;
    float direccion_sprite;
    int velocidad_disparo;
    bool esta_colisionando;
    bool puede_disparar;
    Texture2D sprite;
    Rectangle hitbox;
    Vector2 direccion;
    Vector2 tamaño;
public:
    int id_textura = 0;
    std::vector<proyectil> proyectiles;
    jugador();
    void ubicar(int posx, int posy);
    void cargar( Texture2D textura);
    void dibujar();
    void actualizar();
    bool estado_colision(Rectangle collision);
    void colisiona(Rectangle collision);
    void disparar();
    void vaciar();
};

