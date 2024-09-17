#include "InterfazUsuario.h"

void InterfazUsuario::insertarPiezas(int totalPiezas, Pieza piezas[]) {
    int piezasCriticas = 0, piezasRegulares = 0, piezasVerificacion = 0;

    std::cout << "\n--- Insertando piezas ---\n";
    for (int i = 0; i < totalPiezas; ++i) {
        Pieza pieza = piezas[i];

        switch (pieza.getEstado()) {
        case Pieza::CRITICA: piezasCriticas++; break;
        case Pieza::REGULAR: piezasRegulares++; break;
        case Pieza::VERIFICACION: piezasVerificacion++; break;
        }

        std::cout << "Pieza insertada: ";
        pieza.imprimir();
        std::cout << "Piezas restantes por acomodar: " << (totalPiezas - (i + 1)) << "\n";
    }

    std::cout << "\n--- Resumen de piezas generadas ---\n";
    std::cout << "Total de piezas generadas: " << totalPiezas << "\n";
    std::cout << "Piezas criticas: " << piezasCriticas << "\n";
    std::cout << "Piezas regulares: " << piezasRegulares << "\n";
    std::cout << "Piezas en verificacion: " << piezasVerificacion << "\n";
}

void InterfazUsuario::insertarPiezasEnPila(int totalPiezas, Pieza piezas[]) {
    std::cout << "\n--- Insertando piezas en la Pila ---\n";
    for (int i = 0; i < totalPiezas; ++i) {
        pila.push(piezas[i]);
    }

    std::cout << "Pila desacomodada:\n";
    pila.mostrar();
}

void InterfazUsuario::insertarPiezasEnCola(int totalPiezas, Pieza piezas[]) {
    std::cout << "\n--- Insertando piezas en la Cola ---\n";
    for (int i = 0; i < totalPiezas; ++i) {
        cola.enqueue(piezas[i]);
    }

    std::cout << "Cola desacomodada:\n";
    cola.mostrar();
}

void InterfazUsuario::insertarPiezasEnListaDoble(int totalPiezas, Pieza piezas[]) {
    std::cout << "\n--- Insertando piezas en la Lista Doble Circular ---\n";
    for (int i = 0; i < totalPiezas; ++i) {
        lista.insertar(piezas[i]);
    }

    std::cout << "Lista Doble Circular desacomodada:\n";
    lista.mostrar();
}

void InterfazUsuario::ordenarYMostrarPila() {
    std::cout << "\n--- Ordenando la Pila ---\n";
    pila.quicksort();
    std::cout << "Pila acomodada:\n";
    pila.mostrar();
}

void InterfazUsuario::ordenarYMostrarCola() {
    std::cout << "\n--- Ordenando la Cola ---\n";
    cola.heapsort();
    std::cout << "Cola acomodada:\n";
    cola.mostrar();
}

void InterfazUsuario::ordenarYMostrarListaDoble() {
    std::cout << "\n--- Eliminando piezas defectuosas y ordenando la Lista Doble Circular ---\n";
    lista.eliminarDefectuosos();
    lista.ordenar();
    std::cout << "Lista Doble Circular acomodada:\n";
    lista.mostrar();
}

void InterfazUsuario::ejecutar() {
    int totalPiezas;
    char respuesta;

    do {
        try {
            std::cout << "\nIngrese el numero de piezas a generar: ";
            std::cin >> totalPiezas;

            if (std::cin.fail() || totalPiezas <= 0) {
                throw std::invalid_argument("El numero de piezas debe ser un entero positivo.");
            }

            Pieza* piezas = nullptr;
            try {
                piezas = new Pieza[totalPiezas];
            }
            catch (const std::bad_alloc& e) {
                throw std::runtime_error("Fallo al asignar memoria para las piezas.");
            }

            for (int i = 0; i < totalPiezas; ++i) {
                piezas[i] = generarPiezaAleatoria();
            }

            insertarPiezas(totalPiezas, piezas);

            insertarPiezasEnPila(totalPiezas, piezas);
            ordenarYMostrarPila();

            insertarPiezasEnCola(totalPiezas, piezas);
            ordenarYMostrarCola();

            insertarPiezasEnListaDoble(totalPiezas, piezas);
            ordenarYMostrarListaDoble();

            delete[] piezas;

        }
        catch (const std::invalid_argument& e) {
            std::cerr << "Error: " << e.what() << "\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        catch (const std::runtime_error& e) {
            std::cerr << "Error: " << e.what() << "\n";
        }

        std::cout << "\n¿Desea realizar otra operacion? (s/n): ";
        std::cin >> respuesta;

    } while (respuesta == 's' || respuesta == 'S');

    std::cout << " Hasta luego.\n";
}
