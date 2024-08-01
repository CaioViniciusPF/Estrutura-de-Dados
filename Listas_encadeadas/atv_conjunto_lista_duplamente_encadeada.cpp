#include <string>
#include <iostream>
using namespace std;

class Conjunto
{
struct Noh
{
    Noh *ant;
    int elem;
    Noh *prox;
};
    Noh *inicio,*fim;

public:

    Conjunto(){ inicio=fim=nullptr;}
    
    bool pertence(int e) //precondição, não esta vazia
    {
        Noh *n = inicio;
        while (n != nullptr) 
        { 
            if (n->elem == e)
            {
                return true; 
            }
            
            n = n->prox;
        }
        return false;
    }
    
    void inserir (int e)
    {
        Noh *novo = new Noh{nullptr,e,inicio};
        if ( inicio == nullptr) { fim = novo;}
        else                    { inicio->ant = novo;}
        inicio = novo;
    }
    
    void remover(int e)
    {
        Noh *n = inicio;
        if (pertence(e) && n != nullptr)
        {
            while (n != nullptr)
            {
                if (n->elem == e)
                {
                    if (n->ant != nullptr)
                    {
                        n->ant->prox = n->prox;
                    }
                    else
                    {
                        inicio = n->prox;
                    }

                    if (n->prox != nullptr)
                    {
                        n->prox->ant = n->ant;
                    }
                    else
                    {
                        fim = n->ant;
                    }

                    delete n;
                    return;
                }
                n = n->prox;
            }
        }
    }
    
    void inserir_novo (int e)
    {
        if (!pertence(e))
        {
            inserir(e);
        }
        
    }
    ~Conjunto()
    {
        while (inicio != nullptr)
        {
            Noh *p =inicio;
            inicio=inicio->prox;
            delete p;
        }
        
    }
};
int main ()
{
    try
    {
        Conjunto C;
        C.inserir(1);
        C.inserir(2);
        C.inserir(3);
        
        if (C.pertence(2))
        {
            cout << "2 pertence: "<< C.pertence(2) ;
        }else
        {
            cout << "2 nao pertence";
        }

        C.remover(2);

        if (C.pertence(2))
        {
            cout << "2 pertence: "<< C.pertence(2) ;
        }else
        {
            cout << "2 nao pertence" ;
        }
        
        
    }
    catch( const exception &e)
    {
        cerr << "EXCECAO: "<< e.what() << '\n';
    }
}

