// Honor Pledge:
//
// I pledge that I have neither given not
// received any help on this assignment
//
// iaustin

#include "standardDeck.h"

// Dr. R: Let's let our Header Guard do its job here...
#include "card.h"
#include <iostream>
#include <string>

StandardDeck::StandardDeck() : StandardDeck(52)
{
	// Dr. R: We don't want to set the number of cards
	//		  to be 52 here as that indicates the deck
	//		  would be full.
	numCards_ = 52;
	deck_ = new Card[numCards_];
}

/**
StandardDeck::StandardDeck(const StandardDeck & standarddeck) : deck_(standarddeck.deck_), numCards_(standarddeck.numCards_)
{	
	int armysize_;
	std::string winner_;
	int p1AvgScore_;
	int p2AvgScore_;
	int numRounds_;
}*/

StandardDeck::StandardDeck(int numCards)
{
	// Dr. R: We don't want to set the number of cards
	//		  to be 52 here as that indicates the deck
	//		  would be full.
	numCards_ = numCards;
	deck_ = new Card[numCards_];
	
}

StandardDeck::~StandardDeck()
{
	delete [] deck_;
}

//Accessor Methods
bool StandardDeck::isEmpty() //DONE
{
	if(numCards_ > 0)
		return 0;
	else
		return 1;
} 

bool StandardDeck::addCard(Card c) //DONE
{
	if(numCards_ < 52)
	{
		deck_[numCards_] = c;
		numCards_++;
		return 1;
	}
	else
	{	return 0; }
}

bool StandardDeck::mergeDecks(StandardDeck & deckMerge, bool toShuffle = false) //DONE
{
	int deckRem(0); //remainder in a standard deck
	deckRem = DECK_SIZE - numCards_;
	
	if(numCards_ < DECK_SIZE)
	{
		//merge
		if(deckRem > numCards_)
		{
			numCards_ = deckMerge.getNumCards();
		}
			
		for(int i = 0; i < deckRem; i++)
		{		
			deck_[i+numCards_] = deckMerge.deck_[i];
		}
		
		numCards_ += deckRem;
		//deckRem.numCards_ = 0;
		
		if(toShuffle)
		{
			shuffle();
		}
		
		return true;
	}
	else
	{
		return false;
	}		
}

std::string StandardDeck::getWinner()
{
	return winner_;
}

std::string StandardDeck::getLoser()
{
	return loser_;
} 

int StandardDeck::getNumCards()
{
	return numCards_;
}

int StandardDeck::getNumRounds()
{
	return numRounds;
}

int StandardDeck::getArmySize()
{
	return armysize_;
} 

int StandardDeck::getP1AvgScore()
{
	return p1AvgScore_;
} 

int StandardDeck::getP2AvgScore()
{
	return p2AvgScore_;
} 


void StandardDeck::populateDeck()
{
	numCards_ = 0; //not ideal
	for(int j = 1; j < 5; j++)
	{
		for(int k = 1; k < 14; k++) 
		{
			Card newCard(j,k);
			//newCard.print();
			deck_[numCards_] = newCard;
			numCards_++;
		} 
	}
}

// Dr. R: Some of these methods are common to both
//		  Standard and Non-Standard decks - we need
//		  to move those there.

Card StandardDeck::displayCard(int i)
{
	return deck_[i];
}

void StandardDeck::printDeck()
{	
	for(int i = 0; i < numCards_; i++) 
	{
		deck_[i].print();
	} 
}

void StandardDeck::shuffle() //DONE
{
	srand(time(0));
	
	for(int i = 0; i < 3; i++) 
	{
		for(int j = 1; j < numCards_; j++)
		{
			int randShuf = rand()% (numCards_); //+1;
			Card card1 = deck_[randShuf];
			deck_[randShuf] = deck_[j];
			deck_[j] = card1;
		}
	}
}

Card StandardDeck::dealCard() //DONE
{	std::cout << "TEST1" << std::endl;
	numCards_=52;
	Card dealtCard = deck_[1];
	for (int i = 1; i < numCards_/2; i++)
	{
		deck_[i-1] = deck_[i];
	}
	numCards_--;
	
	return dealtCard; 
}