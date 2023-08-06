#include <iostream>
#include "DeckDetails.h"

using namespace std;


DeckDetails::DeckDetails() {}

void DeckDetails::setHats(int num) 
{
	m_hats = num;
}
	
int DeckDetails::getHats()
{
	return m_hats;
}

void DeckDetails::setDolls(int num) 
{
	m_dolls = num;
}

int DeckDetails::getDolls()
{
	return m_dolls;
}

void DeckDetails::setFarms(int num) 
{
	m_farms = num;
}

int DeckDetails::getFarms()
{
	return m_farms;
}

void DeckDetails::setFlames(int num) 
{
	m_flames = num;
}
	
int DeckDetails::getFlames()
{
	return m_flames;
}
	
void DeckDetails::setToggle(int num) 
{
	m_toggle = num;
}

int DeckDetails::getToggle()
{
	return m_toggle;
}

void DeckDetails::setNumCards(int num)
{
	m_numCards = num;
}

int DeckDetails::getNumCards()
{
	return m_numCards;
}

void DeckDetails::setLevelDetails(int level)
{
	if (level == 1 || level == 2)
	{
		m_hats = 4;
		m_dolls = 4;
		m_farms = 4;
		m_flames = 6;
		m_numCards = 13;
	}

	else if (level == 3 || level == 4)
	{
		m_hats = 3;
		m_dolls = 5;
		m_farms = 4;
		m_flames = 6;
		m_numCards = 13;
			
	}

	else if (level == 5)
	{
		m_hats = 1;
		m_dolls = 1;
		m_farms = 1;
		m_flames = 4;
		m_numCards = 7;
	}

	else if (level == 6)
	{
		m_hats = 1;
		m_dolls = 1;
		m_farms = 1;
		m_flames = 7;
		m_numCards = 7;
	}
}