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

