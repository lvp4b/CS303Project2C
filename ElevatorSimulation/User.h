#pragma once
#include "Elevator.h"

class User
{
public:
	User(int startFloor, int requestedFloor, int time);
	int getWaitTime() const { return waitTime; }
	void onOpenElevator(Elevator& elevator, int time);

private:
	int waitTime;
	int startTime;
	int startFloor;
	int requestedFloor;
	Elevator* elevator;
};

