/*
 * FILE:        utimateRadio.cpp
 * Project:	    PROG 1385 - Assignment 6
 * Author:	    Hoang Phuc Tran
 * Student ID:  8789102
 * Date:		August 05, 2022
 * Description:  This file is used as a testing harness for PioneerCarRadio, PioneerAM, and PioneerWorld
 class. It will display all the attributes of PioneerCarRadio, PioneerAM, and PioneerWorld radio according
 to the radio that the user enter.
 */
#include <stdio.h>
#include "PioneerCarRadio.h"
#include "PioneerAM.h"
#include "PioneerWorld.h"
#include <new>

// Constants
#define PIONEER_CAR_RADIO	'c'		// A single 'c' character represents PioneerCarRadio radio
#define PIONEER_AM			'a'		// A single 'a' character represents PioneerAM radio
#define PIONEER_WORLD		'w'		// A single 'w' character represents  PioneerWorld radio
#define EXIT 'x'					// A single 'w' character means quitting the program


// Prototype
PioneerCarRadio* createRadio(string input);


int main(int argc, char* argv[])
{
	// string get user's input
	string input;
	// this bool variable is used to check the string from the user
	bool validateInput = true;
	// this bool variable is used to check a single character from the user
	bool checkInputCharater = true;

	// copy c-style string into c++ string
	input = argv[1];

	while (validateInput)
	{
		// a pointer to  PioneerCarRadio variable
		PioneerCarRadio* pRadio = NULL;
		char inputCharater = 0;
		checkInputCharater = true;

		
		try
		{
			// Create a new radio based on the input on command line
			pRadio = createRadio(input);
		}
		// Catch the error and display the message
		catch(const char* errorString)
		{
			cerr << errorString << endl;
			return FAILURE;
		}
		// Catch the error about the allocation of memory
		catch (bad_alloc&) {
			cerr << "\nOut of memory!" << endl;
			return FAILURE;
		}

		// Call the RadioManagement methods from the PioneerCarRadio class
		pRadio->RadioManagement();

		// Free the memory
		delete(pRadio);

		// Clear the screen
		system("cls");


		while (checkInputCharater)
		{
			// Get a single character from the user
			inputCharater = getch();

			switch (inputCharater)
			{
			// User enters 'c' character to create and run a new PioneerCarRadio radio
			case PIONEER_CAR_RADIO:
				input = "-car";
				checkInputCharater = false;
				break;
			// User enters 'a' character to create and run a new PioneerAM radio
			case PIONEER_AM:
				input = "-am";
				checkInputCharater = false;
				break;
			// User enters 'w' character to create and run a new PioneerWorld radio
			case PIONEER_WORLD:
				input = "-world";
				checkInputCharater = false;
				break;
			// User enters 'x' character to quit the program
			case EXIT:
				validateInput = false;
				checkInputCharater = false;
				break;
			// User enters invalid characters
			default:
				checkInputCharater = true;
				break;
			}
		}
	}

	return SUCCESS;
}


/*
* Function: PioneerCarRadio* createRadio()
* Description : This function will prints all of the information contained within the map sorted by destination
* Parameters : one parameter - (string).
* Returns : A pointer to PioneerCarRadio class
*/
PioneerCarRadio* createRadio(string input)
{
	// Initilize a an array of 5 struct Freqs that contains the initial radio preset values
	Freqs presets[MAX_FREQS] = { { 1000, 102.1 },{ 1210, 104.3 },{ 800, 100.1 },{ 700,99.3 },{ 1300,89.7 } };

	// a pointer to  PioneerCarRadio variable
	PioneerCarRadio* pRadio = NULL;

	if (input == "-am") 
	{
		// Create a new PioneerAM class in the heap
		pRadio = new PioneerAM(false, presets, Pioneer_XS440_AM);
		return pRadio;
	}

	else if (input == "-car")
	{
		// Create a new PioneerCarRadio class in the heap
		pRadio = new PioneerCarRadio(false, presets, Pioneer_XS440);
		return pRadio;
	}

	else if (input == "-world")
	{
		// Create a new PioneerWorld class in the heap
		pRadio = new PioneerWorld(false, presets, Pioneer_XS440_WRLD);
		return pRadio;
	}
	// If the string is not valid, then it will throw a message
	else 
	{
		throw "SWITCH ENTERED IS NOT VALID!";
	}

	return NULL;
}