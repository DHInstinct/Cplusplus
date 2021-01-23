/*
Daniel Hartley
Assignment 7 - Vector lottery
Due Date: 11/21/19
*/


#include <iostream>
#include <vector>
#include <windows.h>
#include <algorithm>
#include <time.h>

#include "Lottery.h"
#include "Timer.h"

using namespace std;

int main()
{
	srand(time(NULL));
	
	Timer timer;
	Lottery round1;
	cout << "*********************************************************" << endl;
	cout << "*               Welcome to C++ Lottery!                 *" << endl;
	cout << "*********************************************************" << endl;
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << "." << endl;
	Sleep(500);
	   
	vector<int> winningNums;
	vector<int> userNums;

	//Just setting the size
	round1.SetSize(5);
	// And setting the range of numbers
	round1.SetRangeOfNums(40);

	round1.Play(winningNums, userNums);

	cout << "Now Letting the computer play" << endl;
	Sleep(500);
	Sleep(500);
	Sleep(500);
	Sleep(500);
	Sleep(500);
	
	Lottery round2;
	round2.SetSize(5);
	round2.SetRangeOfNums(31);
	vector<int> compNums;
	do
	{
		round2.PlayComp(winningNums, compNums);
	} while (round2.GetIsWin() == false);



	return 0;
}