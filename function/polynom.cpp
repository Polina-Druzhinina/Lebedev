#include "polynom.h"

Polynom::Polynom(double x, vector<double> coef, double left, double right): Function(x, left, right), a(coef){};
double Polynom:: eval(double xVal) { //метод горнера
    double res = 0.0;

    for (double coef: a) {
        res = res * xVal + coef;
    }

    return res;
}
void Polynom::name(){
    cout<<"Polynom"<<endl;
}

double Polynom::valueFunction(){
    return eval(x);
}

double Polynom::searcheMin() {
    double step = 0.001;
    double mini = eval(left);
    for (double xVal = left; xVal <= right; xVal += step) {
        double y = eval(xVal);
        if (y < mini) mini = y;
    }

    return mini;
}

double Polynom::searcheMax() {
    double step = 0.001;
    double maxi = eval(left);
    for (double xVal = left; xVal <= right; xVal += step) {
        double y = eval(xVal);
        if (y > maxi) maxi = y;
    }
    return maxi;
}

double Polynom::integration(){
    double fRight = 0.0;
    double fLeft = 0.0;
    int n = a.size() - 1;
    for (int i = 0; i < a.size(); i++) {
        int power = n - i + 1;
        fRight += a[i] * pow(right, power) / power;
        fLeft  += a[i] * pow(left, power) / power;
    }
    return fRight - fLeft;
}

double Polynom::differentiation(){
    double res = 0.0;
    int n = a.size() - 1;
    for (int i = 0; i < a.size() - 1; i++) {
        res += (n - i) * a[i] * pow(x, n - i - 1);
    }
    return res;
}

