
#include <raylib.h>
#include "entidades/jugador/jugador.h"
#include "entidades/ladrillo/ladrillo.h"
#include "escenas/escenas.h"
#include "media/gestor_media.h"
#include <vector>

int main(){
    const int screenWidth = 512;//ancho de pantalla
    const int screenHeight = 512;//alto de pantalla 
    jugador jugador;//iniciar el jugador
    
    InitWindow(screenWidth, screenHeight, "gizmo");//screen size
    SetTargetFPS(60);//frames

    gestor_media gestor_imagenes;//iniciar el gestor de imagenes
    escenas escenas;//iniciar el gestor de escenas
    escenas.cargar(gestor_imagenes.buscar(1));
    jugador.cargar(gestor_imagenes.buscar(jugador.id_textura));//carga todo el contenido de media asociado al jugador
    
    std::vector<std::vector<ladrillo>> cuarto_posible;//iniciar el vector de cuarto
    //cargar niveles :
    cuarto_posible.emplace_back(escenas.cuarto1());
    cuarto_posible.emplace_back(escenas.cuarto2());

    std::vector<ladrillo> cuarto_actual = cuarto_posible[GetRandomValue(0,1)];//seleccionar un nivel aleatorio

    // bucle del juego
    while (!WindowShouldClose())
    {
        BeginDrawing();//empezar el dibujado de imagen
            ClearBackground(WHITE);//el fondo
            DrawTexturePro(gestor_imagenes.buscar(3),Rectangle{0, 0, 320, 320},Rectangle{0, 0, 512, 512},Vector2{0, 0},0,WHITE);
            for (size_t i = 0; i < cuarto_actual.size(); i++)
            {
                jugador.colisiona(cuarto_actual[i].hitbox);
                cuarto_actual[i].dibujar();
            }
            jugador.dibujar();// dibuja al jugador
            jugador.actualizar(); // actualiza la posición del jugador
            DrawFPS(10, 10);//dibuja los frames
        EndDrawing();//terminar el dibujado de imagen
    }
    gestor_imagenes.vaciar();//quitar todas las imagenes del gestor de imagenes
    CloseWindow();
    return 0;
}