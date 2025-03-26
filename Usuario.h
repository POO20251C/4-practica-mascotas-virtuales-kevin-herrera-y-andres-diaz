#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <vector>
#include "Mascota.h"

class Usuario {
private:
    int id;
    std::string nombre;
    std::vector<Mascota*> mascotas;
public:
    Usuario(int id, const std::string &nombre);
    ~Usuario();
    int getId() const;
    std::string getNombre() const;
    void adoptarMascota(Mascota* mascota);
    void mostrarMascota() const;
    const std::vector<Mascota*>& getMascotas() const {
        return mascotas;
    }
};

#endif //USUARIO_H
