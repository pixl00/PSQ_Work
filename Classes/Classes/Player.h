#include "Pokemon.h"

#pragma once
class Player
{
public:
	Player(std::string _name, Pokemon _pokemon1, Pokemon _pokemon2, Pokemon _pokemon3);

	std::string name;
	Pokemon& pokemon1;
	Pokemon& pokemon2;
	Pokemon& pokemon3;
};

class Players
{
public:
	static Player player1;
	static Player player2;
};

