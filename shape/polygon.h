#pragma once
#include "shape.h"
#include <vector>


class Polygon: public Shape{
    vector<Point> points;
public:
    Polygon();
    void addPoint(const Point& p);
    double calc_area();
    double calc_perimetr();
    void name();
};