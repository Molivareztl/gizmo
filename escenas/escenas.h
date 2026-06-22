#pragma once
#include "../entidades/ladrillo/ladrillo.h"
#include "../media/gestor_media.h"
#include <raylib.h>
#include <vector>
class escenas
{
    public:
    std::vector<ladrillo> cuarto1();
    std::vector<ladrillo> cuarto2();
    Texture2D textura;
    void cargar(Texture2D textura);
};