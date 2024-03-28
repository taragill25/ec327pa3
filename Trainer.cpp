#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include "Trainer.h"
#include "GameObject.h"
#include "Building.h"
#include "Point2D.h"
#include "Vector2D.h"

using namespace std;

bool Trainer::UpdateLocation(){
	if (fabs((destination - location).x) <= fabs(delta.x) &&
        fabs((destination - location).y) <= fabs(delta.y))
    {
        location = destination;
        cout << display_code << GetId() << ": I’m there!" << endl;
        state = STOPPED;
        return true;
   }
    else
    {
      location =location + delta;
      cout << display_code << GetId() << ": step..." << endl;
        return false;
    }
}

void Trainer::SetUpDestination(Point2D dest){
	destination = dest;
	delta = (destination - location) * (speed /GetDistanceBetween(destination, location));
    return;
}

Trainer::Trainer(): GameObject('T'){
	speed = 5.0;
	is_at_center = false;
	is_IN_GYM = false;
	health = 20;
	experience = 0;
	PokeDollars = 0.0;
	battles_to_buy = 0;
	potions_to_buy = 0;
	current_center = NULL;
	current_gym = NULL;
	cout << "Trainer default constructed" << endl;
}

Trainer::Trainer(char in_code):GameObject(in_code){
	display_code = in_code;
	state = STOPPED;
	speed = 5.0;
	is_at_center = false;
	is_IN_GYM = false;
	health = 20;
	experience = 0;
	PokeDollars = 0.0;
	battles_to_buy = 0;
	potions_to_buy = 0;
	current_center = NULL;
	current_gym = NULL;
	cout << "Trainer default  constructed" << endl;
}
Trainer::Trainer(string in_name, int in_id, char in_code, unsigned int in_speed, Point2D in_loc): GameObject(in_loc, in_id, in_code){
	speed = in_speed;
	name = in_name;
	id_num = in_id;
	display_code = in_code;
	location = in_loc;
	is_at_center = false;
	is_IN_GYM = false;
	health = 20;
	experience = 0;
	PokeDollars = 20.0;
	battles_to_buy = 3;
	potions_to_buy = 3;
	current_center = NULL;
	current_gym = NULL;
	cout << "Trainer constructed" << endl;
}

void Trainer::StartMoving(Point2D dest){
	if (!HasFainted())
    {
      if(GetDistanceBetween(location, destination) == 0)
           cout << display_code << GetId() << ": I'm already there. See?" << endl;
       else
       {
            state = MOVING;
	    destination = dest;
	    delta = (destination - location) * (speed / GetDistanceBetween(destination, location));
            cout << display_code << GetId() << ": On my way." << endl;
	    }
    }
    else
        cout << display_code << GetId() << ": My pokemon have fainted. I may move but you just cannot see me. " << endl;
    return;
}

void Trainer::StartMovingToGym(PokemonGym* gym){
  // current_gym = gym;
	  if(!HasFainted()){
	    if(GetDistanceBetween(location, gym ->GetLocation()) == 0)
            cout << display_code << GetId() << ": I'm already at the PokemonGym!" << endl;
        else {
            if(is_IN_GYM){
                current_gym->RemoveOneTrainer(); 
                is_IN_GYM = false;
            }
            else if(is_at_center){
                current_center->RemoveOneTrainer();
                is_at_center = false;
            }
            state = MOVING_TO_GYM; 
            current_gym = gym;
          SetUpDestination(gym->GetLocation());
            cout << display_code << GetId() << ": On my way to gym " << gym->GetId() <<endl; 
       }
    }
    else
        cout << display_code << GetId() << ": My Pokemon have fainted so I can't move to gym..." << endl; 
    return;
}

void Trainer::StartMovingToCenter(PokemonCenter* center){
  //current_center = center;
	 if(!HasFainted()){
	   if(GetDistanceBetween(location, center->GetLocation()) == 0)
            cout << display_code << GetId() << ": I'm already at the Center!" << endl;
       else {
            if(is_at_center){
                current_center->RemoveOneTrainer(); 
                is_at_center = false;
            }

            else if(is_IN_GYM){
                current_gym->RemoveOneTrainer();
                is_IN_GYM = false;
            }
            state = MOVING_TO_CENTER; 
            current_center = center;
           SetUpDestination(center->GetLocation());
            cout << display_code << GetId() << ": On my way to Center " << center->GetId() <<endl; 
       }
    }
    else
        cout << display_code << GetId() << ": My Pokemon have fainted so I should have gone to the center.." << endl; 
    return;
}


