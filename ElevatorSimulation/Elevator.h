#pragma once
#include <vector>
enum Direction { up, down, none };
enum State { empty, called};

class Elevator
{
public:
	void update();
	void pushedCalledButton(int floor);
	int getFloor() const { return floor; }
	Direction getDirection() const { return direction; }
private:
	int floor;
	Direction direction;
	std::vector<State> states;
};

