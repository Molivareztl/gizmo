#include "escenas.h"
#include "../entidades/puerta/puerta.h"

void escenas::cargar(Texture2D _textura){
    textura.reserve(3);
    textura.emplace_back(_textura);
}

std::vector<ladrillo> escenas::cuarto1(){
    std::vector<ladrillo> cuarto;
    cuarto.emplace_back(0, 0, 0, 516, WHITE, textura[0], false, true,false);
    cuarto.emplace_back(512, 0, 0, 512, WHITE, textura[0], false, true,false);
    cuarto.emplace_back(0, 0, 512, 0, WHITE, textura[0], false, true,false);
    cuarto.emplace_back(0, 512, 512, 0, WHITE, textura[0], false, true,false);

    cuarto.emplace_back(128, 265, 256, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(256, 180, 50, 100, WHITE, textura[0], false, false,true);

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

    cuarto.emplace_back(128, 265, 256, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(300, 216, 100, 50, WHITE, textura[0], false, false,true);

    cuarto.emplace_back(200, 80, 50, 50, WHITE, textura[1], true, false,false);
    return cuarto;
}
std::vector<ladrillo> escenas::cuarto3(){
    std::vector<ladrillo> cuarto;
    cuarto.emplace_back(0, 0, 0, 516, WHITE, textura[0], false, true,false);
    cuarto.emplace_back(512, 0, 0, 512, WHITE, textura[0], false, true,false);
    cuarto.emplace_back(0, 0, 512, 0, WHITE, textura[0], false, true,false);
    cuarto.emplace_back(0, 512, 512, 0, WHITE, textura[0], false, true,false);

    cuarto.emplace_back(128, 265, 256, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(300, 165, 50, 100, WHITE, textura[2], false, true,false);

    cuarto.emplace_back(400, 200, 50, 50, WHITE, textura[1], true, false,false);

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

    cuarto.emplace_back(128, 300, 256, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(128, 128, 50, 50, WHITE, textura[1], true, false,false);
    cuarto.emplace_back(178, 128, 256, 50, WHITE, textura[0], false, false,true);
    cuarto.emplace_back(128, 178, 50, 122, WHITE, textura[2], false, true,true);

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

    jugador_inicio.x = 200;
    jugador_inicio.y = 200;
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

    jugador_inicio.x = 200;
    jugador_inicio.y = 200;
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

    jugador_inicio.x = 200;
    jugador_inicio.y = 200;
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

    jugador_inicio.x = 200;
    jugador_inicio.y = 200;
    return cuarto;
}