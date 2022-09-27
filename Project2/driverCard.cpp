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
	StandardDeck warDeck;
	warDeck.printDeck();
	//warDeck.initialize();
	//warDeck.printDeck();
	
	std::cout << std::endl;
	std::cout << "Is the deck empty? " << warDeck.isEmpty() << std::endl;
	std::cout << "Number of Cards: " << warDeck.getNumCards() << std::endl;
	
	int x(15);
	std::cout << x << "th Card: " << std::endl;
	warDeck.displayCard(x); // ask Rybar???
	
	//std::cout << "Can you add another card? " << warDeck.addCard() << std::endl;
	
	/**
	std::cout << warDeck.getWinner() << " was the champion with " << warDeck.getNumRounds() << " victories versus " << ?? << "." << std::endl;
	std::cout << "Player 1 Average Score: " << warDeck.getP1AvgScore() << std::endl;
	std::cout << "Player 2 Average Score: " << warDeck.getP2AvgScore() << std::endl;
	*/
	
	return 0;
}