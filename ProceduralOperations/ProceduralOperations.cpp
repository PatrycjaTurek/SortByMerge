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
			tmpVector.push_back(VectorL[i]);
		}

	}
	//VectorR.erase(drewNumbers.begin(),halflenght);
	for (int i = 0; i < tmpVector.size(); i++)
	{
		drewNumbers[beginingV + i] = tmpVector[i];
	}

	int x;
}

int main()
{
	srand(time(NULL));
	std::vector<int> numbersVector;// = NULL;
	
	drawNumbers(numbersVector, 10);//rand()%51 + 100); //draw 100-150 numbers

	sortMerge(numbersVector, 0, numbersVector.size());
	int i;
}
