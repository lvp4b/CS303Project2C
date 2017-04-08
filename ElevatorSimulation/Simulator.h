#pragma once
#include <vector>
#include "MultiElevator.h"
#include "User.h"

class Simulator
{
public:
	Simulator();
	void simulates();

private:
	void draw(MultiElevator& elevators, int time);
	std::vector<std::vector<User>> floors;
};

