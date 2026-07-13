#pragma once
#include <iostream>
#include <string>
#include <thread>
#include "mysql.h"

class gestor_conexion {
private:
    std::string host;
    std::string usuario;
    std::string contraseña;
    std::string baseDatos;

public:
    gestor_conexion(std::string server, std::string user, std::string pass, std::string db) 
        : host(server), usuario(user), contraseña(pass), baseDatos(db) {}

    bool registro(std::string _usuario, std::string _contraseña) {
        MYSQL* conn = mysql_init(NULL);
        if (conn == NULL) return false;

        if (mysql_real_connect(conn, host.c_str(), usuario.c_str(), contraseña.c_str(), baseDatos.c_str(), 0, NULL, 0) == NULL) {
            std::cout<< mysql_error(conn) << std::endl;
            mysql_close(conn);
            return false;
        }

        // se verifica si los datos del usuario coinsiden con los de la base
        std::string consultaCheck = "SELECT Nombre FROM Usuarios WHERE Nombre = '" + _usuario + "' AND Contraseña = '" + _contraseña + "'";
        if (mysql_query(conn, consultaCheck.c_str())) {
            std::cout<< mysql_error(conn) << std::endl;
            mysql_close(conn);
            return false;
        }

        MYSQL_RES* resultado = mysql_store_result(conn);
        if (resultado == NULL) {
            mysql_close(conn);
            return false;
        }

        // si devuelve, los datos son correctos
        if (mysql_num_rows(resultado) > 0) {
            std::cout << "Usuario validado correctamente (Inicio de sesion)." << std::endl;
            mysql_free_result(resultado);
            mysql_close(conn);
            return true; 
        }
        mysql_free_result(resultado); // se vacia el resultado

        //ve si el nombre ya esta ocupado
        std::string consultaNombre = "SELECT Nombre FROM Usuarios WHERE Nombre = '" + _usuario + "'";
        if (mysql_query(conn, consultaNombre.c_str())) {
            std::cout<< mysql_error(conn) << std::endl;
            mysql_close(conn);
            return false;
        }

        resultado = mysql_store_result(conn);
        if (resultado != NULL && mysql_num_rows(resultado) > 0) {
            mysql_free_result(resultado);
            mysql_close(conn);
            return false; // el nombre esta tomado
        }
        if (resultado != NULL) mysql_free_result(resultado);

        // si no existe se crea
        std::string consultaInsert = "INSERT INTO Usuarios (Nombre, Contraseña, Puntos, Tiempo) VALUES ('" + _usuario + "', '" + _contraseña + "', 0, 0)";
        
        bool exito = false;
        if (mysql_query(conn, consultaInsert.c_str())) {
            std::cout << mysql_error(conn) << std::endl;
        } else {
            exito = true;
        }

        mysql_close(conn);
        return exito;
    }
    bool actualizar(std::string nuevoUsuario, int nuevosPuntos, int nuevoTiempo) {
        MYSQL* conn = mysql_init(NULL);
        if (conn == NULL) return false;

        if (mysql_real_connect(conn, host.c_str(), usuario.c_str(), contraseña.c_str(), baseDatos.c_str(), 0, NULL, 0) == NULL) {
            std::cout << mysql_error(conn) << std::endl;
            mysql_close(conn);
            return false;
        }
        //se actualizan los datos de la base de datos
        std::string consulta = "UPDATE Usuarios SET Puntos = " + std::to_string(nuevosPuntos) + 
                               ", Tiempo = " + std::to_string(nuevoTiempo) + 
                               " WHERE Nombre = '" + nuevoUsuario + "'";
        bool exito = false;
        if (mysql_query(conn, consulta.c_str())) {
            std::cout << mysql_error(conn) << std::endl;
        } else {
            std::cout << "proceso terminado." << std::endl;//fin del proceso
            exito = true;
        }
        mysql_close(conn);
        return exito;
    }
};