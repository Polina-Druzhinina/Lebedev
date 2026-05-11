#include "function.h"

class Hiperbola: public Function{
    double a;
public:
    Hiperbola(double x, double a, double left, double right);
    double valueFunction();
    double searcheMin();
    double searcheMax();
    string integration();
    double differentiation();
};