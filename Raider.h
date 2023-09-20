#pragma once
#include<iostream>
#include <string>

using namespace std;

class Raider 
{

private:

	string m_id;
	string m_type;
	string m_defSymbol;
	string m_penalty;
	string m_bossPenalty;

	bool m_flame = false;

	int m_battleValue = 0;
	int m_setNum = 0;
	
	string getFlameVal();

public:
	Raider();

	void raiderCard(string id, string type, string defSymbol, string penalty, string bossPenalty, bool flame, int battleValue, int setNum);
	
	int getLevel();
	string getID();
	string getDefSym();
};
