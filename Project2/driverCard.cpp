// Honor Pledge:
//
// I pledge that I have neither given not
// received any help on this assignment
//
// iaustin

#include <iostream>
#include <fstream> // File Stream Library
#include "card.h"


//Ace,2-10,Jack, King, Queen,
//Spades, Hearts, Clubs, Diamonds

int main()
{
	/*
	Card * card_ = new Card();

	(*card_).make_card(s,f);
	
	card_.printInfo(); */
	
	//std::ifstream inputFile("decktxt");
	
	std::cout << "***Welcome to the deckstravaganza!***" << std::endl;
	std::cout << std::endl;
	
	std::string suit_("");
	std::string face_("");
	int suitVal_;
	int faceVal_;
	//Card newCard;
	//Card deck[52];
	
	//Card cardTest(0,1);
	//cardTest.print();
	
	for(int j = 1; j <5; j++)
	{
		for (int i = 1; i <14; i++) 
		{
			Card newCard((suitVal_+j), (faceVal_+i));
			newCard.print();
		}
	}
	
}