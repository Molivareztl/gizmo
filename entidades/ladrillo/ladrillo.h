#pragma once
#include <raylib.h>
class ladrillo
{
private:
    Vector2 transicion;
    Vector2 velocidad;
public:
    int id_textura = 1;
    Rectangle hitbox;
    Color color;
    Texture2D textura;
    bool es_puerta;
    bool lastima;
    bool destruible;
    Vector2 vel;
    ladrillo(int posx,int posy,int ancho, int alto, Color _color, Texture2D textura, bool es_puerta, bool lastima, bool destruible);
    void dibujar();
    bool puede_lastimar();
    bool puede_pasar();
    bool se_puede_destruir();
    void definir_animacion(int posx, int posy);
    void animacion();
};

