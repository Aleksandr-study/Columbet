#include <iostream> 
#include <ctime>

using namespace std;

int main(void)
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	int a;
	int i, j;
	int kIteration = 0;
	cout << "Введите размерность матрицы:";
	cin >> a;
	int** array = new int* [a];
	for (int i = 0; i < a; i++)
	{
		array[i] = new int[a];
		kIteration++;
	}

	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < a; j++)
		{
			array[i][j] = rand() % 100;
			cout << array[i][j];
			cout << " ";
			kIteration++;
		}
		cout << endl;
		kIteration++;
	}
	int** array2 = new int* [a];
	for (int i = 0; i < a; i++)
	{
		array2[i] = new int[a];
		kIteration++;
	}
	cout << endl;
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < a; j++)
		{
			array2[i][j] = array[i][j-1];
			array2[i][0] = array[i][a - 1];
			cout << array2[i][j];
			cout << " ";
			kIteration++;
		}
		cout << endl;
		kIteration++;
	}
	delete[] array;
	delete[] array2;
	cout << "Время работы программы: = " << clock() / 1000.0 << " секунды" << endl;;
	cout << "Количество итераций: " << kIteration;
	return 0;
}
