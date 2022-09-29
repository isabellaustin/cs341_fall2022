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
	//numCards_ = 52;
	deck_ = new Card[numCards_];

}

/**
StandardDeck::StandardDeck(const StandardDeck & standarddeck) : deck_(standarddeck.deck_), numCards_(standarddeck.numCards_)
{
	// said A1=A2 ; setting player 1 and player 2; use for merge decks
	
	int armysize_;
	std::string winner_;
	int p1AvgScore_;
	int p2AvgScore_;
	int numRounds_;
}*/

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
bool StandardDeck::isEmpty() //DONE
{
	if(numCards_ > 0)
		return 0;
	else
		return 1;
} 

bool StandardDeck::addCard(Card c) //DONE
{std::cout << "TEST4" << std::endl;
	numCards_ = 0;
	if(numCards_ != 52)
	{
		deck_[numCards_] = c;
		std::cout << "TEST5" << std::endl;
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
			numCards_ = deckMerge.getNumCards(); // deck_.getNumCards() = numCards_??
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
	numCards_ = 0; //so janky, but it works.
//	for(int l = 0; l < numCards_; l++)
	//{
		for(int j = 1; j < 5; j++)
		{
			for(int k = 1; k < 14; k++) 
			{
				Card newCard(j,k); //WHY i-3?????
				//newCard.print();
				deck_[numCards_] = newCard;
				numCards_++;
			} 
		}
		//break;
	//}
}


Card StandardDeck::displayCard(int i)
{
	return deck_[i]; //.print();
	
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

void StandardDeck::shuffle() //DONE
{
	srand(time(0));
	
	for(int i = 0; i < 3; i++) 
	{
		for(int j = 1; j < numCards_; j++) //maybe num cards -1
		{
			int randShuf = rand()% (numCards_); //+1;
			Card card1 = deck_[randShuf];
			deck_[randShuf] = deck_[j];
			deck_[j] = card1;
			
			//std::random_shuffle(deck_, deck_ + numCards_);
		}
	}
}

Card StandardDeck::dealCard() //DONE
{	std::cout << "TEST1" << std::endl;
	Card dealtCard = deck_[0];
	for (int i = 1; i < numCards_; i++)
	{
		deck_[i-1] = deck_[i];
	}
	numCards_--;
	std::cout << "TEST3" << std::endl;
	return dealtCard; 
}



void StandardDeck::dealDeck()
{/**
	armysize_ = numCards_/2;
	//std::cout << armysize_ << std::endl;
	//deal the deck; these funcs should eventually be a dealCard(); addCard(Card c);
	for(int i=0; i<armysize_;i++)
	{
		//deck_[i].print();
		p1[i] = deck_->displayCard(i); //[i]; //.dealCard();
		p1[i].print();
		std::cout << "test2" << std::endl;
		
		
		//p1.addCard(deck_[i]);
		//deck_.dealCard();
	}
	for(int i=0; i<armysize_;i++)
	{
		p2[i] = deck_[i+armysize_];
		p2[i].print();
	}*/
}

/**
void StandardDeck::p1PlayCard() //player 1 always goes first
{
	deck_.dealCard(); //p1.armysize_ = p1.armysize_ - 1;
	numCards_ = numCards_ + 1;
	p1AvgScore_++;
	gamePlay++;
}

void StandardDeck::p2PlayCard()
{
	deck_.dealCard(); //p2.armysize_ = p2.armysize_ - 1;
	numCards_ = numCards_ + 1;
	p2AvgScore_++;
	gamePlay++;
}
*/
