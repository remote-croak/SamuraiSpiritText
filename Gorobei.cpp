#include "Samurai.h"
#include "Gorobei.h"
#include <string>

using namespace std;

Gorobei::Gorobei(string name, int maxBT, string playerID) :
	Samurai(name, maxBT, playerID)
{}

void Gorobei::talent()
{}

void Gorobei::humanKiai()
{}

void Gorobei::animalKiai()
{}

void Gorobei::becomeAnimal()
{
	Samurai::becomeAnimal();
	setMaxBT(12);
}

void Gorobei::becomeHuman()
{
	Samurai::becomeHuman();
	setMaxBT(9);
}