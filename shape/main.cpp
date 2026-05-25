#include "shape.h"
#include "classifyShapes.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"
#include "ellipse.h"
#include "polygon.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main(){
    vector<Shape*> figure;
    figure.push_back(new Circle(0, 0, 5));
    figure.push_back(new Triangle(0, 3, 0, 0, 0, 4));
    figure.push_back(new Rectangle(0, 4, 4, 0, 0, 0, 3, 3));
    int n;
    ifstream file;
    file.open("polygon_coor.txt");
    if(!file.is_open()){
        cout<<"File does not open"<<endl;
        return -1;
    }
    file>>n;
    if(n < 4){
        cout<<"Uncorrect count vershin"<<endl;
        return -1;
    }
    Polygon* p = new Polygon();
    for(int i = 0; i < n; i++){
        Point point;
        if(!(file>>point.x>>point.y)){
            cout<<"Uncorrect coor"<<endl;
            return -1;
        }
        p->addPoint(point);
    }
    file.close();
    figure.push_back(p);

    for(Shape* i: figure){
        i->name();
        cout<<"Perimetr: "<<i->calc_perimetr()<<endl;
        cout<<"Area: "<<i->calc_area()<<endl;
        cout<<endl;
    }
    for(Shape* i: figure){
        delete i;
    }

    classifyShapes detector;
    if (!detector.loadGridFromFile("input2.dat")) {
        return 1;
    }
    ShapeCounts result = detector.countShapes();
    cout << "Rectangle = " << result.rectangles << endl;
    cout << "Circle = "    << result.circles    << endl;
    cout << "Triangle = "  << result.triangles  << endl;
    cout << "Noise = "     << result.noise      << endl;
    /* without vector
    //Circle
    Shape* c = new Circle(0, 0, 5);
    c->name();
    cout << "Area: " << c->calc_area() << endl;
    cout << "Perimeter: " << c->calc_perimetr() << endl;
    
    cout<<endl;

    //Triangle
    Shape* t = new Triangle(0, 3, 0, 0, 0, 4);
    t->name();
    cout << "Area: " << t->calc_area() << endl;
    cout << "Perimeter: " << t->calc_perimetr() << endl;

    cout<<endl;

    //Rectangle
    Shape* r = new Rectangle(0, 4, 4, 0, 0, 0, 3, 3);
    r->name();
    cout << "Area: " << r->calc_area() << endl;
    cout << "Perimeter: " << r->calc_perimetr() << endl;
    cout<<endl;
    //Ellipse
    Shape* e = new Ellipse(0, 0, 5, 3);
    e->name();
    cout << "Area: " << e->calc_area() << endl;
    cout << "Perimeter: " << e->calc_perimetr() << endl;

    cout<<endl;

    //Polygon
    int n;
    ifstream file;
    file.open("polygon_coor.txt");
    if(!file.is_open()){
        cout<<"File does not open"<<endl;
        return -1;
    }
    file>>n;
    if(n < 4){
        cout<<"Uncorrect count vershin"<<endl;
        return -1;
    }
    Shape* p = new Polygon();
    for(int i = 0; i < n; i++){
        Point point;
        if(!(file>>point.x>>point.y)){
            cout<<"Uncorrect coor"<<endl;
            return -1;
        }
        ((Polygon*)p)->addPoint(point);
    }
    file.close();
    p->name();
    cout<<"Perimeter: "<<p->calc_perimetr()<<endl;
    cout<<"Area: "<<p->calc_area()<<endl;
    */
    return 0;
}


