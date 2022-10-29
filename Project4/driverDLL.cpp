// Honor Pledge:

// I pledge that I have neither given nor
// received any help on this assignment.

// iaustin and aschroeder 

//driverDLL.cpp

#include "DoublyLinkedList.h"

#include <iostream>
#include <fstream>

int main()
{
	DoublyLinkedList Dlist;
	int totHops = 0;
	
//-------------------CREATING LIST OF DATA FROM DATA.TXT INTO DLIST--------------------
	std::ifstream inputFile("data.txt");
	std::cout << "data.txt ------------------" << std::endl;
	LinkedNode * Hlink_ = new LinkedNode(0, nullptr, nullptr);	
	if(inputFile.is_open())
	{
		int dataVal = 0;
		
		inputFile >> dataVal;
		Hlink_->setValue(dataVal);
		Dlist.setHead(Hlink_); //setting the head
		Dlist.setTail(Hlink_); //setting the tail
		
		while(!inputFile.eof())
        {
			//LinkedNode * link_ = Dlist.getHead();
			inputFile >> dataVal;
			
			Dlist.insertNode(Hlink_, dataVal);
		}
	}
	inputFile.close();
	
	//Dlist.printList();
	
//-----------------CREATING LIST OF DATA FROM SORTED.TXT-------------------
	DoublyLinkedList Slist;
	int StotHops = 0;
	
	std::ifstream SinputFile("sorted.txt");
	std::cout << "sorted.txt ------------------" << std::endl;
	LinkedNode * Slink_ = new LinkedNode(0, nullptr, nullptr);	
	if(SinputFile.is_open())
	{
		int dataVal = 0;
		
		SinputFile >> dataVal;
		Slink_->setValue(dataVal);
		Slist.setHead(Slink_); //setting the head
		Slist.setTail(Slink_); //setting the tail
		
		while(!SinputFile.eof())
        {
			//LinkedNode * link_ = Dlist.getHead();
			SinputFile >> dataVal;
			
			Slist.insertNode(Slink_, dataVal);
		}
	}
	SinputFile.close();
	
//-------------------INSERTING INTO DATA LIST--------------------
	inputFile.open("inserts.txt");
	std::cout << "inserts.txt ---------------" << std::endl;
	if(inputFile.is_open())
	{
		int insertVal = 0;
		
		while(!inputFile.eof())
        {	
			LinkedNode * temp = Dlist.getHead(); //headhop calculator
			LinkedNode * temp2 = Dlist.getTail(); //tailhop calculator
			LinkedNode * head = Dlist.getHead();
			LinkedNode * tail = Dlist.getTail();
			
			int hHops = 0; //head hops
			int tHops = 0; //tail hops
			
			inputFile >> insertVal;
			
			if(insertVal <= head->getValue()) // if data is less than head, insert at head
            {
                Dlist.insertBeforeLinkedNode(head, insertVal);
            }
            else if(insertVal >= tail->getValue()) // if data is greater/equal to than tail, insert at tail
            {
				Dlist.insertAfterLinkedNode(tail, insertVal);
            }
            else  
            {
                while(insertVal >= temp->getValue())
                {   
                    if(insertVal < temp->getValue())
                    {
                        temp = temp->getPrevLinkedNode();
                        //hHops++;
                        break; 
                    }
                    
                    temp = temp->getNextLinkedNode();
                    hHops++;
                }
                        
                while(insertVal <= temp2->getValue())
                {
                    
                    if(insertVal > temp2->getValue())
                    {
                        temp2 = temp2->getNextLinkedNode();
                        break;
                    }
                    temp2 = temp2->getPrevLinkedNode();
                    tHops++;
                }

                if (hHops<=tHops)
                {
                    Dlist.insertBeforeLinkedNode(temp, insertVal);
                    totHops=totHops+hHops; 
                   
                }
                if (tHops<=hHops)
                {
                    Dlist.insertBeforeLinkedNode(temp, insertVal); //before or after
                    totHops=totHops+tHops;    
                }
            }
        }
    }
    inputFile.close();
	
//-------------------INSERTING INTO SORTED LIST----------------------------------
	
	SinputFile.open("inserts.txt");
	std::cout << "inserts.txt ---------------" << std::endl;
	if(SinputFile.is_open())
	{
		int insertVal = 0;
		
		while(!SinputFile.eof())
        {	
			LinkedNode * temp = Slist.getHead(); //headhop calculator
			LinkedNode * temp2 = Slist.getTail(); //tailhop calculator
			LinkedNode * head = Slist.getHead();
			LinkedNode * tail = Slist.getTail();
			
			int hHops = 0; //head hops
			int tHops = 0; //tail hops
			
			SinputFile >> insertVal;
			
			if(insertVal <= head->getValue()) // if data is less than head, insert at head
            {
                Slist.insertBeforeLinkedNode(head, insertVal);
            }
            else if(insertVal >= tail->getValue()) // if data is greater/equal to than tail, insert at tail
            {
				Slist.insertAfterLinkedNode(tail, insertVal);
            }
            else  
            {
                while(insertVal >= temp->getValue())
                {   
                    if(insertVal < temp->getValue())
                    {
                        temp = temp->getPrevLinkedNode();
                        //hHops++;
                        break; 
                    }
                    
                    temp = temp->getNextLinkedNode(); 
                    hHops++;
                }
                        
                while(insertVal <= temp2->getValue())
                {
                    
                    if(insertVal > temp2->getValue())
                    {
                        temp2 = temp2->getNextLinkedNode();
                        break;
                    }
                    temp2 = temp2->getPrevLinkedNode();
                    tHops++;
                }

                if (hHops<=tHops)
                {
                    Slist.insertBeforeLinkedNode(temp, insertVal);
                    StotHops=StotHops+hHops; 
                   
                }
                if (tHops<=hHops)
                {
                    Slist.insertBeforeLinkedNode(temp, insertVal); //before or after
                    StotHops=StotHops+tHops;    
                }
            }
        }
    }
    SinputFile.close();

//-------------------PRINTING RESULTS INTO OUTPUT.TXT--------------------
	std::ofstream outputFile("output.txt");
	if(outputFile.is_open())
	{
		LinkedNode * current = Dlist.getHead();
		int i=0;
		do{
			outputFile << current->getValue();
			current = current->getNextLinkedNode();
			if(current != Dlist.getTail())
			{
				outputFile << "<-->";
			}
			if (current == Dlist.getTail())
			{
				outputFile << "<-->" << Dlist.getTail()->getValue();
			}
			i++;
		}while(current != nullptr); 
		
		/*outputFile << std::endl;
		outputFile << "Total Number of Big Dawg Hops: " << totHops <<std::endl;*/ // Error checking purposes, matched README.txt file
		
		delete current;
	}
	outputFile.close();
	
//------------------PRINTING RESULTS INTO SORTEEDOUTPUT.TXT-------------------
	std::ofstream SoutputFile("sortedOutput.txt");
	if(SoutputFile.is_open())
	{
		LinkedNode * current = Slist.getHead();
		int i=0;
		do{
			SoutputFile << current->getValue();
			current = current->getNextLinkedNode();
			if(current != Slist.getTail())
			{
				SoutputFile << "<-->";
			}
			if (current == Slist.getTail())
			{
				SoutputFile << "<-->" << Slist.getTail()->getValue();
			}
			i++;
		}while(current != nullptr); 
		
		/*SoutputFile << std::endl;
		SoutputFile << "Total Number of Big Dawg Hops: " << StotHops <<std::endl;*/ // Error checking purposes, matched README.txt file
		
		delete current;
	}
	SoutputFile.close();
	
//-----------------CREATING THE README.TXT----------------------
	std::ofstream readMeFile("README.txt");
	if(readMeFile.is_open())
	{
		readMeFile << "Total Number of Big Dawg Hops from Unsorted List: " << totHops <<std::endl;
		readMeFile << "Total Number of Big Dawg Hops from Sorted List: " << StotHops <<std::endl;
	}
	readMeFile.close();
	
//----------------POINTER GRAVEYARD-------------------------------
	Hlink_=Dlist.getHead();
	while(Hlink_ != Dlist.getTail())
		{
			Hlink_ = Hlink_->getNextLinkedNode();
			delete Hlink_->getPrevLinkedNode();
		}

	delete Hlink_;
	
	Slink_ = Slist.getHead();
	while(Slink_ != Slist.getTail())
		{
			Slink_ = Slink_->getNextLinkedNode();
			delete Slink_->getPrevLinkedNode();
		}

	delete Slink_;

	return 0;
}