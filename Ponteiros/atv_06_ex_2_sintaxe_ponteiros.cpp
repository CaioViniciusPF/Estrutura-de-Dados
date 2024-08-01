#include <iostream>
using namespace std;
int remover_ocorrencias (double *v, int n, double x)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {

         if (*(v + i) != x) {
            *(v + count) = *(v + i);
            count++;
        }
    }
    return count;
    
}
int main()
{
    int n;
    cout << "Digite um inteiro positivo (max 10): ";
    cin >> n;   

    double vetor[n]; 
    cout << "Digite " << n << " numeros double:" << endl;
    for (int i = 0; i < n; ++i) 
    {
        cin >> vetor[i];
    }

    double x;
    cout << "Digite o valor a ser removido: ";
    cin >> x;

    int numero_restantes = remover_ocorrencias(vetor,n,x);

    cout << "Vetor resultante: ";
    for (int i = 0; i < numero_restantes; ++i) {
        cout << vetor[i] << " ";
    }
    cout << endl;
    
    cout << "Quantidade de numeros restantes: " << numero_restantes << endl;
    
    return 0;
}