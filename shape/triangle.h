#include "shape.h"
#include <cmath>

class Triangle: public Shape{
    Point a,b,c;
public:
    Triangle(int x1, int x2,int x3, int y1, int y2, int y3);
    Triangle(float x1, float x2,float x3, float y1, float y2, float y3);
    Triangle(double x1, double x2, double x3, double y1, double y2, double y3);
    Triangle(const Point& a, const Point& b,const Point& c);
    double calc_area();
    double calc_perimetr() ;
    void name();
};

