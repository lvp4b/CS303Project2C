#include "Elevator.h"


void Elevator::update()
{
	if (direction == up)
	{
		floor++;
	}
	else if (direction == down)
	{
		floor--;
	}
	else
	{
		return;
	}

	if (states[floor] == empty)
	{
		return;
	}
	states[floor] = empty;

	int count = 0;

	// Count the number of nonempty floors left in this direction
	for (int i = floor; direction == up? i < states.size():i >= 0; direction == down? i--:i++)
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

	for (int i = 0; i < states.size(); i++)
	{
		if (states[i] != empty)
		{
			count++;
		}
	}

	if(count == 0)
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
	states.resize(floor + 1);
	states[floor] = called;
}

