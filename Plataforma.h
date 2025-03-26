#ifndef PLATAFORMA_H
#define PLATAFORMA_H

#include <map>
#include <vector>
#include "Usuario.h"
#include "Objeto.h"
#include "Habilidad.h"

class Plataforma {
private:
    std::map<int, Usuario*> usuarios;
    std::vector<Objeto> objetos;
public:
    Plataforma();
    ~Plataforma();
    void inicializarObjetos();
    void registrarUsuario(Usuario* usuario);
    Usuario* buscarUsuario(int id);
    void adoptarMascotas(int idUsuario, Mascota* mascota);
    void darObjeto(int idUsuario, const std::string &nombreMascota, const Objeto &obj);
    void ensenarHabilidad(int idUsuario, const std::string &nombreMascota, Habilidad hab);
    void aumentarExperiencia(int idUsuario, const std::string &nombreMascota, int exp);
    void consultarHistorial(int idUsuario, const std::string &nombreMascota);
    const std::map<int, Usuario*>& getUsuarios() const {
        return usuarios;
    }
};

#endif //PLATAFORMA_H
