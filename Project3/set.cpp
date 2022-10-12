// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// iaustin and aschroeder

#include "set.h"

//Constructor
Set::Set(int size) : data_(size)
{
	
}
                        
/// Destructor
Set::~Set()
{
	
}

void Set::initialize(char * word, int size)
{	
	data_.initialize(word, size);
}

int Set::getCardinality() const
{
	int cardinality = 0;
	int condition;
	
	for(int i=0; i<data_.length(); i++)
	{
		// Dr. R: We could combine this into our IF-Statement.
		condition = data_.get(i);
		
		if(condition == 1)
		{ 	cardinality++; }
	}
	
	return cardinality;
}
   
BitArray & Set::getData()
{
	return data_;
}	

bool Set::setUnion(Set & B)
{
	//BitArray Union(data_.bytes());
	char c;
	
	if(data_.length() >= (B.getData()).length()) // Checks if the BitArrays are compatible lengths
	{ 
		for(int i=0; i < B.getData().bytes(); i++)
		{			
			c = data_.get8(i*8) | B.getData().get8(i*8);			
			data_.set8(c, i);
		}
		
		// Fill remaining bytes in A with 0
		for( int i=B.getData().bytes(); i<data_.bytes(); i++)
		{
			data_.set8(0,i);
		}

		return 1;	
	}
	
	return 0;

}

bool Set::setIntersection(Set & B)
{
	//BitArray Intersect(data_.bytes());
	char c;
	
	if(data_.length() >= (B.getData()).length()) // Checks if the BitArrays are compatible lengths
	{ for(int i=0; i<data_.bytes(); i++)
		{			
			c = data_.get8(i*8) & (B.getData()).get8(i*8);			
			data_.set8(c, i);
		}
		
		// Fill remaining bytes in A with 0
		for( int i=B.getData().bytes(); i<data_.bytes(); i++)
		{
			data_.set8(0,i);
		}
		
		return 1;
	}
	
	return 0;
}