// Honor Pledge:
//
// I pledge that I have neither given not
// received any help on this assignment
//
// iaustin

#include <iostream>
//#include <fstream> // File Stream Library

#include "card.h"
#include "standardDeck.h"


//Ace,2-10,Jack, King, Queen,
//Spades, Hearts, Clubs, Diamonds

int main()
{
/**	//std::ifstream inputFile("deck.txt");
	int deckSize;
	int suitVal_;
	int faceVal_;
	
	//int cards(0);
	////Card newCard;
	//Card Deck[52]; */
	
	std::cout << "***Welcome to War the Card Game!***" << std::endl;
	std::cout << std::endl;
	
/**	std::string suit_("");
	std::string face_(""); */
	
	Card test(1,2);
	test.print();
	
	StandardDeck testDeck(52);
	testDeck.printDeck();
	
	return 0;
}