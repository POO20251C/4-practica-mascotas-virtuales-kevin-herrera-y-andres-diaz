#include "Mascota.h"
#include <iostream>

Mascota::Mascota(const std::string &nombre)
    : nombre(nombre), energia(100), salud(SANO), edad(0), emocion(NEUTRAL), experiencia(0)  {}

std::string Mascota::getNombre() const {
    return nombre;
}

void Mascota::aprenderHabilidad(const Habilidad &hab) {
    habilidades.push_back(hab);
    std::string desc = "Habilidad aprendida: " + hab.getNombre();
    agregarCuidados(Cuidados(desc));
}

void Mascota::recibirObjeto(const Objeto &obj) {
    // Aqui vamos a simular un efecto de un objeto pocion el cual aumenta la energia
    if (obj.getTipo() == "Salud") {
        energia += 10;
    }
    std::string desc = "Objeto recibido: " + obj.getNombre();
    agregarCuidados(Cuidados(desc));
}

void Mascota::aumentarExperiencia(int exp) {
    experiencia += exp;
    energia += exp/2;
    edad += exp/10;
    std::string desc = "La experiencia aumenta en: " + std::to_string(exp) + " puntos.";
    agregarCuidados(Cuidados(desc));
}

void Mascota::agregarCuidados(const Cuidados &cuidado) {
    historial.push_back(cuidado);
}

void Mascota::mostrarHistorial() const {
    std::cout << "Historial de " << nombre << ":\n";
    for (const auto &c : historial) {
        c.mostrarInfo();
    }
}

void Mascota::mostrarInfo() const {
    std::cout << "Mascota: " << nombre << "\n"
    << "Energia: " << energia << "\n"
    << "Edad: " << edad << "\n"
    << "Experiencia: " << experiencia << "\n";
    std::cout << "Salud: ";
    switch (salud) {
        case SANO: std::cout << "SANO"; break;
        case REGULAR: std::cout << "REGULAR"; break;
        case ENFERMO: std::cout << "ENFERMO"; break;
        case MUY_ENFERMO: std::cout << "MUY ENFERMO"; break;
    }
    std::cout << "\nEmocion: ";
    switch (emocion) {
        case FELIZ: std::cout << "FELIZ"; break;
        case TRISTE: std::cout << "TRISTE"; break;
        case NEUTRAL: std::cout << "NEUTRAL"; break;
    }
    std::cout << "\n";
}





