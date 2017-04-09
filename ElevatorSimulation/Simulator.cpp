#include "Simulator.h"
#include "Elevator.h"
#include "User.h"
#include "MultiElevator.h"
#include "Stats.h"
#include <iostream>

using namespace std;

Simulator::Simulator(int floors, int elevators, int probability) : floors(floors), elevators(floors, elevators)
{
	tick = 0;
	this->probability = probability;
}

void Simulator::simulate()
{
	stats.start();

	tick = 0;
	while (tick < 10000)
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
	if (rand() % probability != 0)
	{
		return;
	}

	int startingFloor;
	int requestedFloor;

	switch (rand() % 3)
	{
	case 0:
		startingFloor = 0;
		requestedFloor = rand() % (floors.size() - 1) + 1;
		break;
	case 1:
		startingFloor = rand() % (floors.size() - 1) + 1;
		requestedFloor = 0;
		break;
	default:
		startingFloor = rand() % floors.size();
		requestedFloor = rand() % (floors.size() - 1);
		if (startingFloor == requestedFloor)
		{
			requestedFloor++;
		}
		break;
	}

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
			continue;
		}

		vector<User> floor = floors[elevator.getFloor()];
		floors[elevator.getFloor()] = vector<User>();

		for (auto user = floor.begin(); user != floor.end(); ++user)
		{
			user->onOpenElevator(elevator, tick);
			if (user->isInElevator())
			{
				floors[user->getEndingFloor()].push_back(*user);
			}
			else
			{
				stats.add(*user);
			}
		}
	}
}
