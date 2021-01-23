/*
Daniel Hartley
Assignment 3 
*/

#include <iostream>

#include "TextInt.h"
using namespace std;

ostream& operator<<(ostream& out, TextInt& textint) // Overloading stream insertion
{
	out << textint.GetValue() << ": " << textint.GetTranslation();
	return out;
}

int main()
{
	
	
	TextInt value1(3124);
	value1.SetValue(3124);
	cout << "Your Value is: " << value1.GetValue() << endl;
	cout << "Translation: " << value1.GetTranslation() << endl;

	TextInt value2(2458);
	TextInt value3(1278);
	TextInt value4 = value2 + value3;
	cout << value4 << endl; 

	cout << endl;

	TextInt value8(0);
	cout << value8 << endl;

	TextInt value5(15);
	cout << value5 << endl;
	
	TextInt value7(89);
	cout << value7 << endl;
	
	TextInt value6(200);
	cout << value6 << endl;
	

	return 0;
}