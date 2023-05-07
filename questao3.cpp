#include <iostream>
using namespace std;

struct No {
    int dado;   // dado armazenado no nó
    No* prox;   // ponteiro para o próximo nó da lista
};

// Função para inserir um valor inteiro no início da lista
No* insereFrente(No* inicio, int valor) {
    // Cria um novo nó e atribui o valor a ele
    No* novo = new No;
    novo->dado = valor;
    novo->prox = nullptr;
    
    // Se a lista estiver vazia, o novo nó será o início da lista
    if (inicio == nullptr) {
        inicio = novo;
    } else {
        // Caso contrário, o novo nó será adicionado no início da lista
        novo->prox = inicio;
        inicio = novo;
    }
    
    return inicio;
}

// Função para substituir o valor de um nó da lista
void substituir(No* inicio, int posicao, int novoValor) {
    // Variável para percorrer a lista
    No* atual = inicio;
    
    // Percorre a lista até encontrar o nó desejado ou até o final da lista
    for (int i = 1; i < posicao && atual != nullptr; i++) {
        atual = atual->prox;
    }
    
    // Se o nó foi encontrado, substitui o valor
    if (atual != nullptr) {
        atual->dado = novoValor;
        cout << "Valor substituído com sucesso!" << endl;
    } else {
        cout << "Nó não encontrado." << endl;
    }
}

// Função para imprimir os valores da lista
void imprimir(No* inicio) {
    // Variável para percorrer a lista
    No* atual = inicio;
    
    // Percorre a lista e imprime os valores dos nós
    while (atual != nullptr) {
        cout << atual->dado << " ";
        atual = atual->prox;
    }
    
    cout << endl;
}

// Função principal
int main() {
    int n, valor, posicao, novoValor;
    No* inicio = nullptr;   // inicializa o início da lista como vazio
    
    cout << "Quantidade de nós da lista: ";
    cin >> n;
    
    // Loop para inserir os nós na lista
    for (int i = 0; i < n; i++) {
        cout << "Valor do nó " << i+1 << ": ";
        cin >> valor;
        inicio = insereFrente(inicio, valor);
    }
    
    // Imprime os valores da lista
    cout << "Valores da lista: ";
    imprimir(inicio);
    
    // Solicita a posição do nó a ser substituído
    do {
        cout << "Posição do nó a ser substituído (1 a " << n << "): ";
        cin >> posicao;
    } while (posicao <= 0 || posicao > n);
    
    // Solicita o novo valor para o nó
    cout << "Novo valor para o nó " << posicao << ": ";
    cin >> novoValor;
    
    // Substitui o valor do nó selecionado
    substituir(inicio, posicao, novoValor);
    
    // Imprime os valores atualizados da lista
    cout << "Lista apos substituicao: ";
    imprimir(inicio);
    
    return 0;
}


