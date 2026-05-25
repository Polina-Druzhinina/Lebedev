#include "triangle.h"

Triangle::Triangle(int x1, int x2,int x3, int y1, int y2, int y3){
    a.x = x1;
    a.y = y1;
    b.x = x2;
    b.y = y2;
    c.x = x3;
    c.y = y3;
}
Triangle::Triangle(float x1, float x2,float x3, float y1, float y2, float y3){
    a.x = x1;
    a.y = y1;
    b.x = x2;
    b.y = y2;
    c.x = x3;
    c.y = y3;
}
Triangle::Triangle(double x1, double x2, double x3, double y1, double y2, double y3){
    a.x = x1;
    a.y = y1;
    b.x = x2;
    b.y = y2;
    c.x = x3;
    c.y = y3;
}

Triangle::Triangle(const Point& a, const Point& b,const Point& c){
    this->a = a;
    this->b = b;
    this->c = c;
}

double Triangle::calc_area() {
    return 0.5 * abs(a.x * (b.y - c.y) +b.x * (c.y - a.y) +c.x * (a.y - b.y));
}

double Triangle::calc_perimetr() {
    double ab = sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
    double bc = sqrt(pow(c.x - b.x, 2) + pow(c.y - b.y, 2));
    double ca = sqrt(pow(a.x - c.x, 2) + pow(a.y - c.y, 2));
    return ab + bc + ca;
}

void Triangle::name(){
    cout<<"Triangle"<<endl;
}




