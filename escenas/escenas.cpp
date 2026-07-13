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
    jugador_inicio.x = 200;
    jugador_inicio.y = 200;
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
    cuarto_posible.emplace_back(cuarto9());
    cuarto_posible.emplace_back(cuarto10());
}

std::vector<ladrillo> escenas::cuarto1()
{
    std::vector<ladrillo> cuarto;
    cuarto.emplace_back(-32, 0, 0, 544, WHITE, textura[0], false, true,false);
    cuarto.emplace_back(544, 0, 0, 544, WHITE, textura[0], false, true,false);
    cuarto.emplace_back(0, -32, 544, 0, WHITE, textura[0], false, true,false);
    cuarto.emplace_back(0, 544, 544, 0, WHITE, textura[0], false, true,false);

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

    cuarto.emplace_back(-32, 0, 0, 544, WHITE, textura[0], false, true,false);
    cuarto.emplace_back(544, 0, 0, 544, WHITE, textura[0], false, true,false);
    cuarto.emplace_back(0, -32, 544, 0, WHITE, textura[0], false, true,false);
    cuarto.emplace_back(0, 544, 544, 0, WHITE, textura[0], false, true,false);
    
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
    cuarto.emplace_back(-32, 0, 0, 544, WHITE, textura[0], false, true,false);
    cuarto.emplace_back(544, 0, 0, 544, WHITE, textura[0], false, true,false);
    cuarto.emplace_back(0, -32, 544, 0, WHITE, textura[0], false, true,false);
    cuarto.emplace_back(0, 544, 544, 0, WHITE, textura[0], false, true,false);

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
    cuarto.emplace_back(-32, 0, 0, 544, WHITE, textura[0], false, true,false);
    cuarto.emplace_back(544, 0, 0, 544, WHITE, textura[0], false, true,false);
    cuarto.emplace_back(0, -32, 544, 0, WHITE, textura[0], false, true,false);
    cuarto.emplace_back(0, 544, 544, 0, WHITE, textura[0], false, true,false);

    cuarto.emplace_back(100, 300, 250, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(100, 150, 100, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(400, 250, 50, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(250, 150, 100, 50, WHITE, textura[0], false, false,true);

    cuarto.emplace_back(200, 100, 50, 50, WHITE, textura[1], true, false,false);
    return cuarto;
}
std::vector<ladrillo> escenas::cuarto5(){
    std::vector<ladrillo> cuarto;
    cuarto.emplace_back(-32, 0, 0, 544, WHITE, textura[0], false, true,false);
    cuarto.emplace_back(544, 0, 0, 544, WHITE, textura[0], false, true,false);
    cuarto.emplace_back(0, -32, 544, 0, WHITE, textura[0], false, true,false);
    cuarto.emplace_back(0, 544, 544, 0, WHITE, textura[0], false, true,false);

    cuarto.emplace_back(150, 300, 100, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(200, 350, 50, 100, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(300, 250, 50, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(400, 100, 50, 250, WHITE, textura[2], false, true, false);

    cuarto.emplace_back(200, 100, 50, 50, WHITE, textura[1], true, false,false);
    return cuarto;
}
std::vector<ladrillo> escenas::cuarto6(){
    std::vector<ladrillo> cuarto;
    cuarto.emplace_back(-32, 0, 0, 544, WHITE, textura[0], false, true,false);
    cuarto.emplace_back(544, 0, 0, 544, WHITE, textura[0], false, true,false);
    cuarto.emplace_back(0, -32, 544, 0, WHITE, textura[0], false, true,false);
    cuarto.emplace_back(0, 544, 544, 0, WHITE, textura[0], false, true,false);

    cuarto.emplace_back(100, 400, 100, 100, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(200, 350, 100, 100, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(150, 350, 50, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(300, 350, 100, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(100, 50, 350, 50, BLUE, textura[0], false, false,true);
    cuarto.emplace_back(150, 0, 250, 50, BLUE, textura[0], false, false,true);
    cuarto.emplace_back(150, 100, 25, 300, WHITE, textura[2], false, true, false);
    cuarto.emplace_back(150, 200, 50, 300, WHITE, textura[0], false, false, false);
    cuarto.emplace_back(350, 100, 25, 250, WHITE, textura[2], false, true, false);

    cuarto.emplace_back(250, 100, 50, 50, WHITE, textura[1], true, false,false);
    return cuarto;
}
std::vector<ladrillo> escenas::cuarto7(){
    std::vector<ladrillo> cuarto;
    cuarto.emplace_back(-32, 0, 0, 544, WHITE, textura[0], false, true,false);
    cuarto.emplace_back(544, 0, 0, 544, WHITE, textura[0], false, true,false);
    cuarto.emplace_back(0, -32, 544, 0, WHITE, textura[0], false, true,false);
    cuarto.emplace_back(0, 544, 544, 0, WHITE, textura[0], false, true,false);

    cuarto.emplace_back(0, 300, 50, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(100, 300, 50, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(200, 400, 100, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(300, 300, 50, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(400, 300, 50, 50, WHITE, textura[0], false, false,true);

    cuarto.emplace_back(50, 200, 50, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(150, 200, 50, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(350, 200, 50, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(450, 200, 50, 50, WHITE, textura[0], false, false,true);
    
    cuarto.emplace_back(0, 100, 50, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(100, 100, 50, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(300, 100, 50, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(400, 100, 50, 50, WHITE, textura[0], false, false,true);

    cuarto.emplace_back(0, 450, 512, 50, WHITE, textura[2], false, true,false);

    cuarto.emplace_back(200, 100, 50, 50, WHITE, textura[1], true,false,false);
    return cuarto;
}
std::vector<ladrillo> escenas::cuarto8(){
    std::vector<ladrillo> cuarto;
    cuarto.emplace_back(-32, 0, 0, 544, WHITE, textura[0], false, true,false);
    cuarto.emplace_back(544, 0, 0, 544, WHITE, textura[0], false, true,false);
    cuarto.emplace_back(0, -32, 544, 0, WHITE, textura[0], false, true,false);
    cuarto.emplace_back(0, 544, 544, 0, WHITE, textura[0], false, true,false);

    cuarto.emplace_back(0, 250, 25, 250, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(100, 300, 25, 200, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(200, 300, 25, 200, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(300, 300, 25, 200, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(400, 300, 25, 200, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(300, 150, 200, 25, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(200, 200, 100, 25, WHITE, textura[0], false, false,true);

    cuarto.emplace_back(0, 450, 512, 50, WHITE, textura[2], false, true,false);

    cuarto.emplace_back(400, 100, 50, 50, WHITE, textura[1], true,false,false);
    return cuarto;
}
std::vector<ladrillo> escenas::cuarto10(){
    std::vector<ladrillo> cuarto;
    cuarto.emplace_back(-32, 0, 0, 544, WHITE, textura[0], false, true,false);
    cuarto.emplace_back(544, 0, 0, 544, WHITE, textura[0], false, true,false);
    cuarto.emplace_back(0, -32, 544, 0, WHITE, textura[0], false, true,false);
    cuarto.emplace_back(0, 544, 544, 0, WHITE, textura[0], false, true,false);

    cuarto.emplace_back(0, 350, 50, 50, RED, textura[0], false, false,true);
    cuarto.emplace_back(50, 350, 50, 50, GREEN, textura[0], false, false,true);
    cuarto.emplace_back(100, 350, 50, 50, YELLOW, textura[0], false, false,true);
    cuarto.emplace_back(150, 350, 50, 50, BLUE, textura[0], false, false,true);
    cuarto.emplace_back(200, 350, 50, 50, PURPLE, textura[0], false, false,true);
    cuarto.emplace_back(250, 350, 50, 50, ORANGE, textura[0], false, false,true);
    cuarto.emplace_back(300, 350, 50, 50, RED, textura[0], false, false,true);
    cuarto.emplace_back(350, 350, 50, 50, GREEN, textura[0], false, false,true);
    cuarto.emplace_back(400, 350, 50, 50, YELLOW, textura[0], false, false,true);
    cuarto.emplace_back(450, 350, 50, 50, BLUE, textura[0], false, false,true);
    cuarto.emplace_back(500, 350, 50, 50, PURPLE, textura[0], false, false,true);

    cuarto.emplace_back(0, 400, 512, 200, WHITE, textura[2], false, true,true);
    cuarto.emplace_back(224, 150, 50, 25, WHITE, textura[0], false,false,true);
    cuarto.emplace_back(231, 0, 25, 100, WHITE, textura[0], false,false,true);

    cuarto.emplace_back(224, 100, 50, 50, WHITE, textura[1], true,false,false);
    return cuarto;
}
std::vector<ladrillo> escenas::cuarto9(){
    std::vector<ladrillo> cuarto;
    cuarto.emplace_back(-32, 0, 0, 544, WHITE, textura[0], false, true,false);
    cuarto.emplace_back(544, 0, 0, 544, WHITE, textura[0], false, true,false);
    cuarto.emplace_back(0, -32, 544, 0, WHITE, textura[0], false, true,false);
    cuarto.emplace_back(0, 544, 544, 0, WHITE, textura[0], false, true,false);

    cuarto.emplace_back(0, 300, 50, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(50, 300, 50, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(100, 300, 50, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(150, 300, 50, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(200, 300, 50, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(250, 300, 50, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(300, 300, 50, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(350, 300, 50, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(400, 300, 50, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(450, 300, 50, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(500, 300, 50, 50, WHITE, textura[0], false, false,true);

    cuarto.emplace_back(0, 350, 50, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(50, 350, 50, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(100, 350, 50, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(150, 350, 50, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(200, 350, 50, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(250, 350, 50, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(300, 350, 50, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(350, 350, 50, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(400, 350, 50, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(450, 350, 50, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(500, 350, 50, 50, WHITE, textura[0], false, false,true);

    cuarto.emplace_back(0, 400, 50, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(50, 400, 50, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(100, 400, 50, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(150, 400, 50, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(200, 400, 50, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(250, 400, 50, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(300, 400, 50, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(350, 400, 50, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(450, 400, 50, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(500, 400, 50, 50, WHITE, textura[0], false, false,true);

    cuarto.emplace_back(0, 200, 50, 50, GREEN, textura[0], false, false,true);
    cuarto.emplace_back(50, 200, 50, 50, GREEN, textura[0], false, false,true);
    cuarto.emplace_back(100, 200, 50, 50, GREEN, textura[0], false, false,true);
    cuarto.emplace_back(450, 200, 50, 50, GREEN, textura[0], false, false,true);
    cuarto.emplace_back(500, 200, 50, 50, GREEN, textura[0], false, false,true);

    cuarto.emplace_back(0, 250, 50, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(50, 250, 50, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(100, 250, 50, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(150, 250, 50, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(350, 250, 50, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(400, 250, 50, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(450, 250, 50, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(500, 250, 50, 50, WHITE, textura[0], false, false,true);

    cuarto.emplace_back(400, 400, 50, 50, WHITE, textura[1], true,false,false);
    return cuarto;
}