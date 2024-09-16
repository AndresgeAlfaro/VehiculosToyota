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
    cabeza = nullptr;
}

Nodo* ListaDobleCircular::dividirLista(Nodo* cabeza) {
    Nodo* rapido = cabeza;
    Nodo* lento = cabeza;

    while (rapido->siguiente && rapido->siguiente->siguiente) {
        rapido = rapido->siguiente->siguiente;
        lento = lento->siguiente;
    }

    Nodo* mitad = lento->siguiente;
    lento->siguiente = nullptr;
    return mitad; // Retor la cabeza de la segunda mitad
}

Nodo* ListaDobleCircular::fusionarListas(Nodo* izquierda, Nodo* derecha) {
    if (!izquierda) 
        return derecha;
    if (!derecha) 
        return izquierda;

    if (izquierda->pieza.getPrioridad() <= derecha->pieza.getPrioridad()) {
        izquierda->siguiente = fusionarListas(izquierda->siguiente, derecha);
        izquierda->siguiente->anterior = izquierda;
        izquierda->anterior = nullptr;
        return izquierda;
    }
    else {
        derecha->siguiente = fusionarListas(izquierda, derecha->siguiente);
        derecha->siguiente->anterior = derecha;
        derecha->anterior = nullptr;
        return derecha;
    }
}

Nodo* ListaDobleCircular::mergeSort(Nodo* cabeza) {
    if (!cabeza || !cabeza->siguiente) 
        return cabeza;

    Nodo* mitad = dividirLista(cabeza);

    Nodo* izquierda = mergeSort(cabeza);
    Nodo* derecha = mergeSort(mitad);

    return fusionarListas(izquierda, derecha);
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
            if (actual == cabeza){ 
                cabeza = siguiente;
                if (cabeza == actual) //si solo hay un nodo en la lista
                    cabeza = nullptr;
            }
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
    if (!cabeza || !cabeza->siguiente) return;

    // Desconectar la lista circular
    Nodo* ultimo = cabeza->anterior;
    ultimo->siguiente = nullptr;
    cabeza->anterior = nullptr;

    // Ordenar la lista
    cabeza = mergeSort(cabeza);

    // Reconectar la lista circular
    Nodo* actual = cabeza;
    while (actual->siguiente) {
        actual = actual->siguiente;
    }
    actual->siguiente = cabeza;
    cabeza->anterior = actual;
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
