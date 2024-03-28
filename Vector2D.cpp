#include "Vector2D.h"
#include <iostream>
using namespace std;

//default constructor
Vector2D::Vector2D(){
	double x = 0.0;
	double y = 0.0;
}

//parametrized constructor
Vector2D::Vector2D(double in_x, double in_y){
	x = in_x;
	y = in_y;
}

//overloaded * operator, returns vector object
Vector2D operator* (Vector2D v1, double d){
	Vector2D v2;
	v2.x = v1.x * d;
	v2.y = v1.y * d;
	return v2;
}

//overloaded / operator, returns a vector
Vector2D operator/ (Vector2D v1, double d){
	Vector2D v2;
	if (d == 0.0){
		v2 = v1;
	}
	else {
		v2.x = v1.x /d;
		v2.y = v1.y / d;
	}
	
	return v2;
}

//overloaded ostream operator to print vector object
ostream& operator<< (ostream& cons_out, Vector2D v1){
	cons_out << "<" <<v1.x << ", "<< v1.y << ">" << endl;
	return cons_out;
}
