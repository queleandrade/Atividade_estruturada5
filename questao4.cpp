#include <iostream>
using namespace std;

struct no {
    int dado;
    no* proximo;
};

// Função para remover o primeiro nó da lista
no* removerInicio(no* inicio) {
    if (inicio == nullptr) { // Verifica se a lista está vazia
        cout << "Lista vazia!" << endl;
        return inicio;
    }
    no* aux = inicio; // Armazena o nó a ser removido em uma variável auxiliar
    inicio = inicio->proximo; // Ajusta o início da lista para o segundo nó
    delete aux; // Libera a memória do nó removido
    return inicio; // Retorna o ponteiro para o início da lista
}

int main() {
    int n;
    cout << "Digite a quantidade de nos: ";
    cin >> n;

    no* inicio = nullptr; // Inicializa a lista vazia

    // Loop para inserir n nós no início da lista
    for (int i = 1; i <= n; i++) {
        int valor;
        cout << "Digite o valor do no " << i << ": ";
        cin >> valor;
        no* novoNo = new no; // Aloca um novo nó na memória
        novoNo->dado = valor; // Atribui o valor ao novo nó
        novoNo->proximo = inicio; // Ajusta o ponteiro para o próximo nó
        inicio = novoNo; // Ajusta o início da lista para o novo nó
    }

    // Imprime a lista antes de remover o primeiro nó
    cout << "Lista antes da remocao do primeiro no:" << endl;
    no* atual = inicio;
    while (atual != nullptr) {
        cout << atual->dado << " ";
        atual = atual->proximo;
    }
    cout << endl;

    inicio = removerInicio(inicio); // Remove o primeiro nó da lista

    // Imprime a lista após remover o primeiro nó
    cout << "Lista apos a remocao do primeiro no:" << endl;
    atual = inicio;
    while (atual != nullptr) {
        cout << atual->dado << " ";
        atual = atual->proximo;
    }
    cout << endl;

    return 0;
}
