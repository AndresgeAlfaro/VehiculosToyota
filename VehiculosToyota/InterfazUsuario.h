#ifndef INTERFAZUSUARIO_H
#define INTERFAZUSUARIO_H

#include "ListaDoble.h"


class InterfazUsuario {
private:
    Pila pila;
    Cola cola;
    ListaDobleCircular lista;

    void insertarPiezasEnPila(int totalPiezas);
    void ordenarYMostrarPila();

    void insertarPiezasEnCola(int totalPiezas);
    void ordenarYMostrarCola();

    void insertarPiezasEnListaDoble(int totalPiezas);
    void ordenarYMostrarListaDoble();

public:
    void ejecutar();
};

#endif // INTERFAZUSUARIO_H
