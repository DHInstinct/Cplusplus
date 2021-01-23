#pragma once

#include "item.h"

//Consumable child class
class Consumable : public Item
{
private:
	int uses;

public:

	Consumable(int charge, string newName = "Un-named Consumable")
	{
		SetName(newName);
		uses = charge;
	}

	bool IsEmpty() 
	{
		if (uses <= 0)
		{
			cout << "You have no more uses " << endl;
			return false;
		}
		else 
		{
			uses = uses - 1;
			cout << "You now have " << uses << " left" << endl;			 										 
 			return true;
		}
						
	}

	void Use()  override
	{
		cout << "Using consumable: " << GetName() << endl;
		IsEmpty();
		
	}

};