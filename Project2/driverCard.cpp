// Honor Pledge:
//
// I pledge that I have neither given not
// received any help on this assignment
//
// iaustin

#include <iostream>
#include <fstream> // File Stream Library
#include "card.h"
//#include "standardDeck.h"


//Ace,2-10,Jack, King, Queen,
//Spades, Hearts, Clubs, Diamonds

int main()
{
	
	//std::ifstream inputFile("decktxt");
	int deckSize;
	int suitVal_;
	int faceVal_;
	
	int cards(0);
	Card newCard;
	Card Deck[52];
	
	std::cout << "***Welcome to War the Card Game!***" << std::endl;
	std::cout << std::endl;
	
	std::string suit_("");
	std::string face_("");
	
	//print the 52 cards in a standard deck
	while(cards!=52)
	{
		for(int j = 1; j <5; j++)
		{
			for (int i = 1; i <14; i++) 
			{
				Card newCard((suitVal_+j), (faceVal_+i));
				newCard.print();
				Deck[cards] = newCard;
				cards++;
				
			}
		}
	}
	
	
	for(int i = 1; i < 52; i++)
	{
		Deck[i].print();
	}
	
	for (int i = 0; i < DECK_SIZE; i++) 
	{
		
	}
	
}