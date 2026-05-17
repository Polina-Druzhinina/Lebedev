#include "function.h"

class Exponenta: public Function{
    double a;
public:
    Exponenta(double x, double a, double left, double right);
    void name();
    double valueFunction();
    double searcheMin();
    double searcheMax();
    double integration();
    double differentiation();
};