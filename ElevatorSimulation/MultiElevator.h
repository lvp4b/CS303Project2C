#pragma once
#include "Elevator.h"

class MultiElevator
{
public:
	MultiElevator(int floors, int elevators);

	// Updates this elevator
	void update();

	// Request this elevator to visit the specified floor
	void request(int floor);

	int size() const { return elevators.size(); }

	Elevator& operator[] (int index) { return elevators[index]; }

private:
	std::vector<Elevator> elevators;
};
