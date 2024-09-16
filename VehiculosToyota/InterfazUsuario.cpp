#include "InterfazUsuario.h"
#include <iostream>

void InterfazUsuario::insertarPiezasEnPila(int totalPiezas) {
    int piezasCriticas = 0, piezasRegulares = 0, piezasVerificacion = 0;

    std::cout << "\n--- Insertando piezas en la Pila ---\n";
    for (int i = 0; i < totalPiezas; ++i) {
        Pieza pieza = generarPiezaAleatoria();
        pila.push(pieza);

        switch (pieza.getEstado()) {
        case Pieza::CRITICA: piezasCriticas++; break;
        case Pieza::REGULAR: piezasRegulares++; break;
        case Pieza::VERIFICACION: piezasVerificacion++; break;
        }

        std::cout << "Pieza insertada: ";
        pieza.imprimir();
        std::cout << "Total en la pila: " << pila.size() << "\n";
        std::cout << "Piezas restantes por acomodar: " << (totalPiezas - (i + 1)) << "\n";
    }

    std::cout << "\n--- Resumen de piezas en la Pila ---\n";
    std::cout << "Total de piezas generadas: " << totalPiezas << "\n";
    std::cout << "Piezas críticas: " << piezasCriticas << "\n";
    std::cout << "Piezas regulares: " << piezasRegulares << "\n";
    std::cout << "Piezas en verificación: " << piezasVerificacion << "\n";
}

void InterfazUsuario::ordenarYMostrarPila() {
    std::cout << "\n--- Estado de la Pila ---\n";
    std::cout << "Pila antes de ordenar:\n";
    pila.mostrar();
    pila.quicksort();
    std::cout << "Pila después de ordenar:\n";
    pila.mostrar();
}

void InterfazUsuario::insertarPiezasEnCola(int totalPiezas) {
    int piezasCriticas = 0, piezasRegulares = 0, piezasVerificacion = 0;

    std::cout << "\n--- Insertando piezas en la Cola ---\n";
    for (int i = 0; i < totalPiezas; ++i) {
        Pieza pieza = generarPiezaAleatoria();
        cola.enqueue(pieza);

        switch (pieza.getEstado()) {
        case Pieza::CRITICA: piezasCriticas++; break;
        case Pieza::REGULAR: piezasRegulares++; break;
        case Pieza::VERIFICACION: piezasVerificacion++; break;
        }

        std::cout << "Pieza insertada: ";
        pieza.imprimir();
        std::cout << "Total en la cola: " << cola.size() << "\n";
        std::cout << "Piezas restantes por acomodar: " << (totalPiezas - (i + 1)) << "\n";
    }

    std::cout << "\n--- Resumen de piezas en la Cola ---\n";
    std::cout << "Total de piezas generadas: " << totalPiezas << "\n";
    std::cout << "Piezas críticas: " << piezasCriticas << "\n";
    std::cout << "Piezas regulares: " << piezasRegulares << "\n";
    std::cout << "Piezas en verificación: " << piezasVerificacion << "\n";
}

void InterfazUsuario::ordenarYMostrarCola() {
    std::cout << "\n--- Estado de la Cola ---\n";
    std::cout << "Cola antes de ordenar:\n";
    cola.mostrar();
    cola.heapsort();
    std::cout << "Cola después de ordenar:\n";
    cola.mostrar();
}

void InterfazUsuario::insertarPiezasEnListaDoble(int totalPiezas) {
    int piezasCriticas = 0, piezasRegulares = 0, piezasVerificacion = 0;

    std::cout << "\n--- Insertando piezas en la Lista Doble Circular ---\n";
    for (int i = 0; i < totalPiezas; ++i) {
        Pieza pieza = generarPiezaAleatoria();
        lista.insertar(pieza);

        switch (pieza.getEstado()) {
        case Pieza::CRITICA: piezasCriticas++; break;
        case Pieza::REGULAR: piezasRegulares++; break;
        case Pieza::VERIFICACION: piezasVerificacion++; break;
        }

        std::cout << "Pieza insertada: ";
        pieza.imprimir();
        std::cout << "Piezas restantes por acomodar: " << (totalPiezas - (i + 1)) << "\n";
    }

    std::cout << "\n--- Resumen de piezas en la Lista Doble Circular ---\n";
    std::cout << "Total de piezas generadas: " << totalPiezas << "\n";
    std::cout << "Piezas críticas: " << piezasCriticas << "\n";
    std::cout << "Piezas regulares: " << piezasRegulares << "\n";
    std::cout << "Piezas en verificación: " << piezasVerificacion << "\n";
}

void InterfazUsuario::ordenarYMostrarListaDoble() {
    std::cout << "\n--- Estado de la Lista Doble Circular ---\n";
    std::cout << "Lista Doble Circular antes de ordenar:\n";
    lista.mostrar();

    lista.eliminarDefectuosos();

    lista.ordenar();
    std::cout << "Lista Doble Circular después de ordenar:\n";
    lista.mostrar();
}

void InterfazUsuario::ejecutar() {
    int totalPiezas;
    char respuesta;

    do {
        std::cout << "\nIngrese el número de piezas a generar: ";
        std::cin >> totalPiezas;

        insertarPiezasEnPila(totalPiezas);
        ordenarYMostrarPila();

        insertarPiezasEnCola(totalPiezas);
        ordenarYMostrarCola();

        insertarPiezasEnListaDoble(totalPiezas);
        ordenarYMostrarListaDoble();

        std::cout << "\n¿Desea realizar otra operación? (s/n): ";
        std::cin >> respuesta;

    } while (respuesta == 's' || respuesta == 'S');

    std::cout << "¡Gracias por usar el programa! Hasta luego.\n";
}


