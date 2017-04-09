#pragma once
#include <vector>

// Represents a direction
enum Direction { none, up, down };

// Represents the state of a floor
enum State { empty, called };

// Represents an elevator
class Elevator
{
public:
	// Instantiates a new elevator with the specified number of floors
	explicit Elevator(int floors);

	// Updates this elevator's state
	void update();

	// Requests that this elevator visits the specified floor
	void request(int floor);

	// Checks if the doors are open
	bool isDoorOpen() const { return states[floor] == called; }

	// Gets the current floor
	int getFloor() const { return floor; }

	// Gets the direction of travel of this elevator
	Direction getDirection() const { return direction; }

private:
	int floor;
	Direction direction;
	std::vector<State> states;
};

