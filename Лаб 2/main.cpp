#include <iostream> 
#include <ctime>
#include <cstdlib>
#include <time.h>

using namespace std;

int recursion(int size_a, int* b, int* Iteration2, int c2, int i);

int main(void)
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));
    int size_a;
    int c = 0;
    int Iteration = 0;
    int Iteration2 = 0;
    cout << "Введiть кiлькiсть елементiв масива:";
    cin >> size_a;
    int* a = new int[size_a];
    int* b = new int[size_a];
    for (int i = 0; i < size_a; i++)
    {
        a[i] = rand() % 150 - 50;
        b[i] = a[i];
    }

    cout << "\nБез рекурсiї:\n";
    clock_t t2;
    t2 = clock();
    for (int i = 0; i < size_a; i++)
    {
        cout << a[i] << " ";
        if (a[i] < 0)
        {
            c--;
        }
        else if (a[i] > 0)
        {
            c++;
        }
        Iteration++; 
    }
    cout << endl;
    if (c > 0)
    {
        cout << "Додатнiх елементiв бiльше нiж вiд'ємних.\n";
    }
    else if (c < 0)
    {
        cout << "Вiд'ємних елементiв бiльше нiж додатнiх.\n";
    }
    else
    {
        cout << "Кiлькiсть вiд'ємних i додатнiх елементiв однакова.\n";
    }
    t2 = clock() - t2;
    cout << "\nЧас роботи програми: = " << ((float)t2) / CLOCKS_PER_SEC << " секунди" << endl;
    cout << "Кiлькiсть iтерацiй: " << Iteration << endl;

    clock_t t;
    t = clock();
    int c2 = 0;
    int c3;
    int iterator = 0;
    c3 = recursion(size_a, b, &Iteration2, c2, iterator);
    cout << "\nЗ рекурсiєю:\n";
    for (int i = 0; i < size_a; i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;
    if (c3 > 0)
    {
        cout << "Додатнiх елементiв бiльше нiж вiд'ємних.\n";
    }
    else if (c3 < 0)
    {
        cout << "Вiд'ємних елементiв бiльше нiж додатнiх.\n";
    }
    else
    {
        cout << "Кiлькiсть вiд'ємних i додатнiх елементiв однакова.\n";
    }
    t = clock() - t;
    cout << "\nЧас роботи програми: = " << ((float)t) / CLOCKS_PER_SEC << " секунди\n";
    cout << "Кiлькiсть iтерацiй: " << Iteration2 << endl;
    delete[] a;
    delete[] b;
    return 0;
}

int recursion(int size_a, int* b, int* Iteration2, int c2, int i)
{
    if (i < size_a)
    {

        if (b[i] > 0)
        {
            c2++;
        }
        else if (b[i] < 0)
        {
            c2--;
        }
        *(Iteration2) += 1;
        recursion(size_a, b, Iteration2, c2, i + 1);
    }
    return c2;
}