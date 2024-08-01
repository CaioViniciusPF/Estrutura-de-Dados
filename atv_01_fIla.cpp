#include <iostream>
using namespace std;

struct Fila {
    static constexpr int tam_v=5;
    char v[tam_v];
    int u;
    int p = -1;
};
bool vazia(Fila &F){
    return(F.p==-1);
}
bool cheia(Fila &F){
    if (vazia(F)) return false;
    return (F.u +1) % F.tam_v == F.p;
}
bool enfilar(Fila &F, char c ){
    if(cheia(F))return false;
    if(vazia(F)){
      F.p = F.u = 0;  
    }else
    {
        if ( F.u== F.tam_v - 1) F.u=0;
        else                    ++F.u;
    }
    F.v[F.u]=c;
    return true;
}
bool desenfilar(Fila &F){
    if(vazia(F))return false;

    if ( F.u == F.p) F.p= -1;
    else             F.p=(F.p + 1) % F.tam_v;
    return true;
}
char primeiro (Fila &F){
    return F.v[F.p];
}
int main(){
    Fila F;
    for (;;)
    {
        cout<<"Opção: Enfilar ; Desenfilar ; Primeiro ; Sair.";
        char op;
        cin>>op;
        switch (op)
        {
        case 'E':
            cout<<"Elemento a ser inserido";
            char elemento;
            cin>> elemento;
            if(enfilar(F,elemento)) cout<<"Elemento inserido.\n";
            else                    cout<<"Fila cheia.\n";
        break;
        case 'D':
            if(vazia(F)) cout<<"Inviavel, vazia";
            else{
            cout<<"Elemento a ser Desenfilado"
                << primeiro(F)
                <<'\n';
                desenfilar(F);
            }

        break;
        case 'P':
            if(vazia(F)) cout<<"Inviavel, vazia";
            else{
            cout<<"Primeiro: "
                << primeiro(F)
                <<'\n';
                
            }
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
