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
{ // структура списка
    int data; /*переменная, хранящая значение элемента*/
    list* next; /*ссылку на следующий элемент*/
};
void func(list*& begin, int num)
{
    list* ptr = begin;
    while (ptr != nullptr)
    {
        ptr = ptr->next;
    }
    list* new_elem = new list();
    new_elem->data = num;

}

/*ДОБАВЛЕНИЕ ЭЛЕМЕНТА В СПИСОК*/
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



void list_print(list* begin) {
    if (begin == nullptr) {
        cout << "Ошибка! Список пуст!" << endl;
        exit(1);
    }
    list* n = begin;
    if (n->data != 0)
    {
        while (n) {
            cout << n->data << " -> ";
            n = n->next;
        }
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
    cout << "Введите размер списка: ";
    cin >> size;
    cout << "Массив:" << endl;
    int* a = new int[size];   
    int num;
    for (int i = 0; i < size; i++)
    {
        a[i] = rand() % 10 - 0;
        num = a[i];
        cout << num << " ";
    }
    
    cout << "\nВведите елемент-ключ: ";
    cin >> key;
    bool l = true;
    int sp = 0;
    for (int i = 0; i < size; i++)
    {
        num = a[i];
        if (key == num && l)
        {
            func(begin, a[i+1]);
            l = false;
            sp = 1000;
        }
        else if (sp == 1001)
        {
            func1(begin, a[i + 1]);
            sp = 2000;
        }
        else if (sp == 2001)
        {
            func1(begin, a[i - 1]);
        }
        else
        {
            func1(begin, num);
        }
        sp++;
    }
    cout << endl << "Измененный массив" << endl;
    list_print(begin);
    return 0;
}