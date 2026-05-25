#pragma once
#include "shape.h"

class Circle: public Shape{
    Point center;
    double r;
public:
    Circle(int cx, int cy, int r);
    Circle(float cx, float cy, float r);
    Circle(double cx, double cy, double r);
    Circle(const Point& p, int r);
    Circle(const Point& p, float r);
    Circle(const Point& p, double r);

    double calc_area();
    double calc_perimetr() ;
    void name();
};