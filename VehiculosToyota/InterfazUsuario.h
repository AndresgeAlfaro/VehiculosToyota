#ifndef INTERFAZUSUARIO_H
#define INTERFAZUSUARIO_H

#include "ListaDoble.h"


class InterfazUsuario {
private:
    Pila pila;
    Cola cola;
    ListaDobleCircular lista;

public:
    void insertarPiezas(int , Pieza []);
    void insertarPiezasEnPila(int , Pieza []);
    void insertarPiezasEnCola(int , Pieza []);
    void insertarPiezasEnListaDoble(int , Pieza []);

    void ordenarYMostrarPila();
    void ordenarYMostrarCola();
    void ordenarYMostrarListaDoble();

    void ejecutar();
};

#endif // INTERFAZUSUARIO_H
