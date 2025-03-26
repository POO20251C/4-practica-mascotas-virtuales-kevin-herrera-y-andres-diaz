#ifndef CUIDADOS_H
#define CUIDADOS_H

#include <string>

class Cuidados {
private:
    std::string descripcion;
public:
    Cuidados(const std::string &descripcion);
    void mostrarInfo() const;
};

#endif //CUIDADOS_H
