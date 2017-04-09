#pragma once
#include <vector>
#include "User.h"
#include "MultiElevator.h"
#include "Stats.h"

// Represent a simulator
class Simulator
{
public:
	// Instantiates a new simulator with the specified parameters
	Simulator(int floors, int elevators, int probability, int maxTicks);

	// Runs the simulation
	void simulate();

private:
	// Checks if a new user needs to be created
	void checkNewUser();

	// Updates the floors data structure
	void updateFloors();

	std::vector<std::vector<User>> floors;
	int tick;
	MultiElevator elevators;
	Stats stats;
	int probability;
	int maxTicks;
};
