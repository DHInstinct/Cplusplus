#include <iostream>
#include <string>

using namespace std;

class Ability
{
private:
	string abliltyName;
	int damageToPlayer;
	int damageToStamina;
	int damageToMana;
	int staminaCost;
	int manaCost;
	
public:

	Ability()
	{
		abliltyName = "Un-Named ability";
		damageToPlayer = 0;
		damageToStamina = 0;
		damageToMana = 0;
		staminaCost = 0;
		manaCost = 0;
	}

	
	
	void setAbilityName(string nameForAbility)
	{
		if (nameForAbility.length() > 0)
			abliltyName = nameForAbility;
		else
			cout << "Please enter a valid ability name " << endl;
	}

	void setDamageToPlayer(int healthCost)
	{
		if (healthCost > -101 && healthCost < 101)		//Range between -101 - 101, becuase the player might want to have a
			damageToPlayer = healthCost;				// healing ability, which it would do negative damage.
		else
			cout << "Please enter in a value between 0 - 100, for damange to player " << endl;
	}

	void setDamageToStamina(int staminaCost)
	{
		if(staminaCost > 0 && staminaCost < 101) 
			damageToStamina = staminaCost;			
		else
			cout << "Please enter in a value between 0 - 100, for damange to stamina " << endl;
	}

	void setDamageToMana(int manaCost)
	{
		if (manaCost > 0 && manaCost < 101)
			damageToMana = manaCost;
		else
			cout << "Please enter in a value between 0 - 100, for damage to mana " << endl;
	}
	
	int getManaToPlayer()
	{
		return damageToMana;
	}

	string getAbilityName()
	{
		return abliltyName;
	}

	void setStaminaCost(int cost)
	{
		if (cost > 0 && cost < 101)
			staminaCost = cost;
		else
			cout << "Please enter in a value between 0 - 100, for stamina cost " << endl;
	}

	void setManaCost(int cost)
	{
		if (cost > 0 && cost < 101)
			manaCost = cost;
		else
			cout << "Please enter in a value between 0 - 100, for mana cost " << endl;
	}

	int GetManaCost()
	{
		return manaCost;
	}

	void DisplayAbility()
	{
		cout << "Your Ability is: " << abliltyName << endl;
		cout << "It does " << damageToPlayer << " points of Damage" << endl;
		cout << "It takes " << damageToStamina << " stamina points from your opponent" << endl;
		cout << "It takes " << damageToMana << " mana points from your opponent " << endl;
		cout << "It costs " << staminaCost << " Stamina points" << endl;
		cout << "It costs " << manaCost << " Mana points" << endl;
	}
};

class Character //Character Class, stores all infomation about character, and its stats
{
private:
	string name;
	Ability characterAbility;
	int HP;
	int stamina;
	int mana;
	int strength;  

	void isAlive() //Private funtion, cuz the user doesnt need to use this, its just for the class
	{
		if (HP <= 0)
			cout << "Your Character is Dead... Sorry! " << endl;
		else
			cout << "Your character is alive! Yay " << endl;
			
	}

public:

	Character(string Cname = "Unnamed Hero") // Constructor
	{
		HP = 10;
		stamina = 10;
		mana = 10;
		strength = 10;
		if (Cname.length() > 0)
			name = Cname;
	}
	
	void SetName(string Newname) //Set name function
	{
		if(Newname.length() > 0)
			name = Newname;
	}

	void SetHealth(int newHealth) //Set health function
	{
		if (newHealth <= 100 && newHealth >= 0)
			HP = newHealth;
		else
			cout << "Please enter a valid HP amount " << endl;
	}

	void SetStamina(int newStamina)
	{
		if (newStamina <= 100 && newStamina >= 0)
			stamina = newStamina;
		else
			cout << " Please enter a valid Stamina amount " << endl;
		
	}
	
	void SetMana(int newMana)		
	{
		if (newMana <= 100 && newMana >= 0)
			mana = newMana;
		else
			cout << " Please enter a valid Mana amount " << endl;
	}
	
	void setStrength(int newStrength)
	{
		if (newStrength < 100 && newStrength > 0)
			strength = newStrength;
		else
			cout << " Please enter a valid  Strength amount " << endl;
	}

	string GetName()
	{
		return name;
	}

	int GetHP()
	{
		return HP;
	}

	int GetStrength()
	{
		return strength;
	}

	int GetMana()
	{
		return mana;
	}
	
	string GetAbilityName()
	{
		return name;
	}

	void setAbility(Ability ability) 
	{
		ability = characterAbility;
	}
	void setAbility(Ability ability, int healthAffect, int staminaAffect, int manaAffect)
	{
		ability = characterAbility;
		healthAffect += HP;
		staminaAffect += stamina;
		manaAffect += mana;
	}
	

	void attack(Character &character)
	{ 
		cout << '\n';
		cout << "You attacked " << character.name << " You hit them for " << strength << " health points! " << endl;
		character.HP -= strength;
		cout << "Their stats are now :" << endl;
		DisplayCharacter();
	}

	void useAbility(Character character)
	{
		character.mana -= characterAbility.getManaToPlayer();
		mana -= characterAbility.GetManaCost();
		cout << character.GetName() << " got hit by " << characterAbility.getAbilityName();

	}

	void DisplayCharacter()
	{
		cout << "Your Hero's name is " << name << endl;
		cout << "HP: " << HP << endl;
		cout << "Stamina: " << stamina << endl;
		cout << "Mana: " << mana << endl;
		cout << "Strength: " << strength << endl;
		isAlive();
	}
	
};


int main()
{
	
	Character Jerry("Jerry");
	Jerry.SetName("Jerry"); 
	Jerry.SetHealth(50);
	Jerry.SetMana(90);
	Jerry.SetStamina(54);
	Jerry.setStrength(59);
	Jerry.DisplayCharacter();

	cout << '\n';

	Character Harry("Harry");
	Harry.SetName("Harry");
	Harry.SetHealth(50);
	Harry.SetMana(90);
	Harry.SetStamina(50);
	Harry.setStrength(20);
	Harry.DisplayCharacter();

	cout << '\n';

	Ability ForcePush;
	ForcePush.setAbilityName("Force Push");
	ForcePush.setDamageToPlayer(10);
	ForcePush.setDamageToMana(10);
	ForcePush.setDamageToStamina(10);
	ForcePush.setManaCost(10);
	ForcePush.setStaminaCost(10);
	ForcePush.DisplayAbility();
	
	cout << '\n';

	Ability FlameThrower;
	FlameThrower.setAbilityName("Flame Thrower");
	FlameThrower.setDamageToPlayer(25);
	FlameThrower.setDamageToMana(5);
	FlameThrower.setDamageToStamina(15);
	FlameThrower.setManaCost(20);
	FlameThrower.setStaminaCost(20);											
	FlameThrower.DisplayAbility();													
																					
																					
	Jerry.setAbility(ForcePush);													
	Harry.setAbility(FlameThrower);													
	
	Jerry.useAbility(Harry);
	cout << '\n';
	Harry.DisplayCharacter();
	Jerry.attack(Harry);
	


	return 0;
}