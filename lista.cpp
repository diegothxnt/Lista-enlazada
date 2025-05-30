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
