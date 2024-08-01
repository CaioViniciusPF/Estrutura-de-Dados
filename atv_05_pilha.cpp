#include <iostream>
using namespace std;
struct Pilha
{
    static constexpr int tam_v = 5;
    char v[tam_v];
    int cont = 0;
};
bool vazia(Pilha &P){
    return (P.cont == 0);
}
bool empilhar(Pilha &P, char c){
    if (P.cont == P.tam_v - 1) {
        cout << "Pilha cheia";
        return false;
    } 
    P.v[P.cont]=c;
    P.cont++;
    cout<<"Empilhado";
    return true;
}
bool desempilhar(Pilha &P) {
    if (P.cont == 0) {
        cout << "Inviável, vazia";
        return false;
    } else {
        P.cont--;
        cout << "Desempilhado";
        return true;
    }
}
bool consultar_t(Pilha &P){
    
    if(vazia(P)){ 
        cout<<"Inviável, vazia"; 
        return false;
        }
    cout<<"Topo da pilha é: "<<P.v[P.cont-1]; return true;
}
int main(){
    Pilha P;
    for(;;){
        cout<<"\nOpção: Enpilhar ; Desempilhar ; Topo ; Sair.";
        char op;
        cin>>op;
        switch (op)
        {
        case 'E':
            cout<<"\nElemento a ser empilhado: ";
            char element;
            cin>> element;
            empilhar(P,element);
            break;
        case 'D':
            desempilhar(P);
            break;
        case 'T':
            cout<<P.cont;
            consultar_t(P);
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