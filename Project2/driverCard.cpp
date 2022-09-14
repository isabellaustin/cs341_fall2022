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
	
	//std::string suit("");
	//std::string face("");
	Card cardTest(0,1);
	cardTest.print();
}