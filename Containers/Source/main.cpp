#include <iostream>
#include <Bits.h>
#include <unordered_map>

#include "Person.h"
#include "Generator.h"

template<class T>
T Add( T n1, T n2 )
{
	return n1 + n2;
}

class Player
{
public:
	Player() {}
	~Player() {}

	void SetScore(int _Score) { m_Score = _Score; }
	int GetScore() { return m_Score; }

	Player operator+(const Player& otherPlayer)
	{
		m_Score += otherPlayer.m_Score;
		return *this;
	}

private:
	int m_Score;
};

template<class T>
class ScopedPointer
{
public:
	ScopedPointer() { test = new T; }
	~ScopedPointer() { delete test; }

	T* operator->() { return test; }
	T operator*() { return *test; }
private:
	T* test;
};

unsigned int personNum = 0;
void GenerateNewPeople(int amountPlayer)
{
	for (int i = 0; i < amountPlayer; ++i)
	{
		Person* person = new Person;
		person->m_Name = Generator::GenerateName();
		person->m_Age = Generator::GenerateAge();
		//personnummer
		person->m_Pet = Generator::GeneratePets();
		person->m_HouseAddress = Generator::GenerateAddress();
		person->m_EmailAddress = Generator::GenerateEmail();

	}
}

int main()
{
	//Task 1
	ScopedPointer<Player> playerPointer;

	Player p1;
	Player p2;

	p1.SetScore(5);
	p2.SetScore(3);

	Player Res = Add<Player>(p1, p2);

	//Task 2
	srand(time(nullptr));
	std::unordered_map<int, Person> PeopleList;


}