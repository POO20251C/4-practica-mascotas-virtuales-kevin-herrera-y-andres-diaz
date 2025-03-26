#include "Plataforma.h"
#include "Mascota.h"
#include <iostream>

Plataforma::Plataforma() {
    inicializarObjetos();
}

Plataforma::~Plataforma() {
    //Tenemos que liberar espacios
    for (auto &pair : usuarios) {
        delete pair.second;
    }
}

void Plataforma::inicializarObjetos() {
    // Vamos a manejar 8 objetos de ejemplo para las mascotas
    objetos.push_back(Objeto("Snack", "Salud", "Aumenta energia"));
    objetos.push_back(Objeto("Juguete", "Emocion", "Mejora estado de animo"));
    objetos.push_back(Objeto("Poción", "Salud", "Recupera salud"));
    objetos.push_back(Objeto("Capa", "Estetica", "Aumenta carisma"));
    objetos.push_back(Objeto("Collar", "Estetica", "Personaliza la mascota"));
    objetos.push_back(Objeto("Bebida", "Salud", "Aumenta energia"));
    objetos.push_back(Objeto("Bola", "Emocion", "Estimula el juego"));
    objetos.push_back(Objeto("Sombrero", "Estetica", "Personaliza la mascota"));
}

void Plataforma::registrarUsuario(Usuario *usuario) {
    usuarios[usuario->getId()] = usuario;
}

Usuario *Plataforma::buscarUsuario(int id) {
    if (usuarios.find(id) != usuarios.end()) {
        return usuarios[id];
    }
    return nullptr;
}

void Plataforma::adoptarMascotas(int idUsuario, Mascota *mascota) {
    Usuario* usuario = buscarUsuario(idUsuario);
    if (usuario) {
        usuario->adoptarMascota(mascota);
        std::cout << "Mascota " << mascota->getNombre() << " adoptada por " << usuario->getNombre() << "\n";
    } else {
        std::cout << "Usuario no encontrado!!\n";
    }
}

void Plataforma::darObjeto(int idUsuario, const std::string &nombreMascota, const Objeto &obj) {
    Usuario* usuario = buscarUsuario(idUsuario);
    if (usuario) {
        bool encontrado = false;
        for (auto mascota : usuario->getMascotas()) {
            if (mascota->getNombre() == nombreMascota) {
                mascota->recibirObjeto(obj);
                std::cout << "Objeto " << obj.getNombre() << " entregado a " << nombreMascota << "\n";
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            std::cout << "Mascota no encontrada!!\n";
        }
    } else {
        std::cout << "Usuario no encontrado!!\n";
    }
}

void Plataforma::ensenarHabilidad(int idUsuario, const std::string &nombreMascota, Habilidad hab) {
    Usuario* usuario = buscarUsuario(idUsuario);
    if (usuario) {
        bool encontrado = false;
        for (auto mascota : usuario->getMascotas()) {
            if (mascota->getNombre() == nombreMascota) {
                mascota->aprenderHabilidad(hab);
                std::cout << "Habilidad " << hab.getNombre() << " ensenada a " << nombreMascota << "\n";
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            std::cout << "Mascota no encontrada!!\n";
        }
    } else {
        std::cout << "Usuario no encontrado!!\n";
    }
}

void Plataforma::aumentarExperiencia(int idUsuario, const std::string &nombreMascota, int exp) {
    Usuario* usuario = buscarUsuario(idUsuario);
    if (usuario) {
        bool encontrado = false;
        for (auto mascota : usuario->getMascotas()) {
            if (mascota->getNombre() == nombreMascota) {
                mascota->aumentarExperiencia(exp);
                std::cout << "Experiencia aumentada a " << nombreMascota << "\n";
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            std::cout << "Mascota no encontrada!!\n";
        }
    } else {
        std::cout << "Usuario no encontrado!!\n";
    }
}

void Plataforma::consultarHistorial(int idUsuario, const std::string &nombreMascota) {
    Usuario* usuario = buscarUsuario(idUsuario);
    if (usuario) {
        bool encontrado = false;
        for (auto mascota : usuario->getMascotas()) {
            if (mascota->getNombre() == nombreMascota) {
                mascota->mostrarHistorial();
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            std::cout << "Mascota no encontrada!!\n";
        }
    } else {
        std::cout << "Usuario no encontrado!!\n";
    }
}









