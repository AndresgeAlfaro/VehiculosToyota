#include "PiezasUtiles.h"

std::string generarId() {
    static const char alfanumericos[] = "0123456789";
    std::string id;
    for (int i = 0; i < 6; ++i) {
        id += alfanumericos[rand() % (sizeof(alfanumericos) - 1)];
    }
    return id;
}

Pieza generarPiezaAleatoria() {
    const int MAX_PRIORIDAD = 10;
    const int PROBABILIDAD_DEFECTUOSA = 5;

    int estadoNumerico = rand() % 3;

    Pieza::Estado est;
    if (estadoNumerico == 0) {
        est = Pieza::CRITICA;
    }
    else if (estadoNumerico == 1) {
        est = Pieza::REGULAR;
    }
    else {
        est = Pieza::VERIFICACION;
    }

    int prioridad = rand() % MAX_PRIORIDAD;

    bool defectuosa = (rand() % 100) < PROBABILIDAD_DEFECTUOSA;

    return Pieza(generarId(), est, prioridad, defectuosa);
}

