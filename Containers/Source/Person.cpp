#include "Person.h"

#include <iostream>


std::vector<Person*> People::FindName(const std::string& name)
{
	std::vector<Person*> foundPeople;
	for (auto& person_ : *this)
	{
		if (person_->m_Name == name) foundPeople.push_back(person_);
	}
	return foundPeople;
}

std::vector<Person*> People::FindAge(unsigned int age)
{
	std::vector<Person*> foundPeople;
	for (auto& person_ : *this)
	{
		if (person_->m_Age == age) foundPeople.push_back(person_);
	}
	return foundPeople;
}

std::vector<Person*> People::FindPersonNum(unsigned int personNum)
{
	std::vector<Person*> foundPeople;
	for (auto& person_ : *this)
	{
		if (person_->m_PersonNumber == personNum) foundPeople.push_back(person_);
	}
	return foundPeople;
}

std::vector<Person*> People::FindHouseAddress(const std::string& address)
{
	std::vector<Person*> foundPeople;
	for (auto& person_ : *this)
	{
		if (person_->m_HouseAddress == address) foundPeople.push_back(person_);
	}
	return foundPeople;
}

std::vector<Person*> People::FindEmailAddress(const std::string& email)
{
	std::vector<Person*> foundPeople;
	for (auto& person_ : *this)
	{
		if (person_->m_EmailAddress == email) foundPeople.push_back(person_);
	}
	return foundPeople;
}

int People::NameCount(const std::string& name) const
{
	int i = 0;
	for(auto& person : *this)
	{
		if (person->m_Name == name)
			i++;
	}

	return i;
}

void Person::Print() const {
	std::string output;

	output += "Name: " + m_Name + '\n';
	output += "Age: " + std::to_string(m_Age) + '\n';
	output += "Person number: " + std::to_string(m_PersonNumber) + '\n';
	output += "Address: " + m_HouseAddress + '\n';
	output += "Email: " + m_EmailAddress + '\n';

	if (!m_Pets.empty()) {
		output += "Pets: \n";

		for (auto& pet : m_Pets) {
			output += "   Type: " + pet->m_Type + '\n';
			output += "   Name: " + pet->m_Name + '\n';
			output += "   Age: " + std::to_string(pet->m_Age) + "\n\n";
		}
	}
	else
		output += '\n';

	std::cout << output;
}