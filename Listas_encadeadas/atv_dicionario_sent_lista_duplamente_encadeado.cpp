#include <string>
#include <iostream>
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
    Noh *sentinela; 
    public:

    Dicionario(){inicio = sentinela;}

    void inserir(int c, string v) 
    {
        Noh *novo = new Noh{sentinela, c, v, inicio};
        inicio->ant=novo;
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
        sentinela->chave=c;
        while (n->chave != c) { n = n->prox; }
        if (n == sentinela)
        {
            ret.achou = false;
            return ret;
        }
            ret.achou = true;
            ret.valor = n->elem; 
            return ret;  
    }

    void inserir_se_novo(int c, string v) {
        ResConsulta r = consulta(c);
        if (!r.achou) 
        {
            inserir(c, v);
        }
    }

    void remover(int c) {
        Noh *n = inicio;
        while (n != sentinela) 
        {
            if (n->chave == c) 
            {
                n->ant->prox = n->prox;
                n->prox->ant = n->ant;
                if (n == inicio)
                {
                    inicio = n->prox;
                }
                delete n;
                return;
            }
            n = n->prox;
        }
    }

    ~Dicionario() {
        Noh *n = inicio;
        while (n != sentinela)
        {
            Noh *p = n;
            n = n->prox;
            delete p;
        }
        delete sentinela;
    }
};

int main() {
    try {
        Dicionario dic;
        dic.inserir(1, "um");
        dic.inserir(2, "dois");
        dic.inserir(3, "tres");
        dic.inserir(4, "quatro");
        dic.inserir(5, "cinco");
        dic.inserir(6, "seis");

        auto res = dic.consulta(1);
        if (res.achou) {
            cout << "Chave 1 encontrada: " << res.valor << endl;
        } else {
            cout << "Chave 1 nao encontrada" << endl;
        }

        dic.remover(3);
        res = dic.consulta(3);
        if (res.achou) {
            cout << "Chave 3 encontrada: " << res.valor << endl;
        } else {
            cout << "Chave 3 nao encontrada" << endl;
        }

    } catch (const exception &e) {
        cerr << "EXCECAO: " << e.what() << '\n';
    }
    return 0;
}