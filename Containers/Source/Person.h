#pragma once
#include <string>
#include <vector>
#include <unordered_map>

class Pet
{
public:

	std::string m_Type;
	std::string m_Name;
	unsigned int m_Age;
};



class Person
{
public:
	~Person()
	{
		for (auto& pet : m_Pets)
		{
			delete pet;
			pet = nullptr;
		}
	}

	std::string m_Name;
	unsigned int m_Age;
	unsigned int m_PersonNumber;
	std::vector<Pet*> m_Pets;
	std::string m_HouseAddress;
	std::string m_EmailAddress;

	void Print() const;
};

class People : public std::vector<Person*>
{
public:
	~People()
	{
		for (auto& person : *this)
		{
			delete person;
			person = nullptr;
		}
	}

	int NameCount(const std::string& name) const;

	 std::vector<Person*> FindName(const std::string& name);
	 std::vector<Person*> FindAge(unsigned int age);
	 std::vector<Person*> FindPersonNum(unsigned int personNum);
	 std::vector<Person*> FindHouseAddress(const std::string& address);
	 std::vector<Person*> FindEmailAddress(const std::string& email);

};

