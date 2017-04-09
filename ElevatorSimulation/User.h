#pragma once
#include "Elevator.h"

class User
{
public:
	User(int startFloor, int requestedFloor, int time);

	int getWaitTime() const { return waitTime; }

	void onOpenElevator(Elevator& elevator, int time);

	int getStartingFloor() const { return startFloor; }

	int getEndingFloor() const { return requestedFloor; }

	bool isInElevator() const { return elevator != nullptr; }

private:
	int waitTime;
	int startTime;
	int startFloor;
	int requestedFloor;
	Elevator* elevator;
};
