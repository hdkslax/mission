#pragma once //防止头文件重复包含
#include <iostream>
using namespace std;

class Point{
    public:
    Point();
    ~Point();
    Point(double x, double y);
    Point(const Point &p);
    double getX();
    double getY();

    void setX(double x);
    void setY(double y);
    
    private:
    double x, y;
};