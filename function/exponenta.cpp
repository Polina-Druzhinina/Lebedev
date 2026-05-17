#include "exponenta.h"

Exponenta::Exponenta(double x,  double a, double left, double right): Function(x, left, right), a(a){};

void Exponenta::name(){
    cout<<"Exponenta"<<endl;
}

double Exponenta::valueFunction(){
    return a*exp(x);
}

double Exponenta::searcheMin(){
    double y1 = a * exp(left);
    double y2 = a * exp(right);
    return (y1<y2)?y1: y2;
}

double Exponenta::searcheMax(){
    double y1 = a * exp(left);
    double y2 = a * exp(right);
    return (y1>y2)?y1:y2;
}

double Exponenta::integration(){
    return a * (exp(right) - exp(left));
}

double Exponenta::differentiation(){
    return  a * exp(x);
}
