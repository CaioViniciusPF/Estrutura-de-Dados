#include <iostream>
#include <exception>
using namespace std;

class ConjABB
{
struct Noh
{
    Noh *esq;
    double elem;
    Noh *dir;
};
Noh *raiz;
public:

    ConjABB ()
    {
        raiz=nullptr;
    }
    bool vazio()
    {
        return( raiz==nullptr );
    }
    void inseirir (double e)
    {
        Noh *novo = new Noh { nullptr, e, nullptr};
        if (raiz==nullptr)
        {
            raiz = novo;
            return;
        }
        Noh *n = raiz;
        while (true)
        {
            if (e < n->elem)
            {
                if (n->esq == nullptr)
                {
                   n->esq = novo;
                   return;
                }
                n = n->esq;
                
            }
            else
            {
                if (n->dir == nullptr)
                {
                    n->dir = novo;
                    return;
                }
                n = n->dir;
            }
        }
    }
    bool pertence (double e)
    {
        Noh *n = raiz;
        while (n != nullptr)
        {
            if      ( e < n->elem) n = n->esq;          
            else if ( n->elem > e) n = n->dir;
            else                   return true;
        }
        return false;
    }




    ~ConjABB ()
    {

    }
};