#include <iostream>
using namespace std;

int main()
{
    int y = 1;
    setlocale(LC_ALL, "rus");
    int m = 8;
    int** A = new int* [m];
    for (int i = 0; i < m; i++)
    {
        A[i] = new int[m];
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (((i + j) % 4) == 0)
            {
            A[i][j] = y;
            y++;
            }
            else
            {
                A[i][j] = NULL;
            }

        }
    }
    cout << "Разряженая матрица:" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    int n = 0;
    int* a = new int [m*m];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            a[n] = A[i][j];
            n++;
        }
    }
    for (int i = 0; i < n; i++)
        if (a[i] == 0)
        {
            for (int j = i; j < n - 1; j++)
            {
                a[j] = a[j + 1];

            }
            i--;
            n--;
        }
    int** B = new int* [4];
    n = 0;
    for (int i = 0; i < 4; i++)
    {
        B[i] = new int[4];
    }
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            B[i][j] = a[n++];
        }
    }
    int x = 0; y = 0;
    cout << "Сжатая матрица:" << endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }
    int temp;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 2; j < 4; j++)
        {
            temp = B[i][j];
            B[i][j] = B[i+2][j-2];
            B[i + 2][j - 2] = temp;
        }
    }
    cout << "Сжатая матрица с выполненым заданием:" << endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }
    n = 0;
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            a[n++] = B[i][j];
        }
    }
    n = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (((i + j) % 4) == 0)
            {
                A[i][j] = a[n++];
                y++;
            }
            else
            {
                A[i][j] = NULL;
            }
        }
    }
    cout << "Разряженая матрица с выполненым заданием:" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}