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
	// Finds the elevator that can get there the fastest
	Elevator* best_elevator = &elevators[0];
	int best_score = INT_MAX;
	for (int i = 0; i != elevators.size(); i++)
	{
		Elevator& elevator = elevators[i];
		int score = INT_MAX;

		if (elevator.getDirection() == none)
		{
			score = abs(elevator.getFloor() - floor);
		}
		else if (elevator.getDirection() == up && elevator.getFloor() < floor)
		{
			// Elevator going up is below the requested floor
			score = floor - elevator.getFloor();
		}
		else if (elevator.getDirection() == down && elevator.getFloor() > floor)
		{
			// Elevator going down is above the requested floor
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
