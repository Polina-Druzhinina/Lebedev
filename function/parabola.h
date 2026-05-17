#pragma once
#include "function.h"

class Parabola: public Function{
private:
    double a,b,c;
public:
    Parabola(double x, double a, double b, double c, double left, double right);
    void name();
    double valueFunction();
    double searcheMin();
    double searcheMax();
    double integration();
    double differentiation();
};