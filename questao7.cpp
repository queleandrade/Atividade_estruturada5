#include <iostream>
using namespace std;

struct No {
    int valor;
    No *proximo;
};

// Função para inserir um valor inteiro no fim da lista
No* insereFim(No *inicio, int valor) {
    No *novoNo = new No;
    novoNo->valor = valor;
    novoNo->proximo = nullptr;
    
    if (inicio == nullptr) {
        // Se a lista estiver vazia, o novo nó será o início da lista
        inicio = novoNo;
    } else {
        // Senão, percorre a lista até encontrar o último nó e adicionamos o novo nó lá
        No *p = inicio;
        while (p->proximo != nullptr) {
            p = p->proximo;
        }
        p->proximo = novoNo;
    }
    
    return inicio;
}

int main() {
    int m;
    cout << "Digite a quantidade de nos da lista: ";
    cin >> m;
    
    No *inicio = nullptr; // Inicializa a lista como vazia
    
    // Loop para construir a lista com m nós
    for (int i = 0; i < m; i++) {
        int valor;
        cout << "Digite o valor do no " << i+1 << ": ";
        cin >> valor;
        inicio = insereFim(inicio, valor); // Insere o valor no fim da lista
    }
    
    // Imprime a lista
    cout << "Lista: ";
    No *p = inicio;
    while (p != nullptr) {
        cout << p->valor << " ";
        p = p->proximo;
    }
    cout << endl;
    
    return 0;
}
