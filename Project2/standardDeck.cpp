// Honor Pledge:
//
// I pledge that I have neither given not
// received any help on this assignment
//
// iaustin

#include "standardDeck.h"

StandardDeck::StandardDeck() : StandardDeck(52)
{

}

StandardDeck::StandardDeck(int numCards)
{
	numCards_ = numCards;
	deck_ = new Card[numCards_];
}

/**
StandardDeck::StandardDeck(int suitVal, int faceVal)
{
	suitVal_ = suitVal;
	faceVal_ = faceVal;
} */

StandardDeck::~StandardDeck()
{
	delete [] deck_;
}

//Accessor Methods

bool StandardDeck::isEmpty()
{
	if(numCards_ > 0)
		return 0;
	else
		return 1;
} 

bool StandardDeck::addCard(Card c)
{
	if(numCards_ < 52)
		return 1;
	else
		return 0;
}

bool StandardDeck::mergeDecks(StandardDeck & merge, bool isMerging = false)
{
	isMerging = 0;
}

int StandardDeck::getNumCards()
{
	return numCards_;
}

void StandardDeck::displayCard(int i)
{
	deck_[i].print();
	
	/**
	int* iPTR(nullptr);
	std::cout << i << std::endl;
	std::cout << iPTR << std::endl;
	iPTR = &i;  */
}

void StandardDeck::printDeck()
{	
	for(int i = 0; i < numCards_; i++) 
	{
		deck_[i].print();
	} 
}

void StandardDeck::shuffle()
{
	for(int i = 0; i < 3*numCards_; i++) 
	{
		std::random_shuffle(deck_, deck_ + numCards_);
	}
}