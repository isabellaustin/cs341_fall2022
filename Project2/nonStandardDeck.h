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
	public:
		NonStandardDeck(); /// Default constructor.
		NonStandardDeck(int);
		~NonStandardDeck(); /// Default destructor.
		
		virtual void populateDeck() = 0;
