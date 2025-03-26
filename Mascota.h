#ifndef MASCOTA_H
#define MASCOTA_H

#include <string>
#include <vector>
#include "Objeto.h"
#include "Habilidad.h"
#include "Cuidados.h"

enum EstadoSalud {SANO, REGULAR, ENFERMO, MUY_ENFERMO };
enum EstadoEmocional {FELIZ, TRISTE, NEUTRAL };

class Mascota {
private:
    std::string nombre;
    int energia;
    EstadoSalud salud;
    int edad;
    EstadoEmocional emocion;
    int experiencia;
    std::vector<Habilidad> habilidades;
    std::vector<Cuidados> historial;
public:
    Mascota(const std::string &nombre);
    std::string getNombre() const;
    void aprenderHabilidad(const Habilidad &hab);
    void recibirObjeto(const Objeto &obj);
    void aumentarExperiencia(int exp);
    void agregarCuidados(const Cuidados &cuidado);
    void mostrarHistorial() const;
    void mostrarInfo() const;
};

#endif //MASCOTA_H
