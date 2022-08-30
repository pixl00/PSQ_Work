#include "Player.h"

Player::Player(std::string _name, Pokemon _pokemon1, Pokemon _pokemon2, Pokemon _pokemon3):
	name(_name),
	pokemon1(_pokemon1),
	pokemon2(_pokemon2),
	pokemon3(_pokemon3),
	selectedPokemon(pokemon1){}

Player Players::player1{ Player("Player1", Pokemons::empty, Pokemons::empty, Pokemons::empty) };
Player Players::player2{ Player("Player2", Pokemons::empty, Pokemons::empty, Pokemons::empty) };