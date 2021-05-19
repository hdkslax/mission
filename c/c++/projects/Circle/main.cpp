#include <iostream>
#include "Circle.h"
#include "Point.h"
using namespace std;

int main(){
    
    Point center;
    center.setX(10);
    center.setY(0);
    Circle c1;  
    c1.setCenter(center);
    c1.setR(10);

    Point p;
    p.setX(10);
    p.setY(9);

    c1.isInCircle(p);

    Point p1;
    Point p2(10,10);
    Point p3(p2);

    Point p4 = Point(10,20);
    Point p5 = Point(p4);
    Point p6 = p5;

    return 0;
}