
#include <raylib.h>//headers de juego
#include <vector>
#include "entidades/jugador/jugador.h"
#include "entidades/ladrillo/ladrillo.h"
#include "escenas/escenas.h"
#include "media/gestor_media.h"
#include "entidades/contador/contador.h"
#include "entidades/boton/boton.h"
#include "entidades/caja_texto/caja_texto.h"
#include "conector/gestor_conexion.h"

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
    jugador.cargar(gestor_imagenes.buscar(7));//carga todo el contenido de media asociado al jugador
    jugador.cargar(gestor_imagenes.buscar(8));//carga todo el contenido de media asociado al jugador


    std::vector<std::vector<ladrillo>> cuarto_posible;//iniciar el vector de cuarto
    //cargar niveles :
    cuarto_posible.emplace_back(escenas.cuarto1());
    cuarto_posible.emplace_back(escenas.cuarto2());

    int menu_opcion = 0;

    caja_texto usuario(256,256,256,48,RED);//nombre del usuario

    std::vector<ladrillo> cuarto_actual = cuarto_posible[GetRandomValue(0,1)];//seleccionar un nivel aleatorio
    jugador.ubicar(escenas.jugador_inicio.x, escenas.jugador_inicio.y);//posición inicial del jugador
    // bucle del juego
    while (WindowShouldClose() == false && menu_opcion != 3){
        BeginDrawing();//empezar el dibujado de imagen

            Vector2 raton = GetMousePosition();
            bool raton_presionado = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

            DrawTexturePro(gestor_imagenes.buscar(4),Rectangle{0, 0, 320, 320},Rectangle{0, 0, 512, 512},Vector2{0, 0},0,WHITE);
        
        if (menu_opcion == 1 && contador.fin() == false){//solo se dibuja con el contador activo y la opcion 'iniciar' activa
            //dibujar la escena
            DrawText(TextFormat("%i", jugador.mostrar_punto()),240,16, 64, WHITE);
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
                        //detectar colisiones de proyectil y definit su comportamiento
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
                    contador.sumar();
                    break;
                }
                //detectar el contacto con un 'ladrillo malo'
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
        }else if(contador.fin() == true && menu_opcion == 1){menu_opcion = 2;}

        switch(menu_opcion){//menu inicial
            case 0:{
                DrawTexturePro(gestor_imagenes.buscar(6),Rectangle{0, 0, 256, 128},Rectangle{128, 64, 256, 128},Vector2{0, 0},0,WHITE);
                boton iniciar(256,256,128,48,gestor_imagenes.buscar(1));
                boton ayuda(256,312,128,48,gestor_imagenes.buscar(1));
                boton salir(256,368,128,48,gestor_imagenes.buscar(1));
                iniciar.dibujar("iniciar");
                ayuda.dibujar("ayuda");
                salir.dibujar("salir");
                if(iniciar.presionado(raton,raton_presionado)){menu_opcion = 1;}
                if(ayuda.presionado(raton,raton_presionado)){OpenURL("https://www.youtube.com/watch?v=0Ct9ZWEUm7M&t=792s");}
                if(salir.presionado(raton,raton_presionado)){menu_opcion = 3;}
            break;}

            case 2:{
                DrawText("tiempo!",128,128, 64, WHITE);
                DrawText(TextFormat("puntos: %i", jugador.mostrar_punto()),128,216, 32, WHITE);
                DrawText(TextFormat("duración: %i", contador.tiempo_partida()),128,272, 32, WHITE);
                boton volver(192,420,128,48,gestor_imagenes.buscar(1));
                boton cargar(320 + 8,420,128,48,gestor_imagenes.buscar(1));
                volver.dibujar("volver");
                cargar.dibujar("Cargar");
                if(volver.presionado(raton,raton_presionado)){contador.reiniciar(); menu_opcion = 0;}
                if(cargar.presionado(raton,raton_presionado)){contador.reiniciar(); menu_opcion = 4;}
            break;}
            case 4:{
                DrawText("como se llama?",128,164, 32, WHITE);
                usuario.escribir();
                usuario.dibujar();
                boton volver(256 + 64 - 128,420,128,48,gestor_imagenes.buscar(1));
                boton cargar(256 + 64 + 8,420,128,48,gestor_imagenes.buscar(1));
                volver.dibujar("volver");
                cargar.dibujar("Cargar");
                if(volver.presionado(raton,raton_presionado)){contador.reiniciar(); menu_opcion = 0;}
                if(cargar.presionado(raton,raton_presionado)){contador.reiniciar(); menu_opcion = 4;}
            break;}
        }
        EndDrawing();//terminar el dibujado de imagen
    }
    gestor_imagenes.vaciar();//quitar todas las imagenes del gestor de imagenes
    CloseWindow();
    return 0;
}