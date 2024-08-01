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
    void enfilar (string e)
    {
        Noh *novo = new Noh{e,nullptr};

        if (vazia()){ comeco = novo; }
        else      { fim->prox = novo; }

        fim = novo;
        
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
        f.enfilar("a");
        f.enfilar("b");
        f.enfilar("c");
        cout << "Consulta: " << f.consultar() << endl;
        f.desenfilar();
        cout << "Desenfilado uma vez: " << f.consultar() << endl;
        cout << "Vazia: " << f.vazia() << endl;
        f.desenfilar();
        cout << "Desenfilado duas vezes: " << f.consultar() << endl;
        f.desenfilar();
        cout << "Vazia: " << f.vazia() << endl;
    }
    catch( const exception &e)
    {
        cerr << "EXCECAO: "<< e.what() << '\n';
    }
    
 }
 
 