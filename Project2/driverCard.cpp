// Honor Pledge:
//
// I pledge that I have neither given not
// received any help on this assignment
//
// iaustin

#include <iostream>
#include <string>
//#include <fstream> // File Stream Library

#include "card.h"
#include "standardDeck.h"


//Ace,2-10,Jack, King, Queen,
//Spades, Hearts, Clubs, Diamonds

int main()
{
	//std::ifstream inputFile("deck.txt");
	int deckSize;
	int suitVal_;
	int faceVal_;

	
	std::cout << "***Welcome to War the Card Game!***" << std::endl;
	
	std::cout << std::endl;
	StandardDeck testDeck(26);
	testDeck.populateDeck();
	//testDeck.printDeck();
	
	std::cout << std::endl;
	std::cout << "Is the deck empty? " << testDeck.isEmpty() << std::endl;
	std::cout << "Number of Cards: " << testDeck.getNumCards() << std::endl;
	
	int x(15);
	std::cout << x << "th Card: " << std::endl;
	testDeck.displayCard(x);
	
	return 0;
}