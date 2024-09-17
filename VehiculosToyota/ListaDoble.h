#ifndef LISTADOBLE_H
#define LISTADOBLE_H

#include "Cola.h"

struct NodoLista {

    Pieza pieza;
    NodoLista* siguiente;
    NodoLista* anterior;

    NodoLista(const Pieza& p);
};

class ListaDobleCircular {
private:
    NodoLista* cabeza;

    NodoLista* dividirLista(NodoLista* );
    NodoLista* fusionarListas(NodoLista* , NodoLista* );
    NodoLista* mergeSort(NodoLista* );

public:
    ListaDobleCircular();
    ~ListaDobleCircular();

    void insertar(const Pieza& );
    void eliminarDefectuosos();
    void mostrar() const;
    void ordenar();
    int size() const;
};

#endif // LISTADOBLE_H
