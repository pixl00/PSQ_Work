#include <iostream>
#include <Windows.h>
#include <vector>

#include "Player.h"
#include "Pokemon.h"
#include "Move.h"

int currentRound = 2;
std::vector<Pokemon> p1AvailablePokemons;
std::vector<Pokemon> p2AvailablePokemons;
bool playing = true;

int OutputText(std::string output, int typeSpeed = 20)
{
	for (const char i : output)
	{
		std::cout << i;
		Sleep(typeSpeed);
	}
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
int ChoosePlayerSettings()
{
	std::string playerName;
	std::string tempPokemon;
	std::vector<Pokemon> pickablePokemons = { Pokemons::vaporeon, Pokemons::flareon, Pokemons::leafeon };
#pragma region Player1
	OutputText("Player1 choose your name: ", 40);
	std::getline(std::cin, playerName);
	Players::player1.name = playerName;

	//pokemon1
	for (int i = 0; i < pickablePokemons.size(); ++i)
	{
		OutputText(pickablePokemons[i].name + "\n", 20);
	}
	OutputText(playerName + " Choose your first Pokemon: ", 40);
	std::getline(std::cin, tempPokemon);
	tempPokemon = TextToLower(tempPokemon);

	for (int i = 0; i < pickablePokemons.size(); ++i)
	{
		if (TextToLower(pickablePokemons[i].name) == tempPokemon)
		{
			Players::player1.pokemon1 = pickablePokemons[i];
			pickablePokemons.erase(i + pickablePokemons.cbegin());
			p1AvailablePokemons[0] = pickablePokemons[i];
			break;
		}
	}
	//pokemon2
	for (int i = 0; i < pickablePokemons.size(); ++i)
	{
		OutputText(pickablePokemons[i].name + "\n", 20);
	}
	OutputText(playerName + " Choose your second Pokemon: ", 40);
	std::getline(std::cin, tempPokemon);
	tempPokemon = TextToLower(tempPokemon);

	for (int i = 0; i < pickablePokemons.size(); ++i)
	{
		if (TextToLower(pickablePokemons[i].name) == tempPokemon)
		{
			Players::player1.pokemon2 = pickablePokemons[i];
			pickablePokemons.erase(i + pickablePokemons.cbegin());
			p1AvailablePokemons[1] = pickablePokemons[i];
			break;
		}
	}
	//pokemon3
	for (int i = 0; i < pickablePokemons.size(); ++i)
	{
		OutputText(pickablePokemons[i].name + "\n", 20);
	}
	OutputText(playerName + " Choose your third Pokemon: ", 40);
	std::getline(std::cin, tempPokemon);
	tempPokemon = TextToLower(tempPokemon);

	for (int i = 0; i < pickablePokemons.size(); ++i)
	{
		if (TextToLower(pickablePokemons[i].name) == tempPokemon)
		{
			Players::player1.pokemon3 = pickablePokemons[i];
			pickablePokemons.erase(i + pickablePokemons.cbegin());
			p1AvailablePokemons[2] = pickablePokemons[i];
			break;
		}
	}
#pragma endregion
#pragma region Player2
	pickablePokemons = { Pokemons::vaporeon, Pokemons::flareon, Pokemons::leafeon };
	OutputText("\nPlayer2 choose your name: ", 40);
	std::getline(std::cin, playerName);
	Players::player2.name = playerName;

	//pokemon1
	for (int i = 0; i < pickablePokemons.size(); ++i)
	{
		OutputText(pickablePokemons[i].name + "\n", 20);
	}
	OutputText(playerName + " Choose your first Pokemon: ", 40);
	std::getline(std::cin, tempPokemon);
	tempPokemon = TextToLower(tempPokemon);

	for (int i = 0; i < pickablePokemons.size(); ++i)
	{
		if (TextToLower(pickablePokemons[i].name) == tempPokemon)
		{
			Players::player2.pokemon1 = pickablePokemons[i];
			pickablePokemons.erase(i + pickablePokemons.cbegin());
			p2AvailablePokemons[0] = pickablePokemons[i];
			break;
		}
	}
	//pokemon2
	for (int i = 0; i < pickablePokemons.size(); ++i)
	{
		OutputText(pickablePokemons[i].name + "\n", 20);
	}
	OutputText(playerName + "Choose your second Pokemon: ", 40);
	std::getline(std::cin, tempPokemon);
	tempPokemon = TextToLower(tempPokemon);

	for (int i = 0; i < pickablePokemons.size(); ++i)
	{
		if (TextToLower(pickablePokemons[i].name) == tempPokemon)
		{
			Players::player2.pokemon2 = pickablePokemons[i];
			pickablePokemons.erase(i + pickablePokemons.cbegin());
			p2AvailablePokemons[1] = pickablePokemons[i];
			break;
		}
	}
	//pokemon3
	for (int i = 0; i < pickablePokemons.size(); ++i)
	{
		OutputText(pickablePokemons[i].name + "\n", 20);
	}
	OutputText(playerName + "Choose your first Pokemon: ", 40);
	std::getline(std::cin, tempPokemon);
	tempPokemon = TextToLower(tempPokemon);

	for (int i = 0; i < pickablePokemons.size(); ++i)
	{
		if (TextToLower(pickablePokemons[i].name) == tempPokemon)
		{
			Players::player2.pokemon3 = pickablePokemons[i];
			pickablePokemons.erase(i + pickablePokemons.cbegin());
			p2AvailablePokemons[2] = pickablePokemons[i];
			break;
		}
	}
#pragma endregion
	return 0;
}
void CheckPokemonsHealth()
{
	if (Players::player1.selectedPokemon.health <= 0)
	{
		OutputText(Players::player1.name + "'s pokemon fainted\n");
		//om minst en pokemon har mer än 0 hp?
		if (Players::player1.pokemon1.health > 0 || Players::player1.pokemon2.health > 0 || Players::player1.pokemon3.health > 0)
		{
			Switch();
		}
		else
		{
			OutputText(Players::player2.name + " wins!");
			playing = false;
		}
	}
	else if (Players::player2.selectedPokemon.health <= 0)
	{
		OutputText(Players::player2.name + "'s pokemon fainted\n");
		//om minst en pokemon har mer än 0 hp?
		if (Players::player2.pokemon1.health > 0 || Players::player2.pokemon2.health > 0 || Players::player2.pokemon3.health > 0)
		{
			Switch();
		}
		else
		{
			OutputText(Players::player1.name + " wins!");
			playing = false;
		}
	}
}
void Attack()
{
	std::string& p1Name = Players::player1.name;
	std::string& p1PokeName = Players::player1.selectedPokemon.name;
	std::string& p2Name = Players::player2.name;
	std::string& p2PokeName = Players::player2.selectedPokemon.name;
	
	int randNum = 0;
	std::string choice;
	OutputText("Choose an attack: ");
#pragma region player2 attack
	if (currentRound % 2 == 0)
	{
		OutputText(Players::player2.selectedPokemon.move1.name + ", " + Players::player2.selectedPokemon.move2.name + "\n");
		std::getline(std::cin, choice);
		if (TextToLower(choice) == TextToLower(Players::player2.selectedPokemon.move1.name))
		{
			randNum = rand() % 100 + 1;
			if (randNum <= Players::player2.selectedPokemon.move1.accuracy)
			{
				Players::player1.selectedPokemon.health -= Players::player2.selectedPokemon.move1.damage;
				OutputText(p2Name + "'s " + p2PokeName + " did " + std::to_string(Players::player2.selectedPokemon.move1.damage) + " damage to " + p1Name + "'s " + p1PokeName + " current hp: " + std::to_string(Players::player1.selectedPokemon.health));
			
			
			}
			else
			{
				OutputText("attack missed");
			}
		}
		else if (TextToLower(choice) == TextToLower(Players::player2.selectedPokemon.move2.name))
		{
			if (randNum <= Players::player2.selectedPokemon.move2.accuracy)
			{
				Players::player1.selectedPokemon.health -= Players::player2.selectedPokemon.move2.damage;
				OutputText(p2Name + "'s " + p2PokeName + " did " + std::to_string(Players::player2.selectedPokemon.move2.damage) + " damage to " + p1Name + "'s " + p1PokeName + " current hp: " + std::to_string(Players::player1.selectedPokemon.health));

				
			}
			else
			{
				OutputText("attack missed");
			}
		}
		else
		{
			OutputText("\n This attack doesn't exist \n");
			Attack();
		}
	}
#pragma endregion
#pragma region player1 attack
	else
	{
		OutputText(Players::player1.selectedPokemon.move1.name + ", " + Players::player1.selectedPokemon.move2.name + "\n");
		std::getline(std::cin, choice);
		if (TextToLower(choice) == TextToLower(Players::player1.selectedPokemon.move1.name))
		{
			randNum = rand() % 100 + 1;
			if (randNum <= Players::player1.selectedPokemon.move1.accuracy)
			{
				Players::player2.selectedPokemon.health -= Players::player1.selectedPokemon.move1.damage;
				OutputText(p1Name + "'s " + p1PokeName + " did " + std::to_string(Players::player1.selectedPokemon.move1.damage) + " damage to " + p2Name + "'s " + p2PokeName + " current hp: " + std::to_string(Players::player2.selectedPokemon.health));
			}
			else
			{
				OutputText("attack missed");
			}
		}
		else if (TextToLower(choice) == TextToLower(Players::player1.selectedPokemon.move2.name))
		{
			if (randNum <= Players::player1.selectedPokemon.move2.accuracy)
			{
				Players::player2.selectedPokemon.health -= Players::player1.selectedPokemon.move2.damage;
				OutputText(p1Name + "'s " + p1PokeName + " did " + std::to_string(Players::player1.selectedPokemon.move2.damage) + " damage to " + p2Name + "'s " + p2PokeName + " current hp: " + std::to_string(Players::player2.selectedPokemon.health));


			}
			else
			{
				OutputText("attack missed");
			}
		}
		else
		{
			OutputText("\n This attack doesn't exist \n");
			Attack();
		}

	}
#pragma endregion
	CheckPokemonsHealth();
}
int Switch()
{
	std::string input;
	OutputText("Please pick a new pokemon: ");
	if (currentRound % 2 == 0)
	{
		for (int i = 0; i < p2AvailablePokemons.size(); ++i)
		{
			OutputText(p2AvailablePokemons[i].name);
		}
		std::getline(std::cin, input);
		for (int i = 0; i < p2AvailablePokemons.size(); ++i)
		{
			if (TextToLower(p2AvailablePokemons[i].name) == TextToLower(input))
			{
				Players::player2.selectedPokemon = p2AvailablePokemons[i];
				break;
			}
		}
		if (Players::player1.selectedPokemon.health <= 0)
		{
			Switch();
		}
		else if (Players::player2.selectedPokemon.health <= 0)
		{
			Switch();
		}
	}
	else
	{
		for (int i = 0; i < p1AvailablePokemons.size(); ++i)
		{
			OutputText(p1AvailablePokemons[i].name);
		}
		std::getline(std::cin, input);
		for (int i = 0; i < p1AvailablePokemons.size(); ++i)
		{
			if (TextToLower(p1AvailablePokemons[i].name) == TextToLower(input))
			{
				Players::player1.selectedPokemon = p1AvailablePokemons[i];
				break;
			}
		}
	}
	
	
	return 0;
}
#pragma region Input Handling
std::string GetInput()
{
	std::string input;
	if (currentRound % 2)
	{
		OutputText("\n" + Players::player2.name + " choose an action: Attack, Switch Pokemon\n");
	}
	else
	{
		OutputText("\n" + Players::player1.name + " choose an action: Attack, Switch Pokemon\n");
	}
	std::getline(std::cin, input);

	return TextToLower(input);
}
int ProcessInput(std::string i)
{
	if (i == "attack")
		Attack();
	else if (i == "switch")
		Switch();
	else
		GetInput();
	return 0;
}
#pragma endregion
int Render()
{
	return 0;
}


int main() {
	srand(time(NULL));
	ChoosePlayerSettings();
	system("cls");
	while (playing) {
		std::string i = GetInput();
		ProcessInput(i);
		Render();
	}
	return 0;
}