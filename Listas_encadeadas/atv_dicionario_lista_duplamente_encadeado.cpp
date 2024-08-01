#include <string>
#include <iostream>
using std::string;
using namespace std;
class Dicionario 
{
    struct Noh
    {
        Noh *ant;
        int chave;
        string elem;
        Noh *prox;
    };
    Noh *inicio;
    Noh *fim;
    public:

    Dicionario(){inicio=fim=nullptr;}

    void inserir(int c, string v)
    {
        Noh *novo = new Noh{nullptr,c,v,inicio};
        if (inicio==nullptr)    { fim           = novo; }
        else                    { inicio->ant   = novo; }
        inicio=novo;  
    }

    struct ResConsulta
    {
        bool achou;
        string valor;
    };
    
    ResConsulta consulta(int c)
    {
        ResConsulta ret;
        Noh *n = inicio;
        while (n != nullptr)
        {   
            if (n->chave == c)
            {
                ret.achou=true;
                ret.valor=n->elem;
                return ret;
            }
            n = n->prox;
        }
        ret.achou=false;
        return ret;
    }

    void inserir_se_novo(int c, string v){
        ResConsulta r = consulta(c);
        if (not r.achou)
        {
            inserir(c,v);
        }
        
    }
    void remover (int c)
    {
        Noh *n=inicio;
        if (n == nullptr) return;

        while ( n != nullptr)
        {
            if ( n->chave == c)
            {
                if (n->ant != nullptr)
                {
                    n->ant->prox = n->prox;
                }else
                {
                    inicio = n->prox;
                }
                if (n->prox != nullptr)
                {
                    n->prox->ant = n->ant;
                }else
                {
                    fim = n->ant;
                }

                delete n;
                return;
            }
            n = n->prox;
        } 
    }
    ~Dicionario(){
        while (inicio != nullptr)
        {
            Noh *p =inicio;
            inicio = inicio->prox;
            delete p;
        }
    }
};
int main()
{
    try
    {
        Dicionario dic;
        dic.inserir(1, "um");
        dic.inserir(2, "dois");
        dic.inserir(3, "três");

        auto res = dic.consulta(2);
        if (res.achou) {
            cout << "Chave 2 existe e tem valor: " << res.valor << endl;
        } else {
            cout << "Chave 2 nao encontrada" << endl;
        }

        dic.remover(2);
        res = dic.consulta(2);
        if (res.achou) {
            cout << "Chave 2 existe e tem valor: " << res.valor << endl;
        } else {
            cout << "Chave 2 nao encontrada" << endl;
        }
    }
    catch( const exception &e)
    {
        cerr << "EXCECAO: "<< e.what() << '\n';
    }
}