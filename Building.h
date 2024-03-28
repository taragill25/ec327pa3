#include <iostream>
using namespace std;
#include "GameObject.h"
#include "Point2D.h"

#ifndef Building_h
#define Building_h

class Building : public GameObject{
	public:
		Building();
		Building(char in_code, int in_Id, Point2D in_loc);
		void AddOneTrainer();
		void RemoveOneTrainer();
		void ShowStatus();
		bool ShouldBeVisible();

	private:
		unsigned int trainer_count;
	};

#endif
