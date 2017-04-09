#include "User.h"

User::User(int startFloor, int requestedFloor, int time) : waitTime(0)
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
		// User isn't in an elevator		
		this->elevator = &elevator;
		elevator.request(requestedFloor);
	}
	else if (this->elevator == &elevator)
	{
		// User reached their destination		
		this->elevator = nullptr;
		waitTime = time - startTime;
	}
}
