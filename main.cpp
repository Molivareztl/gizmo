
#include <raylib.h>
#include "entidades/jugador/jugador.h"
#include "entidades/ladrillo/ladrillo.h"
#include "escenas/escenas.h"
#include "media/gestor_media.h"
#include "entidades/contador/contador.h"
#include <vector>
#include <chrono>

int main(){
    const int screenWidth = 512;//ancho de pantalla
    const int screenHeight = 512;//alto de pantalla 
    contador contador;
    jugador jugador;//iniciar el jugador
    InitWindow(screenWidth, screenHeight, "gizmo");//iniciar la ventana
    SetTargetFPS(60);// definir frames
    gestor_media gestor_imagenes;//iniciar el gestor de imagenes
    escenas escenas;//iniciar el gestor de escenas
    escenas.cargar(gestor_imagenes.buscar(1));
    escenas.cargar(gestor_imagenes.buscar(2));
    jugador.cargar(gestor_imagenes.buscar(0));//carga todo el contenido de media asociado al jugador
    
    std::vector<std::vector<ladrillo>> cuarto_posible;//iniciar el vector de cuarto
    //cargar niveles :
    cuarto_posible.emplace_back(escenas.cuarto1());
    cuarto_posible.emplace_back(escenas.cuarto2());
    bool kill = 0;

    std::vector<ladrillo> cuarto_actual = cuarto_posible[GetRandomValue(0,1)];//seleccionar un nivel aleatorio
    jugador.ubicar(escenas.jugador_inicio.x, escenas.jugador_inicio.y);//posición inicial del jugador
    // bucle del juego
    while (!WindowShouldClose() && kill == 0){
        BeginDrawing();//empezar el dibujado de imagen
        DrawTexturePro(gestor_imagenes.buscar(4),Rectangle{0, 0, 320, 320},Rectangle{0, 0, 512, 512},Vector2{0, 0},0,WHITE);
        
        //dibujar la escena

        DrawText(TextFormat("%i", jugador.mostrar_punto()),64,64, 64, WHITE);

        contador.dibujar();
        for (size_t i = 0; i < cuarto_actual.size(); i++){
            jugador.colisiona(cuarto_actual[i].hitbox);
            contador.contar();
            cuarto_actual[i].dibujar();
            //dibujar los proyectiles
            if(!jugador.proyectiles.empty()){
                for (size_t j = 0; j < jugador.proyectiles.size(); j++){
                    jugador.proyectiles[j].dibujar();
                    jugador.proyectiles[j].colisiona(cuarto_actual[i].hitbox);
                    //detectar colisiones de proyectil
                    if (jugador.proyectiles[j].esta_colisionando == true){
                        switch (jugador.proyectiles[j].tipo){
                            case 0:
                            if (cuarto_actual[i].destruible == true)
                            {
                                cuarto_actual.erase(cuarto_actual.begin() + i);
                                jugador.proyectiles.erase(jugador.proyectiles.begin() + j);
                            }
                            break;
                            case 1:
                                Rectangle hitbox = jugador.proyectiles[j].devolver_hitbox();
                                cuarto_actual.emplace_back(hitbox.x - hitbox.width,hitbox.y - hitbox.height,50,50, GREEN, gestor_imagenes.buscar(1), false, false, true);
                                jugador.proyectiles.erase(jugador.proyectiles.begin() + j);
                            break;
                        }
                    }
                }
            }
            //detectar el contacto con la puerta
            if (cuarto_actual[i].es_puerta == true && jugador.estado_colision(cuarto_actual[i].hitbox) == true){
                jugador.sumar_punto();
                cuarto_actual.clear();
                cuarto_actual = cuarto_posible[GetRandomValue(0,1)];
                jugador.ubicar(escenas.jugador_inicio.x, escenas.jugador_inicio.y);
                jugador.vaciar();
                break;
            }
            if (cuarto_actual[i].lastima == true && jugador.estado_colision(cuarto_actual[i].hitbox) == true){
                cuarto_actual.clear();
                
                cuarto_actual = cuarto_posible[GetRandomValue(0,1)];
                jugador.ubicar(escenas.jugador_inicio.x, escenas.jugador_inicio.y);
                jugador.vaciar();
                break;
            }
        }
        for (size_t i = 0; i < jugador.proyectiles.size(); i++)
        {
            jugador.proyectiles[i].dibujar();
            jugador.proyectiles[i].mover();
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