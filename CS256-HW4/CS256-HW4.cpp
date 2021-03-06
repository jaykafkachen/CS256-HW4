// CS256-HW4.cpp : 21 Game, Parking Ticket, Ship
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include <dice.h>
#include <gameof21.h>
#include <parking.h>
#include <ships.h>


int main()
{
	std::string name;
	cout << "\n----Game of 21---- \nEnter player name: ";
	cin >> name;
	game21 game(name);
	game.play();
	//
	cout << "\n----Parking Ticket Simulator---- \n";
	ParkedCar honda("honda", "accord", "silver", "1234ABC", 100);
	ParkedCar toyota("toyota", "corolla", "black", "ABC1234", 30);
	ParkingMeter valid(50);
	ParkingMeter expired(0);
	PoliceOfficer fuzz("Alex Jones", "987654321");
	cout << "Officer "<< fuzz.getName() << " checking expired meter: " << endl;
	fuzz.checkMeter(expired, honda);
	cout << endl;
	fuzz.checkMeter(expired, toyota);
	cout << "\nOfficer " << fuzz.getName() << " checking 50 minute meter: " << endl;
	fuzz.checkMeter(valid, honda);
	cout << endl;
	fuzz.checkMeter(valid, toyota);
	//
	cout << "\n----Ships Test---- \n";
	Ship *boats[3] =
	{ 
		new Ship("USS Ship Shape","1999"),
		new CruiseShip("HMS Funzo","2017",500),
		new CargoShip("Ol' Faithful","1975", 7000)
	};

	// Display the grade data for each element in the array.
	for (int count = 0; count < 3; count++)
	{
		cout << "Test #" << (count + 1) << ":\n";
		boats[count]->print();
		cout << endl;
	}
return 0;
}

/*
Chapter 13 Programming Challenge #18  A Game of 21 Pg 809
Chapter 14 Programming Challenge #14 Parking Ticket Sim Pg 889
Chapter 15 Programming Challenge #12  Ship, Cruise, Cargo Ship Pg 967
*/