#include "point.h"

// 无参构造函数
Point::Point(){
    x = 0;
    y = 0;
    cout << "Point的无参构造函数" << endl;
}

// 有参构造函数
Point::Point(double x, double y){
    this->x = x;
    this->y = y;
    cout << "Point的有参构造函数" << endl;
}

// 拷贝构造函数
Point::Point(const Point &p){
    this->x = p.x;
    this->y = p.y;
    cout << "Point的拷贝构造函数" << endl;
}

Point::~Point(){}


double Point::getX(){return x;}
double Point::getY(){return y;}

void Point::setX(double x){this->x = x;}
void Point::setY(double y){this->y = y;}
    
