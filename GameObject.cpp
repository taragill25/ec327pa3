#include "GameObject.h"

//class GameObject{

	GameObject::GameObject(){
		display_code = ' ';
		id_num = 1;
		state = 0;
		cout << "GameObject constructed" <<endl;
	}
	GameObject::GameObject(char in_code){
		display_code = in_code;
		id_num = 1;
		state = 0;
		cout << "GameObject constructed" << endl;
	}

	GameObject::GameObject(Point2D in_loc, int in_id, char in_code){
		//GameObject g1;
		//Point2D p1;
		//g1.id_num = in_id;
		//g1.display_code = in_code;
		//p1 = in_loc;
		location = in_loc;
		id_num = in_id;
		display_code = in_code;
		cout << "GameObject constructed";
	}

	Point2D GameObject::GetLocation(){
		return location;
	}

	int GameObject::GetId(){
		return id_num;
	}

	int GameObject::GetState(){
		return state;
	}

	void GameObject::ShowStatus(){
		//cout << g1.display_code << " " << g1.id_num << " at " << g1.location << endl;
		cout << display_code << " " << id_num <<" at" << location << endl;
	}
GameObject::~GameObject(){
  cout << "GameObject destructed." << endl;
}
void GameObject::DrawSelf(char *ptr){
  *ptr = display_code;
  *(ptr+1) = '0' + id_num;
}
//};
