#include "Elevator.h"
#include <Windows.h>
#include <iostream>
#include "User.h"
using namespace std;

int main()
{
	Elevator elevator(10);
	elevator.request(8);

	User user(6, 2, 0);
	int time = 0;

	while(true)
	{
		time++;
		user.onOpenElevator(elevator, time);
		elevator.update();
		cout << elevator.getFloor() << " " << elevator.getDirection() << endl;
		cout << user.getWaitTime() << endl;

		Sleep(250);
	}
}
