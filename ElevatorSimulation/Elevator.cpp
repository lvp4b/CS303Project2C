#include "Elevator.h"

Elevator::Elevator(int floors) : floor(0), direction(none), states(floors)
{
}

void Elevator::update()
{
	states[floor] = empty;

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
		return;
	}

	int count = -1;

	// Count the number of nonempty floors left in this direction
	for (int i = floor; direction == up ? i < states.size() : i >= 0; direction == down ? i-- : i++)
	{
		if (states[i] != empty)
		{
			count++;
		}
	}

	if (count > 0)
	{
		return;
	}

	count = -1;
	for (int i = 0; i < states.size(); i++)
	{
		if (states[i] != empty)
		{
			count++;
		}
	}

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
