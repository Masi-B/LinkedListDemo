#pragma once
#ifndef LinkedL_H
#define LinkedL_H
#include <cstdlib>
#include <string>
#include "Node.h"
#include "Node.h"
#include <string>
#include <cstdlib>


template <typename T>

class LinkedList
{
public:
	//default constructor creates empty list 
	LinkedList<T>();
	//copy constructor to copy a linked list onto another 
	LinkedList<T>(const LinkedList<T>& list1);
	//destructor
	~LinkedList<T>();
	//adds data to linked list
	void add(T& data);
	//length of linked list
	std::size_t length() const;
	//accessors for last node data
	Node<T>* getTailPointer() const;
	Node<T>* getTailPointer();
	//accessors for the first node data
	Node<T>* getHeadPointer() const;
	Node<T>* getHeadPointer();
	//count number of words in linked list
	void size(T& data);
	//delete node
	void remove();

	LinkedList<T>& operator+(const LinkedList<T>& l);
	//Overloaded assignment operator to copy one linked list onto another
	LinkedList<T>& operator=(const LinkedList<T>& list1);

	//private variables, headpointer points to the first node on the list
	//tailpointer points to the last node on the list
	//listlength is the length of the linked list
private:
	Node<T>* headpointer;
	Node<T>* tailpointer;
	std::size_t listLength;
};
template <typename T>
std::istream& operator >> (std::istream& input, LinkedList<T>& list1);
template <typename T>
std::ostream& operator << (std::ostream& output, LinkedList<T>& list1);
#include "LinkedList.hpp"
#endif //
