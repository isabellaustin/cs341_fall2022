// Honor Pledge:
//
// I pledge that I have neither given not
// received any help on this assignment
//
// iaustin

#include <iostream>
#include <string>
#include "card.h"

std::string Card::SUIT[] = {"No Suit", "Spades", "Hearts", "Diamonds", "Clubs"};

std::string Card::FACE[] = {"Joker", "Ace", "Two", "Three", "Four", "Five", "Six",  
                       "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

Card::Card()
{
	suitVal_ = 0;
	faceVal_ = 0;
}

Card::Card(int suitVal, int faceVal)
{
	suitVal_ = suitVal;
	faceVal_ = faceVal;
}

/**
Card::Card(int suitVal, int faceVal, std::string suit, std::string face)
{
	suitVal_ = suitVal;
	faceVal_ = faceVal;
	suit_ = suit;
	face_ = face;
} */

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
	
	/**if(suitVal_ == 0)
	{
		return "Joker";
	}
	else if(suitVal_ == 1)
		suit_ = "Spades";
	else if(suitVal_ == 2)
		suit_ = "Hearts"; 
	else if(suitVal_ == 3)
		suit_ = "Diamonds";
	else if(suitVal_ == 4)
		suit_ = "Clubs"; 
	
	return suit_; */
}

void Card::setFace(std::string face)
{
	face_ = face;
}

std::string Card::getFace()
{
	
	return FACE[faceVal_];
	
	//FACE[faceVal_] = face_;
	//return face_;
	
	//0-13
}

void Card::print()
{
	std::cout << FACE[faceVal_] << " of " << SUIT[suitVal_] << std::endl;
}