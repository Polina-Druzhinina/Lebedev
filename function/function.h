#pragma once
#include <iostream>
#include <cmath>
using namespace std;
class Function{
protected:
    double x, right,left;
public:
    virtual ~Function() = default;
    Function(double x, double left, double right) : x(x),left(left),right(right) {};
    virtual void name() = 0;
    virtual double valueFunction() = 0;
    virtual double searcheMin() = 0;
    virtual double searcheMax() = 0;
    virtual double integration() = 0;
    virtual double differentiation() = 0;
};