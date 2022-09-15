#include <iostream>
#include <vector>

template<class T>
T Add( T n1, T n2 )
{
	return n1 + n2;
}



class Player
{
public:
	Player() {};
	~Player() {};

	void SetScore(int _Score) { m_Score = _Score; };
	int GetScore() { return m_Score; };

	Player operator+(const Player& otherPlayer) { m_Score += otherPlayer.m_Score; return *this; }

private:
	int m_Score = 0;
};

class ScopedPointer;

int main()
{
	int test = Add(4, 6);

	Player p1;
	Player p2;

	p1.SetScore(5);
	p2.SetScore(3);

	//int Res = Add<Player>(p1, p2);
	//Compiler error! No + operator defined for Player
}