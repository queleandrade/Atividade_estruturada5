#include <iostream>

using namespace std;

struct no {
    int valor;  // Armazena o valor do nó
    no *prox;   // Armazena o endereço do próximo nó da lista
};

int main() {
    int n;
    cout << "Digite a qtd de números de nos na lista:";
    cin >> n;

    // Criando o primeiro nó e armazenado seu endereço em uma variável chamada inicio
    no *inicio = new no;
    inicio->prox = NULL;  // primeiro nó da lista -> não há próximo nó

    // Insere n nós no início da lista digitado pelo usuário
    for (int i = 0; i < n; i++) {
        int valor;
        cout << "Digite o valor do no " << i+1 << ": ";
        cin >> valor;

        // Cria um novo nó e armazena seu endereço em uma variável chamada novoNo
        no *novoNo = new no;
        novoNo->valor = valor;

        // Faz o novo nó apontar para o antigo início da lista
        novoNo->prox = inicio;

        // Faz o início da lista apontar para o novo nó
        inicio = novoNo;
    }

    // Imprime os valores da lista
    cout << "Valores na lista: ";
    no *p = inicio;  // Inicializa um ponteiro chamado "p" para percorrer a lista a partir do início
    while (p != NULL) {  // Enquanto não chegar ao final da lista
        cout << p->valor << " ";  // Imprime o valor do nó atual
        p = p->prox;  // Move o ponteiro para o próximo nó da lista
    }
    cout << endl;

    // Libera a memória alocada para a lista
    no *aux;
    while (inicio != NULL) {  // Enquanto houver nós na lista
        aux = inicio;  // Armazena o endereço do nó atual em uma variável auxiliar
        inicio = inicio->prox;  // Move o ponteiro "inicio" para o próximo nó da lista
        delete aux;  // Libera a memória alocada para o nó atual
    }

    return 0;
}
