#include "PiezasUtiles.h"

std::string generarId() {
    static const char alfanumericos[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string id;
    for (int i = 0; i < 6; ++i) {
        id += alfanumericos[rand() % (sizeof(alfanumericos) - 1)];
    }
    return id;
}

Pieza generarPiezaAleatoria() {
    static const int MAX_PRIORIDAD = 10;
    Pieza::Estado est = static_cast<Pieza::Estado>(rand() % 3);
    int prioridad = rand() % MAX_PRIORIDAD;
    return Pieza(generarId(), est, prioridad);
}
