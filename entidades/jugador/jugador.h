#pragma once
#include "raylib.h"
#include <vector>
#include "../proyectil/proyectil.h"
#include "../ladrillo/ladrillo.h"
#include <chrono>
#include <thread>
class jugador
{
private:
    Vector2 velocidad;
    Vector2 posicion_animacion;
    int velocidad_disparo;
    int opcion;
    bool en_el_suelo;
    bool puede_disparar;
    bool estado_vida;
    bool atravesar_puerta;
    bool input;
    int habitaciones_pasadas;
    std::vector<int> municion;
    std::vector<Texture2D> textura;
    std::vector<Sound> efectos;
    Rectangle hitbox;
    Vector2 direccion;
    bool animacion;
    Rectangle atlas;
public:
    jugador();
    int perdidas;
    std::vector<proyectil> proyectiles;
    void ubicar(int posx, int posy);
    void cargar( Texture2D textura);
    void cargar( Sound textura);
    void dibujar();
    void actualizar();
    void colisiona(ladrillo collision);
    void disparar();
    void vaciar();
    void sumar_punto();
    int mostrar_punto();
    bool colision_lastima();
    bool colision_puerta();
    void animar();
    Vector2 posicion_actual();
};

