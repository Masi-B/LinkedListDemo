#pragma once
#ifndef Queue_H
#define Queue_H
#include "LinkedList.h"
#include <string>
#include <cstdlib>

template <typename T>

class Queue
{
public:
	//constructor with no parameter, creates empty list 
	Queue<T>();
	//constructor with parameters creates one item in the queue
	Queue<T>(T& data);
	//member functions to add, to queue
	//method to add item to queue
	void enqueue(const T& data);
	//method to remove value from queue
	void dequeue();
	//check whether list is empty
	bool isEmpty() const;
	//return copy of item at the front of the queue 
	T front() const;
	//method to check how many items are in the queue
	std::size_t getSize() const;
	//get all the items in a queue 
	LinkedList<T>* getList() const;
	//overloaded addition operator to concatenate queues 
	Queue<T>& operator+(const Queue<T>& l);
	//Overloaded assignment operator to copy one queue onto another
	Queue<T>& operator=(const Queue<T>& queue1);
	//destructor
	~Queue<T>();
	//private member variables
	//instance of LinkedList calls the methods from the LinkedList class and
	//can be used by the queue class 
private:
	LinkedList<T>* list;

};
//non member methods.
//overloaded extraction operator to get user input to populate a queue 
template <typename T>
std::istream& operator >> (std::istream& input, Queue<T>& queue1);
//overloaded insertion operator to return output and print the queue 
template <typename T>
std::ostream& operator << (std::ostream& output, Queue<T>& queue1);
#include "Queue.hpp"
#endif//
