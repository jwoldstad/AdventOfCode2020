#include "Header.h"

void day2a()
{
	ifstream file("day2a.txt");

	string input;
	bool goodPassword;
	int counter = 0;

	while(file.good())
	{ 
		
		getline(file, input);
		goodPassword = checkPassword(input);
		if (goodPassword == true)
		{
			counter++;
		}
		
	}
	cout << "The number of good passwords is " << counter << endl;
	file.close();
}

bool checkPassword(string input)
{
	bool goodPassword;
	int counter = 0, min = 0, max = 0;
	char character;

	string firstHalf, password;

	firstHalf = input.substr(0, input.find(':'));
	password = input.substr(input.find(':') + 2, input.length() - 1);
	min = stoi(firstHalf.substr(0, firstHalf.find('-')));
	max = stoi(firstHalf.substr(firstHalf.find('-') + 1, firstHalf.find(' ')));
	character = firstHalf[firstHalf.length() - 1];
	for (int i = 0; i < password.length(); i++)
	{
		if (password[i] == character)
		{
			counter++;
		}
	}

	if (counter >= min && counter <= max)
	{
		goodPassword = true;
	}
	else {
		goodPassword = false;
	}

	return goodPassword;
}

void day2b()
{
	ifstream file("day2a.txt");

	string input;
	bool goodPassword;
	int counter = 0;

	while (file.good())
	{

		getline(file, input);
		goodPassword = checkPasswordb(input);
		if (goodPassword == true)
		{
			counter++;
		}

	}
	cout << "The number of good passwords is " << counter << endl;
	file.close();
}

bool checkPasswordb(string input)
{
	bool goodPassword;
	int checker = -1, first = 0, second = 0;
	char character;

	string firstHalf, password;

	firstHalf = input.substr(0, input.find(':'));
	password = input.substr(input.find(':') + 2, input.length() - 1);
	first = stoi(firstHalf.substr(0, firstHalf.find('-')));
	second = stoi(firstHalf.substr(firstHalf.find('-') + 1, firstHalf.find(' ')));
	character = firstHalf[firstHalf.length() - 1];

	if (character == password[first-1])
	{
		checker *= -1;
	}
	if (character == password[second-1])
	{
		checker *= -1;
	}

	if(checker == 1)
	{
		goodPassword = true;
	}
	else {
		goodPassword = false;
	}

	return goodPassword;
}