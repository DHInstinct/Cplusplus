
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

struct NonPerfSqrtExc : public exception // struct for an exception
{
	string message;
	int value;

	const char* what() const override
	{
		return message.c_str();
	}
};

int intSqrt(int value)
{
 	double square = sqrt(value);
	
	if ((square - floor(square)) == 0) // checking to see if the value is an 
		return square;				   //integer if it is return its square root
	else							   //else throw an expection
	{
		NonPerfSqrtExc exc;
		exc.value = value;
		exc.message = "Exception! Non-perfect Square ";
		throw exc;
	}
}

int Rpower(int num, int power) // Recursive powerfunction
{
	if (power == 0)
		return 1;
	else
		return (num * Rpower(num, power - 1));
}

template<class T, class K, class J>
J ReturnLargest(T x, K y, J z)	//Template function that returns the largest object
{
	if (x > y && x > z)
		return x;
	else if (y > x && y > z)
		return y;
	else if(z > x && z > y)
		return z;
}

int main()
{
	try 
	{
		cout << intSqrt(16) << endl; // 4
		cout << intSqrt(25) << endl; // 5
		cout << intSqrt(15) << endl; // should output an exception
	}

	catch (NonPerfSqrtExc exc)
	{
		cout << exc.what() << endl;
	}
	
	cout << '\n' << "Recursive Power Function: " << '\n';

	//Recursive Power Funtion
	cout << "2 ^ 3 = " << Rpower(2, 3) << endl;
	cout << "2 ^ 0 = " << Rpower(2, 0) << endl;
	cout << "0 ^ 0 = " << Rpower(0, 0) << endl; 

	cout << '\n' << "Template Function: " << '\n';

	//Returning the largest object
	cout << "Largest Int: " << ReturnLargest(1, 5, 77) << endl;
	cout << "Largest Double: " << ReturnLargest(117.32, 5.5, 4.4)<< endl;
	cout << "Largest string: " << ReturnLargest(string("Jerry"), string("z"), string("test")) << endl;


	return 0;
}