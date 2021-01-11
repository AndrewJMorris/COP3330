//----------------- DEALER.H -----------------

// This embodies the activities of a dealer as well as the rules
// of a particular game.  The numbers of players and decks used,
// and the DealHand and FindBestHand functions can be redefined
// to describe any card game.

#include "player.h"		// for class Player
// Note that since file "player.h" includes the file "carddeck.h"
// we need not include the latter here, even though we refer
// to declarations from it (Deck).

class Dealer
{
public:
   Dealer();			// prepare a dealer to play
   void PlayGame();		// play one complete game
   void DetermineResults();	// announce the final tally
	
private:
   Player p;			// this game has one player,
   Deck d;			// and one deck
   Card hand[5];		// a dealer has a hand of at most 5 cards
   int numCards;		// the current number of cards in the hand

   int HandValue(int) const;	// determines the hand's numeric value
   void ShowHand(int) const;	// display hand starting with specified card

   void DealHand();		// deal one hand, which involves...
   void StartHand();		// deal the first 2 cards to each player
   void DealACardToPlayer();	// deal a single card to the player
   void DealACardToDealer();	// deal a single card to the dealer
   void DealPlayerCards();	// deal remaining cards to the player
   void DealDealerCards();	// deal remaining cards to the dealer

   void FindBestHand();		// find the winner of a hand
   int EndOfDeck() const;	// check whether there are enough cards left
};
