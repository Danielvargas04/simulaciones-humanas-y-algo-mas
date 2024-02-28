#include "personas.h"

std::string Egoista::actuar(const Persona& otra_persona) 
{
    return "correr";
}

std::string Impostor::actuar(const Persona& otra_persona) 
{
    std::random_device rd;
    std::mt19937 gen(rd);
    std::uniform_real_distribution<float> dis(0.0, 1.0);

    if (dis(gen) < empatia) {
        return "avisar";
    } else {
        return "correr";
    }
}

std::string Altruista::actuar(const Persona& otra_persona) 
{
    return "avisar";
}

std::string Solidario::actuar(const Persona& otra_persona) {
    if (otra_persona.mascara == "Solidario") {
        return "avisar";
    } else {
        return "correr";
    }
}