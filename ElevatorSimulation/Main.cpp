#include <iostream>
#include "Simulator.h"
using namespace std;

int main()
{
	srand(1924859067);

	Simulator(8, 8, 10).simulate();

	system("PAUSE");
}
