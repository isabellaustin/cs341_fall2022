// Honor Pledge:
//
// I pledge that I have neither given not
// received any help on this assignment
//
// iaustin

#include "card.h"

// Dr. R: Let our Header Guard do its thing.
#include "standardDeck.h"
#include <iostream>
#include <string>


std::string Card::SUIT[] = {"No Suit", "Spades", "Hearts", "Diamonds", "Clubs"};

std::string Card::FACE[] = {"Joker", "Ace", "Two", "Three", "Four", "Five", "Six",  
                       "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

Card::Card() : Card(0,0)
{

}

Card::Card(int suitVal, int faceVal)
{
	suitVal_ = suitVal;
	faceVal_ = faceVal;
}

Card::~Card()
{
	
}


// Accessor Methods
void Card::setSuitVal(int suitVal)
{
	suitVal_ = suitVal;
}

int Card::getSuitVal()
{
	return suitVal_;
}

void Card::setFaceVal(int faceVal)
{
	faceVal_ = faceVal;
}

int Card::getFaceVal()
{
	return faceVal_;
}

void Card::setSuit(std::string suit)
{
	suit_ = suit;
}

std::string Card::getSuit()
{
	return SUIT[suitVal_];
}

void Card::setFace(std::string face)
{
	face_ = face;
}

std::string Card::getFace()
{
	return FACE[faceVal_];
}

void Card::print()
{
	std::cout << FACE[faceVal_] << " of " << SUIT[suitVal_] << std::endl;
}

void Card::initialize(int, int)
{
	Card(suitVal_, faceVal_);
	
	/*for(int i = 0; i < numCards_; i++)
	//{
		for(int j = 1; j < 5; j++)
		{
			for(int k = 1; k < 14; k++) 
			{
				Card newCard(j,k);
				//newCard.print();
				//deck_[i] = newCard;	
			} 
		}
	//} */
}