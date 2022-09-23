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

StandardDeck::StandardDeck(const StandardDeck & standarddeck) : deck_(standarddeck.deck_), numCards_(standarddeck.numCards_)
{
	// said A1=A2 ; setting player 1 and player 2; use for merge decks
	
	//int armysize_;
	//std::string winner_;
	//int p1AvgScore_;
	//int p2AvgScore_;
	//int numRounds_;
}

StandardDeck::StandardDeck(int numCards)
{
	numCards_ = numCards;
	deck_ = new Card[numCards_];
	//initialize();
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

bool StandardDeck::mergeDecks(StandardDeck & merge, bool toShuffle = false)
{
	
}

/**
std::string Course::getWinner()
{
	return winner_;
} */

int StandardDeck::getNumCards()
{
	return numCards_;
}

/**
int StandardDeck::getNumRounds()
{
	return numRounds_;
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
*/

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

void StandardDeck::dealMethod()
{
	armysize_ = numCards_/2;
	int fieldLength;
	Card battleground[fieldLength];
	p1 = new Card[armysize_];
	p2 = new Card[armysize_];
	
	for(int i = 0; i < armysize_; i++)
	{
		Card newCard;
		//newCard.print();
		p1[i] = newCard;
		
		for(int i = 0; i < armysize_; i++)
		{
			Card newCard;
			//newCard.print();
			p2[i] = newCard;
		}
	}
	
	
	
	/** //how many rounds???
	StandardDeck::playWar(bool gameOver = false) //potentially; p1 > p2 > p1 > p2
	{
		int gamePlay(0);
		//int p1AvgScore_(0);
		//int p2AvgScore_(0);
		//int numRounds(0);
		
		while(gamePlay <= 50)
		{
			numRounds++;
			
			while(gameOver == false)
			{
				//if(p1.getFaceVal() == p2.getFaceVal()) 
				// ^except not just the other players card, the card under it [which would in theory be the other player]
				if(battleground[fieldLength].getFaceVal() == battleground[fieldLength-1].getFaceVal()) //get player func ??
				{
					//p1.armysize_ = p1.armysize_ + battleground.getNumCards();
					p1 = p1 + battleground;
					fieldLength(0);
				}
				
				p1PlayCard() //player 1 always goes first
				{
					p1.armysize_ = p1.armysize_ - 1;
					battleground = battleground + 1;
					p1AvgScore_++;
					gamePlay++;
				}
				
				p2PlayCard()
				{
					p2.armysize_ = p2.armysize_ - 1;
					battleground = battleground + 1;
					p2AvgScore_++;
					gamePlay++;
				}
				
				if(p1.armysize_ == numCards_ & p2.armysize_ == 0)
				{
					gameOver = true;
					p1AvgScore_ = armysize_/numRounds;
					winner_ == "Player 1"
				}
				else if(p2.armysize_ == numCards_ & p2.armysize_ == 0)
				{
					gameOver = true;
					p2AvgScore_ = armysize_/numRounds;
					winner_ == "Player 2"
				}
			} //end of while 2
		} //end of while 1
		
	}
	*/
}
