#pragma once
#include <iostream>
#include <string>
#include <thread>//para que no se trabe

#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "httplib.h"//conexión  con base de datos
#include "json.hpp"

using json = nlohmann::json;

class NetworkManager {
private:
    std::string dominioBase;
    std::string apiKey;

    // Método privado que realiza la petición real (correrá en segundo plano)
    void EnviarPuntajeInterno(std::string nombre, int puntos) {
        json datos;
        datos["nombre_usuario"] = nombre;
        datos["puntuacion"]     = puntos;

        httplib::Client cli(dominioBase);
        
        httplib::Headers headers = {
            { "Content-Type", "application/json" },
            { "apikey", apiKey } // Por si usas Supabase/Firebase, si no, puedes quitarlo
        };

        auto res = cli.Post("/api/guardar_puntaje", headers, datos.dump(), "application/json");

        if (res && res->status == 200) {
            std::cout << "[Network] ¡Puntaje subido con éxito!" << std::endl;
        } else {
            std::cout << "[Network] Error de conexión: " 
                      << (res ? std::to_string(res->status) : "Servidor OFF") << std::endl;
        }
    }

public:
    // Constructor: Configuras el servidor al crear el objeto
    NetworkManager(std::string url, std::string key = "") 
        : dominioBase(url), apiKey(key) {}

    // Método público: El juego llama a este método, el cual genera el hilo automáticamente
    void EnviarPuntajeAsync(std::string nombre, int puntos) {
        // 'this' es necesario para indicarle al hilo qué instancia de la clase va a ejecutar el método privado
        std::thread hilo(&NetworkManager::EnviarPuntajeInterno, this, nombre, puntos);
        hilo.detach(); 
    }
};


