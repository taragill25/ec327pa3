#include <iostream>
#include <cstring>
#include <ctime>
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Point2D.h"
#include "Vector2D.h"

using namespace std;

#ifndef Trainer_h
#define Trainer_h

enum TrainerStates{
	STOPPED,
	MOVING,
	FAINTED,
	AT_CENTER,
	IN_GYM,
	MOVING_TO_CENTER,
	MOVING_TO_GYM,
	BATTLING_IN_GYM,
	RECOVERING_HEALTH,
};

class Trainer: public GameObject{
private:
	double speed;
	bool is_at_center;
	bool is_IN_GYM;
	unsigned int health;
	unsigned int experience;
	double PokeDollars;
	unsigned int battles_to_buy;
	unsigned int potions_to_buy;
	string name;
	PokemonCenter* current_center;
	PokemonGym* current_gym;
	Point2D destination;
	Vector2D delta;

protected:
	bool UpdateLocation();
	void SetUpDestination(Point2D dest);

public:
	Trainer();
	Trainer(char in_code);
	Trainer(string in_name, int in_id, char in_code, unsigned int in_speed, Point2D in_loc);
	void StartMoving(Point2D dest);
	void StartMovingToGym(PokemonGym* gym);
	void StartMovingToCenter(PokemonCenter* center);
	void StartBattling(unsigned int num_battles);
	void StartRecoveringHealth(unsigned int num_potions); 
	void Stop();
	bool HasFainted();
	bool ShouldBeVisible();
	void ShowStatus();
	bool Update();
	virtual ~Trainer();
	string GetName();
};

double GetRandomAmountOfPokeDollars();
#endif
