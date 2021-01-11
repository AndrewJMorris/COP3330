//----------------- CARDDECK.CPP -----------------

// This file contains the definitions for the
// classes Card and Deck.


#include <iostream>		// for cout
#include <cstdlib>		// for rand(), srand()
#include <ctime>		// for clock()
#include "carddeck.h"

using namespace std;

// card class member functions

void Card::Display() const
// display the suit and value of an individual card
{
   if ((2 <= val) && (val <= 10))		// for number cards, show value
	cout << val;
   else									// for face cards, use abbreviation
   {
	switch (val)
	{
	   case 11:   cout << 'J';   break;
	   case 12:   cout << 'Q';   break;
	   case 13:   cout << 'K';   break;
	   case 14:   cout << 'A';   break;
	}
   }
		
   switch (s)							// display suit
   {
	case CLUBS:		cout << " of clubs"; 	  break;
	case DIAMONDS:	cout << " of diamonds";   break;
	case HEARTS:	cout << " of hearts"; 	  break;
	case SPADES:	cout << " of spades"; 	  break;
   }
   cout << '\n';
}

int Card::GetVal() const
// return the numeric value of a card
{   return val;  }

void Card::SetVal(int v)
// set the numeric value of a card
{   val = v;   }

Suit Card::GetSuit() const
// return the suit value of a card
{   return s;  }

void Card::SetSuit(Suit st)
// set the suit of a card
{   s = st;  }

// general utility function for random-number seeding

void Randomize()
// COMPILER-SPECIFIC: sets the random number generator's seed.
{
   unsigned int seed = unsigned(clock());
   srand(seed);
}

// Deck class member functions

Deck::Deck()
// constructor for initializing a new deck of 52 cards
{
   topCard = 0;					// we haven't dealt any cards yet
	
   for (int i = 0; i < 52; i++)			// for each card in the deck:
   {
	cards[i].SetVal((i % 13) + 2);		// assign it a numeric value (2 - 14)
	switch (i / 13)	 					// and a suit.
	{
	   case 0:   cards[i].SetSuit(CLUBS);	 	break;
	   case 1:   cards[i].SetSuit(DIAMONDS);	break;
	   case 2:   cards[i].SetSuit(HEARTS);		break;
	   case 3:   cards[i].SetSuit(SPADES);		break;
	}
   }
}

void Deck::Shuffle()
// shuffle the deck and set the deal position to the beginning
{
   Randomize();
   for (int i = 0; i < 3; i++)		// Shuffle 3 times.
   {
	for (int j = 0; j < 52; j++)    // Rearrange each card (0 - 51).
        {
	   int r = rand() % 52;         // Pick a location to swap j-th 
					//  card with
	   Card c = cards[j];
	   cards[j] = cards[r];
	   cards[r] = c;
        }
   }
   topCard = 0;				// no cards dealt yet
}

void Deck::ShuffleRest()
// shuffle the REST of the undealt cards (leaving topCard at same position).
{
   Randomize();
   for (int i = 0; i < 3; i++)		// Shuffle 3 times.
   {
	for (int j = topCard; j < 52; j++)    
        {
	   // swap j-th card with a random card
	   int r = rand() % (52-topCard) + topCard;   
	   Card c = cards[j];
	   cards[j] = cards[r];
	   cards[r] = c;
        }
   }
}

Card Deck::DealCard()
// deal one card from the top of the deck, and return it
// NOTE -- NEED to add in error check for exhausted deck.
// (and decide on how to handle).
{
   Card deal;
   deal = cards[topCard];	// next deal position
   topCard++;			// increment deal position
   return deal;
}

int Deck::TopCard() const
{    return topCard;  }
