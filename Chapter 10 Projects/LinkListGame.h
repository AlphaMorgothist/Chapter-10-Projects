#pragma once
#include "list.h"
#include <iostream>

class Game {
public:
	Game();
	bool IsWon() const;
	bool IsLost(const List &noFarmer) const;
	bool IsPlaying() const;
	void SetUp();
	void DisplayInstruct() const;
	void DisplayInstruct(Game & other);
	void DisplayBanks() const;
	void TransportItem(List &fromBank, List &toBank);
	void Play();
private:
	static const string NORTH;
	static const string SOUTH;
	static const int NUM_ITEMS = 3;
	static const string ITEMS[NUM_ITEMS];
	List m_North;
	List m_South;
	string m_FarmerBank;
	string Welcome = "Welcome to 'Get all of this shit across a river'.\nYou must get each item across the Raging-Clue River. The only issue is that some items are consumable\nAnd other items will eat them.\nGet all three items across and win the game!\nIf you want to take nothing, enter 'nothing' at the prompt";
	string *welcome = &Welcome;
};