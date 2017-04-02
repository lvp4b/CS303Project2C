#pragma once
#include <vector>
#include "User.h"

class Simulator
{
public:
	Simulator();
	void simulates();

private:
	void draw(Elevator& elevator, int time);
	std::vector< std::vector<User> > users;
};

