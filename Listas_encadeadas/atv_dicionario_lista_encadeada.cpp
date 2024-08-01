#include<string>
using std::string;
class Dicionario 
{
    struct Noh
    {
        int chave;
        string elem;
        Noh *prox;
    };
    Noh *inicio;
    public:

    Dicionario(){inicio=nullptr;}

    void inserir(int c, string v)
    {
        inicio = new Noh{c,v,inicio};
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
        if ( n->chave == c)
        {
            inicio = inicio->prox;
            delete n;
            return;
        }
        while ( n->prox != nullptr)
        {
            if (n->prox->chave == c)
            {
                Noh *p = n->prox;
                n->prox= p->prox;
                delete p;
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