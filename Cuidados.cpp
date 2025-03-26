#include "Cuidados.h"
#include <iostream>

Cuidados::Cuidados(const std::string &descripcion) : descripcion(descripcion) {}

void Cuidados::mostrarInfo() const {
    std::cout << "- " << descripcion << "\n";
}

