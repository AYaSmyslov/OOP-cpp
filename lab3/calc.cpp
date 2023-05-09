#include <iostream>
#include <string>
#include <regex>
#include "FractNum.h"

using namespace std;
using namespace dMath;

int main()
{   
    FractNum n[2], res; // Дроби
    int i; // Итератор строки (дробного выражения)
    char op; // Символ арифметического оператора
    bool f_syntax; // Флаг совпадения строки с регулярным выражением
    regex r(R"(^(-?\d+(\s\d+)?)\/(\d+)(\+|-|\*|:)(-?\d+(\s\d+)?)\/(\d+)$)"); // Формат ввода дробного выражения
    string s; // Дробное выражение

    do{
        i = 0;
        cout << "Input expression: ";
        getline(cin, s); // Ввод дробного выражения
        f_syntax = regex_search(s, r); // Сравнение с регулярным выражением
        if (f_syntax){
            n[0] = parseToFractNum(s, i); // Парсинг первого оператора
            op = s[i]; // Присвоение арифметического оператора из строки
            i++;
            n[1] = parseToFractNum(s, i); // Парсинг второго оператора
            
            cout << n[0].getFtos() << ' ' << op << ' ' << n[1].getFtos(); // Форматированный вывод дробного выражение
            if (n[0].getDen() == 0 || n[1].getDen() == 0) // Проверка на ноль в знаменателе
                cout << " - Denominator must not be ZERO. Try Again" << endl;
        }
            else cout << "Incorrect syntax. Try Again" << endl;
    }while(n[0].getDen() == 0 || n[1].getDen() == 0 || !f_syntax); // Повтор ввода при некорректном выражении
    
    cout << " = ";

    switch(op){ // Выполнение арифметического действия
        case '+': res = n[0] + n[1]; break;
        case '-': res = n[0] - n[1]; break;
        case '*': res = n[0] * n[1]; break;
        case ':': res = n[0] / n[1]; break;
    }
    cout << res.getDecision(); // Вывод подробного решения
    return 0;
}
