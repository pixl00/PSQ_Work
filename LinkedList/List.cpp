#include "List.h"

#include <iostream>

SinglyList::SinglyList()
{
	m_Root = nullptr;
}

SinglyList::~SinglyList()
{
	ClearNodes();
}

void SinglyList::PrependNode(const std::string _data)
{
	Node* newNode = new Node();
	newNode->data = _data;
	newNode->next = m_Root;

	m_Root = newNode;
}

void SinglyList::AppendNode(std::string _data)
{
	Node* newNode = new Node();
	newNode->data = _data;
	newNode->next = nullptr;

	Node* current = m_Root;
	bool cont = true;
	while (cont)
	{
		if (current == nullptr)
		{
			m_Root = newNode;
			cont = false;
		}
		else if (current->next != nullptr)
		{
			current = current->next;
		}
		else
		{
			current->next = newNode;
			cont = false;
		}
	}
}

void SinglyList::PopFront()
{
	Node* next = m_Root->next;

	if (m_Root != nullptr)
	{
		delete m_Root;
		if (next != nullptr)
		{
			m_Root = next;
		}
		else
		{
			m_Root = nullptr;
		}
	}
}

void SinglyList::PopBack()
{
	if (m_Root != nullptr)
	{
		Node* Previous = nullptr;
		Node* current = m_Root;
		while (current->next != nullptr)
		{
			Previous = current;
			current = current->next;
		}
		delete current;
		current = nullptr;
		if (Previous != nullptr)
		Previous->next = nullptr;
	}
}


void SinglyList::PrintNodes(void)
{
	Node* current = m_Root;

	if (current != nullptr)
	{
		while (current->next != nullptr)
		{
			std::cout << current->data << "\n";
			current = current->next;
		}
		std::cout << current->data << "\n";
	}
}

void SinglyList::ClearNodes(void)
{
	if (m_Root != nullptr)
	{
		while (m_Root->next != nullptr)
		{
			Node* next = m_Root->next;
			delete m_Root;
			m_Root = next;
			next = m_Root->next;
		}
		delete m_Root;
		m_Root = nullptr;
	}
}

