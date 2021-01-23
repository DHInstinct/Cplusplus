#pragma once

#include <iostream>

using namespace std;

class TextInt
{
private:
	int value;
	static const int lessThan20Num[];
	static const int tensNum[];
	static const int hundredNum;
	static const int thousandNum;
		   
	static const string lessThan20[20];
	static const string tens[8];
	static const string hundred;
	static const string thousand;

public:
	
	//Default Constructor
		TextInt(int startValue = 0);

	//Function Prototypes
		void SetValue(int newValue);
		int GetValue() const;
		string GetTranslation() const;
	
	//Operator Overloading
		TextInt operator+ (TextInt RHS) //Overloading Addition
		{
			TextInt result(value + RHS.value);
			return result;
		}

		TextInt operator- (TextInt RHS) //Overloading subtraction
		{
			TextInt result(value - RHS.value);
			return result;
		}

		TextInt operator/ (TextInt RHS) // Overloading Division
		{
			TextInt result(value / RHS.value);
			return result;
		}

		TextInt operator* (TextInt RHS) // Overloading Multiplication 
		{
			TextInt result(value * RHS.value);
			return result;
		}

		TextInt operator% (TextInt RHS) // Overloading Modulus
		{
			TextInt result(value % RHS.value);
			return result;
		}

		//check main.cpp for overloaded stream insertion operator :)

};