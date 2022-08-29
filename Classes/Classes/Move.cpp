#include "Move.h"
#include "Type.h"

Move::Move(std::string _name, Type _type, int _damage, int _accuracy) :
	name(_name),
	type(_type),
	damage(_damage),
	accuracy(_accuracy){}


Move Moves::empty{ Move("Empty", Type::empty, 0, 0) };

Move Moves::waterGun{ Move("Water Gun", Type::water, 40, 100) };//vaporeon
Move Moves::octazooka{ Move("Octazooka", Type::water, 65, 85) };
Move Moves::muddyWater{ Move("Muddy Water", Type::water, 90, 85) };

Move Moves::vineWhip{ Move("Vine Whip", Type::grass, 45, 100) };
Move Moves::razorLeaf{ Move("Razor Leaf", Type::grass, 70, 80) };//leafeon

Move Moves::ember{ Move("Ember", Type::fire, 40, 100) };//flareon
Move Moves::inferno{ Move("Inferno", Type::fire, 100, 50) };

Move Moves::quickAttack{ Move("Quick Attack", Type::normal, 40, 100) };

