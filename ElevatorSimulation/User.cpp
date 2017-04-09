#include "User.h"

User::User(int startFloor, int requestedFloor, int time): waitTime(0)
{
	this->startFloor = startFloor;
	this->requestedFloor = requestedFloor;
	startTime = time;
	elevator = nullptr;
}

void User::onOpenElevator(Elevator& elevator, int time)
{
	if (this->elevator == nullptr)
	{
		if (elevator.getFloor() == startFloor)
		{
			this->elevator = &elevator;
			elevator.request(requestedFloor);
		}
	}
	else if (this->elevator == &elevator)
	{
		if (elevator.getFloor() == requestedFloor)
		{
			this->elevator = nullptr;
			waitTime = time - startTime;
		}
	}
}
