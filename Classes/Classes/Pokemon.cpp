

#include "Pokemon.h"
#include "Move.h"

Pokemon::Pokemon(std::string _name, Type _type, int _health, Move _move1, Move _move2) :
	name(_name),
	type(_type),
	health(_health),
	move1(_move1),
	move2(_move2){}

Pokemon Pokemons::empty{ Pokemon("Empty", Type::empty, 0, Moves::empty, Moves::empty) };

Pokemon Pokemons::vaporeon{ Pokemon("Vaporeon", Type::water, 100, Moves::waterGun, Moves::quickAttack) };
Pokemon Pokemons::flareon{ Pokemon("Flareon", Type::fire, 100, Moves::ember, Moves::quickAttack) };
Pokemon Pokemons::leafeon{ Pokemon("Leafeon", Type::grass, 100, Moves::razorLeaf, Moves::quickAttack) };


