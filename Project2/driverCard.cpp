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

int main()
{
//-----------------------------DECLARATIONS-------------------------------------
	//std::ifstream inputFile("deck.txt");
	std::string winner_;
	std::string loser_;
	
	bool gameOver;
	
	int p1AvgScore_;
	int p2AvgScore_;
	int numRounds;
	int numCards_;
	int gamePlay(0);
	int armysize1_ = numCards_/2;
	int armysize2_ = armysize1_;
	
	Card * battleground;
	battleground = new Card[numCards_];
	Card * p1;
	p1 = new Card[armysize1_];
	Card * p2;
	p2 = new Card[armysize2_];
	Card * deck_;
	deck_ = new Card[numCards_];
/**	
	
	StandardDeck battleground;
	StandardDeck p1(armysize1_);
	StandardDeck p2(armysize2_); */
	

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
	warDeck.displayCard(x); // ask Rybar???
	
	std::cout << std::endl;

//-------------------------------PLAY WAR--------------------------------------	

	//deal the deck; these funcs should eventually be a dealCard(); addCard(Card c);
	
	warDeck.dealDeck(); 
	/**
	for(int i=0; i<armysize1_; i++)
	{
		std::cout << "TEST1" << std::endl;
		p1[i] = warDeck.deck_[i];
		//std::cout << std::endl;
		p1[i].print();
		//warDeck.dealCard();
		//p1.addCard(deck_[i]);
		
	}
	for(int i=0; i<armysize2_; i++)
	{ std::cout << "TEST2" << std::endl;
		p2[i] = warDeck.deck_[i+armysize2_];
		//std::cout << std::endl;
		p2[i].print();
		//warDeck.dealCard();
		//p2.addCard(deck_[i+armysize2_]);
	}*/
	
	std::cout << "test1" << std::endl;
/**	
	while(gamePlay <= 50)
	{
		numRounds++;
		//std::cout << gamePlay << std::endl;
		gameOver = false;
		std::cout << "test2" << std::endl;
		while(gameOver == false)
		{	
			
			//p1PlayCard();
			//battleground[0] = p1[0];
			//p1[i].print();
			p1.dealCard(); //p1.armysize_--;
			numCards_++;
			p1AvgScore_++;
			gamePlay++;
			std::cout << "test6" << std::endl;


			//p2PlayCard();
			battleground[1] = p1[1];
			warDeck.dealCard(); //p1.armysize_ = p1.armysize_ - 1;
			numCards_++;
			p2AvgScore_++;
			gamePlay++;

			if(battleground[numCards_].getFace() == battleground[numCards_-1].getFace()) //get face or faceval??
			{
				armysize1_ += numCards_;
				//p1.mergeDecks(battleground, false);
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