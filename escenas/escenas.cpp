#include "escenas.h"
#include "../entidades/puerta/puerta.h"

void escenas::cargar(Texture2D _textura){
    textura.reserve(2);
    textura.emplace_back(_textura);
}

std::vector<ladrillo> escenas::cuarto1(){
    std::vector<ladrillo> cuarto1;
    cuarto1.emplace_back(0, 0, 0, 516, WHITE, textura[0], false, true,false);
    cuarto1.emplace_back(512, 0, 0, 512, WHITE, textura[0], false, true,false);
    cuarto1.emplace_back(0, 0, 512, 0, WHITE, textura[0], false, true,false);
    cuarto1.emplace_back(0, 512, 512, 0, WHITE, textura[0], false, true,false);
    
    cuarto1.emplace_back(0,200,50,50, RED, textura[0], false, false,true);
    cuarto1.emplace_back(100,200,50,50, YELLOW, textura[0], false, false,true);
    cuarto1.emplace_back(200,200,50,50, BLUE, textura[0], false, false,true);
    cuarto1.emplace_back(300,200,50,100, WHITE, textura[0], false, false,true);
    cuarto1.emplace_back(400,200,50,50, GREEN, textura[0], false, false,true);
    cuarto1.emplace_back(500,100,50,100, PURPLE, textura[0], false, false,true);

    cuarto1.emplace_back(256, 400, 50, 50, WHITE, textura[1], true, false,false);

    jugador_inicio.x = 100;
    jugador_inicio.y = 100;
    return cuarto1;
}
std::vector<ladrillo> escenas::cuarto2(){
    std::vector<ladrillo> cuarto2;
    cuarto2.emplace_back(0,200,50,50, RED, textura[0], false, false,true);
    cuarto2.emplace_back(100,200,50,50, YELLOW, textura[0], false, false,true);
    cuarto2.emplace_back(200,200,50,50, BLUE, textura[0], false, false,true);
    cuarto2.emplace_back(500,200,50,50, PURPLE, textura[0], false, false,true);
    cuarto2.emplace_back(0, 500, 512, 12, WHITE, textura[1], false, true,false);
    jugador_inicio.x = 200;
    jugador_inicio.y = 100;
    return cuarto2;
}
