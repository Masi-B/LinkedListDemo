// LinkedListDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <string>
#include <cstdlib>
#include <iostream>
#include <cassert>
#include "Queue.h"


int main()
{
	//Four instances of queue instantiated, three for input and one for the output
	Queue<std::string>* queue1 = new Queue<std::string>();
	Queue<std::string>* queue2 = new Queue<std::string>();
	Queue<std::string>* queue3 = new Queue<std::string>();
	Queue<std::string>* queue4 = new Queue<std::string>();

	//User is prompted to enter 3 sequences   
	std::cout << "Please enter three sequences: \n";
	std::cout << "Enter sequence 1: ";
	std::cin >> *queue1;

	//continue to the next sequence if the previous sequence is ordered
	std::cout << "Enter sequence 2: ";
	std::cin >> *queue2;

	//continue to the next sequence if the previous sequence is ordered
	std::cout << "Enter sequence 3: ";
	std::cin >> *queue3;

	//stop the program without sorting the lists if at least one of the sequences is not ordered
	//the user is notified which sequences are not ordered 
	//if Sequence 1 and any other are not ordered notify user and stop program
	if (queue1->isEmpty())
	{
		std::cout << "\nSequence 1 is not ordered\n";

		if (queue2->isEmpty())
		{
			std::cout << "Sequence 2 is not ordered\n";

			if (queue3->isEmpty())
			{
				std::cout << "Sequence 3 is not ordered\n";
			}
		}
		return 0;
	}
	//if only sequence 2 and 3 not ordered notify user and stop program
	else if (queue2->isEmpty())
	{
		std::cout << "\nSequence 2 is not ordered\n";

		if (queue3->isEmpty())
		{
			std::cout << "Sequence 3 is not ordered\n";
		}
		return 0;
	}
	//if only sequence 3 is not ordered notify user and stop program
	else if (queue3->isEmpty())
	{
		std::cout << "\nSequence 3 is not ordered\n";
		return 0;
	}


	//concatenate all three sequences if they are all ordered 
	//and sort them in alphabetical order or lowest to highest 
	std::cout << "\n";
	*queue4 = *queue1 + *queue2 + *queue3;
	std::cout << *queue4;


	//free memory by using delete to prevent memory leaks
	//all pointer instances of Queue must be deleted after they have been used
	delete queue1;
	delete queue2;
	delete queue3;
	delete queue4;

	return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
