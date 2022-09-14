// Honor Pledge:
//
// I pledge that I have neither given not
// received any help on this assignment
//
// iaustin

#include <iostream>
#include <string>
#include "standardDeck.h"
#include "card.h"

StandardDeck::StandardDeck()
{
	deck_ = new Card[52];
	//deckSize = 1;
}

StandardDeck::~StandardDeck()
{
	delete [] deck_;
}

//Accessor Methods
bool isEmpty()
{
/**	if(deckSize > 0)
		return 0;
	else
		return 1;*/
	
	return 0;
}

int StandardDeck::getNumCards()
{
	return numCards_;
}

void printDeck()
{	
	for (int i = 0; i < DECK_SIZE; i++) 
	{
		Deck[i].print();
	}
}