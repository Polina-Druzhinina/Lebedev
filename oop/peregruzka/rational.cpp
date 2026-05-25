#include "rational.h"
#include <cmath>
#include <iostream>
#include <limits>
#include <stdexcept>
using namespace std;

//Rational:: - означает что функция принадлежит классу Rational 
Rational::Rational(){
    numer = 0;
    denom = 1;
}

Rational::Rational(int number){
    numer = number;
    denom = 1;
}

Rational::Rational(int n, int d){
    numer = n;
    denom = d;
    simplify();
}

Rational::Rational(long long n, long long d){
    numer = n;
    denom = d;
    simplify();
}

/*
Rational::Rational(double x){
    int sign = (x < 0)? -1:1;
    x = (x < 0)? -x:x;
    double m = x;
    int e = 0;

    while(m >= 2){
        m/=2;
        e++;
    }
    while (m < 1){
        m*=2;
        e--;
    }
    long long denom_ll= 1LL << 52;
    long long numer_ll = m*denom_ll;
    if(e>0){
        numer_ll <<=e;
    } 
    else{
        denom_ll <<= -e;
    }
    numer = sign*numer_ll;
    denom = denom_ll; 
    simplify();
}
*/
//оператор добавления
//Rational& - возвращает ссылку на объект Rational (то есть возвращаем тот же самый объект у которого вызван метод)
//operator += == a.operator+=(b)
//Rational& не копируем объект, а передаем ссылку на него
Rational& Rational:: operator += (const Rational& r){
    numer = (numer*r.denom + denom*r.numer);
    denom = denom * r.denom;
    simplify();
    //this - указатель на самого себя
    //*this - ссылка на себя
    return *this;
}

void Rational::simplify(){
    if(denom == 0)
        throw invalid_argument("Denominator must not be zero");

    if(denom < 0){
        numer = -numer;
        denom = -denom;
    }
    long long a = (numer > 0)? numer:-numer;
    long long b = (denom > 0)? denom:-denom;
    while(b != 0){
        long long temp = b;
        b = a % b;
        a = temp;
    }
    if(a != 0){
        numer /= a;
        denom /= a;
    }
}

long long fullSqrt(long long x){
    if(x < 0)
        return -1;

    long long left = 0;
    long long right = x;
    while(left <= right){
        long long mid = left + (right - left) / 2;
        if(mid != 0 && mid > x / mid){
            right = mid - 1;
        }
        else{
            long long square = mid * mid;
            if(square == x)
                return mid;
            left = mid + 1;
        }
    }
    return -1;
}

double sqrtApprox(double x){
    double left = 0;
    double right = x;
    if (x < 1)
        right = 1;
    for(int i = 0; i < 100; i++){
        double  mid = (left + right)/2;
        if(mid*mid > x)
            right = mid;
        else
            left = mid;
    }
    return (left + right) / 2;
}

//Возвращает новый объект Rational по значению, тк + не должен менять исходные объекты
//const в конце - метод не меняет текущий объект (*this)
//создаем новый объект res как копию объекта (*this) 
// Rational a(1,2);Rational b(3,4);Rational c = a + b; *this -> a, создается res с такими же полями что у a
Rational Rational::operator +(const Rational& r) const{  
    Rational res(*this);
    return res += r;
}

Rational Rational::operator -() const{
    Rational r(-numer, denom);
    return r;
}

Rational& Rational::operator-=(const Rational& r){
    return (*this += (-r));
}

Rational Rational::operator -(const Rational& r) const{
    Rational res(*this);
    return res -= r;
}

Rational& Rational::operator *=(const Rational& r){
    numer = (numer*r.numer);
    denom = (denom*r.denom);
    simplify();
    return *this;
}

Rational Rational::operator *(const Rational& r) const{
    Rational res(*this);
    return res*= r;
}

Rational& Rational::operator /=(const Rational& r){
    numer = numer*r.denom;
    denom = denom*r.numer;
    simplify();
    return *this;

}

Rational Rational::operator /(const Rational& r) const{
    Rational res(*this);
    return res/=r;
}

Rational& Rational::operator++(){
    numer += denom;
    return *this;
}

Rational Rational::operator++(int){
    Rational r(*this);
    numer += denom;
    return r;
}

Rational& Rational::operator--(){
    numer -= denom;
    return *this;
}

Rational Rational::operator--(int){
    Rational r(*this);
    numer -= denom;
    return r;
}

bool Rational::operator ==(const Rational& r) const{
    return (numer==r.numer) && (denom==r.denom);
}

bool Rational::operator != (const Rational& r) const{
    return !(*this==r);
} 

bool Rational::operator >(const Rational& r) const{
    return numer*r.denom > r.numer*denom;
}

bool Rational::operator >=(const Rational& r) const{
    return numer*r.denom >= r.numer*denom;
}

bool Rational::operator <(const Rational& r) const{
    return numer*r.denom < r.numer*denom;
}

bool Rational::operator <=(const Rational& r) const{
    return numer*r.denom <= r.numer*denom;
}

Rational::operator int() const{
    return numer/denom;
}

Rational::operator double() const{
    return((double)numer)/denom;
}

Rational Rational::sqrt() const{
    if(denom == 0)
        throw invalid_argument("Denominator must not be zero");
    if(numer < 0)
        throw invalid_argument("Square root of a negative rational number");

    long long n = fullSqrt(numer);
    long long d = fullSqrt(denom);
    if(n != -1 && d != -1)
        return Rational(n,d);

    double value = (double)numer/denom;
    double root = sqrtApprox(value);

    int precision = 100000;
    while(precision > 1 && root > numeric_limits<long long>::max() / precision){
        precision /= 10;
    }

    if(root > numeric_limits<long long>::max() / precision)
        throw overflow_error("Square root is too large for Rational");

    return Rational((long long)(root * precision), (long long)precision);
}

istream& operator >>(istream& in, Rational& r){
    in>>r.numer>>r.denom;
    return in;
}
ostream& operator <<(ostream& out, const Rational& r){
    out<<r.numer<<"/"<<r.denom;
    return out;
}

