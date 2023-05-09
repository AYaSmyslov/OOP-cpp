#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <ctime>
#include <algorithm>
using namespace std;

class Man
{
public:
    string name;
    int age;
    int point;

    Man(int age, string name)
    {
        this->age = age; // указатель на свои данные
        this->name = name;
        point = 50;
    }

    /* Man()
     {
        cin >> this->name >> this->age;
        point = 50;
     }
    */
    virtual void doing(Man *x)
    {
        cout << "Я ничего не делаю \n";
    }

    void say()
    {
        cout << "My name is " << name << endl;
    }
};

class GRM : public Man
{
public:
    GRM(int age, string name) : Man(age, name)
    {
        point = 30;
    }
    void doing(Man *x)
    {
        cout << "Я готовлю пирожки для " << x->name << endl;
        point -= 10;
        x->point += 20;
    }
};

class DOC : public Man
{
public:
    DOC(int age, string name) : Man(age, name)
    {
        point = 100;
    }
    void doing(Man *x)
    {
        cout << "Я лечу " << x->name << endl;
        point -= 20;
        x->point += 30;
    }
};

class MUS : public Man
{
public:
    MUS(int age, string name) : Man(age, name)
    {
        point = 80;
    }
    void doing(Man *x)
    {
        cout << "Я играю на скрипке для " << x->name << endl;
        point -= 20;
        x->point += 10;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    vector<Man *> mass;

    mass.push_back(new GRM(80, "Alla"));
    mass.push_back(new DOC(40, "Ivan"));
    mass.push_back(new MUS(25, "Igor"));
    srand(time(NULL));
    int j;
    while (mass.size() > 1)
    {
        for (int i = 0; i < mass.size(); i++)
        {
            j = rand() % mass.size();
            if (i != j)
            {
                mass.at(i)->doing(mass.at(j));
                if (mass.at(j)->point <= 0)
                {
                    mass.erase(mass.begin() + j);
                }
                cout << "SIZE:\t" << mass.size() << endl;
            }
        }
    }
}