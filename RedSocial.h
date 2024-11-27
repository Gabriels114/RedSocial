//
// Created by gabriels on 26/11/24.
//
#ifndef REDSOCIAL_H
#define REDSOCIAL_H

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

struct Mensaje {
    string contenido;
};

struct Usuario {
    string nombre;
    vector<Mensaje> publicaciones;
    unordered_set<string> amigos;
};

class RedSocial {
public:
    void registrarUsuario(const string& nombre);
    bool iniciarSesion(const string& nombre);
    void cerrarSesion();
    void anadirAmigo(const string& usuario2);
    void publicarMensaje(const string& mensaje);
    void mostrarPublicaciones();
    void buscarUsuario(const string& nombre);
    void cargarUsuariosPredefinidos();

private:
    unordered_map<string, Usuario> usuarios;
    string usuarioConSesionIniciada;
    vector<string> listaUsuarios;
    vector<vector<int>> matriz;

    int obtenerIndiceUsuario(const string& nombre);
    void crearMatriz(size_t tamano);
    void anadirConexion(int indice1, int indice2);
};

#endif // REDSOCIAL_H