#include <iostream>
#include "Model.h"
#include "View.h"
#include <stdlib.h>
//#include <bits/stdc++.h>

using namespace std;

Model::Model(){
	time = 0;

	PokemonCenter* C1 = new PokemonCenter(1,1, 100, Point2D(1,20));
	PokemonCenter* C2 = new PokemonCenter(2, 1, 100, Point2D(10,20));
	center_ptrs[0] = C1;
	center_ptrs[2] = C2;

	Trainer *T1 = new Trainer("Ash", 1, 'T', 1, Point2D(5,1));
	Trainer* T2 = new Trainer("Trainer", 2, 'T', 2, Point2D(10,1));
	trainer_ptrs[0] = T1;
	trainer_ptrs[1] = T2;

	PokemonGym* G1 = new PokemonGym(10, 5, 0.1, 3, 1, Point2D(0,0));
	PokemonGym* G2 = new PokemonGym(20, 5, 7.5, 4, 2, Point2D(5, 5));
	gym_ptrs [0] = G1;
	gym_ptrs[1] = G2;

	object_ptrs[0] = C1;
	object_ptrs[1] = C2;
	object_ptrs[2] = T1;
	object_ptrs[3] = T2;
	object_ptrs[4] = G1;
	object_ptrs[5] = G2;

	num_objects = 6;
	num_centers = 2;
	num_trainers = 2;
	num_gyms = 2;

	cout << "Model default constructed" << endl;
}

Model::~Model(){
  	PokemonCenter* temp_center;
	PokemonGym* temp_gym;
	Trainer* temp_trainer;

	for(int i = 0; i < num_centers; i++){
		temp_center = center_ptrs[i];
		delete temp_center;
	}

	for(int i = 0; i < num_trainers; i++){
		temp_trainer = trainer_ptrs[i];
		delete temp_trainer;
	}

	for(int i = 0; i < num_gyms; i++){
		temp_gym = gym_ptrs[i];
		delete temp_gym;
		}
	cout << "Model destructed." << endl;
}

Trainer* Model::GetTrainerPtr(int id){
	for(int i = 0; i < num_trainers; i ++){
		if(trainer_ptrs[i] -> GetId() == id)
			return trainer_ptrs[i];
	}
}
	PokemonCenter* Model::GetPokemonCenterPtr(int id){
		for(int i = 0; i < num_centers; i ++){
			if(center_ptrs[i] -> GetId() == id)
				return center_ptrs[i];
		}
	}
	PokemonGym* Model::GetPokemonGymPtr(int id){
		for(int i = 0; i < num_gyms; i ++){
			if(gym_ptrs[i] -> GetId() == id)
				return gym_ptrs[i];
		}
	}
	bool Model::Update(){
		time++;

		/*	PokemonCenter* temp_center;
		PokemonGym* temp_gym;
		Trainer* temp_trainer;*/

		bool temp_bool = false;
		unsigned int num_fainted;
		unsigned int num_defeated;

		/*for(int i = 0; i < num_centers; i ++){
			temp_center = center_ptrs[i];
			if(temp_center -> Update())
				temp_bool = true;
				}*/
		for (int i = 0; i <6; i ++){
		  if (object_ptrs[i]-> Update() == 1)
		    return true;
		  /* if (gym_ptrs[i] -> GetNumBattlesRemaining()== 0)
		    num_defeated++;
		    if (trainer_ptrs[i]*/
		  
		}
		for (int i = 0; i < 2; i++){
		  if (gym_ptrs[i] -> defeated())
		    num_defeated++;
		  if(trainer_ptrs[i] -> HasFainted())
		    num_fainted++;
		}
		return false;

		/*for(int i = 0; i < num_trainers; i ++){
			temp_trainer = trainer_ptrs[i];
			if(temp_trainer -> Update())
				temp_bool = true;
			if (temp_trainer -> HasFainted())
				num_fainted ++;
		}

		for(int i = 0; i < num_gyms; i ++){
			temp_gym = gym_ptrs[i];
			if(temp_gym -> Update())
				temp_bool = true;
			if(temp_gym -> GetNumBattlesRemaining() == 0)
				num_defeated ++;
				}*/

		if (num_fainted == num_trainers){
			cout << "GAME OVER: You lose! all of your Trainers' pokemon have fainted!" << endl;
			exit(0);
		}

		else if (num_defeated == num_gyms){
			cout << "GAME OVER: You win! All battles done!" << endl;
			exit(0);
		}

		if(temp_bool)
			return true;
	}
void Model::Display(View& view){
	  cout << "Time: " << time << endl;

		GameObject* game_object;

		view.Clear();
		for (int i = 0; i <num_objects; i++){
        	GameObject* game_object = object_ptrs[i];
        	view.Plot(game_object);
    	}
    	view.Draw();
    	return;
	}
	

	void Model::ShowStatus(){
		GameObject* game_object;
		cout << "Time: " << time << endl; 
		for (int i= 0; i < num_objects; i++){
        	GameObject *game_object = object_ptrs[i];
       		 game_object->ShowStatus();
    	}
    	return; 
	}
