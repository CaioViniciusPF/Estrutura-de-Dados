#include <iostream>
using namespace std;

class DicioTD // Dicionario via tabela de dispercao
{

struct Noh
{
    int chave;
    string valor;
    Noh *prox;
};
int m; //tamanho da tabela
int n; //numero de elemetos
Noh **T;
Noh sent;

int h (int c){ return (m % c);} //Funcao de dispercao
void redimencionar (int novo_tam)
{
    Noh **U = new Noh* [novo_tam];
    int tam_atual = m;
    m = novo_tam; // para viabilizar o usos de h
    int i;
    for ( i = 0; i < novo_tam;  i++) U[i]= &sent;
    for ( i = 0; i < tam_atual; i++)
    {
        Noh *n = T[i];
        while (n != &sent)
        {
            Noh *p = n->prox;
            int j = h(n->chave);
            n->prox = U[j];
            U[j] = n;
            n = p; 
        }
        
    }
    delete[] T;
    T = U;
}
public:
    DicioTD()
    {
        m = 1;
        n = 0;
        T = new Noh * [m];
        for (size_t i = 0; i < m; i++) T[i] = &sent;
        
    }
    ~DicioTD()
    {
        for (int i = 0; i < m; i++) {
            Noh* n = T[i];
            while (n != &sent) {
                Noh* prox = n->prox;
                delete n; // Libera cada nó
                n = prox; // Move para o próximo nó da lista
            }
        }
        delete[] T; // Libera o array da tabela
    }
//Pre condicao: A chave "c" nao pertence ao dicionario
void inserir (int c , string v )
{
    if ( m == n) redimencionar(2*m);
    int i = h(c);
    T[i]= new Noh {c, v, T[i]};
    ++n;
}
void remover (int c){
    int i = h(c); // Calcula o índice usando a função de dispersão
    Noh* inicio = T[i]; // Aponta para o início da lista no índice i
    Noh* anterior = nullptr; // Ponteiro para o nó anterior, usado para remoção
    
    while (inicio != &sent) {
        if (inicio->chave == c) { // Se encontrar a chave
            if (anterior == nullptr) {
                T[i] = inicio->prox; // Remove o primeiro nó da lista
            } else {
                anterior->prox = inicio->prox; // Remove nó intermediário ou final
            }
            delete inicio;  // Libera a memória do nó removido
            --n;            // Decrementa o número de elementos

            // Contrai a tabela se estiver 1/4 preenchida
            if (n > 0 && n == (m / 4)) {
                redimencionar(m / 2);
            }
            return; // Sai da função após remover
        }
        anterior = inicio; // Atualiza o nó anterior
        inicio = inicio->prox; // Move para o próximo nó
    }
    
    cout << "Chave " << c << " não encontrada no dicionário." << endl;
}
struct ResConsulta
{
    bool achou;
    string valor;
};
ResConsulta consulta(int c) {
    int i = h(c); // Calcula o índice usando a função de dispersão
    Noh* n = T[i]; // Aponta para o início da lista ligada no índice i
    
    while (n != &sent) { // Percorre a lista encadeada
        if (n->chave == c) { // Se encontrar a chave
            return {true, n->valor}; // Retorna o valor e indica que encontrou
        }
        n = n->prox; // Move para o próximo nó
    }
    
    // Se não encontrou, retorna um resultado negativo
    return {false, ""}; // Indica que não achou a chave
}
};

int main() {
    DicioTD dicionario;
    
    dicionario.inserir(1, "valor1");
    dicionario.inserir(2, "valor2");
    dicionario.inserir(3, "valor3");
    
    auto resultado = dicionario.consulta(2);
    if (resultado.achou) {
        cout << "Chave 2 encontrada, valor: " << resultado.valor << endl;
    } else {
        cout << "Chave 2 não encontrada." << endl;
    }

    dicionario.remover(2);
    
    resultado = dicionario.consulta(2);
    if (!resultado.achou) {
        cout << "Chave 2 removida com sucesso." << endl;
    }
    
    return 0;
}
