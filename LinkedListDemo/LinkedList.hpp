#include "LinkedList.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <iostream>

template <typename T>
//typedef std::string T;

//default constructor no parameters, creates empty linkedlist
LinkedList<T>::LinkedList()
{
	headpointer = NULL;
	listLength = 0;
}

//copy constructor
template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& list1)
{

	headpointer = list1.getHeadPointer();
	listLength = 0;
}


//function to return number of nodes in linked list
template <typename T>
std::size_t LinkedList<T>::length() const
{
	return listLength;
}

//accssor for the head pointer
template <typename T>
Node <T>* LinkedList<T>::getHeadPointer() const
{
	return headpointer;
}

//non const accessor for the head pointer
template <typename T>
Node<T>* LinkedList<T>::getHeadPointer()
{
	return headpointer;
}

//accessor for the tail pointer
template <typename T>
Node<T>* LinkedList<T>::getTailPointer() const
{
	return tailpointer;
}

//non const accessor for the tail pointer
template <typename T>
Node<T>* LinkedList<T>::getTailPointer()
{
	return tailpointer;
}

//destructor  to delete all the nodes when program ends to free memory

template <typename T>
LinkedList<T>::~LinkedList<T>()
{
	//traverse through the list and call the remove method deleting the nodes
	while (headpointer != NULL)
	{

		remove();

	}
}

//delete nodes
template <typename T>
void LinkedList<T>::remove()
{

	//remove node if only 1 node in list
	if (listLength == 1)
	{
		delete headpointer;
		headpointer = NULL;
		listLength--;
		return;
	}
	// remove rest of the nodes from the list if more than one in the list
	else if (listLength > 1)
	{
		//create a temporary node to point to the tail 
		//traverse through the list and set each node to NULL 
		//delete the temporary node and decrement list
		//by each number of nodes deleted 
		Node<T>* tmpNode = getTailPointer();
		tailpointer = tmpNode->getPrevious();
		tailpointer->setNext(NULL);
		delete tmpNode;
		listLength--;
	}

	else
	{
		return;
	}

}
//method to add data to each node
template <typename T>
void LinkedList<T>::add(T& data)
{
	//add first node to empty list
	//create node pointing to head 
	 //list has 1 node and both tail and headpointers point to same node
	if (listLength == 0)
	{

		headpointer = new Node<T>(data);
		listLength = 1;
		tailpointer = headpointer;
	}

	//insert second and subsequent nodes

	else if (listLength >= 1)
	{

		//create a new temporary node on the heap
	   //point it to NUll, making it the lastest node
	   //create node to point to head,traverse the list 
	   //setting each subsequent node with a value
	   //increment list with each new node set 
		Node<T>* tempNode = new Node<T>(data);
		tempNode->setNext(NULL);
		tempNode->setPrevious(getTailPointer());
		Node<T>* lastNode = headpointer;
		while (lastNode->getNext() != NULL)
		{
			lastNode = lastNode->getNext();
		}
		lastNode->setNext(tempNode);
		tailpointer = tempNode;
		listLength++;

		// set temporary node to null for memory management
		tempNode = NULL;
	}

}

//overloaded addition operator to concatenate sequences
template <typename T>
LinkedList<T>& LinkedList<T>::operator+(const LinkedList <T>& list1)
{
	//create new linked list pointer 
	//create two temporary nodes, one pointing to current list,
	//and the next pointing to the previous list
	LinkedList<T>* tmpList = new LinkedList<T>();
	Node<T>* nodeA = this->getHeadPointer();
	Node<T>* nodeB = list1.getHeadPointer();
	//if there are no lists, there is nothing to concatenate exit addition operation
	while (true)
	{
		if (nodeA == NULL && nodeB == NULL)
		{
			break;
		}
		//to concatenate first linked list to itself
		  //get the data for the list and set it
		if (nodeA == NULL && nodeB != NULL)
		{
			T data = nodeB->getData();
			tmpList->add(data);
			nodeB = nodeB->getNext();
		}
		//to concatenate next linked list to itself
		//get the data for the list and set it
		else if (nodeB == NULL && nodeA != NULL)
		{
			T data = nodeA->getData();
			tmpList->add(data);
			nodeA = nodeA->getNext();
		}
		// concatenate two or more linked lists 
		//get data of two or more lists and concatenate them
		 // and return the concatenated list		
		else
		{
			if (*nodeA > *nodeB)
			{
				T data = nodeB->getData();
				tmpList->add(data);
				nodeB = nodeB->getNext();
			}
			else
			{
				T data = nodeA->getData();
				tmpList->add(data);
				nodeA = nodeA->getNext();
			}
		}
	}
	return *tmpList;
}

//overloaded assignment operator to copy a linked list onto another
template <typename T>
LinkedList <T>& LinkedList<T>::operator=(const LinkedList <T>& list1)
{
	//prevent self assignment
	if (this == &list1)
	{
		return *this;
	}

	//create a new node that points to current list 
	//traverse through each node setting the previous list onto the current list
	Node<T>* node = list1.getHeadPointer();
	while (node != NULL)
	{
		T data = node->getData();
		this->add(data);
		node = node->getNext();
	}
	return *this;

}

//overloaded extraction operator to get user input
template <typename T>
std::istream& operator>> (std::istream& input, LinkedList<T>& link1)
{
	//declare string variable to convert input into string 
	//getline works with strings, converting input into string allows full int sequence
	//to be captured
	std::string userLine;
	getline(input, userLine);

	//user input inserted into stringstream and values sent to add method
	T tempString;
	std::istringstream ss(userLine);
	while (ss >> tempString)
	{
		link1.add(tempString);

	}

	//create new node pointer that points to head
	//create another that points to the previous 
	//if the latest node is greater than the previous node continue with next sequence
	//and sort all the sequences
	Node<T>* node = link1.getHeadPointer();
	Node<T>* lastNode = NULL;
	int f = 0;
	while (node != NULL)
	{
		if (lastNode != NULL)
		{
			if (*lastNode > *node)
			{
				f = 1;
				break;
			}

		}
		lastNode = node;
		node = node->getNext();
	}

	//if a new value added to the list is greater than the preceding one,
	//delete the sequence and end the program
	if (f == 1)
	{
		Node<T>* node1 = link1.getHeadPointer();
		node1 = link1.getHeadPointer();

		while (node1 != NULL)
		{

			node1 = node1->getNext();
			link1.remove();
		}

		//lastest sequence is deleted if it is not ordered 
		link1.remove();
		//std::cout<<"Sequence is not ordered.Program will now close.\n";
	}
	return input;


}

//overloaded output operator to print out lists
template <typename T>
std::ostream& operator<<(std::ostream& output, LinkedList<T>& link1)
{
	//create a new  node that points to the head of the current list
	Node<T>* current = link1.getHeadPointer();

	//traverse through the list until reach the last node 
	//which is the one that points to NULL
	while (current != NULL)
	{
		output << current->getData();

		output << " ";

		current = current->getNext();

	}
	output << "\n";

	return output;


}