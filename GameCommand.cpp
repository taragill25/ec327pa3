#include <iostream>
#include "GameCommand.h"
#include "Model.h"
#include "Trainer.h"
using namespace std;

void DoMoveCommand(Model& model, int trainer_id, Point2D p1){
	if (model.GetTrainerPtr(trainer_id)!= 0)
    {
        cout << "Moving " << model.GetTrainerPtr(trainer_id)->GetName() << " to " << p1 << endl;
       model.GetTrainerPtr(trainer_id)->StartMoving(p1);
       model.Update();
    }
    else
        cout << "ERROR: Please enter valid command!" << endl;
    return;   
}
void DoMoveToCenterCommand(Model& model, int trainer_id, int center_id){
	if (model.GetTrainerPtr(trainer_id)!= 0 && model.GetPokemonCenterPtr(center_id) != 0)
    {
      cout << "Moving " << model.GetTrainerPtr(trainer_id)->GetName() << " to Pokemon Center " << center_id << endl;
      model.GetTrainerPtr(trainer_id)->StartMovingToCenter(model.GetPokemonCenterPtr(center_id));
      model.Update();
    }
    else
        cout << "ERROR: Please enter a valid command!" << endl;
}
void DoMoveToGymCommand(Model& model, int trainer_id, int gym_id){
	if (model.GetTrainerPtr(trainer_id)!= 0 && model.GetPokemonGymPtr(gym_id) != 0)
    {
       cout << "Moving " << model.GetTrainerPtr(trainer_id)->GetName() << " to Pokemon Gym " << gym_id << endl;
      model.GetTrainerPtr(trainer_id)->StartMovingToGym(model.GetPokemonGymPtr(gym_id));
      model.Update();
    }
    else
        cout << "ERROR: Please enter a valid command!" << endl;
}

void DoStopCommand(Model& model, int trainer_id){
	if (model.GetTrainerPtr(trainer_id)!= 0)
        {
            cout << "Stopping " << model.GetTrainerPtr(trainer_id)->GetName() << endl;
            model.GetTrainerPtr(trainer_id)->Stop();
	    model.Update();
        }
        else
            cout << "ERROR: Please enter a valid command!" << endl;
}

void DoBattleCommand(Model& model, int trainer_id, unsigned int battles){
	if (model.GetTrainerPtr(trainer_id) != 0)
    {
        cout <<  model.GetTrainerPtr(trainer_id)->GetName() << " is battling" << endl;
       model.GetTrainerPtr(trainer_id)->StartBattling(battles);
       model.Update();
    }
    else
        cout << "ERROR: Please enter a valid command!" << endl;
}

void DoRecoverInCenterCommand(Model& model, int trainer_id, unsigned int potions_needed){
	if(model.GetTrainerPtr(trainer_id) != 0){
		cout << "Recovering " << model.GetTrainerPtr(trainer_id)->GetName() << "'s Pokemon's health";
		model.Update();
	}

	else
        	cout << "ERROR: Please enter a valid command!" << endl;
}
void DoAdvanceCommand(Model& model, View& view){
	cout << "Advancing one tick." << endl;
	model.Update();
	model.ShowStatus();
	model.Display(view);
	
}
void DoRunCommand(Model& model, View& view){
	cout << "Advancing to next event." << endl;
	bool check = false;
	int runCount = 0;
	while (runCount < 5 && !check){
		check = model.Update();
		runCount++;
	}
	model.ShowStatus();
	model.Display(view);
}
