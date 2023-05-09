#ifndef __NODNOK__
#define __NODNOK__

#include "FractNum.h"

namespace dMath{
    /* Функция разделения числа на множители
    Формальный параметр:
    num - натуральное число.
    Локальные параметры:
    mul - очередной множитель натурального числа;
    arr - указатель на массив множителей натурального числа.
    */
    int* drop(int num){
        int mul = 2;
        int *arr = new int[num];
        arr[0] = 0; // В нулевом элементе указывется количество множителей
        while (num > 1){
            while(num % mul == 0){
                arr[arr[0]+1] = mul;
                arr[0]++; 
                num= num / mul;
            }
            if (mul == 2)
                mul++;
            else
                mul+=2;
        }
        return arr;
    }

    /* Функция нахождения наибольшего общего делителя с помощью функции drop
    Формальные параметры:
    a - первое заданное число, для которого находится НОД;
    b - второе заданное число, для которого находится НОД;
    Локальные параметры:
    a_arr - указатель на массив множителей первого числа;
    b_arr - указатель на массив множителей второго числа;
    n - наибольший общий делитель;
    i - итератор массива a_arr;
    j - итератор массива b_arr;
    */
    int nod(int a, int b){
        int *a_arr = drop(a);
        int *b_arr = drop(b);
        int n = 1, i = 1, j = 1;
        while ((i <= a_arr[0]) && (j <= b_arr[0])){
            if (a_arr[i] == b_arr[j]){
                n *= a_arr[i];
                i++;
                j++;
            }else{
                if (a_arr[i] > b_arr[j])
                    j++;
                else
                    i++;
            }
        }

        delete[] a_arr; // Освобождение выделенной динамической памяти
        delete[] b_arr;
        return n;
    }
    
    // Наименьшее общее кратное
    int nok(int n1, int n2, int max)
    {
        string meaning;
        max = (n1 > n2) ? n1 : n2;
        do
        {
            if (max % n1 == 0 && max % n2 == 0)
            {
                meaning += std::to_string(max);
                break;
            }
            else ++max;
        } while (true);
        return stoi(meaning);
    }
}

#endif