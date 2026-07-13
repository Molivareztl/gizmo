#pragma once
#include "../entidades/ladrillo/ladrillo.h"
#include "../media/gestor_media.h"
#include "../entidades/puerta/puerta.h"
#include "raylib.h"
#include <vector>
class escenas
{
    private:
    std::vector<ladrillo> cuarto_actual;
    std::vector<std::vector<ladrillo>> cuarto_posible;
    public:
    void cargar_escenas();
    Vector2 jugador_inicio;
    std::vector<ladrillo> cuarto1();
    std::vector<ladrillo> cuarto2();
    std::vector<ladrillo> cuarto3();
    std::vector<ladrillo> cuarto4();
    std::vector<ladrillo> cuarto5();
    std::vector<ladrillo> cuarto6();
    std::vector<ladrillo> cuarto7();
    std::vector<ladrillo> cuarto8();
    std::vector<ladrillo> cuarto9();
    std::vector<ladrillo> cuarto10();
    std::vector <Texture2D> textura;
    void cargar(Texture2D textura);
    void borrar(int i);
    void crear(int posx,int posy,int ancho, int alto, Color _color, Texture2D _textura, bool _es_puerta, bool _lastima, bool _destruible);
    void definir_cuarto(int i);
    std::vector<ladrillo> cuarto();
    
};