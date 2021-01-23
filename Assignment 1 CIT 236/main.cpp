/*
Daniel Hartley
9-4-2019
Assignment 1 Review
*/
#include <iostream>
#include <random>
#include <time.h>
#include<string>

using namespace std;

//To get random number between 0 & 99
int Random()
{
	return rand() % 100;
}
// To get random number between 0 and num1
int Random(int num1)
{
	return rand() % num1;
}
//return a random num between the two values inputed
int Random(int val1, int val2)
{
	int range;
	range = (val1 - val2) + 1;
	return val1 + rand() % range;
}

// Randomizes each element of an array
void RandomFill(int nameOfArray[], const unsigned int arrSize)
{
	for (int i = 0; i < arrSize; ++i)
	{
		nameOfArray[i] = Random(); //stores each random number into every available index
		cout << nameOfArray[i] << endl;
	}
}

bool IsFactor(int v1, int v2) 
{
	if (v1 % v2 == 0) 
		return true;  // if v1 divides evenly into v2 there is no remainder thus they are factors 
	return false;	  // if there is a remainder then they are not factors becuase they dont divide evenly
} 

string FlipString(string str)
{
	string choice = str;
	for (int i = 0; i < str.length(); ++i) //for loop to loop through the array
	{
		if(choice[i] == toupper(choice[i])) // if the index of choice is uppercase 
		{
			choice[i] = tolower(choice[i]); // This changes uppercase to lowercase
		}

		else if (choice[i] == tolower(choice[i])) // if the index of choice is lower case
		{
			choice[i] = toupper(choice[i]); //This changes lowercase to uppercase
		}											
	}
	return choice; 
} 

int main()
{
srand(time(0));

	// Random Funtion
	int userChoice;
	int userChoice2;
	cout << "Please enter 2 numbers " << endl;
	cin >> userChoice;
	cin >> userChoice2;
	cout << "Now Testing the Random Funtion " << endl;
	cout << "Random Number between 0 and 99: " << Random() << endl;
	cout << "Random number between 0 and " << userChoice << ": " << Random(userChoice) << endl;
	cout << "Random number between " << userChoice << " and " << userChoice2 << ": " << Random(userChoice, userChoice2) << endl;
	cout << '\n';
													
	// Random fill function
	cout << "Now Testing RandomFill Function " << endl; 					   
	int theArray[5];														   
	RandomFill(theArray, 5);
	cout << '\n';

	//Is Factor function
	cout << "Now Testing IsFactor Function " << endl;	
	cout << "Please enter two values to see if they're factors " << endl;
	int factor1, factor2;
	cin >> factor1 >> factor2;
	while (cin.fail())	// 
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Invalid input, please enter 2 numbers! " << endl;
		cin >> factor1 >> factor2;
	}
	cout << IsFactor(factor1, factor2) << endl;
	cin.ignore(100, '\n');
	cout << '\n';

	
		// Flip string function						   
	cout << "Now testing the FlipString Function " << endl;					   
	string choice;
	cout << "Enter a string to be flipped " << endl;
	getline(cin, choice);
	cout << "You typed: " << choice << endl;
	cout << "Reversed: " << FlipString(choice) << endl;
	
	return 0;
}