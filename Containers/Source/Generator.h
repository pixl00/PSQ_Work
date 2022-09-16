#pragma once
#include "Person.h"


class Generator
{
public:
	static std::string GenerateName();
	static unsigned int GenerateAge();
	static std::vector<Pet*> GeneratePets();
	static std::string GenerateAddress();
	static std::string GenerateEmail(const Person* person, const People& people);
};

