#pragma once
#include "Samurai.h"
#include <string>

class Daisuke : public Samurai
{
private:

public:
	Daisuke(string name = "Daisuke", int maxBT = 8, string playerID = "player1");
	
	virtual void talent();
	virtual void humanKiai();
	virtual void animalKiai();
	virtual void becomeAnimal();
	virtual void becomeHuman();
};
