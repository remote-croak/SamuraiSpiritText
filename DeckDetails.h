#pragma once
#include <iostream>

using namespace std;

class DeckDetails
{

private:
	int m_hats = 0;
	int m_dolls = 0;
	int m_farms = 0;
	int m_flames = 0;
	int m_toggle = 0;
	int m_numCards = 0;

public:
	DeckDetails();

	void setHats(int num);
	int getHats();

	void setDolls(int num);
	int getDolls();

	void setFarms(int num);
	int getFarms();

	void setFlames(int num);
	int getFlames();

	void setToggle(int num);
	int getToggle();

	void setNumCards(int num);
	int getNumCards();

	void setLevelDetails(int level);
};