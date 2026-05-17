#include "function.h"

class Hiperbola: public Function{
    double a;
public:
    Hiperbola(double x, double a, double left, double right);
    void name();
    double valueFunction();
    double searcheMin();
    double searcheMax();
    double integration();
    double differentiation();
};