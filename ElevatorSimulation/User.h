#pragma once
#include "Elevator.h"

// Represents a user
class User
{
public:
	// Instantiates a new user with the specified parameters
	User(int startFloor, int requestedFloor, int time);

	// Gets the time the user waited to get to their destination
	int getWaitTime() const { return waitTime; }

	// Called when the specified elevator opens on this user's floor
	void onOpenElevator(Elevator& elevator, int time);

	// Gets the floor the user starts on
	int getStartingFloor() const { return startFloor; }

	// Gets the destination floor the user ends on
	int getEndingFloor() const { return requestedFloor; }

	// Checks if the user is in an elevator
	bool isInElevator() const { return elevator != nullptr; }

private:
	int waitTime;
	int startTime;
	int startFloor;
	int requestedFloor;
	Elevator* elevator;
};
