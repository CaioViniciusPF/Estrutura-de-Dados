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
    int i=0, f=C.n-1;
    while (i<=f)
    {
        int m = i+(f-i)/2;
        if(c == C.v[m]) return true;
        if(c<C.v[m]) f=m-1;
        else         i=m+1;
    }
    return false;
};
bool inserir(Conjunto &C,char c){
    if (C.n == C.tam_v) {
        cout << "Conjunto cheio." << endl;
        return false;
    }

    if (pertence(C, c)) {
        cout << c << " já pertence ao conjunto." << endl;
        return false;
    }
    int inicio = 0;
    int fim = C.n - 1;
    int posicaoInsercao = 0;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (C.v[meio] < c) {
            inicio = meio + 1;
            posicaoInsercao = inicio; 
        } else {
            fim = meio - 1;
            posicaoInsercao = meio; 
        }
    }

    for (int i = C.n; i > posicaoInsercao; i--) {
        C.v[i] = C.v[i - 1];
    }

    
    C.v[posicaoInsercao] = c;
    C.n++; 
    return true;
};

bool remove(Conjunto &C,char c){
   if (!pertence(C, c)) {
        cout << c << " Nao pertence ao conjunto." << endl;
        return false;
    }
    
    int posicaoRemocao = -1;
    int i=0, f=C.n-1;
    while (i<=f)
    {
        int m = i+(f-i)/2;
        if(c == C.v[m]) {
            posicaoRemocao = m; 
            break;
            }
        if(c<C.v[m]) f=m-1;
        else         i=m+1;
    }
    cout<<posicaoRemocao;
    for (int i = posicaoRemocao; i < C.n-1; i++) {
        C.v[i] = C.v[i + 1];
    }
    
    C.n--; 
    return true;
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
            inserir(C ,element);
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
