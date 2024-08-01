#include <iostream>
using namespace std;
struct Conjunto
{ 
    static constexpr int tam_v=5;
    char v[tam_v];
    int n = 0;
};
void mostrar(Conjunto &C) {
    cout << "Elementos do vetor: "<< C.n;
    for (int i = 0; i < C.n; i++) {
        cout << C.v[i] << " ";
    }
    cout << endl;
};
bool pertence(Conjunto &C, char c){
    for (int i = 0; i < C.n; i++)
    {
        if (C.v[i] == c){ return true;
        }else {            return false;}
    }
};
bool inserir(Conjunto &C,char c){
    if(C.n==C.tam_v){ 
        cout << "Conjunto cheio." << endl; 
        return false;
    }else{

    C.v[C.n]=c;
    ++C.n;
    return true;
    }
};
bool inserir_se_novo(Conjunto &C,char c){
    if (!pertence(C,c))
    {
        return inserir(C,c);
    }else{
        cout<< c <<"Ja Pertence ao vetor.";
        return false; }
};
bool remove(Conjunto &C,char c){
    //se o elemento a ser returado for o ultimo
    if(C.v[C.n-1] == c){
        C.n--; 
        return true;
    }

    for (int i = 0; i < C.n; i++)
    {
        if (C.v[i] == c) {
            
            C.v[i]=C.v[C.n-1];
            C.n--;
            return true;
        }else{             
            cout<< c <<" Elemento nao existe";
            return false; 
        }
    }
    
};
int main(){
    Conjunto C;
    for(;;){
        cout<<"\nOpcao: Inserir ; Remover ; Mostrar ; Sair.\n";
        char op;
        cin>>op;
        switch (op)
        {
        case 'I':
            cout<<"\nElemento a ser inserido: ";
            char element;
            cin>> element;
            inserir_se_novo(C ,element);
            break;
        case 'R':
            cout<<"\nElemento a ser retirado: ";
            char c;
            cin>> c;
            remove(C ,c);
            break;
        case 'M':
            mostrar(C);
            break;
        case 'S':
            cout<<"Saindo";
            return 0;
            break;
        default:
            cout<<"Opção invalida";
            break;
        }
    }
}
