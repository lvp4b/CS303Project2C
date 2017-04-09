#pragma once
#include "User.h"

// Represents user statistics
class Stats
{
public:
	// Instantiates a new statistics class
	Stats();

	// Start collecting statistics
	void start();

	// Updates statistics by adding a user that reached their destination
	void add(const User& user);

	// Prints a summary of the gathered statistics
	void end() const;

private:
	double sum;
	int count;
};
