#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "RaidStack.h"
#include "Daisuke.h"
#include "Gorobei.h"
#include "HumanPlayer.h"

using namespace std;

string uppercase(string word);
RaidStack raid;
Samurai sam;
Daisuke daisuke;
Gorobei gorobei;
Raider topCard;
int cardCount = 0;

bool actions(int round, int numPlayers, GenericPlayer& player);

int main()
{
	string name;
	vector<string> playerNames;
	vector<string> samurai = {"Daisuke", "Gorobei", "Heihachi", "Kanbei", "Katsushiro", "Kikuchiyo", "Kyuzo"};
	vector<Samurai> unselectedSamurai = { daisuke, gorobei };
	//vector<Samurai> selected;
	//vector<string> selected;
	vector<HumanPlayer> players;

	vector<Raider> intruderDeck;
	vector<Raider> discardPile;
	Samurai selSam;
	string selectedSamurai;
	int round = 1;
	bool gameOver = 0;
	int numPlayers = 0;

	//vector<Raider> playingDeck;

	while (numPlayers < 1 || numPlayers > 7)
	{
		cout << "How many Samurai?(1-7): ";
		cin >> numPlayers;
	}

	for (int i = 0; i < numPlayers; i++) {
		cout << "Enter your name: ";
		cin >> name;
		playerNames.push_back(name);

		cout << "Select Your Samurai: ";
		//for_each (samurai.begin(), samurai.end(), printSamurai);
		for (int unsel = 0; unsel < unselectedSamurai.size(); unsel++)
		{
			cout << unselectedSamurai[unsel].getName() << " ";
		}
		cout << ":";
		cin >> selectedSamurai;

		if (selectedSamurai == "daisuke")
		{
			//selSam = unselectedSamurai[0];
			selSam = daisuke;
		}

		if (selectedSamurai == "gorobei")
		{
			selSam = gorobei;
		}

		players.push_back(HumanPlayer(name, selSam));
		// create Player class
		// assign player name to Player class, along with Samurai selected.
		// Player class should be part of an array, when searching selected samurai
		// search player array for matching samurai names
		//if(selectedSamurai == samurai)
		cout << "\n";
	}

	raid.buildStack(numPlayers, 1);
	
	while (gameOver != 1) {
		
		for (int p = 0; p < numPlayers; p++) {
			cout << players.at(p).getName() << " " << players.at(p).getSamurai().getName() << "\n";
			//cout << playerNames.at(p) << endl;
			gameOver = actions(round, numPlayers, players.at(p));
			
		}
		round++;
	}

	return 0;
}

string uppercase(string action) 
{
	
	int i = 0;
	for (i = 0; i < action.length(); i++) {
		action[i] = toupper(action[i]);
	}
	return action;
}

bool actions(int round, int numPlayers, GenericPlayer& player) {

	string action;
	string subAction;

	cout << "The bells are ringing! It's time! Get into positions! Here comes a raider!\n";
	// display the first raider
	cout << player.getBT();
	cout << "\nSamurai do you FIGHT, SUPPORT, or PASS? ";

	cin >> action;
	action = uppercase(action);

	if (action == "FIGHT")
	{
		bool cardMove = 0;
		if (cardCount == numPlayers * 7)
		{
			return 1;
		}
		cout << "\nturns left: " << cardCount << "/" << numPlayers * 7 << "\n";
		cout << "\nBeautiful!\n";
		while (cardMove != 1) {

			topCard = raid.flipTopRaider();
			cout << topCard.getID() << "\n";
			cout << "\nCONFRONT or DEFEND: ";

			cin >> subAction;
			subAction = uppercase(subAction);

			if (subAction == "CONFRONT")
			{
				cout << "\nPlace raider to the right of the samurai board\n";
				player.addCombat(raid.drawRaider());
				
				cardMove = 1;
				cardCount++;

			}

			else if (subAction == "DEFEND")
			{
				

				if ((topCard.getDefSym() == "Hat" && player.samuraiHat() == 1)
					|| (topCard.getDefSym() == "Doll" && player.samuraiDoll() == 1)
					|| (topCard.getDefSym() == "Farm" && player.samuraiFarm() == 1))
				{
					cout << "There is already a Raider with a " << topCard.getDefSym() << " symbol\n";
				}
				else if (topCard.getDefSym() == "None")
				{
					cout << "\nThis raider doesn't help defend the village. You MUST CONFRONT the Raider!\n";
				}
				else
				{
					cout << "\nPlace raider to the left of the samurai board\n";
					player.addDefence(raid.drawRaider());
					cardMove = 1;
					cardCount++;
				}
			}
		}
	}
	else if (action == "SUPPORT")
	{
		cout << "\nIt's noble helping your fellow samurai fight\n";
	}

	else if (action == "CHECK")
	{
		player.getSamurai().printDefendLine();
		//player.getCombatLine();
		player.getCombatLine();
		player.getSamurai().getName();
	}
	else if (action == "PASS")
	{
		
		cout << "\nHalf the battle is knowing your limits\n";
		cout << "is the game over? " << " round Number: " << round << "\n";
		if (round == 3)
		{
			return 1;
		}
		else
		{
			
			raid.buildStack(numPlayers, round);
			//deck.printPlayingDeck();
		}
	}
	
	cout << "\n";
	return 0;
}

