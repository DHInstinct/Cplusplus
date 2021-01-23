#pragma once

#include <iostream>

#include "item.h"

using namespace std;

//Equipment child class
class Equipment : public Item
{
private:
	bool equipped;

public:
	
	Equipment(string newName = "Un-named Equipment") // Default Equipment ctor
	{
		SetName(newName);
	}
	
	
	void Use() override
	{

		if (equipped)
		{
			cout << "Using Equipment: " << GetName() << endl;
			equipped = false;
		}
		if (!equipped)
		{
			cout << "Equiped! Using Equipment: " << GetName() << endl;
			equipped = true;
		}

	}
	
};
