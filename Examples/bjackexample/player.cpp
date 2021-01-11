//----------------- PLAYER.CPP -----------------
// Definition file for class Player

#include <iostream>		// for cin, cout
#include "player.h"		// for class Player

using namespace std;

Player::Player()
// this constructor for class Player defines a player's initial
// pot to be 10 and gives the player an empty hand
{
   pot = 10;
   ClearHand();
}

void Player::ClearHand()
{   numCards = 0;  }

void Player::TakeCard(Card c)
// receive a dealt card and store in hand
{
   if (numCards == 5)
	return;			         // error check - abort if hand full

   hand[numCards] = c;		// put card into hand
   numCards++;			      // increment tracking variable
}

int Player::NumCards() const
{   return numCards;   }

int Player::GetPot() const
{   return pot;   }

void Player::AddToPot(int val)
{
   pot += val;
}

int Player::HandValue() const
// determine the numeric value of the player's hand
{
   int v;
   int total = 0;
   for (int i = 0; i < numCards; i++)
   {
	v = hand[i].GetVal();
	if (v <= 10)		   total += v;
	else if (v <= 13)  	total += 10;
	else  			      total += 11;
   }
   return (total);
}

void Player::ShowHand() const
// use the Display function of class Card to show the hand
{
   cout << "\nPLAYER #1's hand: \n";
   for (int i = 0; i < numCards; i++)
	hand[i].Display();
   cout << "*** Total value: " << HandValue() << '\n';
}
