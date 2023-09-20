#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include "RaidStack.h"

using namespace std;

class Samurai
{
private:
	vector<Raider> m_defendLine; // pos0: farm, pos1: hat, pos2: doll
	vector<Raider> m_combatLine;

	string m_name;
	string m_playerID;

	int m_maxBT;
	int m_wounds;
	int m_currentBT;

	bool m_beastForm;
	bool m_activateKiai;
	bool m_hat;
	bool m_doll;
	bool m_farm;

public:

	Samurai(string name = "samurai", int maxBT = 11, string playerID = "player");

	virtual void talent();
	virtual void humanKiai();
	virtual void animalKiai();
	
	void activateKiai();

	virtual void becomeAnimal();
	virtual void becomeHuman();

	void printCombatLine();
	void printDefendLine();

	void printRaiderLines(); //outdated
	void printLine(vector<Raider> r);

	void confront(Raider r);
	void defend(Raider r);

	int getCurrentBT();

	int getMaxBT();
	void setMaxBT(int maxBT);

	void setWounds(int wounds);
	int getWounds();

	string getName();
	void setName(string name);

	void showStats();

	bool hasHat();
	bool hasDoll();
	bool hasFarm();

	int combatSize();
	

	

	

	
	
	
	
	
	
	

};