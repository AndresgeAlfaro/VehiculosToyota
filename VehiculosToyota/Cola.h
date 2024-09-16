#ifndef COLA_H
#define COLA_H

#include "Pila.h"

class Cola {
public:
    Cola();

    void enqueue(const Pieza& pieza);
    void dequeue();
    void mostrar() const;
    void heapsort();
    int size() const;

private:
    struct Nodo {
        Pieza pieza;
        Nodo* siguiente;
        Nodo(const Pieza& p);
    };

    Nodo* frente;
    Nodo* fin;

    int getSize() const;
    void heapify(Pieza* arr, int n, int i);
    void heapSort(Pieza* arr, int n);
    

};
#endif // COLA_H