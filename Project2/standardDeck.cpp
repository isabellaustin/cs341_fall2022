// Honor Pledge:
//
// I pledge that I have neither given not
// received any help on this assignment
//
// iaustin

//#include <string>
//#include <iostream>

#include "standardDeck.h"

StandardDeck::StandardDeck() : StandardDeck(52)
{

}

StandardDeck::StandardDeck(int numCards)
{
	numCards_ = numCards;
	deck_ = new Card[numCards_];
}

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

int StandardDeck::getNumCards()
{
	return numCards_;
}


void StandardDeck::displayCard(int i)
{
	deck_[i].print();
}

void StandardDeck::printDeck()
{	
	for(int i = 0; i < numCards_; i++) 
	{
		deck_[i].print();
	} 
}

void StandardDeck::populateDeck()
{
	for (int i=0; i < numCards_; i++)
	{
		Card newCard(3, 11);
		deck_[i] = newCard;
	}
}

/**
for(int j = 0; j < 5; j++)
		Card newCard;
		for(int j = 1; j < 5; j++)
		{
			for (int k = 1; k < 14; k++) 
			{
				newCard((suitVal_+j), (faceVal_+i));
			}
		}
		deck_[i] = newCard;
		
*/