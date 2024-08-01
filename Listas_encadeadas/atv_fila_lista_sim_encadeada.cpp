#include <iostream>
using namespace std;
 class Fila
 {
struct Noh
{
    string elem;
    Noh *prox;
};
Noh *fim,*comeco;
 public:

 
    Fila()
    {
        fim = comeco=nullptr;
    }

    bool vazia(){return (comeco==nullptr);}
    void enfilar_fim (string e)
    {
        Noh *novo = new Noh{e,nullptr};

        if (vazia()){ comeco = novo; }
        else      { fim->prox = novo; }

        fim = novo;
        
    }
    void enfilar_comeco (string e)
    {
        Noh *novo = new Noh{e,comeco};

        if (vazia()){  fim = novo; }
        
        comeco = novo; 
        
    }
    void desenfilar ()
    {
        if (not vazia())
        {
            Noh *aux = comeco;
            comeco   = comeco ->prox;
            if (comeco == nullptr){fim = nullptr;}
            
            delete aux;
        }else 
        {
            throw runtime_error("Fila vazia");
        }  
    }
    string consultar (){ 
        if (!vazia()) {
            return comeco->elem;
        } else {
            throw runtime_error("Fila vazia");
        }
        }
    ~Fila()
    {
        while (not vazia())
        {
            desenfilar();
        }
    }
 };
 int main ()
 {
    try
    {
        Fila f;
        f.enfilar_fim("b");
        f.enfilar_fim("c");
        f.enfilar_comeco("a");
        cout << "Consulta: " << f.consultar() << endl;
        f.desenfilar();
        cout << "Consulta apos remocao: " << f.consultar() << endl;
        f.desenfilar();
        cout << "Consulta apos segunda remocao: " << f.consultar() << endl;
        f.desenfilar();
        cout << "Vazia: " << f.vazia() << endl;
    }
    catch( const exception &e)
    {
        cerr << "EXCECAO: "<< e.what() << '\n';
    }
    
 }
 
 