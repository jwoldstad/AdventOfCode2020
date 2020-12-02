#include "header.h"
#include "day1.h"


void day1a()
{
	ifstream file("fuel.txt");
	int input = 0;
	int totalFuel = 0;

	while (file >> input)
	{
		totalFuel += ((input / 3) - 2);
	}

	printf("Total fuel is %d\n", totalFuel);

	file.close();

	return;
}

void day1b()
{
	ifstream file("fuel.txt");
	int input = 0;
	int totalFuel = 0;

	//addfuel = 0;

	while (file >> input)
	{
		totalFuel += calculateFuel(input);
	}

	printf("Total fuel is %d\n", totalFuel);

	file.close();

	return;
}

int calculateFuel(int fuel)
{
	int total = ((fuel / 3) - 2);
	if (total <= 0)
		return 0;
	else
		return(total + calculateFuel(total));
}