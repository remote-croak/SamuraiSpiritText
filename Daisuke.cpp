#include "Samurai.h"
#include "Daisuke.h"
#include <string>

using namespace std;

Daisuke::Daisuke(string name, int maxBT, string playerID) :
	Samurai(name, maxBT, playerID)
{
}

void Daisuke::talent()
{}

void Daisuke::humanKiai()
{
	
}

void Daisuke::animalKiai()
{

}

void Daisuke::becomeAnimal()
{
	Samurai::becomeAnimal();
	setMaxBT(11);
}

void Daisuke::becomeHuman()
{
	Samurai::becomeHuman();
	setMaxBT(8);
}