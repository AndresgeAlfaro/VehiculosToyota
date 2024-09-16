#include "Pila.h"

Pila::Pila() : top(nullptr), contador(0) {}

void Pila::push(const Pieza& pieza) {
    if (pieza.getEstado() == Pieza::CRITICA) { // Solo permitir piezas críticas
        Nodo* nuevo = new Nodo(pieza, top);
        top = nuevo;
        contador++; // Incrementar el contador al agregar un nuevo elemento
    }
    else {
        std::cerr << "Error: Solo se permiten piezas críticas en la pila." << std::endl;
    }
}

void Pila::pop() {
    if (top) {
        Nodo* temp = top;
        top = top->siguiente;
        delete temp;
        contador--; // Decrementar el contador al eliminar un elemento
    }
}

void Pila::mostrar() const {
    Nodo* actual = top;
    while (actual) {
        actual->pieza.imprimir();
        actual = actual->siguiente;
    }
}

void Pila::quicksort() {
    if(top) //verificar que la pila no esté vacía
      quicksortRec(top, obtenerUltimoNodo());
}

Pila::Nodo::Nodo(const Pieza& p, Nodo* s) : pieza(p), siguiente(s) {}

void Pila::quicksortRec(Nodo* inicio, Nodo* fin) {
    if (inicio != fin && inicio != nullptr && inicio != fin->siguiente) {
        Nodo* pivo = particionar(inicio, fin);
        quicksortRec(inicio, pivo);           // Ordenar la parte izquierda
        if (pivo != nullptr && pivo->siguiente != nullptr) {
            quicksortRec(pivo->siguiente, fin); // Ordenar la parte derecha
        }
    }
}

Pila::Nodo* Pila::particionar(Nodo* inicio, Nodo* fin) {
    Pieza pivo = inicio->pieza;
    Nodo* izq = inicio;
    Nodo* der = inicio->siguiente;
    while (der != fin->siguiente) {
        if (der->pieza.getPrioridad() < pivo.getPrioridad()) {
            izq = izq->siguiente;
            intercambiarPiezas(izq->pieza, der->pieza);
        }
        der = der->siguiente;
    }
    intercambiarPiezas(inicio->pieza, izq->pieza);
    return izq;
}

void Pila::intercambiarPiezas(Pieza& a, Pieza& b) {
    Pieza temp = a;
    a = b;
    b = temp;
}

Pila::Nodo* Pila::obtenerUltimoNodo() const{
    Nodo* temp = top;
    while (temp && temp->siguiente) {
        temp = temp->siguiente;
    }
    return temp;
}

int Pila::size() const {
    return contador;
}
