#include "Node.h"

#include <string>
#include <cstdlib>
#include <iostream>

template <typename T>

//default constructor to initialise an empty node 
Node<T>::Node(const T& data, Node <T>* next, Node <T>* previous)
{

	this->data = data;
	next = NULL;
	previous = NULL;
}


//constructor for a node with new data 
template <typename T>
Node<T>::Node(const T& data)
{
	this->data = data;
	next = NULL;
	previous = NULL;
}


//destructor to free up memory when program ends
template <typename T>
Node<T>::~Node<T>()
{
}

//mutator to put data
template <typename T>
void Node<T>::setData(const T& data)
{
	this->data = data;
}

//mutator to set the next node pointer
template <typename T>
void Node<T>::setNext(Node <T>* nextLink)
{
	next = nextLink;
}

//mutator to set the previous node pointer 
template <typename T>
void Node<T>::setPrevious(Node <T>* previousLink)
{
	previous = previousLink;
}

//next node accessor
template <typename T>
Node<T>* Node<T>::getNext()
{
	return next;
}

//previous node accessor
template <typename T>
Node<T>* Node<T>::getPrevious()
{
	return previous;
}

//next node const accessor
template <typename T>
Node<T>* Node<T>::getNext() const
{
	return next;
}

//previous node access
template <typename T>
Node<T>* Node<T>::getPrevious() const
{
	return previous;
}

//data in node accessor
template <typename T>
T Node<T>::getData() const
{
	return data;
}

//greater than overloaded operator to sort values from lowest to highest
template <typename T>
bool operator>(Node<T>& nodeA, Node<T>& nodeB)
{
	if (nodeA.getData() > nodeB.getData())
	{
		return true;
	}
	return false;
}
