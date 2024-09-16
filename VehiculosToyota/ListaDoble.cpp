#include "ListaDoble.h"

Nodo::Nodo(const Pieza& p) : pieza(p), siguiente(nullptr), anterior(nullptr) {}

ListaDobleCircular::ListaDobleCircular() : cabeza(nullptr) {}

ListaDobleCircular::~ListaDobleCircular() {
    if (!cabeza) return;
    Nodo* actual = cabeza;
    do {
        Nodo* siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    } while (actual != cabeza);
}

Nodo* ListaDobleCircular::dividirLista(Nodo* inicio) {
    if (!inicio || inicio->siguiente == inicio) {
        return nullptr;
    }

    Nodo* lento = inicio;
    Nodo* rapido = inicio->siguiente;

    while (rapido != inicio && rapido->siguiente != inicio) {
        lento = lento->siguiente;
        rapido = rapido->siguiente->siguiente;
    }

    Nodo* mitad = lento->siguiente;
    lento->siguiente = inicio;
    inicio->anterior = lento;
    mitad->anterior = nullptr;

    Nodo* ultimo = mitad;
    while (ultimo->siguiente != inicio) {
        ultimo = ultimo->siguiente;
    }
    ultimo->siguiente = mitad;

    return mitad;
}

Nodo* ListaDobleCircular::fusionarListas(Nodo* lista1, Nodo* lista2) {
    if (!lista1) return lista2;
    if (!lista2) return lista1;

    Nodo* cabezaNueva = nullptr;
    Nodo* colaNueva = nullptr;

    while (lista1 && lista2) {
        if (lista1->pieza.getPrioridad() <= lista2->pieza.getPrioridad()) {
            if (!cabezaNueva) {
                cabezaNueva = lista1;
            }
            else {
                colaNueva->siguiente = lista1;
                lista1->anterior = colaNueva;
            }
            colaNueva = lista1;
            lista1 = lista1->siguiente;
        }
        else {
            if (!cabezaNueva) {
                cabezaNueva = lista2;
            }
            else {
                colaNueva->siguiente = lista2;
                lista2->anterior = colaNueva;
            }
            colaNueva = lista2;
            lista2 = lista2->siguiente;
        }
    }

    if (lista1) {
        colaNueva->siguiente = lista1;
        lista1->anterior = colaNueva;
    }
    else {
        colaNueva->siguiente = lista2;
        lista2->anterior = colaNueva;
    }

    return cabezaNueva;
}

Nodo* ListaDobleCircular::mergeSort(Nodo* inicio) {
    if (!inicio || inicio->siguiente == inicio) {
        return inicio;
    }

    Nodo* mitad = dividirLista(inicio);
    Nodo* lista1 = mergeSort(inicio);
    Nodo* lista2 = mergeSort(mitad);

    Nodo* cabezaOrdenada = fusionarListas(lista1, lista2);
    Nodo* ultimo = cabezaOrdenada;
    while (ultimo && ultimo->siguiente != cabezaOrdenada) {
        ultimo = ultimo->siguiente;
    }
    if (ultimo) {
        cabezaOrdenada->anterior = ultimo;
        ultimo->siguiente = cabezaOrdenada;
    }

    return cabezaOrdenada;
}

void ListaDobleCircular::insertar(const Pieza& pieza) {
    if (pieza.getEstado() != Pieza::VERIFICACION) {
        std::cerr << "Error: Solo se permiten piezas que necesitan verificación en la lista." << std::endl;
        return;
    }

    Nodo* nuevo = new Nodo(pieza);

    if (!cabeza) {
        cabeza = nuevo;
        cabeza->siguiente = cabeza;
        cabeza->anterior = cabeza;
    }
    else {
        Nodo* ultimo = cabeza->anterior;
        ultimo->siguiente = nuevo;
        nuevo->anterior = ultimo;
        nuevo->siguiente = cabeza;
        cabeza->anterior = nuevo;
    }
}

void ListaDobleCircular::eliminarDefectuosos() {
    if (!cabeza) return;
    Nodo* actual = cabeza;
    do {
        Nodo* siguiente = actual->siguiente;
        if (actual->pieza.getEstado() == Pieza::CRITICA) {
            if (actual == cabeza) cabeza = siguiente;
            actual->anterior->siguiente = siguiente;
            siguiente->anterior = actual->anterior;
            delete actual;
        }
        actual = siguiente;
    } while (actual != cabeza);
}

void ListaDobleCircular::mostrar() const {
    if (!cabeza) return;
    Nodo* actual = cabeza;
    do {
        actual->pieza.imprimir();
        actual = actual->siguiente;
    } while (actual != cabeza);
}

void ListaDobleCircular::ordenar() {
    if (!cabeza) return;
    cabeza = mergeSort(cabeza);
    Nodo* ultimo = cabeza->anterior;
    cabeza->anterior = ultimo;
    ultimo->siguiente = cabeza;
}

int ListaDobleCircular::size() const {
    if (!cabeza) return 0;
    int count = 0;
    Nodo* actual = cabeza;
    do {
        ++count;
        actual = actual->siguiente;
    } while (actual != cabeza);
    return count;
}
