#include "Pila.h"

Pila::Pila() : top(nullptr), contador(0) {}

void Pila::push(const Pieza& pieza) {
    if (pieza.getEstado() == Pieza::CRITICA) {
        NodoPila* nuevo = new NodoPila(pieza, top);
        top = nuevo;
        contador++;
    }
    else {
        std::cerr << "Error: Solo se permiten piezas criticas en la pila." << std::endl;
    }
}

void Pila::pop() {
    if (top) {
        NodoPila* temp = top;
        top = top->siguiente;
        delete temp;
        contador--;
    }
}

void Pila::mostrar() const {
    NodoPila* actual = top;
    while (actual) {
        actual->pieza.imprimir();
        actual = actual->siguiente;
    }
}

void Pila::quicksort() {
    if (top)
        quicksortRec(top, obtenerUltimoNodo());
}

Pila::NodoPila::NodoPila(const Pieza& p, NodoPila* s) : pieza(p), siguiente(s) {}

void Pila::quicksortRec(NodoPila* inicio, NodoPila* fin) {
    if (inicio != fin && inicio != nullptr && inicio != fin->siguiente) {
        NodoPila* pivo = particionar(inicio, fin);
        quicksortRec(inicio, pivo);
        if (pivo != nullptr && pivo->siguiente != nullptr) {
            quicksortRec(pivo->siguiente, fin);
        }
    }
}

Pila::NodoPila* Pila::particionar(NodoPila* inicio, NodoPila* fin) {
    Pieza pivo = inicio->pieza;
    NodoPila* izq = inicio;
    NodoPila* der = inicio->siguiente;
    while (der != fin->siguiente) {
        if (der->pieza.getId() > pivo.getId()) {
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

Pila::NodoPila* Pila::obtenerUltimoNodo() const {
    NodoPila* temp = top;
    while (temp && temp->siguiente) {
        temp = temp->siguiente;
    }
    return temp;
}

int Pila::size() const {
    return contador;
}

