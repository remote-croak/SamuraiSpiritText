#pragma once
#include <string>
#include "Samurai.h"
#include "Daisuke.h"

using namespace std;

class GenericPlayer
{
private:
	string m_name;
	Samurai m_samurai;

public:
	GenericPlayer(string name, Samurai samurai);

	string getName();
	Samurai getSamurai();

	bool samuraiHat();
	bool samuraiDoll();
	bool samuraiFarm();

	void getDefendLine();
	void getCombatLine();
	void getSamuraiBT(); //Samurai BattleTrack
	void flipSamurai(); // transform the samurai into their beast form
	void addDefence(Raider raider); // add a raider to the defence line
	void addCombat(Raider raider); // add a raider to the combat line
	void useAbility();

	void actions();

	int getBT();
	int sizeOfCombat();
};