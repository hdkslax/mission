#include "Circle.h"

using namespace std;

const double PI = 3.14;

Circle::Circle(){
    Point center(0,0);
    this->center = center;
    this->r = 0;
}
Circle::Circle(Point center, double r){
    this->center = center;
    this->r = r;
}
Circle::Circle(const Circle &c){
    this->center = c.center;
    this->r = c.r;
}

double Circle::getR(){return r;}
Point Circle::getCenter(){return center;}

void Circle::setR(double r){this->r = r;}
void Circle::setCenter(Point center){this->center = center;}

double Circle::getZC(){return 2*PI*r;}
void Circle::isInCircle(Point p){
    double distance = (p.getX()-center.getX())*(p.getX()-center.getX()) + 
                      (p.getY()-center.getY()) * (p.getY()-center.getY());
    double rDistance = r*r;

    if(distance<rDistance) cout << "In the circle" << endl;
    else if(distance == rDistance) cout << "On the circle" << endl;
    else cout << "Out of the circle" << endl;
}
