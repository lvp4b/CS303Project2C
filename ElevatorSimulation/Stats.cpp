#include "Stats.h"
#include <iostream>

using namespace std;

Stats::Stats()
{
	sum = 0;
	count = 0;
}

void Stats::start()
{
	cout << "Pick up\t" << "Destination\t" << "Time" << endl;
	cout << "-----------------------------------------------------------" << endl;
}

void Stats::add(const User& user)
{
	cout << user.getStartingFloor() << "\t" << user.getEndingFloor() << "\t\t" << user.getWaitTime() << endl;
	sum += user.getWaitTime();
	count++;
}

void Stats::end() const
{
	cout << "Average time per person: " << sum / count << endl;
}
