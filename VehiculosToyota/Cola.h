#ifndef COLA_H
#define COLA_H

#include "Pila.h"

class Cola {
public:
    Cola();

    void enqueue(const Pieza& );
    void dequeue();
    void mostrar() const;
    void heapsort();
    int size() const;

private:
    struct NodoCola {
        Pieza pieza;
        NodoCola* siguiente;
        NodoCola(const Pieza& );
    };

    NodoCola* frente;
    NodoCola* fin;

    int getSize() const;
    void heapify(Pieza* , int , int );
    void heapSort(Pieza* , int );
    

};
#endif // COLA_H