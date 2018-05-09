#pragma once

#ifndef _PARKING_H
#define _PARKING_H

#include "stdafx.h"
#include <stdlib.h>

class ParkedCar
{
public:
	ParkedCar(string, string, string, string, int);
	void addMins(int minutes);
	void print();
	string getMake();
	string getModel();
	string getColor();
	string getLicence();
	int getMins();
private:
	string make;
	string model;
	string color;
	string licence;
	int minsParked;
};

ParkedCar::ParkedCar(string mk, string md, string clr, string lc, int time) 
	: make(mk), model(md), color(clr), licence(lc), minsParked(time) {}

void ParkedCar::addMins(int minutes) {	minsParked += minutes; }

string ParkedCar::getMake() { return make; }
string ParkedCar::getModel() { return model; }
string ParkedCar::getColor() { return color; }
string ParkedCar::getLicence() { return licence; }
int ParkedCar::getMins() { return minsParked; }
void ParkedCar::print()
{
	cout << "Make: "<<make<<"\nModel: " << model << "\nColor: "<<color<<"\nLicence Plate: "<< licence <<"\nMinutes Parked: " << minsParked << endl;
}

class ParkingMeter
{
public:
	ParkingMeter(int);
	void addTime(int mins);
	int getMins();
private:
	int minsLeft;
};

ParkingMeter::ParkingMeter(int mins) : minsLeft(mins) {}
void ParkingMeter::addTime(int mins) { minsLeft += mins; }
int ParkingMeter::getMins() { return minsLeft; }

class ParkingTicket
{
public:
	ParkingTicket(string, string, string, string, int);
};

ParkingTicket::ParkingTicket(string mk, string md, string clr, string lc, int time)
{
	ParkedCar ticketed = ParkedCar(mk, md, clr, lc, time);
	double fine = 25;
	int timeleft = time;
	while (timeleft > 60)
	{
		timeleft -= 60;
		fine += 10;
	}
	ticketed.print();
	cout << "Parking ticket fine is $" << fine << endl;
}

class PoliceOfficer
{
public:
	PoliceOfficer(string, string); 
	ParkingTicket checkMeter(ParkingMeter meter, ParkedCar car);
	string getName();
	string getBadge();
private:
	string name;
	string badge;
};

PoliceOfficer::PoliceOfficer(string nm, string bd) : name(nm), badge(bd) {}

ParkingTicket PoliceOfficer::checkMeter(ParkingMeter meter, ParkedCar car)
{
	cout << "\nMinutes left on parking meter: " << meter.getMins() << endl;
	if (meter.getMins() <= 0)
	{
		cout << "Meter is expired" << endl;
		return ParkingTicket(car.getMake(), car.getModel(), car.getColor(), car.getLicence(), car.getMins());
	}
	else
	{
		car.print();
		cout << "Meter is still running" << endl;
	}
}

string PoliceOfficer::getName() { return name; }
string PoliceOfficer::getBadge() { return badge; }

/*
Chapter 14 Programming Challenge #14 Parking Ticket Sim Pg 889

Parking Ticket Simulator
For this assignment you will design a set of classes that work together to simulate a
police officer issuing a parking ticket. The classes you should design are:
• The ParkedCar Class: This class should simulate a parked car. The class’s responsibilities
are:
– To know the car's make, model, color, license number, and the number of minutes
that the car has been parked

• The ParkingMeter Class: This class should simulate a parking meter. The class’s
only responsibility is:
– To know the number of minutes of parking time that has been purchased

• The ParkingTicket Class: This class should simulate a parking ticket. The class’s
responsibilities are:
– To report the make, model, color, and license number of the illegally parked car
– To report the amount of the fine, which is $25 for the first hour or part of an
hour that the car is illegally parked, plus $10 for every additional hour or part of
an hour that the car is illegally parked
– To report the name and badge number of the police officer issuing the ticket

• The PoliceOfficer Class: This class should simulate a police officer inspecting
parked cars. The class’s responsibilities are:
– To know the police officer’s name and badge number
– To examine a ParkedCar object and a ParkingMeter object, and determine
whether the car's time has expired
– To issue a parking ticket (generate a ParkingTicket object) if the car’s time has
expired
Write a program that demonstrates how these classes collaborate. */

#endif