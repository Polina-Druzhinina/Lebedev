#include "hiperbola.h"

Hiperbola::Hiperbola(double x,  double a, double left, double right): Function(x, left, right), a(a){};

void Hiperbola::name(){
    cout<<"Hiperbola"<<endl;
}

double Hiperbola::valueFunction(){
    return a/x;
}

double Hiperbola::searcheMin(){
    double y1 = a/left;
    double y2 = a/right;
    return (y1<y2)?y1: y2;
}

double Hiperbola::searcheMax(){
    double y1 = a/left;
    double y2 = a/right;
    return (y1>y2)?y1:y2;
}

double Hiperbola::integration(){
    return a * log(abs(right/left));
}

double Hiperbola::differentiation(){
    return -a/(x*x);
}