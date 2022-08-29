#include <string>

#include "Type.h"

#pragma once
class Move
{
public:
	Move(std::string _name, Type _type, int _damage, int _accuracy);
	
	std::string name;
	Type type;
	int damage;
	int accuracy;
};

class Moves
{
public:
	//göra till default??
	static Move empty;
	//water
	static Move waterGun;
	static Move octazooka;
	static Move muddyWater;
	//grass
	static Move vineWhip;
	static Move razorLeaf;
	//fire
	static Move ember;
	static Move inferno;
	//normal
	static Move quickAttack;
};