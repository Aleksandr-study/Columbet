#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <conio.h>
#include <time.h>
#include <ctime>

using namespace std;

int main(void)
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));
    int* arr = new int [100];
    ifstream fin;
    fin.open("C://Col.txt");
    if ((fin.is_open()) && (fin.peek() != EOF))
    {
        while (!fin.eof())
        {

            for (int n = 0; n < 100; n++)
            {
           
                fin >> arr[n];
            }
        }
        fin.close();
    }
    int** matr = new int* [10];
    int** matr2 = new int* [10];
    for (int i = 0; i < 10; i++)
    {
        matr[i] = new int[10];
        matr2[i] = new int[10];
    }
    cout << "ѕочаткова матриц¤:" << endl;
    for (size_t i = 0, k = 0; i < 10; ++i)
    {
        for (size_t j = 0; j < 10; ++j)
        {
            matr[i][j] = arr[k++];
            cout << matr[i][j] << " ";
        }
        cout << endl;
    }
    for (size_t i = 0, k = 0; i < 10; ++i)
    {
        for (size_t j = 0; j < 10; ++j)
        {
            matr2[i][j] = arr[k++];
        }
    }
    clock_t t;
    t = clock();
    int temp;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int r = 0; r < 4 - j; r++)
            {
                if (matr[i][r] > matr[i][r + 1])
                {
                    temp = matr[i][r];
                    matr[i][r] = matr[i][r + 1];
                    matr[i][r + 1] = temp;
                }
            }
        }
    }
    for (int i = 5; i < 10; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int r = 5; r < 9 - j; r++)
            {
                if (matr[i][r] > matr[i][r + 1])
                {
                    temp = matr[i][r];
                    matr[i][r] = matr[i][r + 1];
                    matr[i][r + 1] = temp;
                }
            }
        }
    }
    cout << endl << "¬iдсортована матриц¤ (метод бульбашки):" << endl;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << matr[i][j] << " ";
        }
        cout << endl;
    }
    t = clock() - t;
    cout << "\n„ас роботи програми: = " << ((float)t) / CLOCKS_PER_SEC << " секунди\n";
    clock_t t2;
    t2 = clock();
    int rab, x;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            rab = matr2[i][j];
            x = j;
            while (x > 0 && rab < matr2[i][x - 1])
            {
                matr2[i][x] = matr2[i][x - 1];
                x--;
            }
            matr2[i][x] = rab;
        }
    }
    for (int i = 5; i < 10; i++)
    {
        for (int j = 6; j < 10; j++)
        {
            rab = matr2[i][j];
            x = j;
            while (x > 5 && rab < matr2[i][x - 1])
            {
                matr2[i][x] = matr2[i][x - 1];
                x--;
            }
            matr2[i][x] = rab;
        }
    }
    cout <<endl << "¬iдсортована матриц¤ (метод вставки):" << endl;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << matr2[i][j] << " ";
        }
        cout << endl;
    }
    t2 = clock() - t2;
    cout << "\n„ас роботи програми: = " << ((float)t2) / CLOCKS_PER_SEC << " секунди" << endl;
    return 0;
}