void Trainer::StartBattling(unsigned int num_battles){
	unsigned int battles = 0;
	if(!HasFainted()){
		if (state == IN_GYM || state == BATTLING_IN_GYM){
			if (current_gym -> IsAbleToBattle(num_battles, PokeDollars, health)){
				if(!current_gym -> defeated()){
					battles = current_gym -> GetNumBattlesRemaining();
					battles_to_buy = min(num_battles, battles);
					state = BATTLING_IN_GYM;
					cout << display_code << GetId() << " : Started to battle at the PokemonGym" << current_gym -> GetId();
					cout << "with " << battles_to_buy << " battle(s)" << endl;
				}
				else
					cout << display_code << GetId()<< " : Cannot battle! This PokemonGym has no more trainers to battle!" << endl;
			}
			else
				cout << display_code << GetId() << " : Not enough money for battles" << endl;
		}
		else
			cout << display_code << GetId() << ": I can only battle in a PokemonGym!" << endl;
	}
	else 
		cout << display_code << GetId() << ": My Pokemon have fainted so no more battles for me..." << endl; 
    return; 
}

void Trainer::StartRecoveringHealth(unsigned int num_potions){
	 if(state == AT_CENTER || state == RECOVERING_HEALTH){
        if(current_center->CanAffordPotion(num_potions, PokeDollars)){
           if(current_center->HasPotions()){
                state = RECOVERING_HEALTH; 
                potions_to_buy = min(num_potions, current_center->GetNumPotionRemaining());
                cout << display_code << GetId() << ": Started recovering " << num_potions;
                cout << " potions at Pokemon Center " << current_center->GetId() << endl;
	   }
            
            else{
                cout << display_code << GetId() << ": Cannot recover! potion " ;
                cout << "remaining in this Pokemon Center" << endl;  
           }
       }
        else 
            cout << display_code << GetId() << ": Not enough money to recover health." << endl; 
    }
    else 
        cout << display_code << GetId() << ": I can only recover health at a Pokemon Center!" << endl; 
    return;
}

void Trainer::Stop(){
	state = STOPPED; 
    cout << display_code << GetId() << ": Stopping..." << endl; 
    return; 
}

bool Trainer::HasFainted(){
	if (health == 0)
		return true;
	else
		return false;
}

bool Trainer::ShouldBeVisible(){
	return !HasFainted();
}

//fix
void Trainer::ShowStatus(){
cout << name << " status: ";
    GameObject:: ShowStatus();
    if (health == 0){
        cout << name << " is out of health and can't move" << endl; 
        state = FAINTED; 
        return;
    }
    switch (state){
        case STOPPED:
            cout << " stopped" << endl; 
            break;
        case MOVING: 
            if (health == 0){
                cout << name << " is out of health and can't move. " << endl; 
                state = FAINTED;
            }
            else {
            cout << "moving at a speed of " << speed << " to destination" << destination;
            cout  << " at each step of " << delta << endl; 
            }
            break;
        case MOVING_TO_GYM:
            if (health == 0){
                cout << name << " is out of health and can't move. " << endl; 
                state = FAINTED;
            }
            else{
            cout << "heading to PokemonGym" << current_gym->GetId() << " at a speed of " << speed;
            cout << "at each step of" << delta << endl;  
            }
            break; 
        case MOVING_TO_CENTER:
           if (health == 0){
                cout << name << " is out of health and can't move. " << endl; 
                state = FAINTED;
            }
            else {
            cout << " heading to PokemonCenter " << current_center->GetId() << " at a speed of ";
            cout << speed << " at each step of " << delta << endl; 
            }
            break;
        case IN_GYM: 
            cout << "inside PokemonGym " << current_gym->GetId() << endl; 
            break; 
        case AT_CENTER: 
            cout << "inside Pokemon Center " << current_center->GetId() << endl; 
            break; 
        case BATTLING_IN_GYM: 
            cout << "battling in PokemonGym " << current_gym->GetId() << endl; 
            break; 
        case RECOVERING_HEALTH: 
            cout << " recovering health in Pokemon Center " << current_center->GetId() << endl;
        default:
            break;
    }

    cout << "Health: " << health << endl;  
    cout << "PokeDollars: " << PokeDollars << endl; 
    cout << "Experience: " << experience << endl; 
}

