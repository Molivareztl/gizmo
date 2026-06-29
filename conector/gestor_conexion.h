#pragma once
#include <iostream>
#include <string>
#include <thread>
#include <mysql/mysql.h> 

class NetworkManager {
private:
    std::string host;
    std::string usuario;
    std::string contraseña;
    std::string baseDatos;

    void EnviarPuntajeInterno(std::string nombre, int puntos, int tiempo) {
        MYSQL* conn = mysql_init(NULL);
        if (conn == NULL) return;

        if (mysql_real_connect(conn, host.c_str(), usuario.c_str(), contraseña.c_str(), baseDatos.c_str(), 0, NULL, 0) == NULL) {
            std::cout << mysql_error(conn) << std::endl;
            mysql_close(conn);
            return;
        }

        std::string query = "INSERT INTO Usuarios (Nombre, Puntos, Tiempo) VALUES ('" + nombre + "', " + std::to_string(puntos) + ", " + std::to_string(tiempo) + ")";
        
        if (mysql_query(conn, query.c_str())) {
            std::cout << mysql_error(conn) << std::endl;
        } else {
            std::cout << "exito." << std::endl;
        }
        mysql_close(conn);
    }

public:
    NetworkManager(std::string server, std::string user, std::string pass, std::string db) 
        : host(server), usuario(user), contraseña(pass), baseDatos(db) {}

    void EnviarPuntajeAsync(std::string nombre, int puntos, int tiempo) {
        std::thread hilo(&NetworkManager::EnviarPuntajeInterno, this, nombre, puntos, tiempo);
        hilo.detach(); 
    }
};