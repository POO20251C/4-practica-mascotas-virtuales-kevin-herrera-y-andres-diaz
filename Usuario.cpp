#include "Usuario.h"
#include <iostream>

Usuario::Usuario(int id, const std::string &nombre) : id(id), nombre(nombre) {}

Usuario::~Usuario() {
    for (auto mascota : mascotas) {
        delete mascota;
    }
}

int Usuario::getId() const {
    return id;
}

std::string Usuario::getNombre() const {
    return nombre;
}

void Usuario::adoptarMascota(Mascota* mascota) {
    mascotas.push_back(mascota);
    std::cout<<"Mascota de " << nombre << ":\n";
    for (auto m : mascotas) {
        std::cout << "- " << m->getNombre() << "\n";
    }
}

void Usuario::mostrarMascota() const {
    std::cout << "Mascota de " << nombre << ":\n";
    for (auto m : mascotas) {
        std::cout << "- " << m->getNombre() << "\n";
    }
}