//fix
bool Trainer::Update(){
    switch (state){
        case STOPPED:
            return false;
            break;
        case MOVING: 
            if (is_at_center){
                current_center->RemoveOneTrainer();
                is_at_center = false;
            }
            else if (is_IN_GYM){
                current_gym->RemoveOneTrainer(); 
                is_IN_GYM = false;
            }
            if (health == 0)
            	state = FAINTED;
            else{
            UpdateLocation(); 
            	if ((location.x == destination.x) && (location.y == destination.y)){
                	state = STOPPED;
                	return true;
            	}
            	else { 
               		state = MOVING; 
                	return false;
                }
            } 
            break;

        case MOVING_TO_GYM:
            if (is_at_center){
                current_center->RemoveOneTrainer();
                is_at_center = false;
            }
            else if (is_IN_GYM){
                current_gym->RemoveOneTrainer(); 
                is_IN_GYM = false;
            }
            if (health == 0)
            	state = FAINTED;
            else{
            	UpdateLocation(); 
            	if ((location.x == destination.x) && (location.y == destination.y)){
                	current_gym-> AddOneTrainer(); 
                	state = IN_GYM;
                    is_IN_GYM = true;
                    return true;
                }
                else {
                    state = MOVING_TO_GYM;
                    return false;
                }
  			}
            break; 

        case MOVING_TO_CENTER:
            if (is_at_center){
                current_center->RemoveOneTrainer();
                is_at_center = false;
            }
            else if (is_IN_GYM){
                current_gym->RemoveOneTrainer(); 
                is_IN_GYM = false;
            }

            if(health == 0){
                state = FAINTED; 
            }
            else{ 
                UpdateLocation(); 
                if ((location.x == destination.x) && (location.y == destination.y)){
                    current_center->AddOneTrainer(); 
                    is_at_center = true;
                    state = AT_CENTER;
                    return true;
                }
                else {
                    state = MOVING_TO_CENTER;  
                    return false;
                }
            }
            break; 
        case IN_GYM: 
            state = IN_GYM; 
            return false;
            break; 

        case AT_CENTER: 
            state = AT_CENTER;
            return false; 
            break; 

        case BATTLING_IN_GYM: 
            health -= current_gym->GetHealthCost(battles_to_buy);
            PokeDollars -= current_gym->GetPokeDollarCost(battles_to_buy);
            //int new_experience = current_gym->TrainPokemon(battles_to_buy);
	    // experience += new_experience;
	    experience += current_gym->TrainPokemon(battles_to_buy);
            cout << "** " << name << " completed " << battles_to_buy << " battle(s)! **" << endl; 
	    cout << "** " << name << " gained " << experience - (current_gym -> TrainPokemon(battles_to_buy))  << " experience!" << endl; 
            battles_to_buy =0; 
            state = IN_GYM; 
            return true; 
            break;

        case RECOVERING_HEALTH: 
            PokeDollars = PokeDollars - current_center->GetPokeDollarCost(potions_to_buy); 
            //int new_health = current_center->DistributePotion(potions_to_buy);
            //health += new_health;
	    health += current_center -> DistributePotion(potions_to_buy);
            cout << "** " << name << " recovered " << health -(current_center -> DistributePotion(potions_to_buy)) << " health! **" << endl;
            cout << "** " << name << " bought " << potions_to_buy << " potions(s)!" << endl;
            potions_to_buy = 0;
            state = AT_CENTER;
            return true;
            break;
       default: 
            return false;
            break;
    }
   }


double GetRandomAmountOfPokeDollars(){
	double rand_pokedollars = (double)rand() / RAND_MAX;
    return  (rand_pokedollars * 2.0);
}

Trainer::~Trainer(){
	cout << "Trainer destrcuted." << endl;
}

string Trainer::GetName(){
	return name;
}
