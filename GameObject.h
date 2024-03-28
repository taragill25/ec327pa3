#include "Point2D.h"
#include <iostream>
using namespace std;

#ifndef GameObject_h
#define GameObject_h

class GameObject{
protected:
	Point2D location;
	int id_num;
	char display_code;
	char state;


public:
	GameObject();
	GameObject(char in_code);
	GameObject(Point2D in_loc, int in_id, char in_code);
	Point2D GetLocation();
	int GetId();
	int GetState();
	virtual void ShowStatus();
	void DrawSelf(char *ptr);
	virtual bool Update() = 0;
	virtual bool ShouldBeVisible() = 0;
	virtual ~GameObject();
	
};

#endif
