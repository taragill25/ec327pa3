#include <iostream>
using namespace std;

#ifndef Vector2D_h
#define Vector2D_h

class Vector2D{
public:
    double x, y;
	Vector2D();
	Vector2D(double in_x, double in_y);
	friend ostream& operator<< (ostream& cons_out, Vector2D v1);
};

Vector2D operator* (Vector2D v1, double d);
Vector2D operator/ (Vector2D v1, double d);
ostream& operator<< (ostream& cons_out, Vector2D v1);

#endif
