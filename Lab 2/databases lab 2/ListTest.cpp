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
	SLinkedList<int>::Iterator coolIt = list.head()->next().get();

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



	list.makeNewHead(coolIt);

	//Q 5
	std::list<int> randNumList;
	std::list<int> destination;

	for (int i = 0; i < 30; i++)
	{
		randNumList.push_back(rand() % 10 + 1);
	}

	int num1 = 3;
	int num2 = 6;

	// starting at the end of the list to find first instance of num1
	auto revIterator = std::find(randNumList.rbegin(), randNumList.rend(), num1);

	// converting to a forward iterator
	auto forIterator = revIterator.base();

    // forIterator is now being used to find num2
	forIterator = std::find(forIterator, randNumList.end(), num2);
	// numbers between num1 and num2 are being spliced into destination
	destination.splice(destination.begin(), randNumList, revIterator.base(), forIterator);

	system("PAUSE");
}
