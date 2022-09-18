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
	int suitVal_ = 1;
	int faceVal_ = 1;
	
	for (int i = 0; i < numCards_; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			for (int i = 0; i < 13; i++) 
			{
				Card newCard((suitVal_+(j-3)), (faceVal_+i)); //WHY i-3?????
				deck_[i] = newCard;
			} 
		}
	}
}

/**
for (int i=0; i < numCards_; i++)

for(int j = 0; j < 5; j++)
(	
	for(int j = 1; j < 5; j++)
	{
		for (int i = 1; i < 14; i++) 
		{
			newCard((suitVal_+j), (faceVal_+(i-3))); //WHY i-3?????
		}
	}
}
		
*/