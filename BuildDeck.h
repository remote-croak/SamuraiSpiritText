#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include "Raider.h"
#include "DeckDetails.h"

using namespace std;

class BuildDeck
{
private:

	string type;
	string hasSymbol;
	string hasPenalty;
	string hasBossPenalty;
	string id;

	string defSymbol;
	string penaltyArr[8] = { "Fire", "Wound", "Ninja", "Cancel-Block", "Cancel-Support", "Pass-Left", "Pass-Right", "None" };
	string bossPenaltyArr[4] = { "Demon", "Swords", "Meeple", "Discard" };

	int deckSize;

	bool isFlame;
	
	Raider raid;
	array<Raider, 52> commonRaider;
	array<Raider, 7> lieutRaider;
	array<Raider, 8> bossRaider;

	vector<Raider> playingDeck;

	/*Raider* commonDeck;
	Raider* lieutDeck;
	Raider* bossDeck;*/

	DeckDetails details;

	void createRaider(int level);
	void initRaider(int level);
	void checkSymbols();
	void checkFlames(int level);
	void checkHatFlames(int level);
	void checkDollFlames(int level);
	void checkFarmFlames(int level);
	void setRaiderPenalties(int card, int level);
	void addRaider(Raider raid, int card);
	void reduceSymbolCount();

	//void createPlayingDeck(int numPlayers, int round);

	string bossPenalties(int card);
	string commonPenalty(int level);
	string generateID(string type, string level, string cardNum);
	
	string flameBlankPenalty(int level);
	string plainBlankPenalty(int level);
	string flameHatPenalty(int level);
	string plainHatPenalty(int level);
	string flameDollPenalty(int level);
	string plainDollPenalty(int level);
	string flameFarmPenalty(int level);
	string plainFarmPenalty(int level);
	
	
public:
	
	BuildDeck();
	void createPlayingDeck(int numPlayers, int round);
	//void makeCards();

	void loadCommon();
	void loadLieut();
	void loadBoss();
	void printPlayingDeck();

};