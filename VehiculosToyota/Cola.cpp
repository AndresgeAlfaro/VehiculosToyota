#include "Cola.h"

Cola::Cola() : frente(nullptr), fin(nullptr) {}

void Cola::enqueue(const Pieza& pieza) {
    if (pieza.getEstado() == Pieza::REGULAR) {
        NodoCola* nuevo = new NodoCola(pieza);
        if (fin) {
            fin->siguiente = nuevo;
        }
        else {
            frente = nuevo;
        }
        fin = nuevo;
    }
    else {
        std::cerr << "Error: Solo se permiten piezas regulares en la cola." << std::endl;
    }
}

void Cola::dequeue() {
    if (frente) {
        NodoCola* temp = frente;
        frente = frente->siguiente;
        if (!frente) {
            fin = nullptr;
        }
        delete temp;
    }
}

void Cola::mostrar() const {
    NodoCola* actual = frente;
    while (actual) {
        actual->pieza.imprimir();
        actual = actual->siguiente;
    }
}

void Cola::heapsort() {
    int size = getSize();
    Pieza* piezas = new Pieza[size];
    NodoCola* actual = frente;
    int i = 0;
    while (actual) {
        piezas[i++] = actual->pieza;
        actual = actual->siguiente;
    }

    heapSort(piezas, size);

    while (frente) {
        dequeue();
    }

    for (int i = 0; i < size; ++i) {
        enqueue(piezas[i]);
    }

    delete[] piezas;
}

Cola::NodoCola::NodoCola(const Pieza& p) : pieza(p), siguiente(nullptr) {}

int Cola::getSize() const {
    int size = 0;
    NodoCola* actual = frente;
    while (actual) {
        ++size;
        actual = actual->siguiente;
    }
    return size;
}

void Cola::heapify(Pieza* arr, int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].getId() < arr[smallest].getId()) {
        smallest = left;
    }

    if (right < n && arr[right].getId() < arr[smallest].getId()) {
        smallest = right;
    }

    if (smallest != i) {
        std::swap(arr[i], arr[smallest]);
        heapify(arr, n, smallest);
    }
}

void Cola::heapSort(Pieza* arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int Cola::size() const {
    return getSize();
}


