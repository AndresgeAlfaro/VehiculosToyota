#include "ListaDoble.h"

NodoLista::NodoLista(const Pieza& p) : pieza(p), siguiente(nullptr), anterior(nullptr) {}

ListaDobleCircular::ListaDobleCircular() : cabeza(nullptr) {}

ListaDobleCircular::~ListaDobleCircular() {
    if (!cabeza) return;
    NodoLista* actual = cabeza;
    do {
        NodoLista* siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    } while (actual != cabeza);
    cabeza = nullptr;
}

NodoLista* ListaDobleCircular::dividirLista(NodoLista* cabeza) {
    NodoLista* rapido = cabeza;
    NodoLista* lento = cabeza;

    while (rapido->siguiente && rapido->siguiente->siguiente) {
        rapido = rapido->siguiente->siguiente;
        lento = lento->siguiente;
    }

    NodoLista* mitad = lento->siguiente;
    lento->siguiente = nullptr;
    return mitad;
}

NodoLista* ListaDobleCircular::fusionarListas(NodoLista* izquierda, NodoLista* derecha) {
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

NodoLista* ListaDobleCircular::mergeSort(NodoLista* cabeza) {
    if (!cabeza || !cabeza->siguiente) 
        return cabeza;

    NodoLista* mitad = dividirLista(cabeza);

    NodoLista* izquierda = mergeSort(cabeza);
    NodoLista* derecha = mergeSort(mitad);

    return fusionarListas(izquierda, derecha);
}

void ListaDobleCircular::insertar(const Pieza& pieza) {
    if (pieza.getEstado() != Pieza::VERIFICACION) {
        std::cerr << "Error: Solo se permiten piezas que necesitan verificación en la lista." << std::endl;
        return;
    }

    NodoLista* nuevo = new NodoLista(pieza);

    if (!cabeza) {
        cabeza = nuevo;
        cabeza->siguiente = cabeza;
        cabeza->anterior = cabeza;
    }
    else {
        NodoLista* ultimo = cabeza->anterior;
        ultimo->siguiente = nuevo;
        nuevo->anterior = ultimo;
        nuevo->siguiente = cabeza;
        cabeza->anterior = nuevo;
    }
}

void ListaDobleCircular::eliminarDefectuosos() {
    if (!cabeza) return;
    NodoLista* actual = cabeza;
    do {
        NodoLista* siguiente = actual->siguiente;
        if (actual->pieza.getEstado() == Pieza::CRITICA) {
            if (actual == cabeza){ 
                cabeza = siguiente;
                if (cabeza == actual)
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
    NodoLista* actual = cabeza;
    do {
        actual->pieza.imprimir();
        actual = actual->siguiente;
    } while (actual != cabeza);
}

void ListaDobleCircular::ordenar() {
    if (!cabeza || !cabeza->siguiente) return;

    NodoLista* ultimo = cabeza->anterior;
    ultimo->siguiente = nullptr;
    cabeza->anterior = nullptr;

    cabeza = mergeSort(cabeza);

    NodoLista* actual = cabeza;
    while (actual->siguiente) {
        actual = actual->siguiente;
    }
    actual->siguiente = cabeza;
    cabeza->anterior = actual;
}

int ListaDobleCircular::size() const {
    if (!cabeza) return 0;
    int count = 0;
    NodoLista* actual = cabeza;
    do {
        ++count;
        actual = actual->siguiente;
    } while (actual != cabeza);
    return count;
}
