#include "Simulator.h"
#include "Elevator.h"
#include "User.h"
#include <iostream>
#include <Windows.h>
using namespace std;

const int FLOORS = 25;

Simulator::Simulator() : users(FLOORS)
{
}

void Simulator::draw(Elevator& elevator, int time)
{
	if (elevator.getDirection() == none)
	{
		return;
	}

	for (int i = FLOORS - 1; i >= 0; i--)
	{
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

		for (User user : users[i])
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
	Elevator elevator(FLOORS);

	int time = 0;
	srand(1924859067);

	while (true)
	{
		if(rand() % 4 == 0)
		{
			User user(rand() % FLOORS, rand() % FLOORS, time);
			users[user.getStartingFloor()].push_back(user);
			cout << "Add user to floor " << user.getStartingFloor() << " to " << user.getEndingFloor() << endl;

			elevator.request(user.getStartingFloor());
		}

		time++;

		vector<User> floor = users[elevator.getFloor()];
		users[elevator.getFloor()] = vector<User>();

		for (auto it = floor.begin(); it != floor.end(); ++it)
		{
			it->onOpenElevator(elevator, time);
			if (it->isInElevator())
			{
				users[it->getEndingFloor()].push_back(*it);
				cout << "User's on" << endl;
			}
			else
			{
				cout << it->getWaitTime() << endl;
				cout << "User's off" << endl;
			}
		}

		elevator.update();
		//cout << "Floor: " << elevator.getFloor() << "\tDirection: " << elevator.getDirection() << endl;
		
		draw(elevator, time);
		if (elevator.getDirection() != none) {
			system("PAUSE");
		}
		//Sleep(200);
	}
}
