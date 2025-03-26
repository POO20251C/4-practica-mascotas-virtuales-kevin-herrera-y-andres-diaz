#include <iostream>
#include "Plataforma.h"
#include "Usuario.h"
#include "Mascota.h"
#include "Objeto.h"
#include "Habilidad.h"
#include <cstdlib>
#include <ctime>


using namespace std;

void mostrarMenu() {
    cout << "\n--- Bienvenido a PixelPets ---\n";
    cout << "1. Registrar nuevo usuario\n";
    cout << "2. Adoptar nueva mascota\n";
    cout << "3. Dar objeto a mascota\n";
    cout << "4. Ensenar habilidad a mascota\n";
    cout << "5. Aumentar experiencia de mascota\n";
    cout << "6. Consultar historial de mascota\n";
    cout << "7. Mostrar usuarios y sus mascotas\n";
    cout << "0. Salir\n";
    cout << "Ingrese opcion: ";
}

int main() {
    srand(time(0));
    Plataforma plataforma;

    int opcion;
    do {
        mostrarMenu();
        cin >> opcion;
        switch (opcion) {
            case 1: {
                int id;
                string nombre;
                cout << "Ingrese el id del usuario: ";
                cin >> id;
                cout << "Ingrese el nombre: ";
                cin >> nombre;
                Usuario* nuevoUsuario = new Usuario(id, nombre);
                plataforma.registrarUsuario(nuevoUsuario);
                cout << "El usuario registrado.\n";
                break;
            }
            case 2: {
                int id;
                string nombreMascota;
                cout << "Ingrese el id del usuario: ";
                cin >> id;
                cout << "Ingrese el nombre de la mascota: ";
                cin >> nombreMascota;
                plataforma.adoptarMascotas(id, new Mascota(nombreMascota));
                break;
            }
            case 3: {
                int id, index;
                string nombreMascota;
                cout << "Ingrese el id del usuario: ";
                cin >> id;
                cout << "Ingrese el nombre de la mascota: ";
                cin >> nombreMascota;
                cout << "Objetos disponibles:\n ";
                cout << "0. Snack\n1. Juguete\n2. Pocion\n3. Capa\n4. Collar\n5. Bebida\n6. Bola\n7. Sombrero\n";
                cout << "Selecciona opcion (0-7): ";
                cin >> index;
                if (index >= 0 && index <= 7) {
                    Objeto objeto("", "", "");
                    switch (index) {
                        case 0: objeto = Objeto("Snack", "Salud", "Aumenta energia"); break;
                        case 1: objeto = Objeto("Juguete", "Emocion", "Mejora estado de ánimo"); break;
                        case 2: objeto = Objeto("Pocion", "Salud", "Recupera salud"); break;
                        case 3: objeto = Objeto("Capa", "Estetica", "Aumenta carisma"); break;
                        case 4: objeto = Objeto("Collar", "Estetica", "Personaliza la mascota"); break;
                        case 5: objeto = Objeto("Bebida", "Salud", "Aumenta energia"); break;
                        case 6: objeto = Objeto("Bola", "Emocion", "Estimula el juego"); break;
                        case 7: objeto = Objeto("Sombrero", "Estetica", "Personaliza la mascota"); break;
                    }
                    plataforma.darObjeto(id, nombreMascota, objeto);
                } else {
                    cout << "Opcion incorrecto.\n";
                }
                break;
            }
            case 4: {
                int id, xpReq;
                string nombreMascota, nombreHab;
                cout << "Ingrese el id del usuario: ";
                cin >> id;
                cout << "Ingrese el nombre de la mascota: ";
                cin >> nombreMascota;
                cout << "Ingrese el nombre de la habilidad: ";
                cin >> nombreHab;
                cout << "Ingrese experiencia requerida: ";
                cin >> xpReq;
                Habilidad hab(nombreHab, xpReq);
                plataforma.ensenarHabilidad(id, nombreMascota, hab);
                break;
            }
            case 5: {
                int id, xp;
                string nombreMascota;
                cout << "Ingrese el id del usuario: ";
                cin >> id;
                cout << "Ingrese el nombre de la mascota: ";
                cin >> nombreMascota;
                cout << "Ingrese cantidad de experiencia a aumentar o 0 para aleatorio: ";
                cin >> xp;
                if (xp == 0) {
                    xp = rand() % 20 + 1;
                }
                plataforma.aumentarExperiencia(id, nombreMascota, xp);
                break;
            }
            case 6: {
                int id;
                string nombreMascota;
                cout << "Ingrese el id del usuario: ";
                cin >> id;
                cout << "Ingrese el nombre de la mascota: ";
                cin >> nombreMascota;
                plataforma.consultarHistorial(id, nombreMascota);
                break;
            }
            case 7: {
                //Mostrar todos los usuarios y sus mascotas
                for (const auto &pair : plataforma.getUsuarios()) {
                    Usuario* usr = pair.second;
                    cout << "Usuario: " << usr->getNombre() << "\n";
                    usr->mostrarMascota();
                }
                break;
            }
            case 0: {
                cout << "Saliendo de Pixel Pets...\n";
                break;
            }
            default: {
                cout << "Opcion incorrecto. Intente nuevamente.\n";
                break;
            }
        }
    } while (opcion != 0);
}
