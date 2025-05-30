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
void menu() {
    int opcionMenu, datoUsuario, tipoLista;

    cout << "Crear nueva lista:" << endl;
    cout << "1. Lista desordenada" << endl;
    cout << "2. Lista ordenada " << endl;
    cout << "Seleccione tipo: ";
    cin >> tipoLista;

    ListaEnlazada miLista;
    if (tipoLista == 2) {
        miLista = ListaEnlazada(0, nullptr, true);
        miLista.eliminar(0);
    }

    do {
        cout << endl;
        cout << "    MENU  " << endl;
        cout << "1. Insertar valor" << endl;
        cout << "2. Buscar valor" << endl;
        cout << "3. Eliminar valor" << endl;
        cout << "4. Mostrar lista" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcionMenu;

        if (opcionMenu == 1) {
            cout << "Ingrese el valor a insertar: ";
            cin >> datoUsuario;
            miLista.insertar(datoUsuario);
        }
        else if (opcionMenu == 2) {
            cout << "Ingrese el valor a buscar: ";
            cin >> datoUsuario;
            if (miLista.buscar(datoUsuario))
                cout << "Valor encontrado" << endl;
            else
                cout << "Valor no encontrado" << endl;
        }
        else if (opcionMenu == 3) {
            cout << "Ingrese el valor a eliminar: ";
            cin >> datoUsuario;
            miLista.eliminar(datoUsuario);
        }
        else if (opcionMenu == 4) {
            cout << "Contenido de la lista:" << endl;
            miLista.mostrar();
        }
        else if (opcionMenu == 0) {
            cout << "Saliendo del programa..." << endl;
        }
        else {
            cout << "Opcion no valida" << endl;
        }

    } while (opcionMenu != 0);
}
int main() {
    menu();
    return 0;
}

