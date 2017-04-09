#include "MultiElevator.h"

MultiElevator::MultiElevator(int floors, int elevators)
{
	for (int i = 0; i != elevators; i++)
	{
		this->elevators.push_back(Elevator(floors));
	}
}

void MultiElevator::update()
{
	#pragma omp parallel for
	for (int i = 0; i < static_cast<int>(elevators.size()); i++)
	{
		elevators[i].update();
	}
}

void MultiElevator::request(int floor)
{
	Elevator* best_elevator = &elevators[0];
	int best_score = 0x7FFFFFFF;

	for (int i = 0; i != elevators.size(); i++)
	{
		Elevator& elevator = elevators[i];
		int score = 0x7FFFFFFF;

		if (elevator.getDirection() == none)
		{
			score = abs(elevator.getFloor() - floor);
		}
		else if (elevator.getDirection() == up && elevator.getFloor() < floor)
		{
			score = floor - elevator.getFloor();
		}
		else if (elevator.getDirection() == down && elevator.getFloor() > floor)
		{
			score = elevator.getFloor() - floor;
		}

		if (score < best_score)
		{
			best_elevator = &elevator;
			best_score = score;
		}
	}

	best_elevator->request(floor);
}
