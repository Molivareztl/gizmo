
#include <raylib.h>
#include "entidades/jugador/jugador.h"
#include "entidades/ladrillo/ladrillo.h"
#include "escenas/escenas.h"
#include "media/gestor_media.h"
#include <vector>

int main()
{
    const int screenWidth = 512;
    const int screenHeight = 512;

    jugador jugador;
    
    InitWindow(screenWidth, screenHeight, "gizmo");//screen size
    SetTargetFPS(60);//frames

    gestor_media gestor_imagenes;//iniciar el gestor de imagenes
    escenas escenas;
    escenas.cargar(gestor_imagenes.buscar(1));
    jugador.cargar(gestor_imagenes.buscar(jugador.id_textura));//carga todo el contenido de media asociado al jugador
    
    std::vector<std::vector<ladrillo>> cuarto_posible;

    cuarto_posible.emplace_back(escenas.cuarto1());//cargar niveles
    cuarto_posible.emplace_back(escenas.cuarto2());

    std::vector<ladrillo> cuarto_actual = cuarto_posible[GetRandomValue(0,1)];

    // bucle del juego
    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(SKYBLUE);//el fondo
            DrawText("gizmo!", 190, 100, 20, BLUE);// el texto
            for (size_t i = 0; i < cuarto_actual.size(); i++)
            {
                jugador.colisiona(cuarto_actual[i].hitbox);
                cuarto_actual[i].dibujar();
            }
            jugador.dibujar();// dibuja al jugador
            jugador.actualizar(); // actualiza la posición del jugador
            DrawFPS(10, 10);//dibuja los frames
        EndDrawing();
    }
    gestor_imagenes.vaciar();
    CloseWindow();
    return 0;
}