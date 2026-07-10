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
    std::vector<ladrillo> cuarto3();
    std::vector<ladrillo> cuarto4();
    std::vector<ladrillo> cuarto5();
    std::vector<ladrillo> cuarto6();
    std::vector<ladrillo> cuarto7();
    std::vector<ladrillo> cuarto8();
    std::vector <Texture2D> textura;
    void cargar(Texture2D textura);
    Vector2 jugador_inicio;
};