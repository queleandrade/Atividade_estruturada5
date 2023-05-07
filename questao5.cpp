#include <iostream>
using namespace std;

struct No {
    int valor;
    No *proximo;
};

No* busca(No *inicio, int valor) {
    No *p = inicio;
    // vai para o proximo nó, ate que o valor seja encontrado
    while (p != nullptr && p->valor != valor) {
        p = p->proximo; // próximo nó
    }
    // Se chegamos ao final da lista -> valor não encontrado
    if (p == nullptr) {
        cout << "Valor nao encontrado na lista." << endl;
        return nullptr; // retorna null
    } else {
        cout << "Valor encontrado na posicao " << p << " da lista." << endl;
        return p; // retorna o endereço e o valor
    }
}

int main() {
    int n;
    cout << "Quantidade de nos: ";
    cin >> n;
    
    No *inicio = nullptr;
    
    // Cria a lista com n nós
    for (int i = 0; i < n; i++) {
        No *novoNo = new No;
        cout << "Valor do no " << i+1 << ": ";
        cin >> novoNo->valor;
        novoNo->proximo = inicio;
        inicio = novoNo;
    }
    
    cout << "Lista criada:" << endl;
    No *p = inicio;
    while (p != nullptr) {
        cout << p->valor << " ";
        p = p->proximo;
    }
    cout << endl;
    
    int valorBuscado;
    cout << "Valor a ser buscado: ";
    cin >> valorBuscado;
    
    No *noEncontrado = busca(inicio, valorBuscado);
    
    if (noEncontrado != nullptr) {
        cout << "Valor encontrado: " << noEncontrado->valor << endl;
    }
    
    return 0;
}
