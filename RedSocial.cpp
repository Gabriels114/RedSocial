//
// Created by gabriels on 26/11/24.
//
#include "RedSocial.h"
#include <algorithm>
void RedSocial::registrarUsuario(const string& nombre) {
    if (usuarios.find(nombre) == usuarios.end()) {
        usuarios[nombre] = {nombre, {}, {}};
        listaUsuarios.push_back(nombre);
        crearMatriz(listaUsuarios.size());
        cout << "Usuario '" << nombre << "' registrado con éxito.\n";
    } else {
        cout << "El usuario '" << nombre << "' ya existe.\n";
    }
}

bool RedSocial::iniciarSesion(const string& nombre) {
    if (usuarios.find(nombre) != usuarios.end()) {
        usuarioConSesionIniciada = nombre;
        cout << "Sesión iniciada como '" << nombre << "'.\n";
        return true;
    } else {
        cout << "Usuario '" << nombre << "' no encontrado.\n";
        return false;
    }
}

void RedSocial::cerrarSesion() {
    if (!usuarioConSesionIniciada.empty()) {
        cout << "Sesión cerrada para '" << usuarioConSesionIniciada << "'.\n";
        usuarioConSesionIniciada.clear();
    } else {
        cout << "No hay ninguna sesión iniciada.\n";
    }
}

void RedSocial::anadirAmigo(const string& usuario2) {
    if (usuarioConSesionIniciada.empty()) {
        cout << "Debes iniciar sesión para agregar amigos.\n";
    } else if (usuarios.find(usuario2) == usuarios.end()) {
        cout << "Usuario '" << usuario2 << "' no encontrado.\n";
    } else if (usuarioConSesionIniciada == usuario2) {
        cout << "No puedes agregarte a ti mismo como amigo.\n";
    } else {
        usuarios[usuarioConSesionIniciada].amigos.insert(usuario2);
        usuarios[usuario2].amigos.insert(usuarioConSesionIniciada);
        int indice1 = obtenerIndiceUsuario(usuarioConSesionIniciada);
        int indice2 = obtenerIndiceUsuario(usuario2);
        anadirConexion(indice1, indice2);
        cout << "Amistad entre '" << usuarioConSesionIniciada << "' y '" << usuario2 << "' agregada con éxito.\n";
    }
}

void RedSocial::publicarMensaje(const string& mensaje) {
    if (usuarioConSesionIniciada.empty()) {
        cout << "Debes iniciar sesión para publicar un mensaje.\n";
    } else {
        usuarios[usuarioConSesionIniciada].publicaciones.push_back({mensaje});
        cout << "Mensaje publicado por '" << usuarioConSesionIniciada << "'.\n";
    }
}

void RedSocial::mostrarPublicaciones() {
    if (usuarioConSesionIniciada.empty()) {
        cout << "Debes iniciar sesión para ver tus mensajes.\n";
    } else {
        cout << "Mensajes de '" << usuarioConSesionIniciada << "':\n";
        for (const auto& publicacion : usuarios[usuarioConSesionIniciada].publicaciones) {
            cout << "- " << publicacion.contenido << "\n";
        }
    }
}

void RedSocial::buscarUsuario(const string& nombre) {
    if (usuarios.find(nombre) == usuarios.end()) {
        cout << "Usuario '" << nombre << "' no encontrado.\n";
    } else {
        cout << "Usuario encontrado: " << nombre << "\n";
        cout << "Amigos: ";
        for (const auto& amigo : usuarios[nombre].amigos) {
            cout << amigo << " ";
        }
        cout << "\n";

        unordered_set<string> interseccion;
        for (const auto& amigo : usuarios[usuarioConSesionIniciada].amigos) {
            if (usuarios[nombre].amigos.find(amigo) != usuarios[nombre].amigos.end()) {
                interseccion.insert(amigo);
            }
        }
        cout << "Amigos en común: ";
        for (const auto& amigoComun : interseccion) {
            cout << amigoComun << " ";
        }
        cout << "\n";
    }
}

void RedSocial::cargarUsuariosPredefinidos() {
    usuarios["Luis"] = {"Luis", {{"¡Hola, soy Luis!"}}, {"Roger", "David"}};
    usuarios["Roger"] = {"Roger", {{"Explorando C++"}}, {"Luis", "Nico"}};
    usuarios["Nico"] = {"Nico", {{"Amante de la música"}}, {"Roger"}};
    usuarios["David"] = {"David", {{"Amigo de todos"}}, {"Luis"}};
    usuarios["Anne"] = {"Anne", {{"Hello"}}, {"Luis"}};
    usuarios["Sara"] = {"Sara", {{"Bye"}}, {"Roger"}};
    usuarios["Miguel"] = {"Miguel", {{"Hola"}}, {"Roger"}};
    usuarios["Paula"] = {"Paula", {{"jiji"}}, {"Nico"}};
    usuarios["Alvaro"] = {"Alvaro", {{"Los lobos no están hechos para el circo AUUU"}}, {"Luis"}};

    for (const auto& [nombre, usuario] : usuarios) {
        listaUsuarios.push_back(nombre);
    }

    crearMatriz(listaUsuarios.size());
    for (const auto& [nombre, usuario] : usuarios) {
        int indice1 = obtenerIndiceUsuario(nombre);
        for (const auto& amigo : usuario.amigos) {
            int indice2 = obtenerIndiceUsuario(amigo);
            anadirConexion(indice1, indice2);
        }
    }
}

int RedSocial::obtenerIndiceUsuario(const string& nombre) {
    auto it = find(listaUsuarios.begin(), listaUsuarios.end(), nombre);
    return distance(listaUsuarios.begin(), it);
}

void RedSocial::crearMatriz(size_t tamano) {
    matriz.resize(tamano, vector<int>(tamano, 0));
}

void RedSocial::anadirConexion(int indice1, int indice2) {
    matriz[indice1][indice2] = 1;
    matriz[indice2][indice1] = 1;
}