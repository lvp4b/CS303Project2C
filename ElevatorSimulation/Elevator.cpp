#include "Elevator.h"

Elevator::Elevator(int floors) : floor(0), direction(none), states(floors)
{
}

void Elevator::update()
{
	states[floor] = empty;

	// Moves the elevator
	switch (direction)
	{
	case up:
		floor++;
		break;
	case down:
		floor--;
		break;
	default:
		return;
	}

	if (states[floor] == empty)
	{
		// Elevator doors don't need to open
		return;
	}

	int count = -1;

	// Counts the number of nonempty floors left in this direction
	for (int i = floor; direction == up ? i < states.size() : i >= 0; direction == down ? i-- : i++)
	{
		if (states[i] != empty)
		{
			count++;
		}
	}

	if (count > 0)
	{
		// Elevator doesn't need to stop
		return;
	}

	// Counts how many floors are left to visit
	count = -1;
	for (int i = 0; i < states.size(); i++)
	{
		if (states[i] != empty)
		{
			count++;
		}
	}

	// Checks if the elevator needs to stop or switch direction
	if (count == 0)
	{
		direction = none;
	}
	else
	{
		direction = direction == up ? down : up;
	}
}

void Elevator::request(int floor)
{
	states[floor] = called;

	if (direction != none)
	{
		// Elevators that are already traveling don't switch directions
		return;
	}

	if (this->floor > floor)
	{
		direction = down;
	}
	else if (this->floor < floor)
	{
		direction = up;
	}
}
