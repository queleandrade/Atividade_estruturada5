#include <iostream>
using namespace std;

struct No {
    int valor;
    No* proximo;
};

No* concatena(No* inicio1, No* inicio2) {
    // Se a primeira lista estiver vazia, retorna a segunda lista
    if (inicio1 == nullptr) {
        return inicio2;
    }

    // Armazena o endereço do primeiro nó da primeira lista
    No* p = inicio1;

    // Percorre a primeira lista até chegar ao último nó
    while (p->proximo != nullptr) {
        p = p->proximo;
    }

    // Faz o último nó da primeira lista apontar para o primeiro nó da segunda lista
    p->proximo = inicio2;

    // Retorna o início da primeira lista, que agora está concatenada com a segunda
    return inicio1;
}

int main() {
    int n, m;
    cout << "Quantidade de nos da primeira lista: ";
    cin >> n;

    No* inicio1 = nullptr;

    // Cria a primeira lista com n nós
    for (int i = 0; i < n; i++) {
        No* novoNo = new No;
        cout << "Valor do no " << i + 1 << " da primeira lista: ";
        cin >> novoNo->valor;
        novoNo->proximo = inicio1;
        inicio1 = novoNo;
    }

    cout << "Quantidade de nos da segunda lista: ";
    cin >> m;

    No* inicio2 = nullptr;

    // Cria a segunda lista com m nós
    for (int i = 0; i < m; i++) {
        No* novoNo = new No;
        cout << "Valor do no " << i + 1 << " da segunda lista: ";
        cin >> novoNo->valor;
        novoNo->proximo = inicio2;
        inicio2 = novoNo;
    }

    // Concatena as duas listas e armazena o início da lista resultante
    No* inicioConcatenado = concatena(inicio1, inicio2);

    // Imprime a lista concatenada
    cout << "Lista concatenada: ";
    No* p = inicioConcatenado;
    while (p != nullptr) {
        cout << p->valor << " ";
        p = p->proximo;
    }
    cout << endl;

    return 0;
}
