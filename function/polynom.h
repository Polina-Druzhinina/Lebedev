#include "function.h"
#include <vector>
class Polynom: public Function{
private:
    vector<double> a;
    double eval(double xVal);
public:
    Polynom(double x, vector<double> coef, double left, double right);
    void name();
    double valueFunction();
    double searcheMin();
    double searcheMax();
    double integration();
    double differentiation();
};