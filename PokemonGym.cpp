#include <iostream>
#include "Point2D.h"
using namespace std;


#include "Building.h"


#ifndef PokemonCenter_h
#define PokemonCenter_h

enum PokemonCenterStates{
	POTIONS_AVAILABLE,
	NO_POTIONS_AVAILABLE,
};
class PokemonCenter : public Building{
private:
	unsigned int potion_capacity;
	unsigned int num_potions_remaining;
	double pokedollar_cost_per_potion;

public:
	PokemonCenter();
	PokemonCenter(int in_id, double potion_cost, unsigned int potion_cap, Point2D in_loc);
	bool HasPotions();
	unsigned int GetNumPotionRemaining();
	bool CanAffordPotion(unsigned int potion, double budget);
	double GetPokeDollarCost(unsigned int potion);
	unsigned int DistributePotion(unsigned int potion_needed);
	bool Update();
	void ShowStatus();
	~PokemonCenter();
};

#endif
