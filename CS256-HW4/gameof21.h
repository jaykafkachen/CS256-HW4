#pragma once
#ifndef _GAMEOF21_H
#define _GAMEOF21_H

#include "stdafx.h"
#include <stdlib.h>
#include <dice.h>
#include <string>
#include <iostream>
using namespace std;

/*Chapter 13 Programming Challenge #18  A Game of 21 Pg 809

For this assignment, you will write a program that lets the user play against the computer
in a variation of the popular blackjack card game. In this variation of the game,
two six-sided dice are used instead of cards. The dice are rolled, and the player tries to
beat the computer’s hidden total without going over 21.

Here are some suggestions for the game’s design:
• Each round of the game is performed as an iteration of a loop that repeats as long
as the player agrees to roll the dice, and the player’s total does not exceed 21.
• At the beginning of each round, the program will ask the users whether they want
to roll the dice to accumulate points.
• During each round, the program simulates the rolling of two six-sided dice. It rolls
the dice first for the computer, and then it asks the user if he or she wants to roll.
(Use the Die class that was demonstrated in this chapter to simulate the dice).
• The loop keeps a running total of both the computer and the user’s points.
• The computer’s total should remain hidden until the loop has finished.
• After the loop has finished, the computer’s total is revealed, and the player with the
most points without going over 21 wins.

*/

class game21
{
public:
	game21(std::string &);
	void play();
	void winner();
private:
	std::string player;
	int playerTotal;
	int opponentTotal;
};

game21::game21(std::string &name) : player(name), playerTotal(0), opponentTotal(0) {}

void game21::play()
{
	cout << "Rolling dealer turn..." << endl;
	dice oppD6(6);
	opponentTotal += oppD6.roll();
	opponentTotal += oppD6.roll();
	while (opponentTotal < 17)
	{ 
		cout << "Dealer is rolling..." << endl;
		opponentTotal += oppD6.roll();
	}
	//
	dice playerD6(6);
	playerTotal += playerD6.roll();
	playerTotal += playerD6.roll();
	bool stop = false;
	cout << endl << player << "'s turn:\nRolling 2 dice to start..." << endl;
	while (!stop)
	{
		if (playerTotal > 21)
		{
			cout << "Your current total = " << playerTotal << "\nExceeded 21! Ending game..." << endl;
			stop = true;
			break;
		}
		char c;
		cout << "Your current total = " << playerTotal << "\nRoll? (y/n)\n-->";
		cin >> c;
		while (!(c == 'y' || c == 'Y' || c == 'n' || c == 'N'))
		{
			cout << "Invalid input\nYour current total = " << playerTotal << "\nRoll? (y/n)\n-->";
			cin >> c;
		}
		if (c == 'y' || c == 'Y')
		{
			playerTotal += playerD6.roll();
		}
		if (playerTotal > 21)
		{
			cout << "Your current total = " << playerTotal << "\nExceeded 21! Ending game..." << endl;
			stop = true;
			break;
		}
		else if (c == 'n' || c == 'N')
		{
			cout << "Ending " << player << "'s turn...\n" << endl;
			stop = true;
			break;
		}
	}
	winner();
}

void game21::winner()
{
	cout << endl << player << "'s total = " << playerTotal << endl;
	cout << "Dealer's total = " << opponentTotal << endl;
	if ((opponentTotal > playerTotal) || (playerTotal > 21)) //obtained from online blackjack rules, if both players bust dealer wins
		cout << "Dealer wins!" << endl;
	else if (playerTotal > opponentTotal && playerTotal <= 21)
		cout << player << " wins!" << endl;
	else if (playerTotal == opponentTotal)
		cout << "No one wins!" << endl;
}

#endif