// Honor Pledge:
//
// I pledge that I have neither given not
// received any help on this assignment
//
// iaustin

#ifndef STANDARD_DECK_H
#define STANDARD_DECK_H

#include <string>
#include <iostream>

#include "card.h"

#define DECK_SIZE 52

/*
 * @class StandardDeck
 *
 * The StandardDeck class represents a standard deck of 52 cards.
 * 
 */
class StandardDeck
{
	public:
		StandardDeck(); /// Default constructor.
		StandardDeck(int);
		~StandardDeck(); /// Default destructor.

		bool isEmpty();	/*
						 * Returns True/False (1/0) whether or not the Deck is empty.
						 *
						 * @return          Boolean
						*/
							
		bool addCard(Card c);
		
		bool mergeDecks(StandardDeck &, bool);

		int getNumCards();	/*
							 * Returns the number of cards remaining in the deck.
							 *
							 * @return          Integer		value
							*/ 
		
		
		void populateDeck();
		
		Card displayCard(int i); 	/**
									 * Displays the i'th card in the Deck.
									 *
									 * @param[in]      Index
									*/

		void printDeck();	/**
							 * Prints the contents of the Deck. This method should call the 
							 * print() method on each Card.
							*/	
		
		void shuffle();
		
		Card dealCard();
		
		Card * deck_;	// Pointer to record the location of the array of Cards in memory.
	
	protected: 	
		Card * p1;
		Card * p2;
		Card * battleground;
		
		int numCards_;	// Stores the number of Cards currently in the deck.
		std::string winner_;
		std::string loser_;
		int p1AvgScore_;
		int p2AvgScore_;
		int numRounds;
		int armysize_;
		
};

#endif