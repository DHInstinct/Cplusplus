#pragma once

#include <iostream>
#include <time.h>
#include <random>
#include <vector>

using namespace std;

class Lottery
{
private:

	int size = 5;
	int rangeOfNums = 31;
	bool isWin;
	
public:

	void Play(vector<int> vec, vector<int> vec2)
	{
		int totalRunCounter = 0;
		do
		{
			totalRunCounter++;
			SetCompVecNums(vec, GetSize(), GetRangeOfNums());
			DisplayVec(vec);
			SetUserVecNums(vec2, GetSize(), GetRangeOfNums());
			GetResult(vec, vec2);
			cout << "Attempt: " << totalRunCounter << endl;
		} while (isWin == false);
	}

	void PlayComp(vector<int> vec, vector<int> vec2)
	{
		int totalRunCounter = 0;
		do
		{
			totalRunCounter++;
			SetCompVecNums(vec, GetSize(), GetRangeOfNums());
			DisplayVec(vec);
			SetCompVecNums(vec2, GetSize(), GetRangeOfNums());
			GetResult(vec, vec2);
			cout << "Attempt: " << totalRunCounter << endl;
		} while (isWin == false);
	}

	bool GetIsWin() const
	{
		return isWin;
	}

	void SetRangeOfNums(int newRange)
	{
		 rangeOfNums = newRange;
	}

	void SetSize(int newSize)
	{
		 size = newSize;
	}

	int GetRangeOfNums() const
	{
		return rangeOfNums;
	}

	int GetSize() const
	{
		return size;
	}

	void DisplayVec(vector<int> &vec)
	{
		for (int i = 0; i < vec.size(); ++i)
			cout << vec[i] << ", ";
		cout << endl;
	}

	void SetUserVecNums(vector<int> &vec, int size = 5, int rangeOfNums = 31)
	{
		cout << "Please enter " << size << " numbers and I will tell you if you win! " << endl;

		vec.clear();

			for (int i = 0; i < size; ++i) //Setting vector numbers 
			{
				int userChoice;
				cin >> userChoice;
				vec.emplace_back(userChoice);
			}
			
		sort(vec.begin(), vec.end()); // Sorting numbers
	}
	
	void SetCompVecNums(vector<int> &vec, int size = 5, int rangeOfNums = 31)
	{
		//Placing numbers into Vector. Default Range: 0 - 30
		for (int i = 0; i < rangeOfNums; ++i)
		{
			vec.emplace_back(i);
		}
		//randomly shuffling numbers
		random_shuffle(vec.begin(), vec.end());
		//resizing how ever much is specified. Default size: 5
		vec.resize(size);
		//Sort Winning numbers from smallest to largest
		sort(vec.begin(), vec.end());
	}

	void GetResult(vector<int> &vec1, vector<int> &vec2) 
	{
		int runCounter = 0;
		int winCounter = 0;
		int loseCounter = 0;
		
		for (int i = 0; i < vec1.size(); ++i)
		{
			runCounter++;

			if (vec1[i] == vec2[i])
			{
				winCounter++;
				if (winCounter >= vec1.size())
				{
					cout << "You Win!" << endl;
					isWin = true;
					break;
				}
			}
			if (vec1[i] != vec2[i])
			{
				loseCounter++;
				if (loseCounter >= 1)
				{
					loseCounter = 0;
					isWin = false;
					cout << "You Lose! Please Try again" << endl;
					break;
				}
			}
		}
	}
};