#include <iostream>
#include <time.h>

using namespace std;

class MyList {                                       //—писок MyList
    int x, count_;
    MyList* Head, * Tail, * Next, * Prev;
public:
    MyList() :count_(0), Head(NULL), Tail(NULL) {};     //»нициализаци¤ с помощью конструктора по умолчанию
    void Add(int);
    void Show();
    void Del(int);                                  //‘ункци¤ принимает целочисленный параметр, обозначающий номер удал¤емого элемента
    ~MyList();
};

/*ƒќЅј¬Ћ≈Ќ»≈ ЁЋ≈ћ≈Ќ“ј ¬ —ѕ»—ќ */
void MyList::Add(int x) {
    MyList* temp = new MyList;
    temp->x = x;
    temp->Next = NULL;
    count_++;
    if (!Head) {
        temp->Prev = NULL;
        Head = temp;
        Tail = Head;
    }
    else {
        temp->Prev = Tail;                  //предыдущим элементом списка относительно добавленного, будет последний элемент существующего списка
        Tail->Next = temp;                  //—ледующий за последним - непосредственно сейчас добавл¤емый элемент списка
        Tail = temp;                        //последний существующий это только что добавленный элемент
    }
}

/*ѕќ ј«џ¬ј≈“ —ѕ»—ќ  Ќј Ё –јЌ≈*/
void MyList::Show() {
    MyList* t = Head;
    while (t) {
        cout << t->x << " ";
        t = t->Next;
    }
    cout << "\n\n";
}


/*‘”Ќ ÷»я ”ƒјЋ≈Ќ»я  ќЌ –≈“Ќќ√ќ ЁЋ≈ћ≈Ќ“ј ƒ¬”—¬я«Ќќ√ќ —ѕ»— ј*/
void MyList::Del(int x) {
    //¬ списке есть только первый, в списке есть несколько элементов
    if ((x == 1) and (Head->Next)) {                     
        MyList* temp = Head;	                        //”казываем, что нам нужно начало списка
        Head = Head->Next;	                            //—двигаем начало на следующий за началом элемент
        Head->Prev = NULL;	                            //ƒелаем так, чтоб предыдущий началу элемент был пустым
        delete temp;		                            
        count_--;		                               
        return;		                                
    }
    else if ((x == 1) and (Head == Tail)) {            //≈сли удал¤ем первый, но в списке только 1 элемент

        Head->Next = NULL;	                            //обнул¤ем все что нужно
        Head = NULL;
        delete Head;		                            //”дал¤ем указатель на начало
        count_ = 0;		                                //ќб¤зательно обозначаем, что в списке ноль элементов
        return;			                                //и выходим из функции
    }

    //“акже может быть, что удал¤емый элемент ¤вл¤етс¤ последним элементом списка
    if (x == count_) {
        MyList* temp = Tail;	                            //”казываем, что нам нужен хвост
        Tail = Tail->Prev;	                                //ќтодвигаем хвост немного назад
        Tail->Next = NULL;	                                //ќбозначаем, что впереди за хвостом пусто
        delete temp;	                                    //ќчищаем пам¤ть от бывшего хвоста
        count_--;		                                    //ќб¤зательно уменьшаем счетчик элементов
        return;		                                    //» выходим из функции
    }

    //удал¤емый элемент лежит где-то в середине списка

    MyList* temp = Head, * temp2;                        //temp-”дал¤емый элемент, temp2 нужен, чтобы не потер¤ть данные

        //cout<<count_<<"\n";
    for (int i = 0; i < x - 1; i++) temp = temp->Next;  //»дем к адресу удал¤емого элемента

    temp2 = temp;	                                //¬ременно запоминаем адрес удал¤емого элемента
    temp2->Prev->Next = temp->Next;	            //следующий за перед сейчас удал¤емым элементом - это следующий от удал¤емого
    temp2->Next->Prev = temp->Prev;               //а предыдущий дл¤ следующего - это предыдущий дл¤ удал¤емого
    delete temp;                      
    count_--;                         
}


/*ƒ≈—“–” “ќ– ƒЋя  ќ––≈ “Ќќ√ќ ¬џ—¬ќЅќ∆ƒ≈Ќ»я ѕјћя“»*/
MyList::~MyList() {
    while (Head) {
        Tail = Head->Next;
        delete Head;
        Head = Tail;
    }
}


int main() 
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    MyList List1;
    int size;
    int key;
    cout << "¬ведите размер списка: ";
    cin >> size;
    int* a = new int[size];
    int num;
    cout << "ћассив:" << endl;
    for (int i = 0; i < size; i++)
    {
        a[i] = rand() % 10 - 0;
        num = a[i];
        cout << num << " ";
    }
    cout << "\n¬ведите елемент-ключ: ";
    cin >> key;
    
    bool l = true;
    for (int i = 0; i < size; i++)
    {
        if (key == a[i - 1] && l)
        {
            List1.Del(i);
            l = false;
        }

            List1.Add(a[i]);
    }
    cout << "»змененный массив" << endl;
    List1.Show();
    return 0;
}