#include "GenericPlayer.h"
#include "Daisuke.h"
using namespace std;

GenericPlayer::GenericPlayer(string name, Samurai samurai):
	m_name(name),
	m_samurai(samurai)
{}
string GenericPlayer::getName()
{
	return this->m_name;
}


Samurai GenericPlayer::getSamurai()
{
	return this->m_samurai;
}

void GenericPlayer::getSamuraiBT()
{

}

void GenericPlayer::flipSamurai()
{

}

void GenericPlayer::addDefence(Raider raider)
{
	this->m_samurai.defend(raider);
}

void GenericPlayer::addCombat(Raider raider)
{
	this->m_samurai.confront(raider);
}

void GenericPlayer::useAbility()
{

}

void GenericPlayer::actions()
{

}

void GenericPlayer::getDefendLine()
{
	this->m_samurai.printDefendLine();
}

void GenericPlayer::getCombatLine()
{
	this->m_samurai.printCombatLine();
}

bool GenericPlayer::samuraiHat()
{
	return this->m_samurai.hasHat();
}

bool GenericPlayer::samuraiDoll()
{
	return this->m_samurai.hasDoll();
}

bool GenericPlayer::samuraiFarm()
{
	return this->m_samurai.hasFarm();
}

int GenericPlayer::getBT()
{
	return this->m_samurai.getMaxBT();
}

int GenericPlayer::sizeOfCombat()
{
	return m_samurai.combatSize();
}


