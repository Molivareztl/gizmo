#pragma once
#include <raylib.h>
#include <vector>
#include "../proyectil/proyectil.h"
#include <chrono>
#include <thread>
class jugador
{
private:
    Vector2 posicion;
    Vector2 velocidad;
    int gravedad;
    float direccion_sprite;
    int velocidad_disparo;
    int opcion;
    bool en_el_suelo;
    bool esta_colisionando;
    bool puede_disparar;
    int habitaciones_pasadas;
    std::vector<int> municion;
    std::vector<Texture2D> textura;
    Rectangle hitbox;
    Vector2 direccion;
    Vector2 tamaño;
public:
    
    int perdidas;
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
    void sumar_punto();
    int mostrar_punto();
};

