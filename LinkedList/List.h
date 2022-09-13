#pragma once
#include <string>
struct Node;

class SinglyList
{
public:
	SinglyList();
	~SinglyList();

	void PrependNode(std::string _data);
	void AppendNode(std::string _data);
	void PopFront(void);
	void PopBack(void);
	void PrintNodes(void);
	void ClearNodes(void);

private:

	Node* m_Root;
};


struct Node
{
	std::string data;
	Node* next = nullptr;
};