#include "LinkListGame.h"
#include <Windows.h>

const string Game::NORTH = "north";
const string Game::SOUTH = "south";
const string Game::ITEMS[NUM_ITEMS] = { "Bear", "Evans", "Beer" };

Game::Game()
{
	SetUp();
}

void PrintSlow(string &string)
{
	for (int i = 0; i < string.size(); i++)
	{
		Sleep(50);
		cout << string[i];
	}
}

bool Game::IsWon() const
{
	if (m_North.Count() == NUM_ITEMS) {
		cout << "You win!!" << endl;
		return true;
	}
	return false;
}

bool Game::IsLost(const List &noFarmer) const {
	for (int  i = 0; i < NUM_ITEMS; i++)
	{
		if (noFarmer.Contains(ITEMS[i]) && noFarmer.Contains(ITEMS[i + 1])) {
			cout << "The " << ITEMS[i] << " devoured the " << ITEMS[i + 1] << "!";
			Sleep(500);
			cout << "\nYou Lost!" << endl;
			return true;
		}
	}
	return false;
}

bool Game::IsPlaying() const {
	bool lost;
	if (m_FarmerBank == SOUTH)
	{
		lost = IsLost(m_North);
	}
	else
	{
		lost = IsLost(m_South);
	}
	bool won = IsWon();
	return (!lost && !won);
}

void Game::SetUp()
{
	m_South.Clear();
	m_North.Clear();
	m_FarmerBank = SOUTH;
	for (int i = 0; i < NUM_ITEMS; i++)
	{
		m_South.Add(ITEMS[i]);
	}
}

void Game::DisplayInstruct() const
{
	PrintSlow(*welcome); 
	cout << endl;
	system("pause");
	system("CLS");
}

void Game::DisplayInstruct(Game &other) {
	Welcome = other.Welcome;
	PrintSlow(*welcome);
	cout << endl;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 0x20);
	cout << "\nIn this version you can use an overloaded operator to switch all items from one bank to another by typing 'switch'" << endl;
	SetConsoleTextAttribute(h, 0x0F);
	system("pause");
	system("CLS");
}

void Game::DisplayBanks() const
{
	cout << "South Bank: " << endl;
	m_South.Display();
	cout << endl;

	cout << "North Bank: " << endl;
	m_North.Display();
	cout << endl;

	cout << "The Cop is on the " << m_FarmerBank << " bank.\n" << endl;
}

void Game::TransportItem(List & fromBank, List & toBank)
{
	string itemName;
	cout << "What should the cop take?: ";
	cin >> itemName;
	cout << endl;
	if (fromBank.Remove(itemName))
	{
		toBank.Add(itemName);
		cout << "The Cop takes the " << itemName << " with him." << endl;
	}
	else if (itemName == "switch") {
		toBank + fromBank;
	}
	else
	{
		cout << "The Cop takes nothing" << endl;
	}
	cout << endl;
	system("CLS");
}

void Game::Play()
{
	SetUp();
	DisplayBanks();
	while (IsPlaying())
	{
		if (m_FarmerBank == SOUTH)
		{
			TransportItem(m_South, m_North);
			m_FarmerBank = NORTH;
		}
		else
		{
			TransportItem(m_North, m_South);
			m_FarmerBank = SOUTH;
		}
		DisplayBanks();
	}
}




