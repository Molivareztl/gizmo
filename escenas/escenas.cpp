#include "escenas.h"
#include "../entidades/ladrillo/ladrillo.h"
#include <raylib.h>
#include <vector>

std::vector<ladrillo> cuarto1(){
    std::vector<ladrillo> cuarto1;
    cuarto1.emplace_back(0,200,50,50, RED);
    cuarto1.emplace_back(100,200,50,50, YELLOW);
    cuarto1.emplace_back(200,200,50,50, BLUE);
    cuarto1.emplace_back(300,200,50,50, WHITE);
    cuarto1.emplace_back(400,200,50,50, GREEN);
    cuarto1.emplace_back(500,200,50,50, PURPLE);
    cuarto1.emplace_back(0, 500, 512, 12, BLACK);

    return cuarto1;
}
std::vector<ladrillo> cuarto2(){
    std::vector<ladrillo> cuarto2;

    cuarto2.emplace_back(0,200,50,50, RED);
    cuarto2.emplace_back(100,200,50,50, YELLOW);
    cuarto2.emplace_back(400,200,50,50, GREEN);
    cuarto2.emplace_back(500,200,50,50, PURPLE);
    cuarto2.emplace_back(0, 500, 512, 12, BLACK);

    return cuarto2;
}