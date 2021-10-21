#include "SLinkedList.h"

// Need to repeat the alias template here.
template <typename T>
using Iterator = SListIterator<SLinkedList<T>>;

// Need to use explicit template instantiation here too 
//  because template member functions are defined in a separate file to the class.
template class SLinkedList<int>;

template <typename T>
SLinkedList<T>::SLinkedList() :
	m_head(nullptr),
	m_tail(nullptr),
	m_count(0)
{}

template <typename T>
int SLinkedList<T>::size() const
{
	return m_count;
}

template <typename T>
bool SLinkedList<T>::isEmpty() const
{
	return m_count == 0;
}

template <typename T>
void SLinkedList<T>::swap(Iterator& t_first, Iterator& t_second)
{
	T temp = *t_first;
	*t_first = *t_second;
	*t_second = temp;
}

template <typename T>
void SLinkedList<T>::replace(Iterator& t_position, T t_element)
{
	*t_position = t_element;
}

template <typename T>
void SLinkedList<T>::insertFirst(T t_element)
{
	// create the new node.		
	std::unique_ptr<SListNode<T>> newNode = std::make_unique<SListNode<T>>(t_element, this);
	newNode->setNext(m_head);
	// set the head node, and the tail node if needed.
	std::swap(m_head, newNode);

	if (m_tail == nullptr)
	{
		m_tail = m_head.get();
	}

	m_count++;
}

template <typename T>
void SLinkedList<T>::insertLast(T t_element)
{
	// To be completed...

}

template <typename T>
void SLinkedList<T>::insertAfter(Iterator& t_position, T t_element)
{

	SListNode<T>* temp = t_position.get();

	if (temp != nullptr)
	{
		std::unique_ptr<SListNode<T>> newNode = std::make_unique<SListNode<T>>(t_element, this);

		newNode->setNext(temp->next());
		// if the new node is the new end of list node
		if (newNode->next() == nullptr)
		{
			m_tail = newNode.get();
		}
		temp->setNext(newNode);	// newNode is now nullptr

		m_count++;
	}
}

template <typename T>
void SLinkedList<T>::insertBefore(Iterator& t_position, T t_element)
{
	SListNode<T>* t_position = t_pos.get();
	SListNode<T>* current = m_head.get();
	for (; current->next().get() != t_position)
	{
		current = current->next.get();
	}
	// To be completed...

}


template <typename T>
Iterator<T> SLinkedList<T>::remove(Iterator& t_position)
{
	SListNode<T>* node = t_position.get();

	// Advance the iterator position to the next node
	++t_position;

	// If the node to be removed is at the head of the list
	if (m_head.get() == node)
	{
		m_head = std::move(m_head->next());
	}
	else
	{ // Node to be deleted has a predecessor.
		SListNode<T>* previous = m_head.get();

		// Set up 'previous' to point to the node one before the node we wish to delete.
		for (; previous->next().get() != node; previous = previous->next().get());

		// If the node to be deleted is the tail.
		if (node == m_tail)
		{
			m_tail = previous;
		}
		// Get a (unique_ptr) reference to the node to be deleted. 
		std::unique_ptr<SListNode<T>>& deleteMe = previous->next();
		// Link to the node after the one to be deleted.
		deleteMe = std::move(deleteMe->next());
	}

	m_count--;

	// Return the new iterator position
	return t_position;
}


template <typename T>
int SLinkedList<T>::remove(T t_element)
{
	// Remove all occurrences of element
	SListNode<T>* current = m_head.get();
	SListNode<T>* temp;

	int matches = 0;
	while (current != 0)
	{
		// if we have found a match
		if (current->element() == t_element)
		{
			std::cout << "Found a match" << std::endl;
			// Remove the match we have found
			temp = current;
			current = current->next().get();
			Iterator iterToRemove(temp);
			remove(iterToRemove);
			matches++;
		}
		else
		{
			current = current->next().get();
		}
	}
	m_count--;
	return matches;
}


template <typename T>
Iterator<T> SLinkedList<T>::last() const
{
	if (m_tail != nullptr)
	{
		return Iterator(m_tail);
	}
	return this->end();
}


template <typename T>
SListNode<T>* SLinkedList<T>::head() const
{
	return m_head.get();
}

template <typename T>
SListNode<T>* SLinkedList<T>::tail() const
{
	return m_tail;
}

template <typename T>
Iterator<T> SLinkedList<T>::begin() const
{
	Iterator it(m_head.get());
	return it;
}

template <typename T>
Iterator<T> SLinkedList<T>::end() const
{
	// Return a "one past the end" iterator  
	SListNode<T>* temp = nullptr;

	Iterator it(temp);
	return it;
}