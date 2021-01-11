//----------------- game.cpp -----------------

// This program uses classes Deck, Player, and Dealer
// to play a simple game of black jack.  The player may
// draw up to five cards, and the dealer acts like the
// "house" in that it must draw if under 17.  All aces are
// counted as 11.

#include <iostream>
#include "dealer.h"		// for classes Dealer, Player, and Deck
#include "utility.h"

using namespace std;

int main()
{
   do
   {
	// create a dealer, which implicitly creates
	// a player and a new deck of cards
	Dealer theDealer;
	
	// start a game
	theDealer.PlayGame();
	theDealer.DetermineResults();
   } while (!ReadyToQuit());
	
   cout << "Goodbye!\n";
   return 0;
}

