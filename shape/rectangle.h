#pragma once
#include "shape.h"

class Rectangle: public Shape{
    Point a,b,c,d;
public:
    Rectangle(int x1, int x2,int x3, int x4, int y1, int y2, int y3, int y4);
    Rectangle(float x1, float x2,float x3, float x4, float y1, float y2, float y3, float y4);
    Rectangle(double x1, double x2, double x3,double x4, double y1, double y2, double y3, double y4);
    Rectangle(const Point& a, const Point& b,const Point& c,const Point& d);
    double calc_area();
    double calc_perimetr() ;
    void name();
};

