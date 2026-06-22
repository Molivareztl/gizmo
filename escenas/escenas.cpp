#include "escenas.h"

void escenas::cargar(Texture2D _textura)
{
    textura = _textura;
}

std::vector<ladrillo> escenas::cuarto1()
{
    std::vector<ladrillo> cuarto1;
    cuarto1.emplace_back(0,200,50,50, RED, textura);
    cuarto1.emplace_back(100,200,50,50, YELLOW, textura);
    cuarto1.emplace_back(200,200,50,50, BLUE, textura);
    cuarto1.emplace_back(300,200,50,100, WHITE, textura);
    cuarto1.emplace_back(400,200,50,50, GREEN, textura);
    cuarto1.emplace_back(500,200,50,50, PURPLE, textura);
    cuarto1.emplace_back(0, 500, 512, 12, BLACK, textura);

    return cuarto1;
}
std::vector<ladrillo> escenas::cuarto2()
{
    std::vector<ladrillo> cuarto2;
    cuarto2.emplace_back(0,200,50,50, RED, textura);
    cuarto2.emplace_back(100,200,50,50, YELLOW, textura);
    cuarto2.emplace_back(200,200,50,50, BLUE, textura);
    cuarto2.emplace_back(500,200,50,50, PURPLE, textura);
    cuarto2.emplace_back(0, 500, 512, 12, BLACK, textura);
    return cuarto2;
}

