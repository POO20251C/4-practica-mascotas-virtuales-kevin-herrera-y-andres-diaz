#include "Habilidad.h"
#include <iostream>

Habilidad::Habilidad(const std::string &nombre, int xpRequerida)
    : nombre(nombre), xpRequerida(xpRequerida) {}

std::string Habilidad::getNombre() const {
    return nombre;
}

int Habilidad::getXpRequerida() const {
    return xpRequerida;
}

void Habilidad::mostrarInfo() const {
    std::cout << "Habilidad: " << nombre << ", Exp.Requerida: " << xpRequerida << "\n";
}


