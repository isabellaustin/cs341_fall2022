#include <iostream>
#include <string>
#include "card.h"

std::string Card::SUIT[] = {"No Suit", "Spades", "Hearts", "Diamonds", "Clubs"};

std::string Card::FACE[] = {"Joker", "Ace", "Two", "Three", "Four", "Five", "Six",  
                       "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

Card::Card()
{

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
	/**
	if(suitVal_ == 0)
		suit_ = "Joker";
	else if(suitVal_ == 1)
		suit_ = "Spades";
	else if(suitVal_ == 2)
		suit_ = "Hearts"; 
	else if(suitVal_ == 3)
		suit_ = "Diamonds";
	else if(suitVal_ == 4)
		suit_ = "Clubs"; 
	
	return suit_; 
	*/
	
	switch (suit_)
	{
		case 0: "Joker";
			break;
		case 1:	"Spades";
			break;
		case 2: "Hearts";
			break;
		case 3:	"Diamonds";
			break;
		case 4:	"Clubs";
			break;	
	}
	
	return suit_; 
}

void Card::setFace(std::string face)
{
	face_ = face;
}

std::string Card::getFace()
{
	switch (face_)
	{
		case 0: "Joker";
			break;
		case 1: "Ace";
			break;
		case 2: "Two";
			break;
		case 3: "Three";
			break;
		case 4:  "Four";
			break;
		case 5: "Five";
			break;
		case 6:	"Six";
			break;
		case 7:	"Seven";
			break;
		case 8: "Eight";
			break;
		case 9:	"Nine";
			break;
		case 10: "Ten";
			break;
		case 11: "Jack";
			break;
		case 12: "Queen";
			break;
		case 13: "King";
			break;
	}
	
	return face_;
}

void Card::print()
{
	std::cout << suit_ << " of " << face_ << std::endl;
}