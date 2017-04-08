#include "Simulator.h"
#include "Elevator.h"
#include "User.h"
#include <iostream>
#include "MultiElevator.h"
using namespace std;

const int FLOORS = 25;

Simulator::Simulator() : floors(FLOORS)
{
}

void Simulator::draw(MultiElevator& elevators, int time)
{
	for (int i = FLOORS - 1; i >= 0; i--)
	{
		for (int j = 0; j != elevators.size(); j++)
		{
			Elevator& elevator = elevators[j];
			if (i == elevator.getFloor())
			{
				cout << "# " << (elevator.getDirection() == up ? "/\\" :
					elevator.getDirection() == down ? "\\/" : "  ") <<
					" # ";
			}
			else
			{
				cout << "|    | ";
			}
		}

		for (User user : floors[i])
		{
			if (user.isInElevator()) {
				cout << user.getStartingFloor() << "=> " << time - user.getStartTime() << ", ";
			}
			else
			{
				cout << "<=" << user.getEndingFloor() << " " << time - user.getStartTime() << ", ";
			}
		}
		cout << endl;
	}
	cout << endl;
}

void Simulator::simulates()
{
	MultiElevator elevators(FLOORS, 6);

	int time = 0;
	srand(1924859067);

	while (true)
	{
		if(rand() % 4 == 0)
		{
			int startingFloor;
			int requestedFloor;

			switch (rand() % 3)
			{
				case 0:
					startingFloor = 0;
					requestedFloor = rand() % (FLOORS - 1) + 1;
					break;
				case 1:
					startingFloor = rand() % (FLOORS - 1) + 1;
					requestedFloor = 0;
					break;
				default:
					startingFloor = rand() % FLOORS;
					requestedFloor = rand() % (FLOORS - 1);
					if (startingFloor == requestedFloor)
					{
						requestedFloor++;
					}
					break;
			}
			User user(startingFloor, requestedFloor, time);
			floors[user.getStartingFloor()].push_back(user);
			cout << "Add user to floor " << user.getStartingFloor() << " to " << user.getEndingFloor() << endl;
			
			elevators.request(user.getStartingFloor());
		}

		time++;

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
				user->onOpenElevator(elevator, time);
				if (user->isInElevator())
				{
					floors[user->getEndingFloor()].push_back(*user);
					cout << "User's on" << endl;
				}
				else
				{
					cout << user->getWaitTime() << endl;
					cout << "User's off" << endl;
				}
			}
		}

		elevators.update();
		
		draw(elevators, time);
		system("PAUSE");
	}
}
