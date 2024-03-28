#include <iostream>
using namespace std;
#include "Building.h"
#include "Point2D.h"

#ifndef PokemonGym_h
#define PokemonGym_h

enum PokemonGymStates{
	NOT_DEFEATED,
	DEFEATED,
};

class PokemonGym : public Building{
public:
	PokemonGym();
	PokemonGym(unsigned int max_battle, unsigned int health_loss, double  PokeDollar_cost, unsigned int exp_per_battle, int in_id, Point2D in_loc);
	double GetPokeDollarCost(unsigned int battle_qty);
	unsigned int GetHealthCost(unsigned int battle_qty);
	unsigned int GetNumBattlesRemaining();
	bool IsAbleToBattle(unsigned int battle_qty, double budget, unsigned int health);
	unsigned int TrainPokemon(unsigned int battle_units);
	unsigned int GetExperiencePerBattle();
	bool Update();
	bool defeated();
	void ShowStatus();
	~PokemonGym();

private:
	unsigned int num_battle_remaining;
	unsigned int max_number_of_battles;
	unsigned int health_cost_per_battle;
	double PokeDollar_cost_per_battle;
	unsigned int experience_per_battle;
};

#endif
