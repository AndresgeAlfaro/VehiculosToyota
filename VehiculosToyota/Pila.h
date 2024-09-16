#ifndef PILA_H
#define PILA_H

#include "Pieza.h"
#include "PiezasUtiles.h" 

class Pila {
public:
    Pila();

    void push(const Pieza& pieza);
    void pop();
    void mostrar() const;
    void quicksort();
    int size() const;

private:
    struct Nodo {
        Pieza pieza;
        Nodo* siguiente;
        Nodo(const Pieza& p, Nodo* s);
    };

    Nodo* top;
    int contador;

    void quicksortRec(Nodo* inicio, Nodo* fin);
    Nodo* particionar(Nodo* inicio, Nodo* fin);
    void intercambiarPiezas(Pieza& a, Pieza& b);

};

#endif // PILA_H



