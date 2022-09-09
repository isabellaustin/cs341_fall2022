// Honor Pledge:
//
// I pledge that I have neither given not
// received any help on this assignment
//
// iaustin

#include <iostream>
#include <fstream> // File Stream Library
#include "Car.h"


void simulateRace(Car racer[])		
{
	bool winner(false);
	srand((unsigned) time(0)); //the tutor told me to use this
	std::cout << "***--> Racing..." << std::endl;
	
	while(!winner)
	{
		int advance(0);

		for(int i(0); i<33; i++)
		{
			if(racer[i].getControl() > 5)
			{
				int r = 1 + (rand() % 10);
				advance += racer[i].getControl()/r;
			}
			
			advance += racer[i].getSpeed();
			racer[i].setLapNum(racer[i].getLapNum()+advance);
						
			if(racer[i].getLapNum() == 200)
			{
				winner = true;
				
				std::cout << std::endl;
				std::cout << "***" << racer[i].getName() << " has won the 2022 Indianapolis 500! ***" << std::endl;
				
				break;
			}
		}
	}
	
	while(winner=true)
	{	
		std::cout << std::endl;
		std::cout << "Driver Name: Lap Number" << std::endl;
		std::cout << "***********************" << std::endl;
		
		for(int i(0); i<33; i++)
		{
			racer[i].printInfo();
		}	
		break;
	}
}


int main()
{
	std::ifstream inputFile("indy500.txt");
	
	std::cout << "***Welcome to the 2022 Indianapolis 500 Race!***" << std::endl;
	std::cout << std::endl;
	
	std::string name("");
	int speed;
	int control;
	int cars(0);
	Car newRacer;
	Car racetrack[33];
	
	if(inputFile.is_open())
	{
		while(!inputFile.eof())
		{
			while(cars!=33)
			{
				inputFile >> name >> speed >> control;	
				Car newRacer(name,speed,control);
				racetrack[cars] = newRacer;
				cars++;
			}
			simulateRace(racetrack);
		}
		
		inputFile.close();
		
		std::cout << std::endl;
		std::cout << "Thank you for racing - see you next year!" << std::endl;	
	}
	else
	{
		std::cout << "Unable to open file" << std::endl;
	} 

	return 0;
}