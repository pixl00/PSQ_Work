#include <iostream>

#include "List.h"


int main()
{
	SinglyList singlyList;

	singlyList.PrependNode("test1");
	singlyList.PrependNode("test2");
	singlyList.PrependNode("test3");
	singlyList.AppendNode("test4");

	singlyList.PrintNodes();
	singlyList.PopFront();
	singlyList.PrintNodes();
	singlyList.ClearNodes();
	singlyList.PrintNodes();



	//för att testa efter memory leaks
	bool test = true;
	while (test)
	{
		singlyList.PrependNode("test1");
		singlyList.PrependNode("test2");
		singlyList.AppendNode("test3");
		singlyList.AppendNode("test4");
		singlyList.PrintNodes();
		singlyList.PopFront();
		singlyList.PopBack();
		singlyList.ClearNodes();
	}
}