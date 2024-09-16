#include "Pieza.h"

Pieza::Pieza() : identificador(""), estado(REGULAR), prioridad(0) {}

Pieza::Pieza(const std::string& id, Estado est, int pri)
    : identificador(id), estado(est), prioridad(pri) {}

std::string Pieza::getId() const { return identificador; }

Pieza::Estado Pieza::getEstado() const { return estado; }

int Pieza::getPrioridad() const { return prioridad; }

void Pieza::imprimir() const {
    std::string est;
    switch (estado) {
    case CRITICA: est = "Critica"; break;
    case REGULAR: est = "Regular"; break;
    case VERIFICACION: est = "Verificacion"; break;
    }
    std::cout << "ID: " << identificador << ", Estado: " << est << ", Prioridad: " << prioridad << std::endl;
}
