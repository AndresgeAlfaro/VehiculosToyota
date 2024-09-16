#ifndef PIEZA_H
#define PIEZA_H

#include "Includes.h"

class Pieza {

public:
    enum Estado { CRITICA, REGULAR, VERIFICACION };

    Pieza();
    Pieza(const std::string& id, Estado est, int pri);

    std::string getId() const;
    Estado getEstado() const;
    int getPrioridad() const;

    void imprimir() const;

private:
    std::string identificador;
    Estado estado;
    int prioridad;
};

#endif // !PIEZA_H

