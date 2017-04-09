#include <iostream>
#include <string>
#include "Simulator.h"
using namespace std;

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
	srand(1924859067);

	int floors = prompt("How many floors?");
	int elevators = prompt("How many elevators?");
	int probability = prompt("What is the probability 1 in ___ of creating a new user per tick?");
	int maxTicks = prompt("How many ticks to simulate for?");

	Simulator(floors, elevators, probability, maxTicks).simulate();

	system("PAUSE");
}
