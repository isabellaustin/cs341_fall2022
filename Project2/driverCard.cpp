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

//--------------------AVERAGE SCORE--------------------

int averageScore(int scores[], int numScores)
{
	int avgScore(0);
	
	for (int i = 0; i < numScores; i++) 
	{
		avgScore += scores[i];
	}
	
	avgScore = avgScore/numScores;

	return avgScore;
}

//------------------------MAIN-------------------------
int main()
{
	std::cout << "***Welcome to War the Card Game!***" << std::endl;
	std::cout << std::endl;

//-----------------------------DECLARATIONS-------------------------------------	

	StandardDeck warDeck; //DECK TO SPLIT
	//warDeck.shuffle();
	warDeck.populateDeck();
	//warDeck.printDeck();
	
	int p1AvgScore_, p2AvgScore_, score_;
	int p1NumWins_ = 0;
	int p2NumWins_ = 0;
	int* p1Score_ = new int[100];
	int* p2Score_ = new int[100];
	
	int numCards_ = 0;
	int numRounds = 0;
	int player;
	
	std::string winner;
	std::string loser;

//-------------------------------PLAY WAR--------------------------------------	
	
	while(numRounds < 2)
	{
		numCards_ = warDeck.getNumCards();
		//warDeck.shuffle();
		
		
		int armysize1_ = numCards_/2;
		//int armysize2_ = armysize1_;
		
		StandardDeck battleground;
		StandardDeck p1(armysize1_);
		StandardDeck p2(armysize1_);
		
		std::cout << "TEST 1" << std::endl;
		for (int i = 0; i < armysize1_; i++) 
		{
		  p1.addCard(warDeck.displayCard(i));
		  p2.addCard(warDeck.displayCard(i+armysize1_));
		}
	
	/**	p1.printDeck();
		std::cout << std::endl;
		p2.printDeck();
	*/	
		
		std::cout << "TEST 2" << std::endl;
		bool gameOver = false;
		player = 1;
		
		Card c1, c2, nullCard(0,0);

		while(gameOver == false)
		{	
			
			std::cout << "TEST 1" << std::endl;	
			if(player == 1 && p1.isEmpty()) 
			{std::cout << "TEST 1.1" << std::endl;	
				score_ = p2.getNumCards();
				p2Score_[p2NumWins_] = score_;	
				p2NumWins_++;
				gameOver = true;
			}
			else if (player == 2 && p2.isEmpty())
			{std::cout << "TEST 1.2" << std::endl;	
				score_ = p1.getNumCards();
				std::cout << "TEST 1.3" << std::endl;
				p1Score_[p1NumWins_] = score_;
				p1NumWins_++;
				gameOver = true;
			}
			
			std::cout << "TEST 2" << std::endl;	
			std::cout << player << std::endl;
			
			if(player == 1)
			{std::cout << "TEST 3" << std::endl;
				c1 = p1.dealCard();
			}
			else if(player != 1)
			{std::cout << "TEST 3.25" << std::endl;
				c1 = p2.dealCard();
			}
			
			if(battleground.getNumCards() == 0)
			{std::cout << "TEST 3.5" << std::endl;	
				c2 = nullCard;
			}
			else
			{	c2 = battleground.displayCard(battleground.getNumCards()-1); }
			
			std::cout << "TEST 4" << std::endl;
			battleground.addCard(c1);
			
			std::cout << c1.getFace() << std::endl;
			std::cout << c2.getFace() << std::endl;
			if(c1.getFace() == c2.getFace())
			{	
				//battleground.printDeck();
				
				if(player == 1)
				{
					std::cout << "TEST 51" << std::endl;
					p1.mergeDecks(battleground, false);
				}
				else //if(player == 2)
				{
					std::cout << "TEST 52" << std::endl;
					p2.mergeDecks(battleground, false);
					std::cout << "TEST 52.1" << std::endl;
					
				}
			}
			else
			{
				std::cout << "TEST 6" << std::endl;
				if(player == 1)
				{
					player = 2;
				}
				else
					player = 1;
			}	
			std::cout << "TEST 6.5" << std::endl;
			
			//std::cout << p1.getNumCards() << std::endl;
			//std::cout << p2.getNumCards() << std::endl;
		} 
		
		numRounds++;
		std::cout << numRounds << std::endl;
	}
	std::cout << "TEST 7" << std::endl;
	std::cout << p2NumWins_ << std::endl;
	std::cout << p1NumWins_ << std::endl;
	
	if(p1NumWins_ > p2NumWins_)
	{
		winner = "Player 1";
		loser = "Player 2";
	}
	else if(p2NumWins_ > p1NumWins_)
	{
		winner = "Player 2";
		loser = "Player 1";
	}
	
	std::cout << winner << std::endl;
	p1AvgScore_ = averageScore(p1Score_, p1NumWins_);
	p2AvgScore_ = averageScore(p2Score_, p2NumWins_);
	

/**	
//-----------------------------FILE READ-IN-------------------------------------
	
	int suit_, face_;
	
	std::ifstream inputFile("deck.txt");
	inputFile >> name;
	inputFile >> suit_ >> face_;
	
//-----------------------------DECLARATIONS-------------------------------------
	//std::string winner_ = "TBD";
	//std::string loser_;
	
	bool gameOver;
	
	int armysize_;
	
	
	int numRounds(0);
	int numCards_;
	int gamePlay(0);

	Card * deck_;
	deck_ = new Card[numCards_]; 

//------------------------------PRINT OUTS--------------------------------------

	
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
	

	while(numRounds= <= 50)
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
	
	std::cout << winner << " was the champion with " << numRounds << " victories versus " << loser << "." << std::endl;
	std::cout << "Player 1 Average Score: " << p1AvgScore_ << std::endl;
	std::cout << "Player 2 Average Score: " << p2AvgScore_ << std::endl;	
	
	return 0;
}