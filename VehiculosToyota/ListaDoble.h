#ifndef LISTADOBLE_H
#define LISTADOBLE_H

#include "Cola.h"

class Nodo {
public:
    Pieza pieza;
    Nodo* siguiente;
    Nodo* anterior;

    Nodo(const Pieza& p);
};

class ListaDobleCircular {
private:
    Nodo* cabeza;

    Nodo* dividirLista(Nodo* inicio);
    Nodo* fusionarListas(Nodo* lista1, Nodo* lista2);
    Nodo* mergeSort(Nodo* inicio);

public:
    ListaDobleCircular();
    ~ListaDobleCircular();

    void insertar(const Pieza& pieza);
    void eliminarDefectuosos();
    void mostrar() const;
    void ordenar();
    int size() const;
};

#endif // LISTADOBLE_H
