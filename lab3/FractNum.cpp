#ifndef __FRACTNUM_CPP__
#define __FRACTNUM_CPP__

#include "FractNum.h"

namespace dMath{
    // Конструктор с установкой значений числителя и знаменателя
    FractNum::FractNum(bool sign, int whole, int num, int den){
        this->sign = sign;
        this->whole = whole;
        this->num = num;
        this->den = den; // Знаменатель не должен быть равен нулю
    }

    FractNum::FractNum(const FractNum& ref_FractNum)
    {
        // копирование данных из одного объекта в другой
        this->num = ref_FractNum.num;
        this->den = ref_FractNum.den;
        this->whole = ref_FractNum.whole;
        this->sign = ref_FractNum.sign;
    }

    // Методы GET
    // Получить значение числителя
    int FractNum::getNum(){
        return num;
    }

    // Получить значение знаменателя
    int FractNum::getDen(){
        return den;
    }

    // Получить значение целой части
    int FractNum::getWhole(){
        return whole;
    }

    // Получить значение знака числа
    bool FractNum::getSign(){
        return sign;
    }

    string FractNum::getDecision(){
        return decision;
    }

    string FractNum::getFtos(){
        string res = "";
        if (sign)
            res += "-";
        if ((whole == 0) && (num == 0))
            res += to_string(whole);
        if (whole != 0){
            res += to_string(whole)+ " ";
        }
        if (num != 0){
            res += to_string(abs(num)) + "/" + to_string(den);
        }
        return res;
    }

    // Методы SET
    // Установить значение числителя
    void FractNum::setNum(int num){
        this->num = num;
    }

    // Установить значение знаменателя
    void FractNum::setDen(int den){
        this->den = den;
    }

    // Установить значение целой части
    void FractNum::setWhole(int whole){
        this->whole = whole;
    }

    // Установить значение знака числа
    void FractNum::setSign(bool sign){
        this->sign = sign;
    }

    // Упрощение дроби
    void FractNum::simplify(){
        this->addDecision(this->getFtos());
        if (this->getNum() < 0){
            this->setSign(true);
            this->setNum(-this->getNum());
        }
        if (this->getWhole() < 0){
            this->setSign(true);
            this->setWhole(-this->getWhole());
        }
        int n = this->getNum(), d = this->getDen();
        int val = nod(n, d);
        this->setNum(n/val);
        this->setDen(d/val);
        if ((abs(this->getNum()) >= this->getDen())||(val !=1)){
            this->setWhole(this->getNum() / this->getDen());
            this->setNum(this->getNum() - this->getWhole() * this->getDen());
            this->addDecision(" = ");
            this->addDecision(this->getFtos());
        }else
            this->setWhole(0);
        
    }

    // Приведение дроби в неправильный вид
    void FractNum::toWrong(){
        this->setNum(this->getNum()+this->getWhole()*this->getDen());
        this->setWhole(0);
    }

    // Добавление шага решения в общую строку
    void FractNum::addDecision(string decision){
        this->decision += decision;
    }

    // Сложение дробей
    FractNum FractNum::operator+(FractNum n){
        FractNum res(*this);
        res.toWrong();
        n.toWrong();
        int m;
        if (res.getDen() != n.getDen()){
            
            int common = nok(res.getDen(), n.getDen());
            if (res.getDen() != common){
                m = common / res.getDen();
                if (res.sign)
                    res.addDecision("-");
                res.addDecision(to_string(res.getNum()) + "*" + to_string(m) + "/" + to_string(res.getDen()) + "*" + to_string(m));
                res.setNum(res.getNum() * common / res.getDen());
                res.setDen(common);
            }else
                res.addDecision(res.getFtos());

            if (!n.getSign())
                res.addDecision(" + ");
            if (n.getDen() != common){
                m = common / n.getDen();
                if (n.sign)
                    res.addDecision(" - ");
                res.addDecision(to_string(n.getNum()) + "*" + to_string(m) + "/" + to_string(n.getDen()) + "*" + to_string(m) + " = ");
                n.setNum(n.getNum() * common / n.getDen());
                n.setDen(common);
            }else
                res.addDecision(n.getFtos() + " = ");
            res.setDen(common);
        }
        res.addDecision(res.getFtos());
        if (!n.getSign()){
            res.addDecision(" + ");
            res.addDecision(n.getFtos());
        }
        else{
            res.addDecision(" - ");
            n.setSign(false);
            res.addDecision(n.getFtos());
            n.setSign(true);
        }
        res.addDecision(" = ");

        if (res.getSign())
            res.setNum(-res.getNum());
        if (n.getSign())
            n.setNum(-n.getNum());
        res.setNum(res.getNum() + n.getNum());
        res.simplify();
        return res;
    }

    // Вычитание дробей
    FractNum FractNum::operator-(FractNum n){
        FractNum res(*this);
        n.setSign(!n.getSign());
        res = res + n;
        return res;
    }

    // Умножение дробей
    FractNum FractNum::operator*(FractNum n){
        FractNum res(*this);
        res.toWrong();
        n.toWrong();
        if (res.getSign() != n.getSign()){
            res.setSign(true);
            res.addDecision(" - ");
        }
        res.addDecision(to_string(res.getNum()) + "*" + to_string(n.getNum()) + "/" + to_string(res.getDen()) + "*" + to_string(n.getDen()) + " = ");
        res.setNum(res.getNum() * n.getNum());
        res.setDen(res.getDen() * n.getDen());
        res.simplify();
        return res;
    }

    // Деление дробей
    FractNum FractNum::operator/(FractNum n){
        FractNum res(*this);
        res.toWrong();
        n.toWrong();
        int temp = n.getNum();
        n.setNum(n.getDen());
        n.setDen(temp);
        res.addDecision(res.getFtos());
        res.addDecision(" * ");
        res.addDecision(n.getFtos());
        res.addDecision(" = ");
        res = res * n;
        return res;
    }
}

#endif