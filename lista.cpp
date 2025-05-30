#include <iostream>

using namespace std;

class Nodo {
public:
    int valor;
    Nodo* siguiente;

    Nodo(int valor) {
        this->valor = valor;
        this->siguiente = nullptr;
    }
};
class ListaEnlazada {
private:
    Nodo* inicio;
    bool esOrdenada;

public:
 ListaEnlazada() {
        inicio = nullptr;
        esOrdenada = false;
    }
ListaEnlazada(int valor, Nodo* siguienteNodo) {
        inicio = new Nodo(valor);
        inicio->siguiente = siguienteNodo;
        esOrdenada = false;
    }
ListaEnlazada(int valor, Nodo* siguienteNodo, bool tipoOrden) {
        inicio = new Nodo(valor);
        inicio->siguiente = siguienteNodo;
        esOrdenada = tipoOrden;
    }
void insertar(int nuevoValor) {
        Nodo* nuevoNodo = new Nodo(nuevoValor);

        if (!inicio) {
            inicio = nuevoNodo;
            return;
        }

        if (!esOrdenada) {
            nuevoNodo->siguiente = inicio;
            inicio = nuevoNodo;
        } else {
            if (nuevoValor < inicio->valor) {
                nuevoNodo->siguiente = inicio;
                inicio = nuevoNodo;
                return;
            }

            Nodo* nodoActual = inicio;
            while (nodoActual->siguiente && nodoActual->siguiente->valor < nuevoValor) {
                nodoActual = nodoActual->siguiente;
            }
            nuevoNodo->siguiente = nodoActual->siguiente;
            nodoActual->siguiente = nuevoNodo;
        }
    }
Nodo* buscar(int valorBuscado) {
        Nodo* nodoActual = inicio;
        while (nodoActual) {
            if (nodoActual->valor == valorBuscado)
                return nodoActual;
            nodoActual = nodoActual->siguiente;
        }
        return nullptr;
    }
 void eliminar(int valorEliminar) {
        if (!inicio) {
            cout << "La lista esta vacia" << endl;
            return;
        }

        if (inicio->valor == valorEliminar) {
            Nodo* nodoTemporal = inicio;
            inicio = inicio->siguiente;
            delete nodoTemporal;
            cout << "Nodo con valor " << valorEliminar << " eliminado" << endl;
            return;
        }

        Nodo* nodoActual = inicio;
        while (nodoActual->siguiente && nodoActual->siguiente->valor != valorEliminar) {
            nodoActual = nodoActual->siguiente;
        }

        if (nodoActual->siguiente) {
            Nodo* nodoTemporal = nodoActual->siguiente;
            nodoActual->siguiente = nodoTemporal->siguiente;
            delete nodoTemporal;
            cout << "Nodo con valor " << valorEliminar << " eliminado" << endl;
        } else {
            cout << "Valor no encontrado" << endl;
        }
    }
void mostrar() {
        Nodo* nodoActual = inicio;
        while (nodoActual) {
            cout << nodoActual->valor;
            if (nodoActual->siguiente)
                cout << " - ";
            nodoActual = nodoActual->siguiente;
        }
        cout << endl;
    }
};
