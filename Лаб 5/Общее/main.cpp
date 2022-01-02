#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <iostream> 
#include <ctime>
#include <cstdlib>
#include <time.h>
#include  <conio.h>
#include <string>
#include <fstream>
#include <clocale>

using namespace std;

struct list
{
    int data; /*переменна¤, хран¤ща¤ значение элемента*/
    list* next; /*ссылку на следующий элемент*/
};


/*ƒќЅј¬Ћ≈Ќ»≈ ЁЋ≈ћ≈Ќ“ј ¬ —ѕ»—ќ */
void func1(list*& begin, int num)
{
    if (begin == nullptr)
    {
        begin = new list();
        begin->data = num;
        begin->next = nullptr;
    }
    else
    {
        list* ptr = begin;
        while (ptr->next)
        {
            ptr = ptr->next;
        }
            list* next = ptr->next;
            list* new_elem = new list();
            new_elem->data = num;
            ptr->next = new_elem;
            new_elem->next = next;   
    }
}

/*ѕќ ј«џ¬ј≈“ —ѕ»—ќ  Ќј Ё –јЌ≈*/
void list_print(list* begin) {
    if (begin == nullptr) {
        cout << "ќшибка! —писок пуст!" << endl;
        exit(1);
    }
    list* n = begin;
    while (n) {
        cout << n->data << " -> ";
        n = n->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    list* begin = nullptr;
    int size;
    int key;
    cout << "¬ведите размер списка: ";
    cin >> size;
    int* a = new int[size];
    int max = 0;
    cout << "ћассив:" << endl;
    for (int i = 0; i < size; i++)
    {
        a[i] = rand() % 10 - 0;
        if (max < *(a + i))
        {
            max = *(a + i);
        }
        cout << a[i] << " ";
    }
    cout << "\n¬ведите елемент-ключ: ";
    cin >> key;
    
    bool l = true;
    for (int i = 0; i < size ; i++) 
    {
        if (key < a[i -1] && l)
        {
            func1(begin, max);
            l = false;
        }
        func1(begin, a[i]);
    }
    cout  << "»змененный массив" << endl;
    list_print(begin);
    return 0;
}