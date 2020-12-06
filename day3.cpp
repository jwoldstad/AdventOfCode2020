#include "Header.h"

void day3a()
{
	ifstream file("day3a.txt");

	vector<string> treeMap;
	string input;
	int mapLength = 0;
	int rightMove = 0;
	int treesHit = 0;
	while (file >> input)
	{
		treeMap.push_back(input);
	}
	mapLength = treeMap[0].length() - 1;


	for (int i = 0; i < treeMap.size(); i++)
	{
		char temp = treeMap[i][rightMove];
		treeMap[i][rightMove] = 'O';
		

		if (temp == '#')
		{
			treesHit++;
			treeMap[i][rightMove] = 'X';

		}
		cout << treeMap[i] << endl;
		rightMove += 3;
		if (rightMove > mapLength)
		{
			rightMove = (rightMove % mapLength) -1;
		}

	}

	cout << "There have been " << treesHit << " trees hit" << endl;
}

void day3b()
{
	unsigned long int solution = 1;

	solution *= checkTreeHits(1, 1);
	solution *= checkTreeHits(3, 1);
	solution *= checkTreeHits(5, 1);
	solution *= checkTreeHits(7, 1);
	solution *= checkTreeHits(1, 2);

	cout << "The solution is " << solution << endl;
}

int checkTreeHits(int right, int down)
{
	ifstream file("day3a.txt");

	vector<string> treeMap;
	string input;
	int mapLength = 0;
	int rightMove = 0;
	int treesHit = 0;
	while (file >> input)
	{
		treeMap.push_back(input);
	}
	mapLength = treeMap[0].length() - 1;


	for (int i = 0; i < treeMap.size(); i+= down)
	{
		char temp = treeMap[i][rightMove];
		treeMap[i][rightMove] = 'O';


		if (temp == '#')
		{
			treesHit++;
			treeMap[i][rightMove] = 'X';

		}
		//cout << i << "\t" << treeMap[i] << endl;
		rightMove += right;
		if (rightMove > mapLength)
		{
			rightMove = (rightMove % mapLength) - 1;
		}

	}

	cout << "There have been " << treesHit << " trees hit" << endl;

	file.close();

	return treesHit;
}