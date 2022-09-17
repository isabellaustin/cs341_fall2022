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
	int i;
	
	int cards(0);
	Card newCard;
	Card Deck[52];  */
	
	std::cout << "***Welcome to War the Card Game!***" << std::endl;
	std::cout << std::endl;
	
/**	std::string suit_("");
	std::string face_("");
	
	for (int i=0; i < numCards_; i++)
	{
		Card newCard("Test","Testerson",i);
		
		deck_[i] = newCard;
	} */
	
	Card test(1,2);
	test.print();
	
	StandardDeck testDeck(52);
	testDeck.printDeck(); //should be in final
	
	std::cout << "Is the deck empty? " << testDeck.isEmpty() << std::endl;
	std::cout << "Number of Cards: " << testDeck.getNumCards() << std::endl;
	std::cout << /**i << */ "th Card: " /**<< testDeck.displayCard(int i) */ << std::endl; 
	
	return 0;
}