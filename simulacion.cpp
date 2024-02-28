#include "personas.h"
#include <vector>
#include <iostream>

std::random_device rd;
std::mt19937 gen(rd);
std::uniform_real_distribution<int> dis(0, 10);

void interaccion(std::vector<Persona*>& poblacion)
{
    //Escoge 2 personas para interactuar
    std::uniform_int_distribution<int> dis_index(0, poblacion.size());
    int index_observador = dis_index(gen);
    int index_distraido = dis_index(gen);

    Persona* observador = poblacion[index_observador];
    Persona* distraido = poblacion[index_distraido];

    //Uno de los 2 detecta un depredador y actua
    std::string accion = observador->actuar(*distraido);

    std::uniform_int_distribution<int> dis_kill(0, 10);
    if (accion == "avisar") {
        if (dis_kill(gen) < 5) { //Muere el altruista
            poblacion.erase(poblacion.begin() + index_observador);
        } else { // Ambos se salvan
            // No hacer nada
        }
    } else {
        poblacion.erase(poblacion.begin() + index_distraido);
    }
}

/*void reproduccion(std::vector<Persona*>& poblacion) {
    // Escoge 2 personas para interactuar
    std::uniform_int_distribution<int> dis_index(0, poblacion.size());
    int index1 = dis_index(gen);
    int index2 = dis_index(gen);

    Persona* macho = poblacion[index1];
    Persona* hembra = poblacion[index2];

    //Numero de bebes 
    std::uniform_int_distribution<int> dis_camada(0, 4);
    int camada = dis_camada(gen);

    // Verificar si las instancias de macho y hembra son iguales
    bool crianza = typeid(*macho) == typeid(*hembra);

    for (int i = 0; i < camada; i++) {
        if (crianza) {
            poblacion.push_back(new Persona());  // El bebé hereda la instancia de los padres
        } else {
            // El bebé hereda una instancia al azar
            Persona* cria = (rand() % 2 == 0) ? new Persona(*macho) : new Persona(*hembra);
            poblacion.push_back(cria);
        }
    }
}
*/

