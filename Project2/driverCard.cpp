// Honor Pledge:
//
// I pledge that I have neither given not
// received any help on this assignment
//
// iaustin

/** Unfortunately, I wasn't able to finish this project. I did start it the day 
it was assigned and consistently worked on it; however, for some reason, I thought 
the actual game part was intended to be a method in standardDeck.cpp. I didn't 
realize my mistake until the Tuesday before it was due and it set me back about a 
week. While I did go to tutoring every day and tried to get it as working as I could, 
at that point, my code was a mess and it wasn't realistic that I was going to finish 
it. Additionally, I was behind on most of my other school work seeing as I spent 
about 98% of my time trying to fix it. Long story short, I'm sorry this code is 
definitely not my best work. */


#include <iostream>
#include <string>
#include <fstream> // File Stream Library

#include "card.h"
#include "standardDeck.h"

int main()
{
//-----------------------------FILE READ-IN-------------------------------------
	/**
	int suit_, face_;
	
	std::ifstream inputFile("deck.txt");
	inputFile >> name;
	inputFile >> suit_ >> face_;
	*/
//-----------------------------DECLARATIONS-------------------------------------
	std::string winner_ = "TBD";
	std::string loser_;
	
	bool gameOver;
	
	int armysize_;
	int p1AvgScore_;
	int p2AvgScore_;
	int numRounds;
	int numCards_;
	int gamePlay(0);

	Card * deck_;
	deck_ = new Card[numCards_]; 

//------------------------------PRINT OUTS--------------------------------------

	std::cout << "***Welcome to War the Card Game!***" << std::endl;
	
	std::cout << std::endl;
	StandardDeck warDeck; //DECK TO SPLIT
	warDeck.populateDeck();
	warDeck.printDeck();
	
	std::cout << std::endl;
	std::cout << "Is the deck empty? " << warDeck.isEmpty() << std::endl;
	std::cout << "Number of Cards: " << warDeck.getNumCards() << std::endl;
	
	int x(15);
	std::cout << x << "th Card: " << std::endl;
	warDeck.displayCard(x);
	
	std::cout << std::endl;

//-------------------------------PLAY WAR--------------------------------------	

	numCards_ = warDeck.getNumCards();
	int armysize1_ = numCards_/2;
	int armysize2_ = armysize1_;
	
	StandardDeck battleground;
	StandardDeck p1(armysize_);
	StandardDeck p2(armysize_);
	
	warDeck.printDeck();
	std::cout << std::endl;

	
	while(numCards_!=0 )
	{
		p1.addCard(warDeck.dealCard());
		p2.addCard(warDeck.dealCard());
	}
	p1.printDeck();
	std::cout << std::endl;
	p2.printDeck();
	std::cout << std::endl;
	

/**	while(gamePlay <= 50)
	{
		numRounds++;
		gameOver = false;

		while(gameOver == false)
		{	
			//p1 takes a turn
			p1.dealCard();
			numCards_++;
			p1AvgScore_++;
			gamePlay++;
			std::cout << "test6" << std::endl;
	
			//p2 takes a turn
			p2.dealCard();
			numCards_++;
			p2AvgScore_++;
			gamePlay++;

			if(battleground.deck_[numCards_].getFace() == battleground.deck_[numCards_-1].getFace()) //get face or faceval??
			{
				armysize1_ += numCards_;
				battleground.mergeDecks(p1, false);
				numCards_ = 0;
			}			
		
			if(armysize1_ == numCards_ & armysize2_ == 0)
			{
				gameOver = true;
				p1AvgScore_ = armysize1_/numRounds;
				winner_ = "Player 1";
				loser_ = "Player 2";
			}
			else if(armysize2_ == numCards_ & armysize1_ == 0)
			{
				gameOver = true;
				p2AvgScore_ = armysize2_/numRounds;
				winner_ = "Player 2";
				loser_ = "Player 1";
			}
		} //end of while 2 
	} //end of while 1
*/
//------------------------------PRINT OUTS--------------------------------------
	
	std::cout << warDeck.getWinner() << " was the champion with " << warDeck.getNumRounds() << " victories versus " << warDeck.getLoser() << "." << std::endl;
	std::cout << "Player 1 Average Score: " << warDeck.getP1AvgScore() << std::endl;
	std::cout << "Player 2 Average Score: " << warDeck.getP2AvgScore() << std::endl;	
	
	return 0;
}