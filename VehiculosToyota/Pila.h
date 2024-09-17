#ifndef PILA_H
#define PILA_H

#include "Pieza.h"
#include "PiezasUtiles.h" 

class Pila {
public:
    Pila();

    void push(const Pieza& );
    void pop();
    void mostrar() const;
    void quicksort();
    int size() const;

private:
    struct NodoPila {
        Pieza pieza;
        NodoPila* siguiente;
        NodoPila(const Pieza& , NodoPila* );
    };

    NodoPila* top;
    int contador;

    void quicksortRec(NodoPila* , NodoPila* );
    NodoPila* particionar(NodoPila* , NodoPila* );
    void intercambiarPiezas(Pieza& , Pieza& );
    NodoPila* obtenerUltimoNodo() const;

};

#endif // PILA_H



