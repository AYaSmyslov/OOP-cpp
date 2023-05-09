#ifndef __FRACTNUM_H__
#define __FRACTNUM_H__

#pragma once

#include <iostream>
using namespace std;

namespace dMath{
    class FractNum{
        public:     
            FractNum(bool sign=false, int whole=0, int num=0, int den=1); // Конструктор по умолчанию
            FractNum(const FractNum& ref_FractNum); // Конструктор копирования

            // Методы GET
            int getNum(); // Возврат числителя
            int getDen(); // Возврат знаменателя
            int getWhole(); // Возврат целой части
            bool getSign(); // Возврат знака 
            string getDecision();
            string getFtos();

            // Методы SET
            void setNum(int num); // Присвоить числитель
            void setDen(int den); // Присвоить знаменатель
            void setWhole(int whole); // Присвоить целую часть
            void setSign(bool sign); // Присвоить знак

            // Перегрузка арифметических операторов
            FractNum operator+(FractNum n);
            FractNum operator-(FractNum n);
            FractNum operator*(FractNum n);
            FractNum operator/(FractNum n);
            
        private:
            int num = 0; // Числитель
            int den = 1; // Знаменатель
            int whole = 0; // Целая часть
            bool sign = false; // Знак
            string decision = ""; // Строка с подробным решением

            void addDecision(string decision); // Добавление шага решения

            void simplify(); // Упрощение дроби
            void toWrong(); // Приведение дроби в неправильный вид
        
    };

    int* drop(int num); // Разделение чисел на множители
    int nod(int a, int b); // Вычисление НОД
    int nok(int n1, int n2, int max=0); // Вычисление НОК
    FractNum parseToFractNum(string str, int& i); // Парсинг дроби из строки начиная с i-го символа
}
#endif