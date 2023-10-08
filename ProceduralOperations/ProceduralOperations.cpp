// ProceduralOperations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "stdfh.h"


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
	if(drewNumbers.size()<2) return;// shouldnt be a case but better add this than be sorry
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
	if (endV - halflenght <=0)
	{
		return;
	}
	std::vector<int> VectorL (drewNumbers), VectorR;
	VectorL.resize(halflenght);
	std::copy(drewNumbers.begin()+ halflenght , drewNumbers.end(), std::back_inserter(VectorR));


	if (VectorL.size() > 1)
	{
		sortMerge(VectorL, beginingV, VectorL.size()-1);
	}
	if (VectorR.size() > 1)
	{
		sortMerge(VectorR, beginingV, VectorR.size()-1);
	}
	std::vector <int> tmpVector;
	tmpVector.clear();
	int j = 0;
	for (int i = 0; i < VectorL.size(); i++)
	{
		for (; j < VectorR.size(); j++)
		{
			if (VectorL[i] >= VectorR[j])
			{
				tmpVector.push_back(VectorR[j]);
			}
			else
			{
				tmpVector.push_back(VectorL[i]);
				break;
			}
		}
		if (j == VectorR.size())
		{
			tmpVector.push_back(VectorL[i]); //if left vector is biger than right one
		}

	}
	//VectorR.erase(drewNumbers.begin(),halflenght);
	for (int i = 0; i < tmpVector.size(); i++)
	{
		drewNumbers[beginingV + i] = tmpVector[i];
	}

	int x;
}

void display(std::vector<int>& drewNumbers)
{
	for (auto& y : drewNumbers)
	{
		std::cout << y << "\n";
	}
}
int main()
{
	srand(time(NULL));
	std::vector<int> numbersVector;// = NULL;
	
	drawNumbers(numbersVector, 30);
	display(numbersVector);

	char userAnswear;
	bool exitLoop = true;
	do
	{
		std::cout << "\n\n\tDo you want to add more numbers? \n\n\t 1 - randomize another 10 numbers\n\t 2 declare will to give your set of numbers\n\t 3 -exit\n\n\n";
		std::cin.get(userAnswear);
		switch (userAnswear)
		{
		case '1':
		{
			drawNumbers(numbersVector, 10);
			display(numbersVector);
			break;
		}
		case '2':
		{
			//takeUserNumbers();
			display(numbersVector);
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


	} while(!exitLoop);

	sortMerge(numbersVector, 0, numbersVector.size());
	display(numbersVector);
	int i;
}
