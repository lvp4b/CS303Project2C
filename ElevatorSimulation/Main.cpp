// Lia Vang
// lvp4b@mail.umkc.edu
// CS 303
// April 9, 2017
// Project 2C

#include <iostream>
#include <string>
#include "Simulator.h"

using namespace std;

// Ask user for a positive integer input, and returns it
int prompt(string question)
{
	while (true)
	{
		cout << question << " ";
		int input;
		cin >> input;

		if (input <= 0)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "That's not a valid option" << endl;
			continue;
		}

		return input;
	}
}

int main()
{
	int floors = prompt("How many floors?");
	int elevators = prompt("How many elevators?");
	int probability = prompt("What is the probability 1 in ___ of creating a new user per tick?");
	int maxTicks = prompt("How many ticks to simulate for?");

	// Run simulation
	Simulator(floors, elevators, probability, maxTicks).simulate();

	system("PAUSE");
}
