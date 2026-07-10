
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
    InitAudioDevice();//iniciar el audio
    SetTargetFPS(60);// definir frames
    gestor_media gestor_media;//iniciar el gestor de imagenes
    escenas escenas;//iniciar el gestor de escenas
    NetworkManager conexion("pma.torga.com.ar", "u3_TIM7rSia9H", "C^Sc9FRhnwH7Owkr@T8i0S0W", "s3_gizmo_db");
    escenas.cargar(gestor_media.buscar(1));
    escenas.cargar(gestor_media.buscar(3));
    escenas.cargar(gestor_media.buscar(9));
    
    jugador.cargar(gestor_media.buscar(0));//carga todo el contenido de media asociado al jugador
    jugador.cargar(gestor_media.buscar(7));//carga todo el contenido de media asociado al jugador
    jugador.cargar(gestor_media.buscar(8));//carga todo el contenido de media asociado al jugador

    jugador.cargar(gestor_media.buscar_audio(0));
    jugador.cargar(gestor_media.buscar_audio(1));

    std::vector<std::vector<ladrillo>> cuarto_posible;//iniciar el vector de cuarto
    //cargar niveles :
    cuarto_posible.emplace_back(escenas.cuarto1());
    cuarto_posible.emplace_back(escenas.cuarto2());
    cuarto_posible.emplace_back(escenas.cuarto3());
    cuarto_posible.emplace_back(escenas.cuarto4());
    cuarto_posible.emplace_back(escenas.cuarto5());
    cuarto_posible.emplace_back(escenas.cuarto6());
    cuarto_posible.emplace_back(escenas.cuarto7());
    cuarto_posible.emplace_back(escenas.cuarto8());
    int menu_opcion = 0;

    caja_texto usuario(256,256,256,48,RED);//nombre del usuario

    std::vector<ladrillo> cuarto_actual = cuarto_posible[GetRandomValue(0,7)];//seleccionar un nivel aleatorio
    // bucle del juego
    while (WindowShouldClose() == false && menu_opcion != 3){
        BeginDrawing();//empezar el dibujado de imagen
            DrawFPS(500, 500);
            Vector2 raton = GetMousePosition();
            bool raton_presionado = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

            DrawTexturePro(gestor_media.buscar(4),Rectangle{0, 0, 320, 320},Rectangle{0, 0, 512, 512},Vector2{0, 0},0,WHITE);
        
        if (menu_opcion == 1 && contador.fin() == false){//solo se dibuja con el contador activo y la opcion 'iniciar' activa
            //dibujar la escena
            DrawText(TextFormat("%i", jugador.mostrar_punto()),240,16, 64, WHITE);
            contador.dibujar();
            for (size_t i = 0; i < cuarto_actual.size(); i++){
                jugador.colisiona(cuarto_actual[i]);
                contador.contar();
                cuarto_actual[i].dibujar();

                if (jugador.colision_lastima() == false){
                    cuarto_actual = cuarto_posible[GetRandomValue(0,7)];
                    jugador.ubicar(escenas.jugador_inicio.x, escenas.jugador_inicio.y);
                }
                if (jugador.colision_puerta() == true){
                    cuarto_actual = cuarto_posible[GetRandomValue(0,7)];
                    jugador.ubicar(escenas.jugador_inicio.x, escenas.jugador_inicio.y);
                }

                //dibujar los proyectiles
                if(!jugador.proyectiles.empty()){
                    for (size_t j = 0; j < jugador.proyectiles.size(); j++){
                        jugador.proyectiles[j].dibujar();
                        jugador.proyectiles[j].colisiona(cuarto_actual[i]);
                        //detectar colisiones de proyectil y definit su comportamiento
                        if (jugador.proyectiles[j].estado_colision() == true){
                                if (jugador.proyectiles[j].destruir() == true)
                                {
                                    cuarto_actual.erase(cuarto_actual.begin() + i);
                                    jugador.proyectiles.erase(jugador.proyectiles.begin() + j);
                                }
                                if (jugador.proyectiles[j].crear() == true)
                                {
                                    Rectangle hitbox = jugador.proyectiles[j].devolver_hitbox();
                                    cuarto_actual.emplace_back(hitbox.x - hitbox.width,hitbox.y - hitbox.height,50,50, GREEN, gestor_media.buscar(1), false, false, true);
                                    jugador.proyectiles.erase(jugador.proyectiles.begin() + j);
                                }
                        }
                    }
                }
            }
            for (size_t i = 0; i < jugador.proyectiles.size(); i++)
            {
                jugador.proyectiles[i].dibujar();
                jugador.proyectiles[i].mover();
            }
            jugador.actualizar(); // actualiza la posición del jugador
            jugador.dibujar();// dibuja al jugador
        }else if(contador.fin() == true && menu_opcion == 1){menu_opcion = 2;}

        switch(menu_opcion){//menu inicial
            case 0:{
                contador.reiniciar();
                jugador.ubicar(escenas.jugador_inicio.x, escenas.jugador_inicio.y);//posición inicial del jugador
                jugador.vaciar();
                DrawTexturePro(gestor_media.buscar(6),Rectangle{0, 0, 256, 128},Rectangle{128, 64, 256, 128},Vector2{0, 0},0,WHITE);
                boton iniciar(256,256,128,48,gestor_media.buscar(1));
                boton ayuda(256,312,128,48,gestor_media.buscar(1));
                boton salir(256,368,128,48,gestor_media.buscar(1));
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
                boton volver(192,420,128,48,gestor_media.buscar(1));
                boton cargar(320 + 8,420,128,48,gestor_media.buscar(1));
                volver.dibujar("volver");
                cargar.dibujar("Cargar");
                if(volver.presionado(raton,raton_presionado)){contador.reiniciar(); menu_opcion = 0;}
                if(cargar.presionado(raton,raton_presionado)){menu_opcion = 4;}
            break;}
            case 4:{
                DrawText("como se llama?",128,164, 32, WHITE);
                usuario.escribir();
                usuario.dibujar();
                boton volver(256 + 64 - 128,420,128,48,gestor_media.buscar(1));
                boton cargar(256 + 64 + 8,420,128,48,gestor_media.buscar(1));
                volver.dibujar("volver");
                cargar.dibujar("Cargar");
                if(volver.presionado(raton,raton_presionado)){contador.reiniciar(); menu_opcion = 0;}
                if(cargar.presionado(raton,raton_presionado))
                {
                    conexion.EnviarPuntajeAsync(usuario.datos(), jugador.mostrar_punto(), contador.tiempo_partida());
                    contador.reiniciar(); menu_opcion = 0;
                }
            break;}
        }
        EndDrawing();//terminar el dibujado de imagen
    }
    gestor_media.vaciar();//quitar todas las imagenes del gestor de imagenes
    CloseWindow();
    return 0;
}