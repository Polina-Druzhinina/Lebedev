#pragma once
#include "shape.h"

class Ellipse: public Shape{
    Point center;
    double r1, r2;
public:
    Ellipse(int cx, int cy, int r1, int r2);
    Ellipse(float cx, float cy, float r1, float r2);
    Ellipse(double cx, double cy, double r1, double r2);
    Ellipse(const Point& p, int r1, int r2);
    Ellipse(const Point& p, float r1, float r2);
    Ellipse(const Point& p, double r1, double r2);

    double calc_area();
    double calc_perimetr() ;
    void name();
};