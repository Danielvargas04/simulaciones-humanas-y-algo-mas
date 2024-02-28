#ifndef PERSONAS_H
#define PERSONAS_H

#include <string>
#include <random>

class Persona {
public:
    std::string mascara;

    virtual std::string actuar(const Persona& otra_persona) = 0;
};

class Altruista : public Persona {
public:
    Altruista() {
        mascara = "Altruista";
    }

    std::string actuar(const Persona& otra_persona) override;
};

class Egoista : public Persona {
public:
    Egoista() {
        mascara = "Egoista";
    }

    std::string actuar(const Persona& otra_persona) override;
};

class Impostor : public Persona {
public:
    Impostor() {
        mascara = "Solidario";
        empatia = 0.4;
    }

    float empatia;
    std::string actuar(const Persona& otra_persona) override;
};

class Solidario : public Persona {
public:
    Solidario() {
        mascara = "Solidario";
    }

    std::string actuar(const Persona& otra_persona) override;
};

#endif // PERSONAS_H