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
    Rectangle direccion;
    Vector2 tamaño;
public:
    int id_textura = 0;
    jugador();
    void ubicar(int posx, int posy);
    void cargar( Texture2D textura);
    void dibujar();
    void actualizar();
    bool estado_colision(Rectangle collision);
    void colisiona(Rectangle collision);
};

