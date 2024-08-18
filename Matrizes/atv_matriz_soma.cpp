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

    Matriz somar(const Matriz &B)
    {
        Matriz resultado(num_lin, num_col);

        for (int i = 0; i < num_lin; ++i)
        {
            for (int j = 0; j < num_col; ++j)
            {
                resultado(i, j) = M[i][j] + B.M[i][j];
            }
        }

        return resultado;
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
    int getLinhas() const { return num_lin; }
    int getColunas() const { return num_col; }
};
int  main()
{
    try
    {
        int l1; cout << "#linhas da primeira matriz: "; cin >> l1;
        int c1; cout << "#colunas da primeira matriz: "; cin >> c1;
        Matriz M1 (l1,c1);


        int l2; cout << "#linhas da segunda matriz: "; cin >> l2;
        int c2; cout << "#colunas da segunda matriz: "; cin >> c2;
        Matriz M2 (l2,c2);

        
        if (l1 != l2 || c1 != c2)
        {
            cout << "Para efetuar a somar as matrizes precisam ter o mesmo tamanho!";
            return 1;
        }
        


    cout << "Insira os elementos da Matriz 1:\n";
        for (int i = 0; i < l1; ++i)
        {
            for (int j = 0; j < c1; ++j)
            {
                cout << "Elemento [" << i << "][" << j << "]: ";
                cin >> M1(i, j);
            }
        }

        cout << "Insira os elementos da Matriz 2:\n";
        for (int i = 0; i < l2; ++i)
        {
            for (int j = 0; j < c2; ++j)
            {
                cout << "Elemento [" << i << "][" << j << "]: ";
                cin >> M2(i, j);
            }
        }


         // cout << "M[" << i << "][" << j << "]: "<< M1(i,j)<< '\n';
        cout << "Matriz 1:" << '\n';
        for (int i = 0; i < l1; ++i)
        {
            cout << '[';
            for (int j = 0; j < c1; ++j){cout << ' ' << M1(i,j); }
            cout << " ]\n";
        }


        // cout << "M[" << i << "][" << j << "]: "<< M2(i,j)<< '\n';
        cout << "Matriz 2:" << '\n';
        for (int i = 0; i < l2; ++i)
        {
            cout << '[';
            for (int j = 0; j < c2; ++j){cout << ' ' << M2(i,j); }
            cout << " ]\n";
        }

        Matriz M_resultado = M1.somar(M2);

        cout << "Matriz Resultado:" << '\n';
        for (int i = 0; i < M_resultado.getLinhas(); ++i)
        {
            cout << '[';
            for (int j = 0; j < M_resultado.getColunas(); ++j){cout << ' ' << M_resultado(i,j); }
            cout << " ]\n";
        }


        
    }
    catch(const exception &e)
    {
        cerr << "EXECEÇAO" << e.what() << '\n';
        return 1;
    }
    
}
