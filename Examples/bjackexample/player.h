//----------------- PLAYER.H -----------------

// Declarations for a player in our simple card game.
// These could be modified to accomodate a variety
// of different card games.

#include "carddeck.h"		// for class Card

class Player
{
public:
   Player();		   // initializes a new player
   void ClearHand();	   // clear out player's hand -- reset for new deal
   void TakeCard(Card c);  // receive a dealt card into hand
   int NumCards() const;   // return number of cards in hand
   int GetPot() const;	   // return value in the "pot".
   void AddToPot(int val); // add val to the pot
   int HandValue() const;  // calculates the numeric value of the hand
   void ShowHand() const;  // displays a player's hand and value

private:
   Card hand[5];	   // for this game, a hand is at most 5 cards
   int pot;		      // one point for a win, lose one for a loss
   int numCards;	   // the number of cards currently in the hand
};
