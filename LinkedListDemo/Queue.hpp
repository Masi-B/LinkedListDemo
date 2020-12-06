#include "Queue.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cassert>
#include <algorithm>

//constructor with no parameters and creates empty queue 
template <typename T>
Queue<T>::Queue()
{    //create new queue using linked list 
	list = new LinkedList<T>();
}


//constructor that creates a new queue with an item
template <typename T>
Queue<T>::Queue(T& data)
{   //create new queue using linked list 
	list = new LinkedList<T>(data);
}

//destructor to free memory
template <typename T>
Queue<T>::~Queue()
{   //delete queue 
	delete list;
}

//method to get the length of a queue 
template <typename T>
std::size_t Queue<T>::getSize() const
{
	//call linked list length method to get the number of items in a queue
	return list->length();


}

//method to check if queue is empty 
//returns true if it is empty 
template <typename T>
bool Queue<T>::isEmpty() const
{

	return getSize() == 0;


}

//put values into the queue by calling linked list add method
template <typename T>
void Queue<T>::enqueue(const T& data)
{

	return list->add(data);

}

//remove items from queue
template <typename T>
void Queue<T>::dequeue()
{   //call the linked list remove method to delete values in a queue
	list->remove();
}

//get all the values in a queue
template <typename T>
LinkedList<T>* Queue<T>::getList() const
{   //call the add method from linked list 
	return list;
}

//overloaded addition operator to concatenate the queues
template <typename T>
Queue<T>& Queue<T>::operator+(const Queue <T>& queue1)
{
	//create queue instance 
	//create linked list instance 
	//concatenate latest queue to the previous 
	Queue<T>* tmpQueue = new Queue<T>();
	LinkedList<T>* tmpList = tmpQueue->getList();
	*tmpList = *this->getList() + *queue1.getList();
	return *tmpQueue;
}

//overloaded assignment operator to copy a linked list onto another
template <typename T>
Queue <T>& Queue<T>::operator=(const Queue <T>& queue1)
{
	//prevent self assignment
	if (this == &queue1)
	{
		return *this;
	}
	//else copy current queue onto the first
	*this->getList() = *queue1.getList();
	return *this;

}

//overloaded extraction operator to input value into queues
template <typename T>
std::istream& operator>> (std::istream& input, Queue<T>& link1)
{   //call linked list overloaded extraction operator 
	std::cin >> *link1.getList();
	return input;
}

//overloaded output operator to print out queues
template <typename T>
std::ostream& operator<<(std::ostream& output, Queue<T>& link1)
{   //call linked list overloaded insertion operator
	std::cout << *link1.getList();
	return output;
};





