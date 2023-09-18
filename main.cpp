#include <iostream>

class N_Arbol {
public:
    int dato;
    N_Arbol* izq;
    N_Arbol* dere;

    N_Arbol(int valor) : dato(valor), izq(nullptr), dere(nullptr) {}
};

class Ar_Binario {
private:
    N_Arbol* raiz;

public:
    Ar_Binario() : raiz(nullptr) {}

    void insertar(int valor) {
        if (raiz == nullptr) {
            raiz = new N_Arbol(valor);
        } else {
            insertarRecursivo(raiz, valor);
        }
    }

    void insertarRecursivo(N_Arbol* nodo, int valor) {
        if (valor < nodo->dato) {
            if (nodo->izq == nullptr) {
                nodo->izq = new N_Arbol(valor);
            } else {
                insertarRecursivo(nodo->izq, valor);
            }
        } else if (valor > nodo->dato) {
            if (nodo->dere == nullptr) {
                nodo->dere = new N_Arbol(valor);
            } else {
                insertarRecursivo(nodo->dere, valor);
            }
        }
    }
};

int main() {
    
    Ar_Binario arbol;
    char continuar;

    do {
        int dato;
        std::cout << "\n\tInserta un dato: ";
        std::cin >> dato;

        arbol.insertar(dato);

        std::cout << "\n¿Quieres ingresar otro dato? (Y/N): ";
        std::cin >> continuar;
    } while (std::toupper(continuar) == 'Y');

    return 0;
}




