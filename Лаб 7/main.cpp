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
    int N = 10, K, M, a = 0;
    int* ai = new int[N];
    ifstream in;
    in.open("C://input.txt");
    if ((in.is_open()) && (in.peek() != EOF))
    {
        while (!in.eof())
        {
            in >> N;
            for (int i = 0; i < N; i++)
            {
                in >> ai[i];
            }
            in >> K;
        }
        in.close();
    }
    cout << "INPUT:\n" << N << endl;
    for (int i = 0; i < N; i++)
    {
        cout << ai[i] << " ";
    }
    cout << endl << K << endl << endl;
    for (int i = 1; i <= N; i++)
    {
        M = K / ai[N - i];
        cout << "Потрiбно купюр номiналом " << ai[N - i] << ": " << M << endl;
        K = K - M * ai[N - i];
        a += M;
    }
    cout << "\nOUTPUT\n";
    if (K != 0)
    {
        cout << "-1" << endl;
        ofstream out;
        out.open("C://output.txt");
        if (out.is_open())
        {
            out << "-1";
        }
        out.close();
    }
    else
    {
        cout << a << endl;
        ofstream out;
        out.open("C://output.txt");
        if (out.is_open())
        {
            out << a;
        }
        out.close();
    }
    system("pause");
    return 0;
}