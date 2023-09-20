#pragma once
#include "Samurai.h"
#include <string>

class Gorobei : public Samurai
{
public:
	Gorobei(string name = "Gorobei", int maxBT = 9, string playerID = "player2");

	virtual void talent();
	virtual void humanKiai();
	virtual void animalKiai();
	virtual void becomeAnimal();
	virtual void becomeHuman();
};