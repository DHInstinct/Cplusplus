#include <iostream>

#include "TextInt.h"

using namespace std;

const string TextInt::lessThan20[] = {"zero ", "one ", "two ", "three ", "four ", "five ", 
"six ", "seven ", "eight ", "nine ", "ten ", "eleven ", "twelve ", "thirteen ", "fourteen ",
"fifteen ", "sixteen ", "seventeen ", "eighteen ", "ninteen "};

const string TextInt::tens[] = { "twenty ", "thirity ", "fourty ", "fifty ", "sixty ", "seventy ", "eighty ", "ninty " };

const string TextInt::hundred = { "Hundred " };

const string TextInt::thousand = { "Thousand " };

const int TextInt::lessThan20Num[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19 };

const int TextInt::tensNum[] = { 20,30,40,50,60,70,80,90 };

const int TextInt::hundredNum = { 100 };

const int TextInt::thousandNum = { 1000 };


//TextInt class function definitions 
TextInt::TextInt(int startValue)
{
	SetValue(startValue);

}

void TextInt::SetValue(int newValue)
{
	if (newValue < 0)
	{		//This keeps the user in bounds
		cout << "I cannot translate negative numbers, Sorry! I clamped your number at the lowest I can translate" << endl;
		newValue = 0;
	}
	else if (newValue > 9999)
	{		//Still keeping the user in bounds
		cout << "The higest number I can translate to is 9999, Sorry! I clamped your number at the largest I can translate" << endl;
		newValue = 9999;
	}
	
	value = newValue;
}

string TextInt::GetTranslation() const
{
	string result;
	int tempValue = value;
	int index = 0;
	
		
	if (tempValue <= 19)
	{
		index = tempValue;
		result = lessThan20[index];
		return result;
	}

	if (tempValue >= 20 && tempValue <= 99)
	{
		index = (tempValue / 10) - 2;
		result = tens[index];
		return result;
	}

	
	if (tempValue >= 100 && tempValue <= 999)
	{
		index = tempValue / 100;
		result = lessThan20[index];
		result += "Hundred";
		return result;
	}
	
	//Translating the Thounsands Digit
	int thousandsDigit = value / 1000;
	index = thousandsDigit;
	result += lessThan20[index];
	result += "Thousand ";
	tempValue -= 1000 * thousandsDigit;

	//Translating the Hundred digit
	int hundredDigit = tempValue / 100;
	index = hundredDigit;
	result += lessThan20[index];
	result += "Hundred ";
	tempValue -= 100 * hundredDigit;

	//Translating the tens
	int tensDigit = tempValue /10;
	index = tensDigit - 2;
	result += tens[index];
	tempValue -= 10 * tensDigit;

	//translating ones
	int onesDigit = tempValue / 1;
	index = onesDigit;
	result += lessThan20[index];
	tempValue = value;

	return result;
}

int TextInt::GetValue() const
{	
	return value;
}
