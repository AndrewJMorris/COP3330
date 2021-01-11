//----------------- CARDDECK.H -----------------

// These are the declarations of classes Card
// and Deck, to be used by card-playing programs.

enum Suit {CLUBS, DIAMONDS, HEARTS, SPADES};

class Card
// this class describes a single card
{
public:

   void Display() const;  // for displaying a card in a readable fashion
   int GetVal() const;    // retrieves the card's value
   void SetVal(int);      // sets the card's value to the value provided
   Suit GetSuit() const;  // retrieves the card's suit
   void SetSuit(Suit);    // sets the card's suit to the suit provided

private:             		
   Suit s;		  // each card has a suit
   int val;		  // and a value (2 ... 14, representing 2 ... Q, K, A)
};

class Deck
// This class describes a collection of 52 cards
{
public:
   Deck();		            // the constructor opens a new deck of cards.
   void Shuffle();	      // shuffle the cards in the deck
   void ShuffleRest();	   // shuffle the REST of the currently undealt cards
   Card DealCard();	      // deal one card from the deck (and return it)
   int TopCard() const;	   // return top card position

private:
   int topCard;		// points to position of current top card of deck
   Card cards[52];	// a deck is 52 cards.
};
