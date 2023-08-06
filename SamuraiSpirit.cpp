#include <iostream>
#include <string>
#include <vector>
#include "BuildDeck.h"

using namespace std;

string uppercase(string word);
BuildDeck deck;


int main()
{
	string action;
	string subAction;
	string name;
	vector<string> playerNames;
	int round = 1;
	bool gameOver = false;

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
	}

	deck.createPlayingDeck(numPlayers, round);
	//deck.printPlayingDeck();
	
	while (!gameOver) {
		
		
		//deck.loadCommon();
		//deck.loadLieut();
		//deck.loadBoss();

		cout << "The bells are ringing! It's time! Get into positions! Here come the raiders!\n";
		// display the first raider
		
		cout << "Samurai do you FIGHT, SUPPORT, or PASS? ";

		cin >> action;
		action = uppercase(action);

		if (action == "FIGHT")
		{

			cout << "\nBeautiful! Will you CONFRONT or DEFEND? ";

			cin >> subAction;
			subAction = uppercase(subAction);

			if (subAction == "CONFRONT")
			{
				cout << "\nPlace raider to the right of the samurai board\n";

			}
			
			else if (subAction == "DEFEND")
			{
				cout << "\nPlace raider to the left of the samurai board\n";

			}
		}
		else if (action == "SUPPORT")
		{
			cout << "\nIt's noble helping your fellow samurai fight\n";
		}
		else if (action == "PASS")
		{
			cout << "\nHalf the battle is knowing your limits\n";
			if (round == 3) 
			{
				gameOver = true;
			}
			else
			{
				round++;
				deck.createPlayingDeck(numPlayers, round);
				//deck.printPlayingDeck();
			}
			

		}
		cout << "\n";

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

