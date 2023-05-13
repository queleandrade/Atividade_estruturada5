
// 

#include<iostream>

using namespace std;

//Estrutura
struct no {
    int numero;
    no* referencia;
};
// Prototipo
int Menu();
no* CreateNo(int numero);
void InsertNo(no** inicio, int numero);
void ListarNos(no* inicio);
no* insereFrente(no* inicio, int valor);
// Função para substituir o valor de um nó da lista
void substituir(no* inicio, int posicao, int novoValor);
// Função para remover o primeiro nó da lista
no* removerInicio(no* inicio);

int main()
{
    int op;
    int n,numero;
    no* inicio = NULL;
    no* atual = inicio;
    do{
        op = Menu();
         switch(op){
            case 1:
                
                cout << "Digite a quantidade de NOS para a lista: ";
                cin >> n;
                while (n < 0) {
                    cout << "A quantidade de nos deve ser maior ou igual a zero. ";
                    cin >> n;
                }
                inicio = NULL;
                for (int i = 1; i <= n; i++) {
                    
                    cout << "Digite o valor do no " << i << ": ";
                    cin >> numero;
                    InsertNo(&inicio, numero);
                }
                break;
            case 2:
                
               atual= inicio;
                
                // n+=1;
                cout << "Digite o valor a ser inserido: ";
                cin >> numero;
                
                
                inicio=insereFrente(inicio,numero);
                ListarNos(inicio);
                n++;
                // for (int i = 1; i <= n; i++) {
                    
                //     cout << "Digite o valor do no " << i << ": ";
                //     cin >> numero;
                //     insereFrente(inicio,valor)
                // }
            
                break;
            
            case 3:
                cout << "Lista: ";
                ListarNos(inicio);
                break;
            case 4:
                 int posicao, novoValor;
                 do {
                        cout << "Posição do nó a ser substituído (1 a " << n << "): ";
                        cin >> posicao;
                } while (posicao <= 0 || posicao > n);

                // Solicita o novo valor para o nó
                cout << "Novo valor para o nó " << posicao << ": ";
                cin >> novoValor;

                // Substitui o valor do nó selecionado
                substituir(inicio, posicao, novoValor);
                break;
             case 5:
                 
                inicio = removerInicio(inicio); // Remove o primeiro nó da lista

                // Imprime a lista após remover o primeiro nó
                cout << "Lista apos a remocao do primeiro no:" << endl;
                atual = inicio;
                ListarNos(atual);
             case 6:
                 break;
        }
    }while(op!=0);
    return 0;
}

// implementação
int Menu(){
    int op;
    cout << "[1] - Adicionar valores"<< endl;
    cout << "[2] - Adicionar ao inicio"<< endl;
    cout << "[3] - Listar"<< endl;
    cout << "[4] - Substituir valor"<< endl;
    cout << "[5] - Remover do inicio"<< endl;
    cout << "[0] - Encerrar"<< endl;
    cin >> op;
    
    return op;
}
no* CreateNo(int numero){
    
    // aqui ele está 'estanciando' um novo no
    no* newNo = new no;
    // aqui ele recebe o valor passado
    newNo->numero = numero;
    
    newNo->referencia = NULL;
    
    return newNo;
    
    
}

void InsertNo(no** inicio, int numero){
    no* newNo = CreateNo(numero);
    
    if(*inicio == NULL){
        *inicio = newNo;
        return;
    }
    no* atual = *inicio;
    while(atual->referencia != NULL) atual=atual->referencia;
    
    atual->referencia=newNo;
    
    
}

void ListarNos(no* inicio){
    no* atual = inicio;
    while(atual != NULL){
        cout << atual->numero << " ";
        atual=atual->referencia;
    }
    cout << endl;
}

no*  insereFrente(no* inicio, int valor){
    no* newNo = CreateNo(valor);
    newNo->referencia=inicio;
    return newNo;
}

void substituir(no* inicio, int posicao, int novoValor) {
    // Variável para percorrer a lista
    no* atual = inicio;
    
    // Percorre a lista até encontrar o nó desejado ou até o final da lista
    for (int i = 1; i < posicao && atual != NULL; i++) {
        atual = atual->referencia;
    }
    
    // Se o nó foi encontrado, substitui o valor
    if (atual != NULL) {
        atual->numero = novoValor;
        cout << "Valor substituído com sucesso!" << endl;
    } else {
        cout << "Nó não encontrado." << endl;
    }
}

// Função para remover o primeiro nó da lista
no* removerInicio(no* inicio) {
    if (inicio == NULL) { // Verifica se a lista está vazia
        cout << "Lista vazia!" << endl;
        return inicio;
    }
    no* aux = inicio; // Armazena o nó a ser removido em uma variável auxiliar
    inicio = inicio->referencia; // Ajusta o início da lista para o segundo nó
    delete aux; // Libera a memória do nó removido
    return inicio; // Retorna o ponteiro para o início da lista
}
