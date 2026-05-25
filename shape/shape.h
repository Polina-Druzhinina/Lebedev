#pragma once
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

struct Point{
    double x, y;
};

class Shape{
public:
    virtual ~Shape() = default;
    virtual double calc_perimetr() = 0;
    virtual double calc_area() = 0;
    virtual void name() = 0;
};
