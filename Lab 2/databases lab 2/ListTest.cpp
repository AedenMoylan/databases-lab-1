#include <iostream>
#include "SLinkedList.h"
#include <algorithm>

int main()
{
	// Sample usage of SLinkedList class. 

	// Create a list with 3 nodes.
	SLinkedList<int> list;
	list.insertFirst(15);
	list.insertFirst(20);
	list.insertFirst(10);
	list.insertFirst(5);

	//std::fill(list.begin(), list.end(), -1);
	//int count = std::count(list.begin(), list.end(), -1);
	// Get an iterator to list beginning and "one past the end"
	SLinkedList<int>::Iterator it = list.begin();
	SLinkedList<int>::Iterator itEnd = list.end();

	//list.insertBefore(itEnd, 30);
	//list.moveLastToFront();

	list.reverse();

	int result2 = list.removePart2(10);
	
	// Simple equality test on two iterators
	bool result = (it != itEnd);

	// Output the value of the first list element
	std::cout << "First element: " << *it << std::endl;

	// Output the number of nodes in the list
	std::cout << list.size() << std::endl;

	system("PAUSE");
}
