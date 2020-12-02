void day1a()
{
	ifstream file("day1a.txt");

	vector<int> listOfNumbers;
	int input = 0, i = 0, j = 0, combined = 0;
	while (file >> input)
	{
		listOfNumbers.push_back(input);
	}

	sort(listOfNumbers.begin(), listOfNumbers.end());

	i = 0;
	j = listOfNumbers.size() - 1;
	//have trackers at beginning and end
	//if value is too big, move end value one closer to middle
	//if value is too small, move begin value one closer to middle
	while (i < j)
	{
		combined = listOfNumbers[i] + listOfNumbers[j];
		if (combined < 2020)
		{
			i++;
		}
		else if (combined > 2020)
		{
			j--;
		}
		if (combined == 2020)
		{
			cout << "i =" << listOfNumbers[i] << " j =" << listOfNumbers[j] << endl;
			break;
		}
	}
	cout << endl << listOfNumbers[i] * listOfNumbers[j];
	file.close();
}

void day1b()
{
	ifstream file("day1a.txt");

	vector<int> listOfNumbers;
	int input = 0, i = 0, j = 0, k = 0, combined = 0, goal = 0;
	bool escape = false;
	while (file >> input)
	{
		listOfNumbers.push_back(input);
	}
	sort(listOfNumbers.begin(), listOfNumbers.end());


	k = listOfNumbers.size() - 1;
	for (i = 0; i < listOfNumbers.size(); i++)
	{
		cout << listOfNumbers[i] << endl;
	}
	while (k != 0)
	{
		i = 0; 
		j = 1;
		goal = 2020 - listOfNumbers[k];
		if ((listOfNumbers[i] + listOfNumbers[j]) <= goal)
		{
			while (listOfNumbers[j] < goal)
			{
				j++;

			}
			while (i < j)
			{
				
				
				combined = listOfNumbers[i] + listOfNumbers[j];

				if (combined < goal)
				{
					i++;
				}
				else if (combined > goal)
				{
					j--;
				}
				if (combined == goal)
				{
					cout << "i =" << listOfNumbers[i] << " j =" << listOfNumbers[j] << " k =" << listOfNumbers[k] << endl;
					cout << "multiplied together the answer is " << listOfNumbers[i] * listOfNumbers[j] * listOfNumbers[k] << endl;
					escape = true;
					break;
				}
			}
		}
		if (escape == true)
		{
			break;
		}

		k--;
		
	}
}
