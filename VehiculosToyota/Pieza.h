#ifndef PIEZA_H
#define PIEZA_H

#include "Includes.h"

class Pieza {

public:
    enum Estado { CRITICA, REGULAR, VERIFICACION };

    Pieza();
    Pieza(const std::string& , Estado , int , bool = false);

    std::string getId() const;
    Estado getEstado() const;
    int getPrioridad() const;
    bool esDefectuosa() const;

    void imprimir() const;

private:
    std::string id;
    Estado estado;
    int prioridad;
    bool defectuosa;
};

#endif // !PIEZA_H

