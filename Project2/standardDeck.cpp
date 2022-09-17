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
	//std::cout << deck_[i].print() << std::endl;
}

void StandardDeck::printDeck()
{	
	for(int i = 0; i < numCards_; i++) 
	{
		std::cout << deck_[i].print() << std::endl;
	} 
}