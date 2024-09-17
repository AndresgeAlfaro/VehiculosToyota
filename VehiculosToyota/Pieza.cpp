#include "Pieza.h"

Pieza::Pieza() : id(""), estado(REGULAR), prioridad(0), defectuosa(false) {}

Pieza::Pieza(const std::string& id, Estado est, int pri, bool defectuosa)
    : id(id), estado(est), prioridad(pri), defectuosa(defectuosa) {}

std::string Pieza::getId() const { return id; }

Pieza::Estado Pieza::getEstado() const { return estado; }

int Pieza::getPrioridad() const { return prioridad; }

bool Pieza::esDefectuosa() const { return defectuosa; }

void Pieza::imprimir() const {
    std::string est;
    switch (estado) {
    case CRITICA: est = "Critica"; break;
    case REGULAR: est = "Regular"; break;
    case VERIFICACION: est = "Verificacion"; break;
    }
    std::cout << "ID: " << id << ", Estado: " << est << ", Prioridad: " << prioridad;
    if (defectuosa) {
        std::cout << ", Defectuosa";
    }
    std::cout << std::endl;
}
