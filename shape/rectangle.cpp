#include "rectangle.h"

Rectangle::Rectangle(int x1, int x2,int x3, int x4, int y1, int y2, int y3, int y4){
    a.x = x1;
    a.y = y1;
    b.x = x2;
    b.y = y2;
    c.x = x3;
    c.y = y3;
    d.x = x4;
    d.y = y4;
}
Rectangle::Rectangle(float x1, float x2,float x3, float x4, float y1, float y2, float y3, float y4){
    a.x = x1;
    a.y = y1;
    b.x = x2;
    b.y = y2;
    c.x = x3;
    c.y = y3;
    d.x = x4;
    d.y = y4;
}
Rectangle::Rectangle(double x1, double x2, double x3,double x4, double y1, double y2, double y3, double y4){
    a.x = x1;
    a.y = y1;
    b.x = x2;
    b.y = y2;
    c.x = x3;
    c.y = y3;
    d.x = x4;
    d.y = y4;
}

Rectangle::Rectangle(const Point& a, const Point& b,const Point& c,const Point& d){
    this->a = a;
    this->b = b;
    this->c = c;
    this->d = d;
}

double Rectangle::calc_area() {
    double ab = sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
    double bc = sqrt(pow(c.x - b.x, 2) + pow(c.y - b.y, 2));

    return ab * bc;
}

double Rectangle::calc_perimetr() {
    double ab = sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
    double bc = sqrt(pow(c.x - b.x, 2) + pow(c.y - b.y, 2));
    double cd = sqrt(pow(d.x - c.x, 2) + pow(d.y - c.y, 2));
    double da = sqrt(pow(a.x - d.x, 2) + pow(a.y - d.y, 2));

    return ab + bc + cd + da;
}


void Rectangle::name(){
    cout<<"Rectangle"<<endl;
}
