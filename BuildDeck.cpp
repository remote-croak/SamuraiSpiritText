#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <chrono>
#include "Raider.h"
#include "DeckDetails.h"
#include "BuildDeck.h"

using namespace std;

BuildDeck::BuildDeck()
{

	for (int level = 1; level < 7; level++)
	{
		this->createRaider(level);
	}
	//this->createRaider(7);
}

void BuildDeck::initRaider(int level)
{
	details.setLevelDetails(level);
	isFlame = true;
	hasSymbol = "Hat";
	hasPenalty = "Fire";
	hasBossPenalty = "None";
	details.setToggle(0);

	deckSize = details.getNumCards();
}

void BuildDeck::createRaider(int level)
{
	this->initRaider(level);

	for (int card = 1; card <= deckSize; card++)
	{
		this->checkSymbols();
		this->checkFlames(level);
		this->setRaiderPenalties(card, level);
			

		id = generateID(type, to_string(level), to_string(card));
		raid.raiderCard(id, type, hasSymbol, hasPenalty, hasBossPenalty, isFlame, level, card);
		
		this->addRaider(raid, card);

		reduceSymbolCount();

	}

}

void BuildDeck::addRaider(Raider raid, int card)
{
	
	if (raid.getLevel() <= 4)
	{	
		int common_card = (raid.getLevel() - 1) * 13 + card;
		
		commonRaider[common_card - 1] = raid;
	}

	else if (raid.getLevel() == 5)
	{
		lieutRaider[card-1] = raid;
	}

	else
	{
		bossRaider[card-1] = raid;
	}
}

void BuildDeck::reduceSymbolCount()
{
	if (this->hasSymbol == "Hat" && details.getHats() > 0)
	{
		details.setHats(details.getHats() - 1);
	}

	if (this->hasSymbol == "Doll" && details.getDolls() > 0)
	{
		details.setDolls(details.getDolls() - 1);
	}

	if (this->hasSymbol == "Farm" && details.getFarms() > 0)
	{
		details.setFarms(details.getFarms() - 1);
	}
}

// checks if there are still symbols that can be applied of a type.
// If the symbol is empty then it switches to the next type and resets the flame.
void BuildDeck::checkSymbols()
{
	if (details.getHats() == 0)
	{
		this->hasSymbol = "Doll";
		this->isFlame = true;
	}

	if (details.getDolls() == 0)
	{
		this->hasSymbol = "Farm";
		this->isFlame = true;
	}

	if (details.getFarms() == 0)
	{
		this->hasSymbol = "None";
		this->isFlame = true;
	}

}

void BuildDeck::checkFlames(int level)
{
	if (this->isFlame == true && level != 6)
	{
		if (details.getFlames() < 1)
		{
			this->isFlame = false;
		}

		this->checkHatFlames(level);
		this->checkDollFlames(level);
		this->checkFarmFlames(level);
	}
}
	
void BuildDeck::checkHatFlames(int level)
{
	if (this->hasSymbol == "Hat")
	{
		if (details.getHats() < 3 && level < 3)
		{
			this->isFlame = false;
		}

		else if (details.getHats() < 2 && level <= 4)
		{
			this->isFlame = false;
		}
			
		else if (details.getHats() < 2 && level == 5)
		{
			this->isFlame = false;
		}

		else
		{
			details.setFlames(details.getFlames() - 1);
		}
	}
}

void BuildDeck::checkDollFlames(int level)
{
	if (this->hasSymbol == "Doll")
	{
		if (details.getDolls() < 3)
		{
			this->isFlame = false;
		}

		else if (details.getDolls() <= 3 && level > 2 && level < 5)
		{
			this->isFlame = false;
		}

		else if (details.getDolls() < 1 && level == 5)
		{
			this->isFlame = false;
		}

		else
		{
			details.setFlames(details.getFlames() - 1);
		}
	}
}

void BuildDeck::checkFarmFlames(int level)
{
	if (this->hasSymbol == "Farm")
	{
		if (details.getFarms() <= 2)
		{
			this->isFlame = false;
		}

		else if (details.getFarms() < 1 && level == 5)
		{
			this->isFlame = false;
		}

		else
		{
			details.setFlames(details.getFlames() - 1);
		}
	}
}

void BuildDeck::setRaiderPenalties(int card, int level)
{
	if (level == 6)
	{
		this->type = "Boss";
		this->isFlame = true;
		details.setToggle(0);
		this->hasPenalty = bossPenalties(card);
		details.setToggle(1);
		this->hasBossPenalty = bossPenalties(card);

	}

	else
	{
		if (level == 5)
		{
			this->type = "Lieutenant";
		}

		else if (level <= 4)
		{
			type = "Plunderer";
		}

		hasPenalty = commonPenalty(level);
		hasBossPenalty = "None";
	}
}

