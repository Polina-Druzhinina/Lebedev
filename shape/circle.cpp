#include "circle.h"

Circle::Circle(int cx, int cy, int r){
    center.x = cx;
    center.y = cy;
    this->r = r;
}
Circle::Circle(float cx, float cy, float r){
    center.x = cx;
    center.y = cy;
    this->r = r;
}
Circle::Circle(double cx, double cy, double r){
    center.x = cx;
    center.y = cy;
    this->r = r;
}
Circle::Circle(const Point& p, int r){
    center = p;
    this->r = r;
}
Circle::Circle(const Point& p, float r){
    center = p;
    this->r = r;
}
Circle::Circle(const Point& p, double r){
    center = p;
    this->r = r;
}

double Circle::calc_area(){
    return M_PI * r * r;
}

double Circle::calc_perimetr(){
    return 2. * M_PI * r;
}

void Circle::name(){
    cout<<"Circle"<<endl;
}
