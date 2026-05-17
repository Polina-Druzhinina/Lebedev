#include "parabola.h"

Parabola::Parabola(double x, double a, double b, double c, double left, double right): Function(x, left, right), a(a), b(b), c(c) {};

void Parabola::name(){
    cout<<"Parabola"<<endl;
}

double Parabola::valueFunction(){
    return a*x*x + b*x + c;
}

double Parabola::searcheMin(){
    double y1 = a*left*left + b * left + c;
    double y2 = a*right*right + b*right + c;
    double min = (y1 < y2)? y1 : y2;
    double x_v = -b / (2*a);
    if(x_v >= left && x_v <= right){
        double yv = a*x_v * x_v + b*x_v + c;
        min = (min < yv)? min:yv;
    }
    return min;
}

double Parabola::searcheMax(){
    double y1 = a*left*left + b * left + c;
    double y2 = a*right*right + b*right + c;
    double max = (y1 > y2)? y1 : y2;
    double x_v = -b / (2*a);
    if(x_v >= left && x_v <= right){
        double yv = a*x_v * x_v + b*x_v + c;
        max = (max > yv)? max:yv;
    }
    return max;
}

double Parabola::integration(){
    double fRight = a*right*right*right / 3.0 + b*right*right / 2.0 + c*right;
    double fLeft = a*left*left*left / 3.0 + b*left*left / 2.0 + c*left;
    return fRight - fLeft;
}

double Parabola::differentiation(){
    return 2*a*x + b;
}

