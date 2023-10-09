// ProceduralOperations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "stdfh.h"


void display(std::vector<int>& drewNumbers)
{
	std::cout << "\n\n";
	for (auto& y : drewNumbers)
	{
		std::cout << "\t" << y << "\n";
	}
	std::cout << "\n\n";
}
void drawNumbers(std::vector<int> &drewNumbers, int howMany) 
{
	if (drewNumbers.empty())
	{
		drewNumbers.clear();
	}
	double tmp;
	for (int i = 0; i < howMany; i++)
	{
		tmp = (rand()%10000) -5000;
		drewNumbers.push_back(tmp); //to change to 2 digits after comma
	}
}

void sortMerge(std::vector<int> &drewNumbers, int beginingV, int endV) // re_merge if it's time to re-merge "subvectors"
{

	//if(drewNumbers.size()<2) return;// shouldnt be a case but better add this than be sorry
	if(drewNumbers.size() == 2)
	{
		if (drewNumbers[0] > drewNumbers[1])
		{
			int tmp = drewNumbers[0];
			drewNumbers[0] = drewNumbers[1];
			drewNumbers[1] = tmp;
		}
		return;
	}
	int halflenght = floor((endV) / 2);

	std::vector<int> VectorL (drewNumbers), VectorR;
	VectorL.resize(halflenght);
	std::copy(drewNumbers.begin()+ halflenght , drewNumbers.end(), std::back_inserter(VectorR));


	if (VectorL.size() > 1)
	{
		sortMerge(VectorL, beginingV, VectorL.size());
	}
	if (VectorR.size() > 1)
	{
		sortMerge(VectorR, beginingV, VectorR.size());
	}
	std::vector <int> tmpVector;
	tmpVector.clear();
	int j = 0, i =0;
	while (true)
	{	
		if (i >= VectorL.size())
		{
			while (j<VectorR.size())
			{
				tmpVector.push_back(VectorR[j]);
				j++;
			}
			break;
		}
		else if (j >= VectorR.size())
		{
			while (i < VectorL.size())
			{
				tmpVector.push_back(VectorL[i]);
				i++;
			}
			break;
		}
		else if(VectorL[i] < VectorR[j])
		{
			tmpVector.push_back(VectorL[i]);
			i++;
		}
		else
		{
			tmpVector.push_back(VectorR[j]);
			j++;
		}


	}

	for (int i = 0; i < tmpVector.size(); i++)
	{
		drewNumbers[beginingV + i] = tmpVector[i];
	}

}
bool isNOTIntegrer(std::string stringToCheck)
{
	for (int i =0 ;i<stringToCheck.size();i++)
	{
		if (!isdigit(stringToCheck[i]))
		{
			return true;
		}
	}
	return false;
}
void takeUserNumbers(std::vector<int>& drewNumbers)
{
	std::cout << "Enter number(one integrer). In case You don't want to gave another number enter anything but number\n";
	std::string usernumber;

	while (true)
	{
		std::cin >> usernumber;
		if (isNOTIntegrer(usernumber))
		{
			break;
		}
		drewNumbers.push_back(atoi(usernumber.c_str()));
	}

	std::cout << "\tNumberers have been added\n\n";
}

void displayMenu(std::vector<int>& drewNumbers)
{
	char userAnswear;
	bool exitLoop = true;
	do
	{
		std::cout << "\n\n\tDo you want to add more numbers? \n\n\t 1 - randomize another 10 numbers and start sorting\n\t 2 enter your set of numbers\n\t 3 -exit\n\n\n";
		std::cin.get(userAnswear);
		switch (userAnswear)
		{
		case '1':
		{
			drawNumbers(drewNumbers, 10);
			display(drewNumbers);
			break;
		}
		case '2':
		{
			takeUserNumbers(drewNumbers);
			display(drewNumbers);
			break;
		}
		case '3':
		{
			break;
		}
		default:
		{
			exitLoop = false;
			std::cout << "Answear invalid.\n\tTry Again";
			break;
		}
		}
		std::cin.clear(); //to clear cin buffer in case user use key when operation was done;

	} while (!exitLoop);
}
int main()
{
	srand(time(NULL));
	std::vector<int> numbersVector;// = NULL;
	
	drawNumbers(numbersVector, 60);
	display(numbersVector);

	displayMenu(numbersVector);

	sortMerge(numbersVector, 0, numbersVector.size());
	display(numbersVector);
	int i;
}
