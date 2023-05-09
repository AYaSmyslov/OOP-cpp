#ifndef __PARSEFRACTIONS__
#define __PARSEFRACTIONS__

#include "FractNum.h"

namespace dMath{
    
    // Парсинг числа из строки до встречи иного символа или конца строки
    int findNum(string str, int& i){
        string res = "";
        while(('0' <= str[i] && str[i] <= '9') && (str[i] != '\0')){
            res += str[i];
            i++;
        }
        //cout << res << endl;
        return stoi(res);
    }

    // Парсинг дроби из строки
    FractNum parseToFractNum(string str, int& i){
        FractNum res;
        int val;
        if (str[i] == '-'){
            res.setSign(true);
            i++;
        }
        val = findNum(str, i);
        if (str[i] == ' '){
            res.setWhole(val);
            i++;
            val = findNum(str, i);
        }
        else
            res.setWhole(0);
        if (str[i] == '/'){
            res.setNum(val);i++;
        }
        if (str[i] == '-'){
            res.setSign(true);
            i++;
        }
        res.setDen(findNum(str, i));
        return res;
    }
}

#endif