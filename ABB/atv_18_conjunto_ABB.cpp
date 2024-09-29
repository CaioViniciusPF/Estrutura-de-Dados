#include <iostream>
#include <vector>
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

void destruir(Noh *n)
    {
        if (n != nullptr)
        {
            // Apaga os nós recursivamente (pós-ordem)
            destruir(n->esq);  // Deleta a subárvore esquerda
            destruir(n->dir);  // Deleta a subárvore direita
            delete n;          // Deleta o nó atual
        }
    }
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
    void remover (double e)
    {
        Noh *n = raiz;
        Noh* *cima = &raiz;
        
        while (n != nullptr)
        {
            if (e < n->elem)
            {
                cima = & n;
                n = n->esq;
            }
            else if (e > n->elem)
            {
                cima = &n;
                n = n->dir;
            }
            else break;
        }
        if (n == nullptr) return;

        if      (n->dir == nullptr) *cima = n->esq;
        else if (n->esq == nullptr) *cima = n->dir;
        else
        {
            Noh *s = n->dir;
            Noh* *cima_s = & n->dir;
            while (s->esq !=nullptr)
            {
                cima_s = & s->esq;
                s = s->esq;
            }
            
            *cima_s = s->dir;
            *cima = s;
            s->esq = n->esq;
            s->dir = n->dir;

        }
        
        delete n;
    }

    Noh* construir(const vector<double>& nums, int inicio, int fim)
    {
       
        if (inicio > fim)
            return nullptr;

        // Encontrar o elemento do meio
        int meio = (inicio + fim) / 2;

        // Criar o nó da árvore
        Noh* novo = new Noh{nullptr, nums[meio], nullptr};

        // Recursivamente construir a subárvore esquerda e direita
        novo->esq = construir(nums, inicio, meio - 1);
        novo->dir = construir(nums, meio + 1, fim);

        return novo;
    }
     void imprimirInOrder(Noh *n)
    {
        
        if (n == nullptr) return;

        imprimirInOrder(n->esq);
        cout << n->elem << " ";
        imprimirInOrder(n->dir);
    }
    // Inicializa a construção da árvore e impressão
    void InicializarConstrucao(const vector<double>& nums)
    {
        raiz = construir(nums, 0, nums.size() - 1);
        imprimirInOrder(raiz);
        cout << endl;
    }

    ~ConjABB()
    {
        destruir(raiz);
    }

};

int main()
{
    // Vetor ordenado de exemplo
    vector<double> nums = {1, 2, 3, 4, 5, 6, 7};

    ConjABB arvore;
    arvore.InicializarConstrucao(nums);

    return 0;
}