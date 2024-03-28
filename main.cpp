#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>


using namespace std;

#include "Point2D.h"
#include "Vector2D.h"
#include "GameObject.h"
#include "Building.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Trainer.h"
#include "Model.h"
#include "GameCommand.h"
#include "View.h"

int main(){

  cout << "EC327: Introduction to Software Engineering" << endl;
  cout << "Fall 2022" << endl;
  cout <<  "Programming Assignment 3" << endl;
  cout << "Welcome to Pokemon!" << endl;
  cout << endl;

  Model game_model;
  View game_view;
  char command;

bool isGameRunning = true;

//game_model.Update();
 //game_model.ShowStatus()

srand(time(NULL));
game_model.ShowStatus();
game_model.Display(game_view);

  





while(isGameRunning){
  Point2D  move;
  unsigned int potions;
  unsigned int battles;
  int object_id;
  int in_id;
  cout << "Enter game command: ";
  cin >> command;
  switch(command){
    case 'm':
      cout << "enter trainer id x-coordinate and  y-coordinate: " << endl;
      cin >> in_id;
      cin >> move.x;
      cin >> move.y;
      //cin >> move;
      DoMoveCommand(game_model, in_id, move);
      game_model.Display(game_view);
      break;
    case 'c':
      cout <<"enter trainer id and center: " << endl;
      cin >> in_id;
      cin >> object_id;
      DoMoveToCenterCommand(game_model, in_id, object_id);
      game_model.Display(game_view);
      break;
    case 'g':
      cout <<"enter trainer id and gym: " <<endl;
      cin >> in_id;
      cin >> object_id;
      DoMoveToGymCommand(game_model, in_id, object_id);
      game_model.Display(game_view);
      break;
    case 's':
      cout <<"enter trainer id: " << endl;
      cin >> in_id;
      DoStopCommand(game_model, in_id);
      game_model.Display(game_view);
      break;
    case 'p':
      cout << "enter trainer id and potions: " << endl;
      cin >> in_id;
      cin >> potions;
      DoRecoverInCenterCommand(game_model, in_id, potions);
      game_model.Display(game_view);
		  break;
    case 'b':
      cout << "enter trainer id and battles : " << endl;
      cin >> in_id;
      cin >> battles;
      DoBattleCommand(game_model, in_id, battles);
      game_model.Display(game_view);
		  break;
    case 'a':
      DoAdvanceCommand(game_model, game_view);
      //game_model.Display(game_view);
		  break;
    case 'r':
      cout << "run: ";
      DoRunCommand(game_model, game_view);
      //game_model.Display(game_view);
		  break;
    case 'q':
      cout << "Terminating program!" << endl;
      isGameRunning = false;
      break;
      }
}

	return 0;
}
