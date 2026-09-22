#include <iostream>

struct Fila {
    int dados[5];
    int inicio;
    int fim;
    int quantidade;
};

void inicializar(Fila &fila) {
    fila.inicio = 0;
    fila.fim = 0;
    fila.quantidade = 0;
}

int main() {
    using namespace std;
    
    cout << "Hello world!" << endl;
    
    return 0;
}


