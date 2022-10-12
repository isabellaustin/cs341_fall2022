// Honor Pledge:
//
// I pledge that I have neither given not
// received any help on this assignment
//
// iaustin

#include "standardDeck.h"
#include "card.h"

#include <iostream>
#include <string>

StandardDeck::StandardDeck() : StandardDeck(52)
{
	deck_ = new Card[DECK_SIZE];
	numCards_ = 0;
}


StandardDeck::StandardDeck(int numCards)
{
	//numCards_ = numCards;
	deck_ = new Card[numCards];	
	
}

StandardDeck::~StandardDeck()
{
	delete [] deck_;
}

//Accessor Methods
bool StandardDeck::isEmpty() //DONE
{std::cout << "TEST EM1" << std::endl;	
	if(numCards_ > 0)
		return 0;
	else
		return 1;
} 

bool StandardDeck::addCard(Card c) //DONE
{	//std::cout << "TEST 1.3" << std::endl;
	if(numCards_ < DECK_SIZE)
	{ 	//std::cout << "TEST 1.4" << std::endl;
		deck_[numCards_] = c;
		//std::cout << "TEST 1.5" << std::endl;
		numCards_++;
		//std::cout << "TEST 1.6" << std::endl;
		return true;
	}
	return false; 

}

bool StandardDeck::mergeDecks(StandardDeck & deckMerge, bool toShuffle = false) //DONE
{
	int deckRem = 0; //remainder in a standard deck
	deckRem = DECK_SIZE - numCards_;
	std::cout << deckRem << std::endl;
	std::cout << numCards_ << std::endl;
	
	if(numCards_ < DECK_SIZE)
	{
		//merge
		if(deckRem > numCards_)
		{
			std::cout << "TEST 5.1" << std::endl;
			std::cout << deckMerge.getNumCards() << std::endl;
			
			numCards_ = deckMerge.getNumCards();
		}	
		
		std::cout << numCards_ << std::endl;
			
		for(int i = 0; i < deckRem; i++)
		{		
			std::cout << "TEST 5.2" << std::endl;
			deck_[numCards_] = deckMerge.deck_[i]; //i+numCards_ ??
			//std::cout << "TEST 5.25" << std::endl;
		}
		
		numCards_ += deckRem;
		//deckRem.numCards_ = 0;
		
		if(toShuffle)
		{
			std::cout << "TEST 5.3" << std::endl;
			shuffle();
		} 
		std::cout << "TEST 5.4" << std::endl;
		return true;
	}
	else
	{
		std::cout << "TEST 5.5" << std::endl;
		return false;
	}		
}

int StandardDeck::getNumCards()
{
	return numCards_;
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


Card StandardDeck::displayCard(int i)
{
	//std::cout << "TEST 1.9" << std::endl;
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
{	std::cout << "TEST DEAL" << std::endl;
	std::cout << numCards_ << std::endl;
	
	if(!isEmpty())
	{
		Card dealtCard = deck_[numCards_-1];
		numCards_--;
		return dealtCard;
	}
	else
	{
		Card nullCard(0,0);
		return nullCard;
	}
}