#include "Simulator.h"
#include "Elevator.h"
#include "User.h"
#include "MultiElevator.h"
#include "Stats.h"
#include <iostream>

using namespace std;

Simulator::Simulator(int floors, int elevators, int probability, int maxTicks) : elevators(floors, elevators)
{
	this->floors = vector<vector<User>>(floors);
	tick = 0;
	this->probability = probability;
	this->maxTicks = maxTicks;
}

void Simulator::simulate()
{
	stats.start();

	tick = 0;
	while (tick < maxTicks)
	{
		checkNewUser();
		tick++;
		updateFloors();
		elevators.update();
	}

	stats.end();
}

void Simulator::checkNewUser()
{
	// 1 in probability chance of creating a new user
	if (rand() % probability != 0)
	{
		return;
	}

	// Randomly determine where the user is going
	int startingFloor;
	int requestedFloor;
	switch (rand() % 3)
	{
	case 0:
		// User goes from ground floor to another floor
		startingFloor = 0;
		requestedFloor = rand() % (floors.size() - 1) + 1;
		break;
	case 1:
		// User is going to ground floor
		startingFloor = rand() % (floors.size() - 1) + 1;
		requestedFloor = 0;
		break;
	default:
		// User is traveling between floors
		startingFloor = rand() % floors.size();
		requestedFloor = rand() % (floors.size() - 1);
		if (startingFloor == requestedFloor)
		{
			requestedFloor++;
		}
		break;
	}

	// Creates a new user and calls an elevator to them
	User user(startingFloor, requestedFloor, tick);
	floors[user.getStartingFloor()].push_back(user);
	elevators.request(user.getStartingFloor());
}

void Simulator::updateFloors()
{
	for (int i = 0; i != elevators.size(); i++)
	{
		Elevator& elevator = elevators[i];

		if (!elevator.isDoorOpen())
		{
			// Elevator doesn't change where users are
			continue;
		}

		vector<User> floor = floors[elevator.getFloor()];
		floors[elevator.getFloor()] = vector<User>();

		// Tell each user on the floor that an elevator is open
		for (auto user = floor.begin(); user != floor.end(); ++user)
		{
			user->onOpenElevator(elevator, tick);
			if (user->isInElevator())
			{
				// Moves user to their ending floor
				floors[user->getEndingFloor()].push_back(*user);
			}
			else
			{
				// User has left the elevator
				stats.add(*user);
			}
		}
	}
}
