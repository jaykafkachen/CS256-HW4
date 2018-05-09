#pragma once
#ifndef _SHIPS_H
#define _SHIPS_H

class Ship 
{
public:
	Ship(string, string);
	string getName() { return name; }
	string getYear() { return year; }
	virtual void print() { cout << "Ship: " << name << "\nYear: " << year << endl; }
protected:
	string name;
	string year;
};

Ship::Ship(string n, string y) : name(n), year(y) {}

class CruiseShip : public Ship
{
public:
	CruiseShip(string, string, int);
	int getPassengers() { return passengers; }
	virtual void print() { cout << "Cruise Ship: " << name << "\nPassengers: " << passengers << endl; }
private:
	int passengers;
};

CruiseShip::CruiseShip(string n, string y, int pass) : Ship(n, y), passengers(pass) {}


class CargoShip : public Ship
{
public:
	CargoShip(string, string, int);
	int getCapacity() { return capacity; }
	virtual void print() { cout << "Cargo Ship: " << name << "\nCargo capacity: " << capacity << endl; }
private:
	int capacity;
};

CargoShip::CargoShip(string n, string y, int cap) : Ship(n, y), capacity(cap) {}


/* 
Chapter 15 Programming Challenge #12  Ship, Cruise, Cargo Ship Pg 967
Ship , CruiseShip , and CargoShip Classes
Design a Ship class that has the following members:
• A member variable for the name of the ship (a string)
• A member variable for the year that the ship was built (a string)
• A constructor and appropriate accessors and mutators
• A virtual print function that displays the ship’s name and the year it was built.

Design a CruiseShip class that is derived from the Ship class. The CruiseShip class
should have the following members:
• A member variable for the maximum number of passengers (an int)
• A constructor and appropriate accessors and mutators
• A print function that overrides the print function in the base class. The CruiseShip
class’s print function should display only the ship’s name and the maximum number
of passengers.

Design a CargoShip class that is derived from the Ship class. The CargoShip class
should have the following members:
• A member variable for the cargo capacity in tonnage (an int).
• A constructor and appropriate accessors and mutators.
• A print function that overrides the print function in the base class. The CargoShip
class’s print function should display only the ship’s name and the ship’s cargo capacity.

Programming Challenges 967
968 Chapter 15 Inheritance, Polymorphism, and Virtual Functions
Demonstrate the classes in a program that has an array of Ship pointers. The array
elements should be initialized with the addresses of dynamically allocated Ship,
CruiseShip, and CargoShip objects. (See Program 15-14 , lines 17 through 22, for an
example of how to do this.) The program should then step through the array, calling
each object’s print function. */

#endif