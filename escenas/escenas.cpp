#include "escenas.h"

void escenas::cargar(Texture2D _textura){
    textura.reserve(3);
    textura.emplace_back(_textura);
}

void escenas::borrar(int i)
{
    cuarto_actual.erase(cuarto_actual.begin() + i);
}

void escenas::crear(int posx, int posy, int ancho, int alto, Color _color, Texture2D _textura, bool _es_puerta, bool _lastima, bool _destruible)
{
    cuarto_actual.emplace_back(posx, posy, ancho, alto, _color, _textura, _es_puerta, _lastima, _destruible);
}

void escenas::definir_cuarto(int i)
{
    cuarto_actual = cuarto_posible[i];
}

std::vector<ladrillo> escenas::cuarto()
{
    return cuarto_actual;
}

void escenas::cargar_escenas()
{
    cuarto_posible.emplace_back(cuarto1());
    cuarto_posible.emplace_back(cuarto2());
    cuarto_posible.emplace_back(cuarto3());
    cuarto_posible.emplace_back(cuarto4());
    cuarto_posible.emplace_back(cuarto5());
    cuarto_posible.emplace_back(cuarto6());
    cuarto_posible.emplace_back(cuarto7());
    cuarto_posible.emplace_back(cuarto8());
}

std::vector<ladrillo> escenas::cuarto1()
{
    std::vector<ladrillo> cuarto;
    cuarto.emplace_back(0, 0, 0, 516, WHITE, textura[0], false, true,false);
    cuarto.emplace_back(512, 0, 0, 512, WHITE, textura[0], false, true,false);
    cuarto.emplace_back(0, 0, 512, 0, WHITE, textura[0], false, true,false);
    cuarto.emplace_back(0, 512, 512, 0, WHITE, textura[0], false, true,false);

    cuarto.emplace_back(100, 300, 50, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(150, 300, 50, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(200, 300, 50, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(250, 300, 50, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(300, 300, 50, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(250, 200, 50, 100, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(350, 300, 100, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(300, 250, 50, 50, WHITE, textura[0], false, false,true);

    cuarto.emplace_back(400, 200, 50, 50, WHITE, textura[1], true, false,false);

    jugador_inicio.x = 200;
    jugador_inicio.y = 200;
    return cuarto;
}
std::vector<ladrillo> escenas::cuarto2(){
    std::vector<ladrillo> cuarto;

    cuarto.emplace_back(0, 0, 0, 516, WHITE, textura[0], false, true,false);
    cuarto.emplace_back(512, 0, 0, 512, WHITE, textura[0], false, true,false);
    cuarto.emplace_back(0, 0, 512, 0, WHITE, textura[0], false, true,false);
    cuarto.emplace_back(0, 512, 512, 0, WHITE, textura[0], false, true,false);
    
    cuarto.emplace_back(100, 300, 50, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(100, 250, 50, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(150, 300, 50, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(200, 300, 50, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(250, 300, 50, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(300, 300, 50, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(300, 200, 50, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(350, 200, 50, 100, WHITE, textura[0], false, false,true);

    cuarto.emplace_back(200, 100, 50, 50, WHITE, textura[1], true, false,false);
    return cuarto;
}
std::vector<ladrillo> escenas::cuarto3(){
    std::vector<ladrillo> cuarto;
    cuarto.emplace_back(0, 0, 0, 516, WHITE, textura[0], false, true,false);
    cuarto.emplace_back(512, 0, 0, 512, WHITE, textura[0], false, true,false);
    cuarto.emplace_back(0, 0, 512, 0, WHITE, textura[0], false, true,false);
    cuarto.emplace_back(0, 512, 512, 0, WHITE, textura[0], false, true,false);

    cuarto.emplace_back(200, 300, 50, 100, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(100, 350, 100, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(250, 200, 50, 100, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(300, 200, 100, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(350, 350, 50, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(100, 150, 50, 50, WHITE, textura[0], false, false,true);

    cuarto.emplace_back(350, 400, 50, 50, WHITE, textura[1], true, false,false);
    cuarto.emplace_back(100, 100, 50, 50, WHITE, textura[1], true, false,false);

    jugador_inicio.x = 200;
    jugador_inicio.y = 200;
    return cuarto;
}
std::vector<ladrillo> escenas::cuarto4(){
    std::vector<ladrillo> cuarto;
    cuarto.emplace_back(0, 0, 0, 516, WHITE, textura[0], false, true,false);
    cuarto.emplace_back(512, 0, 0, 512, WHITE, textura[0], false, true,false);
    cuarto.emplace_back(0, 0, 512, 0, WHITE, textura[0], false, true,false);
    cuarto.emplace_back(0, 512, 512, 0, WHITE, textura[0], false, true,false);

    cuarto.emplace_back(100, 300, 250, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(100, 150, 100, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(400, 250, 50, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(250, 150, 100, 50, WHITE, textura[0], false, false,true);

    cuarto.emplace_back(200, 100, 50, 50, WHITE, textura[1], true, false,false);

    jugador_inicio.x = 200;
    jugador_inicio.y = 200;
    return cuarto;
}
std::vector<ladrillo> escenas::cuarto5(){
    std::vector<ladrillo> cuarto;
    cuarto.emplace_back(0, 0, 0, 516, WHITE, textura[0], false, true,false);
    cuarto.emplace_back(512, 0, 0, 512, WHITE, textura[0], false, true,false);
    cuarto.emplace_back(0, 0, 512, 0, WHITE, textura[0], false, true,false);
    cuarto.emplace_back(0, 512, 512, 0, WHITE, textura[0], false, true,false);

    cuarto.emplace_back(128, 300, 200, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(256, 220, 100, 100, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(256, 220, 50, 50, WHITE, textura[2], false, false,true);
    cuarto.emplace_back(360, 128, 50, 50, WHITE, textura[1], true, false,false);
    return cuarto;
}
std::vector<ladrillo> escenas::cuarto6(){
    std::vector<ladrillo> cuarto;
    cuarto.emplace_back(0, 0, 0, 516, WHITE, textura[0], false, true,false);
    cuarto.emplace_back(512, 0, 0, 512, WHITE, textura[0], false, true,false);
    cuarto.emplace_back(0, 0, 512, 0, WHITE, textura[0], false, true,false);
    cuarto.emplace_back(0, 512, 512, 0, WHITE, textura[0], false, true,false);

    cuarto.emplace_back(128, 240, 200, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(400, 220, 50, 256, WHITE, textura[2], false, false,false);
    cuarto.emplace_back(256, 400, 50, 50, WHITE, textura[1], true, false,false);


    return cuarto;
}
std::vector<ladrillo> escenas::cuarto7(){
    std::vector<ladrillo> cuarto;
    cuarto.emplace_back(0, 0, 0, 516, WHITE, textura[0], false, true,false);
    cuarto.emplace_back(512, 0, 0, 512, WHITE, textura[0], false, true,false);
    cuarto.emplace_back(0, 0, 512, 0, WHITE, textura[0], false, true,false);
    cuarto.emplace_back(0, 512, 512, 0, WHITE, textura[0], false, true,false);

    cuarto.emplace_back(128, 320, 128, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(256, 364, 128, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(320, 300, 50, 50, WHITE, textura[2], false, true, true);
    cuarto.emplace_back(0, 480, 512, 50, WHITE, textura[2], false, false,false);
    cuarto.emplace_back(256, 128, 50, 50, WHITE, textura[1], true, true,false);
    return cuarto;
}
std::vector<ladrillo> escenas::cuarto8(){
    std::vector<ladrillo> cuarto;
    cuarto.emplace_back(0, 0, 0, 516, WHITE, textura[0], false, true,false);
    cuarto.emplace_back(512, 0, 0, 512, WHITE, textura[0], false, true,false);
    cuarto.emplace_back(0, 0, 512, 0, WHITE, textura[0], false, true,false);
    cuarto.emplace_back(0, 512, 512, 0, WHITE, textura[0], false, true,false);

    cuarto.emplace_back(0, 300, 50, 50, WHITE, textura[0], false, true,false);
    cuarto.emplace_back(100, 300, 50, 50, WHITE, textura[2], false, true,false);
    cuarto.emplace_back(200, 300, 50, 50, WHITE, textura[0], false, true,false);
    cuarto.emplace_back(300, 300, 50, 50, WHITE, textura[2], false, true,false);
    cuarto.emplace_back(400, 300, 50, 50, WHITE, textura[2], false, true,false);
    cuarto.emplace_back(300, 128, 50, 50, WHITE, textura[1], false, true,false);
    return cuarto;
}