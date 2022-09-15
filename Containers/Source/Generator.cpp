#include "Generator.h"



std::string Generator::GenerateName()
{
	std::string name;
	//generate first capital letter
	char _char = 65 + rand() % (1 + 87 - 65);
	name += _char;
	//generate the rest
	const int nameLength = 2 + rand() % 10;
	for (int i = 0; i < nameLength; ++i)
	{
		_char = 97 + rand() % (119 - 97 + 1);
		name += _char;
	}
	
	return name;
}
unsigned int Generator::GenerateAge()
{
	unsigned int age = 18 + rand() % (100 - 18);
	return age;
}
std::vector<Pet> Generator::GeneratePets()
{
	std::vector<Pet> pets;

	const int petAmount = rand() % 4;
	for (int i = 0; i < petAmount; ++i)
	{
		Pet* pet = new Pet;

		int num = rand() % 2;
		switch (num)
		{
		case 0:
			pet->m_Type = "Dog";
			break;
		case 1:
			pet->m_Type = "Cat";
		}
		pet->m_Name = GenerateName();
		pet->m_Age = rand() % 15;
		pets.push_back(*pet);
	}
	return pets;
}
std::string Generator::GenerateAddress()
{
	
}
std::string Generator::GenerateEmail()
{
	
}