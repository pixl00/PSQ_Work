#include <iostream>
#include <Windows.h>
#include <vector>
#include <map>

#include "Player.h"
#include "Pokemon.h"
#include "Move.h"

int OutputText(std::string output, float typeSpeed) {
	for (int i = 0; i < output.size(); i++)
	{
		std::cout << output[i];
		Sleep(typeSpeed);
	}
	return 0;
}
#pragma region Input Handling
int GetInput() {
	return 0;
}
int ProcessInput() {
	return 0;
}
#pragma endregion
int Render() {
	return 0;
}

std::string TextToLower(std::string input)
{
	std::string output = "";
	for (int i = 0; i < input.length(); ++i)
	{
		output += tolower(input[i]);
	}
	return output;
}
int ChoosePlayerSettings() {
	std::string playerName;
	std::string tempPokemon;
	Player currentPlayer = Players::player1;
	std::vector<Pokemon> availablePokemons = { Pokemons::vaporeon, Pokemons::flareon, Pokemons::leafeon };

	//classen är non-copyable?
	currentPlayer = std::ref(Players::player2);
	OutputText("Player1 choose your name: ", 40);
	std::cin >> playerName;
	Players::player1.name.append(playerName);

	for (int i = 0; i < availablePokemons.size(); ++i)
	{
		OutputText(availablePokemons[i].name + "\n", 20);
	}
	OutputText(playerName + "Choose your first Pokemon: ", 40);
	std::cin >> tempPokemon;
	TextToLower(tempPokemon);

	for (int i = 0; i < availablePokemons.size(); ++i)
	{
		if (TextToLower(availablePokemons[i].name) == tempPokemon)
		{

		}

	}

	return 0;
}
int InitializeGame() {
	return 0;
}

int main() {
	ChoosePlayerSettings();
	const bool playing = true;
	while (playing) {
		GetInput();
		ProcessInput();
		Render();
	}
	return 0;
}