#include "ellipse.h"

Ellipse::Ellipse(int cx, int cy, int r1, int r2){
    center.x = cx;
    center.y = cy;
    this->r1 = r1;
    this->r2 = r2;
}

Ellipse::Ellipse(float cx, float cy, float r1, float r2){
    center.x = cx;
    center.y = cy;
    this->r1 = r1;
    this->r2 = r2;
}

Ellipse::Ellipse(double cx, double cy, double r1, double r2){
    center.x = cx;
    center.y = cy;
    this->r1 = r1;
    this->r2 = r2;
}

Ellipse::Ellipse(const Point& p, int r1, int r2){
    center = p;
    this->r1 = r1;
    this->r2 = r2;
}

Ellipse::Ellipse(const Point& p, float r1, float r2){
    center = p;
    this->r1 = r1;
    this->r2 = r2;
}

Ellipse::Ellipse(const Point& p, double r1, double r2){
    center = p;
    this->r1 = r1;
    this->r2 = r2;
}

double Ellipse::calc_area(){
    return M_PI * r1 * r2;
}

double Ellipse::calc_perimetr(){
    double h = pow(r1 - r2, 2) / pow(r1 + r2, 2);
    return M_PI * (r1 + r2) * (1 + (3*h)/(10 + sqrt(4 - 3*h)));
}

void Ellipse::name(){
    cout<<"Ellipse"<<endl;
}
