
#include <iostream>

using namespace std;

const int TAMANHO = 10;

// Struct representando o cliente
struct Cliente {
    int codigo;
    char nome[50];
    char atendimento[100];
};

// Struct representando a fila
struct Fila {
    Cliente dados[TAMANHO];
    int inicio;
    int fim;
    int quantidade;
};

// Inicializa a fila
void inicializar(Fila &fila) {
    fila.inicio = 0;
    fila.fim = 0;
    fila.quantidade = 0;
}

// Verifica se a fila está vazia
bool estaVazia(Fila fila) {
    return fila.quantidade == 0;
}

// Verifica se a fila está cheia
bool estaCheia(Fila fila) {
    return fila.quantidade == TAMANHO;
}

// Retorna a quantidade de clientes
int tamanho(Fila fila) {
    return fila.quantidade;
}

// Cadastra e insere um cliente no final da fila
bool enfileirar(Fila &fila) {

    if (estaCheia(fila)) {
        cout << "\nFila cheia! Nao e possivel cadastrar outro cliente.\n";
        return false;
    }

    Cliente novo;

    cout << "\n==================================\n";
    cout << "       CADASTRAR CLIENTE\n";
    cout << "==================================\n";

    cout << "Codigo: ";
    cin >> novo.codigo;

    cin.ignore();

    cout << "Nome: ";
    cin.getline(novo.nome, 50);

    cout << "Tipo de atendimento: ";
    cin.getline(novo.atendimento, 100);

    fila.dados[fila.fim] = novo;

    fila.fim++;
    fila.quantidade++;

    cout << "\nCliente cadastrado com sucesso!\n";

    return true;
}

// Remove o primeiro cliente da fila
bool desenfileirar(Fila &fila, Cliente &cliente) {

    if (estaVazia(fila)) {
        cout << "\nFila vazia! Nao ha clientes para atender.\n";
        return false;
    }

    cliente = fila.dados[fila.inicio];

    fila.inicio++;
    fila.quantidade--;

    return true;
}

// Consulta o primeiro cliente sem removê-lo
bool frente(Fila fila, Cliente &cliente) {

    if (estaVazia(fila)) {
        return false;
    }

    cliente = fila.dados[fila.inicio];

    return true;
}

// Exibe os dados de um cliente
void exibirCliente(Cliente cliente) {

    cout << "Codigo: " << cliente.codigo << endl;
    cout << "Nome: " << cliente.nome << endl;
    cout << "Atendimento: " << cliente.atendimento << endl;
}

// Exibe todos os clientes da fila
void exibir(Fila fila) {

    if (estaVazia(fila)) {
        cout << "\nFila vazia!\n";
        return;
    }

    cout << "\n==================================\n";
    cout << "       CLIENTES AGUARDANDO\n";
    cout << "==================================\n";

    for (int i = fila.inicio; i < fila.fim; i++) {

        cout << "\nCliente " << (i - fila.inicio + 1) << endl;
        cout << "Codigo: " << fila.dados[i].codigo << endl;
        cout << "Nome: " << fila.dados[i].nome << endl;
        cout << "Atendimento: " << fila.dados[i].atendimento << endl;

        cout << "----------------------------------\n";
    }
}

// Menu principal
void exibirMenu() {

    cout << "\n==================================\n";
    cout << "       ATENDIMENTO TECNICO\n";
    cout << "==================================\n";
    cout << "1 - Cadastrar cliente\n";
    cout << "2 - Atender cliente\n";
    cout << "3 - Consultar proximo cliente\n";
    cout << "4 - Exibir fila\n";
    cout << "5 - Verificar se esta vazia\n";
    cout << "6 - Verificar se esta cheia\n";
    cout << "7 - Mostrar quantidade\n";
    cout << "0 - Sair\n";
    cout << "==================================\n";
    cout << "Escolha: ";
}

int main() {

    Fila fila;

    inicializar(fila);

    int opcao;

    do {

        exibirMenu();
        cin >> opcao;

        switch (opcao) {

            case 1:
                enfileirar(fila);
                break;

            case 2: {

                Cliente cliente;

                if (desenfileirar(fila, cliente)) {

                    cout << "\n==================================\n";
                    cout << "         CLIENTE ATENDIDO\n";
                    cout << "==================================\n";

                    exibirCliente(cliente);
                }

                break;
            }

            case 3: {

                Cliente cliente;

                if (frente(fila, cliente)) {

                    cout << "\n==================================\n";
                    cout << "        PROXIMO CLIENTE\n";
                    cout << "==================================\n";

                    exibirCliente(cliente);
                }
                else {
                    cout << "\nFila vazia!\n";
                }

                break;
            }

            case 4:
                exibir(fila);
                break;

            case 5:

                if (estaVazia(fila)) {
                    cout << "\nA fila esta vazia.\n";
                }
                else {
                    cout << "\nA fila possui clientes.\n";
                }

                break;

            case 6:

                if (estaCheia(fila)) {
                    cout << "\nA fila esta cheia.\n";
                }
                else {
                    cout << "\nExiste espaco na fila.\n";
                }

                break;

            case 7:

                cout << "\nQuantidade de clientes: "
                     << tamanho(fila) << endl;

                break;

            case 0:

                cout << "\nPrograma encerrado.\n";

                break;

            default:

                cout << "\nOpcao invalida!\n";

                break;
        }

    } while (opcao != 0);

    return 0;
}

