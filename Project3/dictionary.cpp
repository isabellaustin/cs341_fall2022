// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// iaustin and aschroeder

#include "dictionary.h"

Dictionary::Dictionary() : data_()
{
	lookupTable_ = new int[DICTIONARY_SIZE];
	
	//building the lookup table
	for(int i=0; i<DICTIONARY_SIZE; i++) 
	{
		Set A(1);
		char test[1];
		
		test[0] = i;
		A.initialize(test,1);
		lookupTable_[i] = A.getCardinality();
	}
	
}	

Dictionary::Dictionary (const Dictionary & dict) : data_()
{	
	if(dict.lookupTable_)
	{
		lookupTable_ = new int[DICTIONARY_SIZE];
		
		for(int i=0; i<DICTIONARY_SIZE; i++) 
		{
			lookupTable_[i] = dict.lookupTable_[i];
		}
	}
}	

Dictionary::~Dictionary()
{
	delete [] lookupTable_;
}	
    
void Dictionary::initialize(char * word, int size)
{
	data_.initialize(word, size);
}	

int Dictionary::rank_range(int start, int end, int bit)//WORKS
{
	// Phase IV
	int rrange = 0;
	int condition;
	
	for(int i=start; i<end; i++) // (start+1): rank_range doesnt include start // [square bracket] means INCLUDE, so just start? -AS
	{			
		condition = data_.get(i);
			
		if(condition == bit)
		{ 	rrange++; }
	}
	
	return rrange;
	
	
}	
            
int Dictionary::select_range(int start, int end, int k, int bit) //WORKS
{
	int position = start; // Should this be set equal to start?? -AS
	int count = 0;
	int srange;

	for(int i=start; i<end; i++) // ?? (start+1): select_range doesnt include start // [square bracket] means INCLUDE, so no change -AS
	{
		srange = data_.get(i);
		
		if(srange == bit && count != k) //(k-1) instead of k ?? // I don't think so, this makes sense to me -AS
		{ count++; }
		if (count == k) // Changed this to an if statement so that the loop will break before position++
		{	break;	}

		position++;	
	}

	if(count != k)		// Added condition in case k is not within the range
	{	return -1;	}
	else
	{	return position;	}
}	

int Dictionary::rank(int end, int bit) //WORKS
{	
	// Phase IV
	//Rank tells you how many 1s there are in the range [0, j)
	/*int rank = 0;
	int condition;
	
	for(int i=0; i<end; i++) //start at 0 or 1? // ZERO -AS
	{			
		condition = data_.get(i);
			
		if(condition == bit)
		{ 	rank++; }
	}
	
	return rank;*/
	
	// Phase V -------------------------------------------------------------- WORKS
	int rank=0;
	
	for(int i=0; i<data_.bytes(); i++)
	{
		rank = rank + lookupTable_[data_.get8(i*BIT_IN_BYTE)]; // Finds the corresponding cardinality in lookupTable_
	}
	
	return rank;
}

int Dictionary::select(int k, int bit) //WORKS
{	
	// Phase IV
	/*int position = 0;
	int count = 0;
	int select;
	
	// I added the LENGTH variable to the initializer in bitarray.cpp, so now it can be accessed through data_

	for(int i=0; i<(data_.length()-1); i++) // Should this be data_.length()-1 ??
	{
		select = data_.get(i);
		
		if(select == bit && count != k) //k-1 bc k needs to start at 0 ?? // ?? Just k, similar to select_range -AS
		{ count++; }
		if (count == k)
		{	break;	}

		position++;	
	}
	
	if(count != k)		// Added condition in case k is not within the range
	{	return -1;	}
	else
	{	return position;	}*/

	// Phase V -------------------------------------------------------------- WORKS
	int count = 0;
	int index = -1;
	int position = 0;
	int select;
	
	while(count < k)
	{
		index++;
		count = count + lookupTable_[data_.get8(index)]; // Does the initial count through lookupTable_
	}
	
	count = count - lookupTable_[data_.get8(index)]; // Subtract the index that caused it to be > k
	position = (index*BIT_IN_BYTE) - 1; 			// Find the highest bit position where count was still < k
	
	for(int i=position; i<(data_.length()-1); i++)	// Start the loop at that position
	{
		select = data_.get(i);						// Slower version, but accounts for partial bytes
		
		if(select == bit && count != k) //k-1 bc k needs to start at 0 ?? // ?? Just k, similar to select_range -AS
		{ count++; }
		if (count == k)
		{	break;	}

		position++;	
	}
	
	if(count != k)		// Added condition in case k is not within the range
	{	return -1;	}
	else
	{	return position;	}
		

}	

void Dictionary::printLookupTable(std::ostream & output)
{	//lookupTable_[B.get8(i)], lookupTable_[i],  A.getCardinality()
	//lookupTable_[i] = data_.getCardinality();
	
	for(int i=0; i<DICTIONARY_SIZE; i++) 
	{
		output << "lookupTable_["<< i << "]		" << lookupTable_[i] << std::endl;
	}
}