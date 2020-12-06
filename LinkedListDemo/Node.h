#pragma once
#ifndef Nod_H
#define Nod_H
#include <string>
#include <cstdlib>

//declare template
template <typename T>

class Node
{
	//member methods that are extenally visible
public:
	//typedef for the program, this can be modified to change variable type the nodes hold
	//constructor that initialises an empty node 
	Node<T>(const T& data, Node<T>* next, Node<T>* previous);
	//constructor for a new node with data
	Node<T>(const T& data);
	//destructor
	~Node<T>();
	//setters to mutate private variables
	void setData(const T& data);
	void setNext(Node<T>* nextLink);
	void setPrevious(Node<T>* previousLink);

	//getters to access private variable values set
	//each variable has two getters, a const and non const to account for if whether a non const or const pointer instance of the class created
	Node<T>* getNext();
	Node<T>* getPrevious();
	Node<T>* getNext() const;
	Node<T>* getPrevious() const;
	T getData() const;

	//private member variables to create a new node, point the previous and next nodes and store data
private:
	T data;
	Node<T>* next;
	Node<T>* previous;
};
//greater than operator to compare and sort values from lowest to highest
template <typename T>
bool operator >(Node<T>& nodeA, Node<T>& nodeB);

#include "Node.hpp"
#endif // !1
