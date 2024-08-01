#include <iostream>
using namespace std;

struct Pilha
{
    struct Noh
    {
        int elem;
        Noh* prox;
    };

    Noh *topo;
    Pilha () 
    {
        topo=nullptr;
    }
    void empilhar(int e)
    {
        Noh *novo =new Noh;
        novo->elem=e;
        novo->prox=topo;
        topo=novo;
        // mesma funcionalidade
        // topo= new Noh {e,topo};
    };
    int consultar_topo(){return topo->elem;}
    void desempilhar()
    {
        Noh *primeiro =topo;
        topo=topo->prox;
        delete primeiro;
    };
    ~Pilha()
    {
        while (topo != nullptr) {
            Noh *aux = topo;
            topo = topo->prox;
            delete aux;
        }
        
    }
};

int main() {
    
    try {
        Pilha p;

        // Empilhando elementos
        p.empilhar(10);
        p.empilhar(20);
        p.empilhar(30);

        // Consultando e desempilhando elementos
        cout << "Topo: " << p.consultar_topo() << endl; // Deve imprimir 30
        p.desempilhar();
        cout << "Topo: " << p.consultar_topo() << endl; // Deve imprimir 20
        p.desempilhar();
        cout << "Topo: " << p.consultar_topo() << endl; // Deve imprimir 10
        p.desempilhar();

        // Tentativa de consultar o topo de uma pilha vazia
        cout << "Topo: " << p.consultar_topo() << endl; // Deve lançar exceção

    } catch (const exception &e) {
        cerr << "Erro: " << e.what() << endl;
    }

    return 0;
}