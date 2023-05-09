#include <iostream>
using namespace std;

class Node
{
public:
    int x;
    Node *next;
    Node(int x)
    {
        this->x = x;
        next = NULL;
    }
};

void addElem(Node *f, Node *n)
{
    if (f->next == NULL)
        f->next = n;
    else
        addElem(f->next, n);
}

void print(Node *f)
{
    cout << f->x << '\t';
    if (f->next != NULL)
        print(f->next);

    cout << endl;
}

void DellAll(Node *f)
{
    if (f->next != NULL)
        print(f->next);
    delete f;
}

int count(Node *f)
{
    if (f->next != NULL)
        return 1 + count(f->next);
    else
        return 1;
}

Node *DellElem(Node *f, int x)
{
    if (f->x != x)
    {
        Node *copy = f;
        while (copy->next != NULL && copy->next->x != x)
            copy = copy->next;
        if (copy->next != NULL)
        {
            Node *c = copy->next;
            copy->next = copy->next->next;
            delete c;
        }
        else
            cout << "Такого элемента нет\n";
    }
    else
    {
        Node *copy = f;
        f = f->next;
        delete copy;
    }
    return f;
}

Node *swap(Node *f, int i)
{
    if (f == NULL)
    {
        cout << "Список пуст\n";
        return NULL;
    }
    if (count(f) < i + 2)
    {
        cout << "Элементов в списке меньше, чем " << i + 2 << "\n";
        return f;
    }
    Node *cur = f;
    Node *prev = NULL;
    for (int j = 0; j < i; j++)
    {
        prev = cur;
        cur = cur->next;
    }
    Node *next = cur->next;
    cur->next = next->next;
    next->next = cur;
    if (prev == NULL)
    {
        f = next;
    }
    else
    {
        prev->next = next;
    }
    return f;
}

int menu()
{
    cout << "1. Добавление элемента в список\n";
    cout << "2. Подсчет количества элементов списка\n";
    cout << "3. Вывод на экран содержимого списка\n";
    cout << "4. Удаление элемента\n";
    cout << "5. Уничтожение списка с освобождением памяти\n";
    cout << "6. Индивидуальное задание\n";
    cout << "0. Exit\n";
    int a;
    cin >> a;
    return a;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    Node *first = NULL;
    int x;
    while (true)
    {
        if (first != NULL)
            print(first);
        else
            cout << "Список пуст\n";
        switch (menu())
        {
        case 0:
            return 0;
            break;
        case 1:
            cout << "Введите число, которое хотите добавить в список" << endl;
            cout << "[int value]: ";
            cin >> x;
            if (first == NULL)
                first = new Node(x);
            else
                addElem(first, new Node(x));
            break;
        case 2:
            if (first != NULL)
                cout << "count = " << count(first) << endl;
            else
                cout << "Список пуст\n";
            system("pause");
            break;
        case 3:
            if (first != NULL)
                print(first);
            else
                cout << "Список пуст\n";
            break;
        case 4:
            if (first != NULL)
            {
                cin >> x;
                first = DellElem(first, x);
            }
            else
                cout << "Список пуст\n";
            break;
        case 5:
            if (first != NULL)
            {
                DellAll(first);
                first = NULL;
            }
            break;

        case 6:

            if (first != NULL)
            {
                cout << "Введите номер (i) элемента, который хотите поменять с i+1 элементом" << endl;
                cout << "[index]: ";
                cin >> x;
                first = swap(first, x);
            }
            break;
        }
        system("cls");
    }
}