#include <iostream>
using namespace std;

struct No {
    int valor;
    No *proximo;
};

// Função para remover o último nó da lista
No* removeFim(No *inicio) {
    // Verifica se a lista está vazia
    if (inicio == nullptr) {
        cout << "Lista vazia." << endl;
        return inicio;
    }
    
    // Verifica se há apenas um nó na lista
    if (inicio->proximo == nullptr) {
        delete inicio;
        return nullptr;
    }
    
    // Percorre a lista até chegar no penúltimo nó
    No *p = inicio;
    while (p->proximo->proximo != nullptr) {
        p = p->proximo;
    }
    
    // Remove o último nó e atualiza o ponteiro do penúltimo nó, operador
    delete p->proximo;
    p->proximo = nullptr;
    
    return inicio;
}

int main() {
    int m;
    cout << "Quantidade de nos: ";
    cin >> m;
    
    No *inicio = nullptr;
    
    // Cria a lista com m nós
    for (int i = 0; i < m; i++) {
        int valor;
        cout << "Valor do no " << i+1 << ": ";
        cin >> valor;
        
        // Insere o valor no fim da lista
        No *novoNo = new No;
        novoNo->valor = valor;
        novoNo->proximo = nullptr;
        
        if (inicio == nullptr) {
            inicio = novoNo;
        } else {
            No *p = inicio;
            while (p->proximo != nullptr) {
                p = p->proximo;
            }
            p->proximo = novoNo;
        }
    }
    
    cout << "Lista antes da remocao do ultimo no:" << endl;
    No *p = inicio;
    while (p != nullptr) {
        cout << p->valor << " ";
        p = p->proximo;
    }
    cout << endl;
    
    inicio = removeFim(inicio);
    
    cout << "Lista apos a remocao do ultimo no:" << endl;
    p = inicio;
    while (p != nullptr) {
        cout << p->valor << " ";
        p = p->proximo;
    }
    cout << endl;
    
    return 0;
}
