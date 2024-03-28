#include "Point2D.h"
#include <iostream>
#include "Vector2D.h"
#include <cmath>
using namespace std;

//default constructor
Point2D::Point2D(){
	double x = 0.0;
	double y = 0.0;
}

//the parametrized constructor
Point2D::Point2D(double in_x, double in_y){
	x = in_x;
	y = in_y;
}
//non-member function to calculate distance between two points
double GetDistanceBetween(Point2D p1, Point2D p2){
	double distance;
	distance = sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2));
	return distance;
}
//overloaded cout operator to print a point object
ostream& operator<< (ostream& cons_out, Point2D p1){
	cons_out << "(" <<p1.x << ", "<< p1.y << ")" << endl;
	return cons_out;
}

//overloaded + operator to add two points, returns point object	
Point2D operator+ (Point2D p1, Point2D p2) {
	Point2D p3;
	p3.x = p1.x + p2.x;
	p3.y = p1.y + p2.y;
	return p3;
}

//overloaded - operator to subtract two points, returns a vector object
Vector2D operator- (Point2D p1, Point2D p2){
	Vector2D v1;
	v1.x = p1.x - p2.x;
	v1.y = p1.y - p2.y;
	return v1;
}

Point2D operator+(Point2D p1, Vector2D v1){
  Point2D p2;
  p2.x = p1.x + v1.x;
  p2.y = p1.y + v1.y;
  return p2;
}
