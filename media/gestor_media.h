#pragma once
#include <raylib.h>
#include <vector>

class gestor_media
{
private:
    std::vector<Texture2D>imagenes;
    std::vector<Sound> sonidos;
public:
    gestor_media();
    Texture2D buscar(int id);
    void vaciar();
};