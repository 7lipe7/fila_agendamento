#include <iostream>
#include <string>

using namespace std;

// Struct representando a entidade Equipamento
struct Equipamento {
    int codigo;
    string descricao;
    string tipo;
    int quantidade;
    int situacao; // 1 - Disponível, 2 - Em manutenção, 3 - Indisponível
    Equipamento* proximo;
};

// Inicializa a lista como vazia
void inicializar(Equipamento*& inicio) {
    inicio = NULL;
}

// Funcao auxiliar para converter o codigo da situacao em texto
string obterTextoSituacao(int situacao) {
    switch (situacao) {
        case 1: return "Disponivel";
        case 2: return "Em manutencao";
        case 3: return "Indisponivel";
        default: return "Desconhecida";
    }
}

// 1. Inserir equipamento no final da lista
void inserirEquipamento(Equipamento*& inicio) {
    Equipamento* novo = new Equipamento;
    
    cout << "\n--- CADASTRAR NOVO EQUIPAMENTO ---\n";
    cout << "Codigo: ";
    cin >> novo->codigo;
    cin.ignore();
    
    cout << "Descricao: ";
    getline(cin, novo->descricao);
    
    cout << "Tipo: ";
    getline(cin, novo->tipo);
    
    cout << "Quantidade: ";
    cin >> novo->quantidade;
    
    cout << "Situacao (1 - Disponivel, 2 - Em manutencao, 3 - Indisponivel): ";
    cin >> novo->situacao;
    
    novo->proximo = NULL;

    if (inicio == NULL) {
        inicio = novo;
    } else {
        Equipamento* atual = inicio;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novo;
    }
    cout << "Equipamento cadastrado com sucesso no final da lista!\n";
}

// 2. Exibir equipamentos cadastrados
void exibirEquipamentos(Equipamento* inicio) {
    if (inicio == NULL) {
        cout << "\nNenhum equipamento cadastrado na lista.\n";
        return;
    }

    cout << "\n========================================\n";
    cout << "EQUIPAMENTOS CADASTRADOS\n";
    cout << "========================================\n";
    
    Equipamento* atual = inicio;
    while (atual != NULL) {
        cout << "Codigo: " << atual->codigo << "\n";
        cout << "Descricao: " << atual->descricao << "\n";
        cout << "Tipo: " << atual->tipo << "\n";
        cout << "Quantidade: " << atual->quantidade << "\n";
        cout << "Situacao: " << obterTextoSituacao(atual->situacao) << "\n";
        cout << "----------------------------------------\n";
        atual = atual->proximo;
    }
}

// 3. Pesquisar equipamento por codigo (pesquisa sequencial)
void pesquisarEquipamento(Equipamento* inicio) {
    if (inicio == NULL) {
        cout << "\nA lista esta vazia.\n";
        return;
    }

    int codigoBusca;
    cout << "\nDigite o codigo do equipamento a ser pesquisado: ";
    cin >> codigoBusca;

    Equipamento* atual = inicio;
    while (atual != NULL) {
        if (atual->codigo == codigoBusca) {
            cout << "\n--- EQUIPAMENTO ENCONTRADO ---\n";
            cout << "Codigo: " << atual->codigo << "\n";
            cout << "Descricao: " << atual->descricao << "\n";
            cout << "Tipo: " << atual->tipo << "\n";
            cout << "Quantidade: " << atual->quantidade << "\n";
            cout << "Situacao: " << obterTextoSituacao(atual->situacao) << "\n";
            cout << "----------------------------------------\n";
            return;
        }
        atual = atual->proximo;
    }

    cout << "\nEquipamento nao encontrado.\n";
}

// 4. Remover equipamento por codigo
void removerEquipamento(Equipamento*& inicio) {
    if (inicio == NULL) {
        cout << "\nA lista esta vazia. Nao e possivel remover.\n";
        return;
    }

    int codigoRemover;
    cout << "\nDigite o codigo do equipamento a ser removido: ";
    cin >> codigoRemover;

    Equipamento* atual = inicio;
    Equipamento* anterior = NULL;

    while (atual != NULL && atual->codigo != codigoRemover) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        cout << "\nCodigo inexistente. Nenhum equipamento foi removido.\n";
        return;
    }

    if (anterior == NULL) {
        inicio = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    delete atual;
    cout << "Equipamento com codigo " << codigoRemover << " removido com sucesso!\n";
}

// 5. Contar equipamentos
int contarEquipamentos(Equipamento* inicio) {
    int contador = 0;
    Equipamento* atual = inicio;
    while (atual != NULL) {
        contador++;
        atual = atual->proximo;
    }
    return contador;
}

// 6. Liberar toda a memoria da lista ao sair
void liberarMemoria(Equipamento*& inicio) {
    Equipamento* atual = inicio;
    while (atual != NULL) {
        Equipamento* aux = atual;
        atual = atual->proximo;
        delete aux;
    }
    inicio = NULL;
    cout << "\nMemoria liberada com sucesso. inicio -> NULL\n";
}

// Exibir Menu
void exibirMenu() {
    cout << "\n========================================\n";
    cout << "CONTROLE DE EQUIPAMENTOS - LABORATORIO\n";
    cout << "========================================\n";
    cout << "1 - Inserir equipamento\n";
    cout << "2 - Exibir equipamentos\n";
    cout << "3 - Pesquisar equipamento\n";
    cout << "4 - Remover equipamento\n";
    cout << "5 - Contar equipamentos\n";
    cout << "6 - Sair\n";
    cout << "Escolha: ";
}

int main() {
    Equipamento* inicio;
    inicializar(inicio);

    int opcao = 0;

    do {
        exibirMenu();
        if (!(cin >> opcao)) {
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        switch (opcao) {
            case 1: inserirEquipamento(inicio); break;
            case 2: exibirEquipamentos(inicio); break;
            case 3: pesquisarEquipamento(inicio); break;
            case 4: removerEquipamento(inicio); break;
            case 5: cout << "\nQuantidade: " << contarEquipamentos(inicio) << "\n"; break;
            case 6: liberarMemoria(inicio); cout << "Programa encerrado.\n"; break;
            default: cout << "\nOpcao invalida!\n"; break;
        }
    } while (opcao != 6);

    return 0;
}