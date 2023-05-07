#include <iostream>

using namespace std;

struct no {
    int valor;  // Armazena o valor do nó
    no *prox;   // Armazena o endereço do próximo nó da lista
};

//  a função imprimir é recursiva e recebe como parâmetro um ponteiro para o nó atual da lista
void imprimir(no *p) {
    if (p == NULL) {  // se o nó atual for NULL -> retorna sem fazer nada
        return;
    }
    cout << p->valor << " ";  // Imprime o valor do nó atual
    imprimir(p->prox);  // Chamando a função recursivamente para imprimir o restante da lista
}

int main() {
    no *inicio = new no;
    no *p = inicio;
    for (int i = 0; i < 3; i++) {  //criando uma lista com 3 nós
        p->valor = i+1;
        p->prox = new no;
        p = p->prox;
    }
    p->prox = NULL;  // último nó como sendo o fim da lista

    // Imprimindo
    cout << "Valores na lista: ";
    imprimir(inicio);
    cout << endl;

    // Libera a memória alocada
    no *aux;
    while (inicio != NULL) {  // Enquanto houver nós na lista
        aux = inicio;  // Armazena o endereço do nó atual em uma variável auxiliar
        inicio = inicio->prox;  // Move o ponteiro "inicio" para o próximo nó da lista
        delete aux;  // Libera a memória alocada para o nó atual
    }

    return 0;
}
