#pragma once
#include <iostream>
using namespace std;

class Rational{
private:
    void simplify();

public:
    long long numer;
    long long denom;
    Rational(); //конструктор по умолчанию, чтобы не хранить мусорный значения
    Rational(int number); //объявление конструктора с одним параметром
    Rational(int n, int d); //объявление конструктора с 2 параметрами
    Rational(long long n, long long d);
    //Rational(double x);
    Rational& operator += (const Rational& r); //оператор добавления
    Rational operator +(const Rational& r) const; //оператор сложения
    Rational operator-() const; //оператор отрицания (унарный минус)
    Rational& operator -=(const Rational& r); //оператор уменьшения
    Rational operator -(const Rational& r) const; //оператор вычитания
    Rational& operator *=(const Rational& r);
    Rational operator *(const Rational& r) const;
    Rational& operator /=(const Rational& r);
    Rational operator /(const Rational& r) const;

    Rational& operator ++(); //префикс инкремент
    Rational operator ++(int); //постфикс инкремент
    Rational& operator --(); 
    Rational operator --(int);

    bool operator ==(const Rational& r) const;
    bool operator !=(const Rational& r) const;
    bool operator >(const Rational& r) const;
    bool operator >=(const Rational& r) const;
    bool operator <(const Rational& r) const;
    bool operator <=(const Rational& r) const;
    operator int() const;
    operator double() const;

    friend istream& operator >>(istream& in, Rational& r);
    friend ostream& operator <<(ostream& out, const Rational& r);

    Rational  sqrt() const;
};
