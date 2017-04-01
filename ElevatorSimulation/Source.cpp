#include "Elevator.h"
#include <Windows.h>
#include <iostream>

int main()
{
	Elevator elevator;
	elevator.request(3);
	while(true)
	{
		elevator.update();
		std::cout << elevator.getFloor() << " " << elevator.getDirection() << std::endl;
		Sleep(250);
	}
}