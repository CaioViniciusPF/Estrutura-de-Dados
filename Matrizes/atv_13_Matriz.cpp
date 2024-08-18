#include <iostream>
#include <exception>
using namespace std;

class Matriz
{
    int num_lin;
    int num_col;
    double **M;
 
public:
    Matriz(int linhas , int colunas)
    {
        num_lin = linhas;
        num_col = colunas;
        M = new double* [linhas];
         for (int l = 0; l < linhas; ++l)
         {
            M[l] = new double [colunas];
         }
    }


    ~Matriz()
    {
        for (int l = 0; l < num_lin; ++l)
        {
           delete M[l];
        }
        delete[] M;
    }
    double& operator() (int l , int c){ return M[l][c]; }
};
int  main()
{
    try
    {
        int l; cout << "#linhas: "; cin >> l;
        int c; cout << "#colunas: "; cin >> c;
        Matriz M (l,c);
        int i = 0;
        int j = 0;
        double valor = 3.14;
        M(i,j) = valor;
        cout << "M[" << i << "][" << j << "]: "<< M(i,j)<< '\n';
        for ( i = 0; i < l; ++i)
        {
            cout << '[';
            for ( j = 0; j < c; ++j){cout << ' ' << M(i,j); }
            cout << " ]\n";
        }
        
    }
    catch(const exception &e)
    {
        cerr << "EXECEÇAO" << e.what() << '\n';
        return 1;
    }
    
}
