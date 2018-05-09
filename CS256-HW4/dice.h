// dice.h

#ifndef _DICE_H
#define _DICE_H

#include <stdlib.h>
#include <time.h>
//because iostream is included in main class file, not needed in this header file

class dice 
{
public:
	dice(int sides);	
	int roll();
	void display();
	int numSides();	
	int numRolls();
private:
	int sides;
	int rolls = 0;
};								


dice::dice(int sides)
{
	this->sides = sides;
	srand(time(0)); //this is req to generate rand # from pc clock, otherwise rand() always returns the same number
}

int dice::roll()
{
	rolls++;
	return  1 + rand() % sides;
}

void dice::display()
{
	cout << "Rolling" << sides << "-sided die." << endl;
	cout << "Rolled: " << roll() << endl;
}

int dice::numSides()
{
	return sides;
}

int dice::numRolls()
{
	return rolls;
}

#endif
