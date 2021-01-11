//----------------- DEALER.CPP -----------------

// This is the definition file for class Dealer

#include <iostream>			// for cin, cout
#include <cctype>			// for toupper

#include "utility.h"			// for WaitForUser
#include "dealer.h"			// for obvious reasons

using namespace std;

Dealer::Dealer()
// the way our classes are organized, all that a dealer need
// explicitly do to prepare for a game is shuffle the deck,
// and clear out its own hand
{
   d.Shuffle();
   numCards = 0;
}

void Dealer::PlayGame()
// continues dealing and evaluating hands until there are no
// cards remaining to deal.
{
   cout << "\n\nGame on!!!\n\n";
   do
   {
	DealHand();		// deal and display each hand.
	FindBestHand();		// determine and display the winner.
   }
   while (!EndOfDeck());
}

void Dealer::DetermineResults()
// after all hands are done, display the player's final "pot"
{
   cout << "\n\nPLAYER #1 started with a pot of 10\n";
   cout << "*** FINAL POT: " << p.GetPot() << '\n';
}

void Dealer::ShowHand(int startCard) const
// display the dealer's hand starting with card startCard;
// at the start of a game, the first card can be hidden from
// the player
{
   cout << "\nDealer's hand: \n";
   for (int i = startCard; i < numCards; i++)
	hand[i].Display();
   // display the value showing by determining the hand's value, and
   // subtracting the value of the first (hidden) card
   cout << "*** Value showing: " << HandValue(startCard) << '\n';
}

int Dealer::HandValue(int startCard) const
// determine the numeric value of the dealer's hand
{
   int v;
   int total = 0;
   for (int i = startCard; i < numCards; i++)
   {
	v = hand[i].GetVal();
	if (v <= 10)		total += v;
	else if (v <= 13)  	total += 10;	// it's a face card
	else  			total += 11;	// it's an Ace
   }
   return (total);
}

void Dealer::DealHand()
// deals a complete game to the player and the dealer
{
   StartHand();			// start the game by dealing 2 cards to each
   DealPlayerCards();		// deal the rest of player's cards
   DealDealerCards();		// deal the rest of dealer's cards
}

void Dealer::StartHand()
// start the game by dealing 2 cards each to the player and the dealer
// and displaying the resulting hands
{
   p.ClearHand();		// clear out player's hand
   numCards = 0;		// clear out own hand
   for (int i = 0; i < 2; i++)
   {   DealACardToPlayer();
       DealACardToDealer();
   }
   p.ShowHand();         // show player's hand
   ShowHand(1);          // show dealer's hand (except for first card)
}

void Dealer::DealACardToPlayer()
// take the top card of the deck and place it in player's hand, and
// increment the number of cards in the hand
{
   p.TakeCard(d.DealCard());
}

void Dealer::DealACardToDealer()
// take the top card of the deck and place it in dealer's hand, and
// increment the number of cards in the hand
{
   hand[numCards++] = d.DealCard();
}

void Dealer::DealPlayerCards()
// deal additional cards to the player so long as they are asked for,
// there is room in the hand, and the total is less than 21
{
   char ans;
   do
   {
	cout << "\nDo you want another card ";
	cout << "(Y for yes, N for no)? ";
	cin >> ans;
	ans = toupper(ans);
	if (ans == 'Y')
	{
	   DealACardToPlayer();
	   p.ShowHand();		
	}
   } while ((ans == 'Y') && (p.HandValue() < 21) && (p.NumCards() <= 5));
}

void Dealer::DealDealerCards()
// deal cards to the dealer so long as the total is less than 17
// and there is room in the hand
{
   ShowHand(0);
   // make sure to count all cards, even the hidden one
   while ((HandValue(0) < 17) && (numCards <= 5))
   {
	DealACardToDealer();
	ShowHand(0);
   }
}

void Dealer::FindBestHand()
// compare the hands of the two contestants to find out who,
// if either, won.
{
   // get and display the two final hand scores
   int pVal = p.HandValue();
   int dVal = HandValue(0);

   // it's a draw if both are "over", or if they're equal in value
   if (((pVal > 21) && (dVal > 21)) || (pVal == dVal))
	cout << "Hand was a draw\n";

   // player wins with a better legal hand, or if computer is "over"
   else if (((pVal <= 21) && (pVal > dVal)) || (dVal > 21))
   {
	cout << "Player #1 wins hand\n";	// player wins,
	p.AddToPot(1);				// so update pot
   }

   // computer wins with a better legal hand, or if player is over
   else if (((dVal <= 21) && (dVal > pVal)) || (pVal > 21))
   {
	cout << "Computer wins hand\n";		// computer wins,
	p.AddToPot(-1);				// so update pot
   }

   WaitForUser();
}

int Dealer::EndOfDeck() const
// check to see that we have enough
// cards left to deal a new hand; we need (at most)
// 10 cards.  Returns 1 = yes, 0 = no.
{
   return (d.TopCard() >= 42);
}
