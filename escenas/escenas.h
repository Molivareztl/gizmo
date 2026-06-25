#pragma once
#include "../entidades/ladrillo/ladrillo.h"
#include "../media/gestor_media.h"
#include "../entidades/puerta/puerta.h"
#include <raylib.h>
#include <vector>
class escenas
{
    public:
    std::vector<ladrillo> cuarto1();
    std::vector<ladrillo> cuarto2();
    std::vector <Texture2D> textura;
    void cargar(Texture2D textura);
    Vector2 jugador_inicio;
    void agregar(Rectangle hitbox);
};