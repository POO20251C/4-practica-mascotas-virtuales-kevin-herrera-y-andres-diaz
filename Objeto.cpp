#include "Objeto.h"
#include <iostream>

Objeto::Objeto(const std::string &nombre, const std::string &tipo, const std::string &efecto)
    : nombre(nombre), tipo(tipo), efecto(efecto)  {}

std::string Objeto::getNombre() const {
    return nombre;
}

std::string Objeto::getTipo() const {
    return tipo;
}

std::string Objeto::getEfecto() const {
    return efecto;
}

void Objeto::mostrarInfo() const {
    std::cout << "Objeto: " << nombre << ", Tipo: " << tipo << ", Efecto: " << efecto << "\n";
}


