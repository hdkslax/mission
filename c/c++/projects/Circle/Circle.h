#pragma once
#include <iostream>
#include "Point.h"

using namespace std;

class Circle{
    public:
    Circle();
    Circle(Point center, double r);
    Circle(const Circle &c);
    double getR();
    Point getCenter();

    void setR(double r);
    void setCenter(Point center);

    double getZC();
    void isInCircle(Point p);
    
    private:
    Point center;
    double r;
};