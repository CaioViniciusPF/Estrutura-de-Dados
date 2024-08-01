#include <iostream>
using namespace std;

// Função para inverter a ordem dos elementos do vetor
void inverter(double *p, int n) {
    cout <<"Valores de *p antes do laco: "<< *p <<"\n";
    for (int i = 0; i < n / 2; ++i) {

        double temp = *(p + i);         // double temp = p[i];
        *(p + i) = *(p + n - 1 - i);    // p[i] =p[n-1-i];
        *(p + n - 1 - i) = temp;        // p[n-1-i]=temp;
    }
}

int main() {
    int n;
    
    // Lendo o valor de n
    do {
        cout << "Digite um inteiro positivo (max 10): ";
        cin >> n;
    } while (n <= 0 || n > 10);
    
    double vetor[10];
    
    // Lendo os elementos do vetor
    cout << "Digite " << n << " numeros double:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> vetor[i];
    }
    
    // Invertendo a ordem dos elementos do vetor
    inverter(vetor, n);
    
    // Imprimindo os elementos invertidos
    cout << "Elementos na ordem invertida:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << vetor[i] << " ";
    }
    cout << endl;
    
    return 0;
}