#include "function.h"
#include "parabola.h"
#include "hiperbola.h"
#include "exponenta.h"
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<Function*> functions;
    functions.push_back(new Parabola(2.0,1.0,-3.0,2.0,-10.0,10.0));
    functions.push_back(new Hiperbola(2.0,4.0,1.0,10.0));
    functions.push_back(new Exponenta(0.0, 1.0, -2.0, 2.0));
    for(Function *i: functions){
        i->name();
        cout<<"Function value: "<<i->valueFunction()<<endl;
        cout<<"Maximum: "<<i->searcheMax()<<endl;
        cout<<"Minimum: "<<i->searcheMin()<<endl;
        cout<<"Integration: "<<i->integration()<<endl;
        cout<<"differentiation: "<<i->differentiation()<<endl;
        cout<<endl;
    }
    return 0;
}