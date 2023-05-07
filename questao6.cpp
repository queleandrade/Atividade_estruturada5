#include <iostream>
using namespace std;

// Definição da estrutura de nó da lista
struct No {
    int valor;
    No *proximo;
};

// Função para contar o número de nós da lista
int contaNos(No *inicio) {
    int count = 0;
    
    // Percorre a lista enquanto não chegar ao final
    while (inicio != nullptr) {
        count++;
        inicio = inicio->proximo;
    }
    
    return count;
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
    
    // Chama a função para contar o número de nós da lista
    int quantidade = contaNos(inicio);
    
    cout << "A lista possui " << quantidade << " nos." << endl;
    
    return 0;
}
