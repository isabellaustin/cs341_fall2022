// Honor Pledge:
//
// I pledge that I have neither given not
// received any help on this assignment
//
// iaustin

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
	
/**	Card * battleground;
	battleground = new Card[numCards_];
	Card * p1;
	p1 = new Card[armysize1_];
	Card * p2;
	p2 = new Card[armysize2_]; */
	Card * deck_;
	deck_ = new Card[numCards_]; 
	 /* **/

//------------------------------PRINT OUTS--------------------------------------

	std::cout << "***Welcome to War the Card Game!***" << std::endl;
	
	std::cout << std::endl;
	StandardDeck warDeck; //DECK TO SPLIT
	warDeck.populateDeck();
	//int armysize_ = warDeck.getNumCards()/2;
	warDeck.printDeck();
	
	std::cout << std::endl;
	std::cout << "Is the deck empty? " << warDeck.isEmpty() << std::endl;
	std::cout << "Number of Cards: " << warDeck.getNumCards() << std::endl;
	
	int x(15);
	std::cout << x << "th Card: " << std::endl;
	warDeck.displayCard(x);
	
	std::cout << std::endl;

//-------------------------------PLAY WAR--------------------------------------	

	//deal the deck; these funcs should eventually be a dealCard(); addCard(Card c);
	
	//warDeck.dealDeck(); 
	numCards_ = warDeck.getNumCards();
	int armysize1_ = numCards_/2;
	int armysize2_ = armysize1_;
	
	StandardDeck battleground;
	StandardDeck p1(armysize_);
	StandardDeck p2(armysize_);
	
	warDeck.printDeck();
	std::cout << std::endl;

	
	while( warDeck.getNumCards()!=0 )
	{
		/**std::cout << "TEST1" << std::endl;
		std::cout << armysize_ << std::endl;
		std::cout << std::endl; */

		p1.addCard(warDeck.dealCard());
		p2.addCard(warDeck.dealCard());
		//std::cout << "test5" << std::endl;

	}
	p1.printDeck();
	std::cout << std::endl;
	p2.printDeck();
	std::cout << std::endl;

	while(gamePlay <= 50)
	{
		numRounds++;
		//std::cout << gamePlay << std::endl;
		gameOver = false;
		std::cout << "test2" << std::endl;
		while(gameOver == false)
		{	
			//p1PlayCard();
			//battleground.deck_[1] = p2.deck_[1];
			p1.dealCard(); //p1.armysize_--;
			numCards_++;
			p1AvgScore_++;
			gamePlay++;
			std::cout << "test6" << std::endl;
	
			//p2PlayCard();
			//battleground.deck_[1] = p1.deck_[1];
			p2.dealCard(); //p1.armysize_ = p1.armysize_ - 1;
			numCards_++;
			p2AvgScore_++;
			gamePlay++;

			if(battleground.deck_[numCards_].getFace() == battleground.deck_[numCards_-1].getFace()) //get face or faceval??
			{
				armysize1_ += numCards_;
				p1.mergeDecks(battleground, false);
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
	} //end of while 1 */

//------------------------------PRINT OUTS--------------------------------------
	
	std::cout << warDeck.getWinner() << " was the champion with " << warDeck.getNumRounds() << " victories versus " << warDeck.getLoser() << "." << std::endl;
	std::cout << "Player 1 Average Score: " << warDeck.getP1AvgScore() << std::endl;
	std::cout << "Player 2 Average Score: " << warDeck.getP2AvgScore() << std::endl;	
	
	return 0;
}