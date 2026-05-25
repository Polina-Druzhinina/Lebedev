#include "polygon.h"

Polygon::Polygon(){}

void Polygon::addPoint(const Point& p){
    points.push_back(p);
}

double Polygon::calc_perimetr(){
    double per = 0.;
    for(int i = 0; i < points.size(); i++){
        int j = (i + 1) % points.size();
        double res = sqrt(pow(points[j].x - points[i].x, 2) + pow(points[j].y - points[i].y, 2));
        per += res;
    }
    return per;
}

double Polygon::calc_area(){
    double s = 0.5;
    double sum = 0.;
    for(int i = 0; i < points.size(); i++){
        int j = (i + 1) % points.size();
        sum += (points[i].x*points[j].y - points[j].x*points[i].y);
    }
    return s*abs(sum);
}

void Polygon::name(){
    cout<<"Polygon"<<endl;
}
