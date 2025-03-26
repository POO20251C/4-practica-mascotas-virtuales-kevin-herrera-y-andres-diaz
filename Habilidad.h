#ifndef HABILIDAD_H
#define HABILIDAD_H

#include <string>

class Habilidad {
private:
    std::string nombre;
    int xpRequerida;
public:
    Habilidad(const std::string &nombre, int &xpRequerida);
    std::string getNombre() const;
    int getXpRequerida() const;
    void mostrarInfo() const;
};

#endif //HABILIDAD_H
