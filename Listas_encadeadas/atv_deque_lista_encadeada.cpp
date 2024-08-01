#include <iostream>
using namespace std;

class Deque
{
    struct Noh
    {
        Noh *ant;
        int elem;
        Noh *prox;
    };
    Noh *esq, *dir;
public:


    Deque()
    {
        esq = dir= nullptr ;
    };

    bool vazio(){return (esq==nullptr and dir == nullptr);}
    
    void inserir_esq( int e)
    {
        Noh *novo = new Noh{nullptr,e,esq};
        if(esq==nullptr){ dir      = novo; } 
        else            { esq->ant = novo; }
        
        esq = novo;
    }
    void inserir_dir( int e)
    {
        Noh *novo = new Noh{dir,e,nullptr};
        if(dir==nullptr){ esq      = novo; }
        else            { dir->prox = novo; }
        dir = novo;
    }
    void remover_esq()
    {
        Noh *aux = esq;
        esq = esq->prox;
        if (esq == nullptr) { dir      = nullptr;}
        else                { esq->ant = nullptr;}

        delete aux;
    }
     void remover_dir()
    {
        Noh *aux = dir;
        dir = dir->ant;
        if (dir == nullptr) { esq      = nullptr;}
        else                { dir->prox = nullptr;}

        delete aux;
    }
    int consultar_esq(){return (esq->elem);}
    int consultar_dir(){return (dir->elem);}

    ~Deque()
    {
        while (dir != nullptr)
        {
            remover_dir();
        }
        
    }
};
int main() {
    Deque dq;

    // Testando inserção pela esquerda
    dq.inserir_esq(10);
    dq.inserir_esq(20);
    dq.inserir_esq(30);

    cout << "Deque apos insercoes pela esquerda: ";
    cout << "Esq: " << dq.consultar_esq() << " | ";
    cout << "Dir: " << dq.consultar_dir() << endl;

    // Testando inserção pela direita
    dq.inserir_dir(40);
    dq.inserir_dir(50);
    dq.inserir_dir(60);

    cout << "Deque apos insercoes pela direita: ";
    cout << "Esq: " << dq.consultar_esq() << " | ";
    cout << "Dir: " << dq.consultar_dir() << endl;

    // Testando remoção pela esquerda
    dq.remover_esq();
    cout << "Deque apos remocao pela esquerda: ";
    cout << "Esq: " << dq.consultar_esq() << " | ";
    cout << "Dir: " << dq.consultar_dir() << endl;

    // Testando remoção pela direita
    dq.remover_dir();
    cout << "Deque apos remocao pela direita: ";
    cout << "Esq: " << dq.consultar_esq() << " | ";
    cout << "Dir: " << dq.consultar_dir() << endl;

    return 0;
}
