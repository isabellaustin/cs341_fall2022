// Honor Pledge:
//
// I pledge that I have neither given not
// received any help on this assignment
//
// iaustin

#ifndef CARD_H
#define CARD_H

#include <string>

/**
 * @class Card
 *
 * The Card class is an object that represents a single card in from a standard deck of cards.
 * It is mainly used to store and print the contents of a card. It also allows you to initialize in two ways:
 * 1) via the initialize function (that sets both values at once), and 
 * 2) via a non-default constructor, if you happen to want to do it when you declare a Card instance
 */
class Card
{
	protected:
		std::string suit_;
		std::string face_;
	
	private:
		int suitVal_;				// contains the index of the suit array that corresponds to the suit of the card
		int faceVal_;				// contains the index of the face array that corresponds to the face of the card
		static std::string SUIT[5];
		static std::string FACE[14];
        
	public:
		// Constructors/Destructors
		Card();	/// Default constructor.	
		Card(int, int);	/**
						   * Initializing constructor.
						   *
						   * @param[in]      Suit
						   * @param[in]		 Face
						   */
		virtual ~Card(); /// Destructor

		//Accessor Methods
		void setSuitVal(int suitVal);
		int getSuitVal();
		void setFaceVal(int faceVal);
		int getFaceVal();
		void setSuit(std::string suit);
		void setFace(std::string face);
  	
		
		std::string getSuit();	/**Returns the string corresponding to the suit of the card
								 * 
								 *
								 * @return          Suit
								*/  
 
		std::string getFace();	/**
								 * Returns the string corresponding to the face of the card
								 *
								 * @return          Face
								*/
		
		void print();	/**
						 * Returns a string with the full name of the card. (e.g., "Ace of Spades")
						 *
						 * @return          String
						*/
			
		void initialize(int, int);	/**
									 * Returns a string with the full name of the card. (e.g., "Ace of Spades")
									 *
									 * @param[in]      Suit
									 * @param[in]	   Face
									*/
};

#endif