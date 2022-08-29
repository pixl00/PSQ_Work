
#include "Move.h"

#pragma once
class Pokemon
{
public:
	Pokemon(std::string _name, Type _type, int _health, int _speed, Move _move1, Move _move2);

	std::string name;
	Type type;
	int health;
	int speed;
	Move move1;
	Move move2;
};

class Pokemons
{
public:
	static Pokemon empty;

	static Pokemon vaporeon;
	static Pokemon flareon;
	static Pokemon leafeon;
};