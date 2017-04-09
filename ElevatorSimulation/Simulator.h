#pragma once
#include <vector>
#include "User.h"
#include "MultiElevator.h"
#include "Stats.h"

class Simulator
{
public:
	Simulator(int floors, int elevators, int probability);

	void simulate();

private:
	void checkNewUser();
	void updateFloors();
	std::vector<std::vector<User>> floors;
	int tick;
	MultiElevator elevators;
	Stats stats;
	int probability;
};
