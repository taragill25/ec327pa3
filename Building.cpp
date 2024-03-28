#include "Building.h"
#include "Point2D.h"
#include "GameObject.h"
#include <iostream>

//default constructor
	Building::Building(){
		//GameObject();
		display_code = 'B';
		trainer_count = 0;
		cout << "Building default constructed" << endl;
	}
//parametrized constructor
	Building::Building(char in_code, int in_Id, Point2D in_loc): GameObject(in_code){
		id_num = in_Id;
		location = in_loc;
		display_code = in_code;
		trainer_count = 0;
		cout << "Building constructed" << endl;
	}
//adds one to trainer count if a trainer enters a building
	void Building::AddOneTrainer(){
		trainer_count++;
		return;
	}
//subtracts one trainer from count if trainer leaves building
	void Building::RemoveOneTrainer(){
		trainer_count--;
		return;
	}

//shows the status of building (code num and location) as well as how many trainers are in the building
	void Building::ShowStatus(){
		cout<< display_code << id_num << " located at (" << location.x << ", " << location.y << ")" <<  endl;
		return;
	}
//function that sees is building should be visible
	bool Building::ShouldBeVisible(){
		return true;
	}
