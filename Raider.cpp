#include <iostream>
#include <string>
#include "Raider.h"


using namespace std;

Raider::Raider() {}

void Raider::raiderCard(string id, string type, string defSymbol, string penalty, string bossPenalty, bool flame, int battleValue, int setNum)
{
	m_id = id;
	m_type = type;
	m_defSymbol = defSymbol;
	m_penalty = penalty;
	m_bossPenalty = bossPenalty;
	m_flame = flame;
	m_battleValue = battleValue;
	m_setNum = setNum;

}

string Raider::getFlameVal()
{

	if (m_flame == true)
	{
		return "true";
	}
	else
		return "false";
}

int Raider::getLevel()
{
	return m_battleValue;
}

string Raider::getID() 
{
	return (m_id + "\nFlame: " + getFlameVal() + "\nDef: " + m_defSymbol + "\nPenalty: " + m_penalty + "\nBoss Penalty: " + m_bossPenalty);
}

string Raider::getDefSym()
{
	return m_defSymbol;
}

