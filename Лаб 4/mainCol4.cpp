#include <fstream>
#include "conio.h" 
#include "math.h" 
#include <cstdlib>
#include "iostream"
#include <ctime>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    int k;
    int Iteration = 0;
    int Iteration2 = 0;
    int Iteration3 = 0;
    int a[10][10];
    int b[100];
    ifstream fin;
    fin.open("C://Col.txt");
    if ((fin.is_open()) && (fin.peek() != EOF))
    {
        while (!fin.eof())
        {

            for (int n = 0; n < 10; n++)
            {
                for (int m = 0; m < 10; m++)
                {
                    fin >> a[n][m];
                }
            }
        }
        fin.close();
    }
    ifstream fin2;
    fin2.open("C://Col.txt");
    if ((fin2.is_open()) && (fin2.peek() != EOF))
    {
        while (!fin2.eof())
        {

            for (int n = 0; n < 100; n++)
            {
                fin2 >> b[n];    
            }
        }
        fin2.close();
    }
    for (int n = 0; n < 10; n++)
    {
        for (int m = 0; m < 10; m++)
        {
            cout << a[n][m] << " ";
        }
        cout << endl;
    }
    cout << "\nВведите k - ";
    cin >> k;
    int z = k;
    cout << "\nМетод поиска с барьером:\n";
    clock_t t;
    t = clock();
    for (int n = 0, m; n < 10; n++)
    {
        for (int m = 0; m < 10; m++)
        {
            if (a[n][m] == k)
            {
                cout << k << " - находится на позиции " << n + 1 << " " << m + 1 << endl; 
            }
            if (n == 9)
            {
                if (m == 9)
                {
                    a[n][m] = k;
                }
            }
            Iteration++;
        }
    }
    cout << "\nМатрица с заменой:\n";
    for (int n = 0; n < 10; n++)
    {
        for (int m = 0; m < 10; m++)
        {
            cout << a[n][m] << " ";
        }
        cout << endl;
    }
    t = clock() - t;
    cout << "\nВремя работи программы: " << ((float)t) / CLOCKS_PER_SEC << " секунды\n";
    cout << "Количество итераций: " << Iteration << endl;
    clock_t t2;
    t2 = clock();
    int temp;
    for (int i = 0; i < 99; i++) {
        for (int j = 0; j < 99 - i; j++) {
            if (b[j] > b[j + 1])
            {
                temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
                Iteration3++;
            }
        }
    }
    cout << "\nМетод бинарного поиска:\n";
    clock_t t3;
    t3 = clock();
    bool flag = false;
    int l = 0; 
    int r = 99;
    int mid;
    while ((l <= r) && (flag != true)) {
        mid = (l + r) / 2;
        if (b[mid] == k)
        {
            flag = true; //проверяем ключ со серединным элементом
        }
        if (b[mid] > k)
        {
            r = mid - 1;
        }
        else l = mid + 1;
        Iteration2++;
        Iteration3++;
    }
    if (flag) cout << "Индекс элемента " << k << " в массиве равен: " << mid;
    else cout << "В массиве нет такого числа!";
    t3 = clock() - t3;
    t2 = clock() - t2;
    cout << "\n\nВремя работи программы без сортировки: " << ((float)t3) / CLOCKS_PER_SEC << " секунды\n";
    cout << "Количество итераций без сортировки:" << Iteration2 << endl;
    cout << "\n\nВремя работи программы с сортировкой: " << ((float)t2) / CLOCKS_PER_SEC << " секунды\n";
    cout << "Количество итераций с сортировкой: " << Iteration3 << endl;
    system("pause");
    return 0;
}