string BuildDeck::bossPenalties(int card) 
{

	string pen = "";

	if (hasSymbol == "Hat")
	{
		pen = penaltyArr[2];
	}

	else if (hasSymbol == "Doll")
	{
		if (details.getToggle() == 0)
		{
			pen = penaltyArr[7];
		}

		else
		{
			pen = bossPenaltyArr[2];
		}
	}

	else if (hasSymbol == "Farm")
	{
		pen = penaltyArr[0];
	}

	else
	{
		if (card == details.getNumCards() - 3)
		{
			if (details.getToggle() == 0)
			{
				pen = penaltyArr[3];
			}

			else if (details.getToggle() == 1)
			{
				pen = bossPenaltyArr[0];
			}
		}

		else if (card == details.getNumCards() - 2)
		{
			if (details.getToggle() == 0)
			{
				pen = penaltyArr[1];
			}

			else if (details.getToggle() == 1)
			{
				pen = bossPenaltyArr[1];
			}
		}

		else if (card == details.getNumCards() - 1)
		{
			if (details.getToggle() == 0)
			{
				pen = penaltyArr[4];
			}

			else if (details.getToggle() == 1)
			{
				pen = penaltyArr[1];
			}
		}

		else if (card == details.getNumCards())
		{
			if (details.getToggle() == 0)
			{
				pen = penaltyArr[7];
			}

			else if (details.getToggle() == 1)
			{
				pen = bossPenaltyArr[3];
			}
		}
	}

	return pen;
}

string BuildDeck::commonPenalty(int level)
{
	string pen = "";
		
	if (this->hasSymbol == "Hat")
	{
		if (this->isFlame == true)
		{
			pen = flameHatPenalty(level);
		}

		else
		{
			pen = plainHatPenalty(level);
		}
	}

	if (this->hasSymbol == "Doll")
	{
		if (this->isFlame == true)
		{
			pen = flameDollPenalty(level);
		}

		else
		{
			pen = plainDollPenalty(level);
		}
	}

	if (this->hasSymbol == "Farm")
	{
		if (this->isFlame == true)
		{
			pen = flameFarmPenalty(level);
		}

		else
		{
			pen = plainFarmPenalty(level);
		}
	}

	if (this->hasSymbol == "None")
	{
		if (this->isFlame == true)
		{
			pen = flameBlankPenalty(level);
		}

		else
		{
			pen = plainBlankPenalty(level);
		}
	}

	return pen;
}

string BuildDeck::flameBlankPenalty(int level)
{
	string pen = "";

	if (details.getToggle() == 0)
	{
		details.setToggle(1);

		if (level == 1 || level == 2 || level == 5)
		{
			pen = penaltyArr[0];
		}

		else if (level == 3 || level == 4)
		{
			pen = penaltyArr[4];
		}
	}

	else if (details.getToggle() == 1)
	{
		details.setToggle(2);

		if (level == 5)
		{
			pen = penaltyArr[1];
		}
	}

	else if (details.getToggle() == 2)
	{
		details.setToggle(3);

		if (level == 5)
		{
			pen = penaltyArr[2];
		}
	}

	else if (details.getToggle() == 3)
	{
		details.setToggle(0);

		if (level == 5)
		{
			pen = penaltyArr[4];
		}
	}

	return pen;
}

string BuildDeck::plainBlankPenalty(int level)
{
	string pen = "";

	if (details.getToggle() == 0)
	{
		details.setToggle(1);

		if (level == 1 || level == 2)
		{
			pen = penaltyArr[0];
		}

		else if (level == 3 || level == 4)
		{
			pen = penaltyArr[1];
		}
	}

	return pen;
}


string BuildDeck::flameHatPenalty(int level)
{
	string pen = "";

	if (details.getToggle() == 0)
	{
		details.setToggle(1);
			
		if (level == 1 || level == 2)
		{
			pen = penaltyArr[1];
		}

		else if (level == 3 || level == 4)
		{
			pen = penaltyArr[0];
		}
	}

	else
	{
		details.setToggle(0);

		if (level == 1 || level == 2 || level == 3)
		{
			pen = penaltyArr[7];
		}

		else if (level == 4)
		{
			pen = penaltyArr[6];
		}
	}

	return pen;
}

