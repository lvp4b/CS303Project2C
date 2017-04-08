#pragma once
#include <vector>

// Represents a direction
enum Direction { none, up, down };

// Represents the state of a floor
enum State { empty, called};

// Represents an elevator
class Elevator
{
public:
	explicit Elevator(int floors);

	// Updates this elevator
	void update();

	// Request this elevator to visit the specified floor
	void request(int floor);

	// Checks if the doors are open
	bool isDoorOpen() const { return states[floor] == called; }

	// Get the current floor
	int getFloor() const { return floor; }

	// Get the direction of travel of this elevator
	Direction getDirection() const { return direction; }

private:
	int floor;
	Direction direction;
	std::vector<State> states;
};

