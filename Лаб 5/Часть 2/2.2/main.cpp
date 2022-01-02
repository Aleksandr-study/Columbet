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
        Tail->Next = temp;                  //—ледующий за последним существующим это непосредственно сейчас добавл¤емый элемент списка
        Tail = temp;                        //что последний существующий это только что добавленный элемент
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


/*ƒ≈—“–” “ќ– ƒЋя  ќ––≈ “Ќќ√ќ ¬џ—¬ќЅќ∆ƒ≈Ќ»я ѕјћя“»*/
MyList::~MyList() {
    //   cout<<"\nDELETES\n";
    while (Head) {
        // cout<<"Del is: "<<Head->x<<"  ";
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
    int max = 0;
    int num;
    cout << "ћассив:" << endl;
    for (int i = 0; i < size; i++)
    {
        a[i] = rand() % 10 - 0;
        if (max < *(a + i))
        {
            max = *(a + i);
        }
        num = a[i];
        cout << num << " ";
    }
    cout << "\n¬ведите елемент-ключ: ";
    cin >> key;
    
    bool l = true;
    for (int i = 0; i < size; i++)
    {
        if (key < a[i - 1] && l)
        {

            List1.Add(max);
            l = false;
        }
        List1.Add(a[i]);
    }
    cout <<  "»змененный массив" << endl;
    List1.Show();
    return 0;
}