string BuildDeck::plainHatPenalty(int level)
{
	string pen = "";

	if (details.getToggle() == 0)
	{
		details.setToggle(1);

		if (level == 1 || level == 2)
		{
			pen = penaltyArr[2];
		}

		else if (level == 3 || level == 4)
		{
			if (level == 3)
			{
				pen = penaltyArr[5];
			}
				
			else if (level == 4)
			{
				pen = penaltyArr[7];
			}

			details.setToggle(0);
		}

		else if (level == 5)
		{
			pen = penaltyArr[1];
		}
	}

	else
	{
		details.setToggle(0);

		if (level == 1 || level == 2)
		{
			pen = penaltyArr[3];
		}

	}

	return pen;
}

string BuildDeck::flameDollPenalty(int level)
{
	string pen = "";

	if (details.getToggle() == 0)
	{
		details.setToggle(1);

		if (level < 5)
		{
			pen = penaltyArr[0];
		}
	}

	else
	{
		details.setToggle(0);

		if (level < 5)
		{
			pen = penaltyArr[1];
		}
	}

	return pen;
}

string BuildDeck::plainDollPenalty(int level)
{
	string pen = "";

	if (details.getToggle() == 0)
	{
		details.setToggle(1);
		if (level < 5)
		{
			pen = penaltyArr[7];
		}
	}

	else if (details.getToggle() == 1)
	{
		details.setToggle(2);
			
		if (level == 1 || level == 2 || level == 5)
		{
			pen = penaltyArr[2];
			details.setToggle(0);
		}

		else if (level == 3 || level == 4)
		{
			pen = penaltyArr[3];
		}
	}

	else
	{
		details.setToggle(0);

		if (level == 3)
		{
			pen = penaltyArr[5];
		}
		else if (level == 4)
		{
			pen = penaltyArr[6];
		}
	}

	return pen;
}

string BuildDeck::flameFarmPenalty(int level)
{
	string pen = "";
		
	if (details.getToggle() == 0)
	{
		details.setToggle(1);

		if (level < 5)
		{
			pen = penaltyArr[0];
		}
	}

	else if (details.getToggle() == 1)
	{
		details.setToggle(0);

		if (level < 5)
		{
			pen = penaltyArr[1];
		}
	}

	return pen;
}

string BuildDeck::plainFarmPenalty(int level)
{
	string pen = "";
		
	if (details.getToggle() == 0)
	{
		details.setToggle(1);

		if (level != 5)
		{
			pen = penaltyArr[4];
		}

		else
		{
			pen = penaltyArr[0];
			details.setToggle(0);
		}
	}
	else if (details.getToggle() == 1)
	{
		details.setToggle(0);

		if (level == 1 || level == 2)
		{
			pen = penaltyArr[2];
		}

		else if (level == 3)
		{
			pen = penaltyArr[5];
		}

		else if (level == 4)
		{
			pen = penaltyArr[6];
		}
	}

	return pen;
}

string BuildDeck::generateID(string type, string level, string cardNum)
{
	string id = type + level + "-" + cardNum;
	return id;
}
		
void BuildDeck::loadCommon()
{
	for (int i = 0; i < 52; i++) {
		
		std::cout << commonRaider[i].getID() << endl;
	}
}

void BuildDeck::loadLieut()
{
	for (int i = 0; i < 7; i++)
	{
		std::cout << lieutRaider[i].getID() << endl;
	}
}

void BuildDeck::loadBoss()
{

	for (int i = 0; i < 7; i++)
	{
		std::cout << bossRaider[i].getID() << endl;
	}
}

void BuildDeck::printPlayingDeck()
{
	for (int i = 0; i < playingDeck.size(); i++)
	{
		cout << playingDeck[i].getID() << endl;
	}
	cout << playingDeck.size() << endl;
}

void BuildDeck::createPlayingDeck(int numPlayers, int round)
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	if (round == 1)
	{
		shuffle(commonRaider.begin(), commonRaider.end(), default_random_engine(seed));

		for (int c = 0; c < numPlayers * 7; c++)
		{
			playingDeck.push_back(commonRaider[c]);
		}
	}
	else if (round == 2)
	{
		shuffle(lieutRaider.begin(), lieutRaider.end(), default_random_engine(seed));

		for (int c = 0; c < numPlayers; c++)
		{
			playingDeck.push_back(lieutRaider[c]);
		}

		shuffle(playingDeck.begin(), playingDeck.end(), default_random_engine(seed));

	}
	else if (round == 3) 
	{	
		shuffle(bossRaider.begin(), bossRaider.end(), default_random_engine(seed));

		for (int c = 0; c < numPlayers; c++)
		{
			playingDeck.push_back(bossRaider[c]);
			
		}

		shuffle(playingDeck.begin(), playingDeck.end(), default_random_engine(seed));
	}
}

