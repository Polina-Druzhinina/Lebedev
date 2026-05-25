#include "rational.h"
#include <iostream>
using namespace std;

Rational findRoot(Rational a, Rational b, Rational discr){
    return (-b + discr) / (Rational(2)*a);
}

int main(){
    Rational a(1),b(-3532,13923),c(209,13923);
    Rational d = b*b - (Rational(4)*a*c);
    if (d < Rational(0)){
        cout<<"There are no roots"<<endl;
        return -1;
    }
    else if(d == Rational(0)){
        Rational x = findRoot(a, b, 0);
        cout << "Root: " << x<<endl;
    }
    else{
        Rational pow = d.sqrt();
        Rational x1 = findRoot(a, b, pow);
        Rational x2 = findRoot(a, b, -pow);
        cout << "Roots: " << x1 << " and " << x2 << endl;
    }

    /*
    Rational a(1, 2);   
    Rational b(-1, 6);  

    cout << "a = " << a << ", b = " << b << endl;

    //Сложение и вычитание
    Rational sum = a + b;
    Rational diff = a - b;
    cout << "a + b = " << sum << endl;   
    cout << "a - b = " << diff << endl;  

    //Умножения и деление
    Rational prod = a * b;
    Rational quot = a / b;
    cout << "a * b = " << prod << endl;  
    cout << "a / b = " << quot << endl;  

    //Инкремент и декремент
    Rational c = a; 
    cout << "c = " << c << endl;
    cout << "++c = " << ++c << endl;    
    cout << "c++ = " << c++ << endl;    
    cout << "c = " << c << endl;

    cout << "--c = " << --c << endl;    
    cout << "c-- = " << c-- << endl;    
    cout << "c = " << c << endl;

    //Сравнения
    cout << "a > b: " << (a > b) << endl;   
    cout << "a < b: " << (a < b) << endl;   
    cout << "a == b: " << (a == b) << endl;
    cout << "a != b: " << (a != b) << endl; 

    // Преобразование в int и double
    cout << "a as int: " << int(a) << endl;   
    cout << "a as double: " << double(a) << endl; 

    */

    
    return 0;
}