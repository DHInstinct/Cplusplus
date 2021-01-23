/*
Daniel Hartley
Assignment 4 
*/

#include <iostream>

#include "item.h"
#include "Equipment.h"
#include "Consumable.h"

using namespace std;

int main()
{
	Item stick("Stick");
	Equipment grenade("Grenade");
	Consumable healthPot(5, "HealthPot");

	Item* Inventory[3];
	Inventory[0] = &stick;
	Inventory[1] = &grenade;
	Inventory[2] = &healthPot;

	for (int i = 0; i < 3; ++i)
	{
		Inventory[i]->Use();
		Inventory[i]->Use();
		Inventory[i]->Use();
		Inventory[i]->Use();
		Inventory[i]->Use();
		cout << '\n';

	}

	return 0;
}