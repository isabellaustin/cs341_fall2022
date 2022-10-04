// Honor Pledge:
//
// I pledge that I have neither given not
// received any help on this assignment
//
// iaustin

#ifndef NON_STANDARD_DECK_H
#define NON_STANDARD_DECK_H

#include <string>
#include <iostream>

#include "standardDeck.h"

class NonStandardDeck
{
	protected: 
		// Dr. R: We shouldn't need this here - as these are Card attributes.
		int suit_, face_;
	public:
		NonStandardDeck(); /// Default constructor.
		NonStandardDeck(int);
		virutal ~NonStandardDeck(); /// Default destructor.
		
		// Dr. R: The Card class creates a card - let it do its thing.
		void create_card (int a, int b) 
		{ 
			suit_=a; 
			face_=b; 
		}
		
		// Pure (= 0) Virtual Method Declaration
		virtual void populateDeck() = 0;
		
// Dr. R: Missing closing } here and ;
