#pragma once
#include "Elevator.h"

// Represents multiple elevators 
class MultiElevator
{
public:
	// Instantiates multiple elevators with the specified number of floors
	MultiElevator(int floors, int elevators);

	// Updates all of the elevators
	void update();

	// Requests that an elevator visits the specified floor
	void request(int floor);

	// Gets the number of elevators
	int size() const { return elevators.size(); }

	// Gets the specified elevators
	Elevator& operator[] (int index) { return elevators[index]; }

private:
	std::vector<Elevator> elevators;
};
