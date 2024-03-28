#include <cmath>
#include <iostream>
#include "Vector2D.h"
using namespace std;

#ifndef Point2D_h
#define Point2D_h


class Point2D{
  public:
    double x, y;
	Point2D();
	Point2D(double in_x, double in_y);
	friend ostream& operator<< (ostream& cons_out, Point2D p1);
};

ostream& operator<< (ostream& cons_out, Point2D p1);
Point2D operator+ (Point2D p1, Point2D p2);
Vector2D operator- (Point2D p1, Point2D p2);
double GetDistanceBetween(Point2D, Point2D);
Point2D operator+(Point2D, Vector2D);

#endif
