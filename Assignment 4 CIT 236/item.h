#pragma once

#include <iostream>
#include <string>

using namespace std;

//Parent class
class Item 
{
private:
	string name;
	
public:

	Item(string newName = "Un-named Item") //Default ctor
	{
		SetName(newName);
	}

	virtual void Use() 
	{
		cout << "Using Item: " << name << endl;
	}

	void SetName(string &newName)
	{
		name = newName;
	}

	string GetName() const
	{
		return name;
	}

};
