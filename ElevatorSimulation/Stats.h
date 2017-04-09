#pragma once
#include "User.h"

class Stats
{
public:
	Stats();

	void start();

	void add(const User& user);

	void end() const;

private:
	double sum;
	int count;
};
