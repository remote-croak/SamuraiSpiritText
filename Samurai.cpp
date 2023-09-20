
#include "Samurai.h"
#include <string>

using namespace std;

Samurai::Samurai(string name, int maxBT, string playerID):
	m_name(name),
	m_maxBT(maxBT),
	m_playerID(playerID)
{
	m_wounds = 0;
	m_currentBT = 0;
	
	m_beastForm = 0;
	m_activateKiai = 0;
	m_hat = 0;
	m_doll = 0;
	m_farm = 0;
}

void Samurai::talent()
{}

void Samurai::humanKiai()
{}

void Samurai::animalKiai()
{}

void Samurai::activateKiai()
{
	if (m_beastForm == 0)
	{
		humanKiai();
	}
	else
	{
		animalKiai();
	}
}

void Samurai::becomeAnimal()
{
	m_beastForm = 1;
}

void Samurai::becomeHuman()
{
	m_beastForm = 0;
}
void Samurai::printCombatLine()
{
	if (m_combatLine.empty() != 1)
	{
		cout << "\n COMBAT LINE\n" << m_name << "\n";
		cout << "\n Current Battle Track: " << getCurrentBT() << "/" << getMaxBT();
		printLine(m_combatLine);
	}
	else
	{
		cout << "\n combat line is empty";
	}
}

void Samurai::printDefendLine()
{
	if (m_defendLine.empty() != 1)
	{
		cout << "\n DEFEND LINE\n";
		printLine(m_defendLine);
	}

	else
	{
		cout << "\n defend line is empty";
	}
}

// outdated
void Samurai::printRaiderLines()
{
	cout << this->m_name;
	//cout << this->playerId;
	cout << this->m_currentBT;
	cout << this->m_maxBT;
	cout << this->m_beastForm;
	cout << "\n";
	cout << m_defendLine.empty();
	if (m_defendLine.empty() != 1)
	{
		printLine(m_defendLine);
	}

	else
	{
		cout << "\ndefendline is empty";
	}
}

void Samurai::printLine(vector<Raider> r)

{
	for (int line = 0; line < r.size(); line++)
	{
		cout << "\n" << r[line].getID() << "\n\n";
	}
}

void Samurai::confront(Raider r)
{
	cout << "Raider Has Been Confronted";
	this->m_currentBT += r.getLevel();
	this->m_combatLine.push_back(r);
}

void Samurai::defend(Raider r)
{
	if (r.getDefSym() == "Hat")
	{
		m_hat = 1;
	}
	else if (r.getDefSym() == "Doll")
	{
		m_doll = 1;
	}
	else if (r.getDefSym() == "Farm")
	{
		m_farm = 1;
	}

	m_defendLine.push_back(r);
}


int Samurai::getCurrentBT()
{
	return this->m_currentBT;
}

int Samurai::getMaxBT()
{
	return m_maxBT;
}

void Samurai::setMaxBT(int maxBT)
{
	m_maxBT = maxBT;
}

int Samurai::getWounds()
{
	return m_wounds;
}

void Samurai::setWounds(int wounds)
{
	m_wounds = wounds;
}

string Samurai::getName()
{
	return m_name;
}

void Samurai::setName(string name)
{
	m_name = name;
}

void Samurai::showStats()
{
	cout << m_name;
	cout << m_currentBT << "/" << m_maxBT;
	cout << m_hat << m_doll << m_farm;
}

bool Samurai::hasHat()
{
	return m_hat;
}

bool Samurai::hasDoll()
{
	return m_doll;
}

bool Samurai::hasFarm()
{
	return m_farm;
}

int Samurai::combatSize()
{
	return m_combatLine.size();
}