#pragma once
#include <string>
#include <vector>

class Pet
{
public:
	Pet();
	~Pet();

	std::string m_Type;
	std::string m_Name;
	unsigned int m_Age;
};

class Person
{
public:
	std::string m_Name;
	unsigned int m_Age;
	unsigned int m_PersonNumber;
	std::vector<Pet> m_Pet;
	std::string m_HouseAddress;
	std::string m_EmailAddress;
};

