/*
 * FILE:        PioneerCarRadio.cpp
 * Project:	    PROG 1385 - Assignment 5
 * Author:	    Hoang Phuc Tran
 * Student ID:  8789102
 * Date:		June 23, 2022
 * Description:  This file contains all methods for the PioneerCarRadio class.
 *	- A constructor
 *		PioneerCarRadio(bool newOn, Freqs newButton[MAX_FREQS]);
 *	- A destructor
 *		~PioneerCarRadio(void)
 *	- Methods
 *		void DisplayRadio(void);
 *		int RadioManagement(void);
 */

#include "PioneerCarRadio.h"


 /*  -- Method Header Comment
	  Name	: PioneerCarRadio -- CONSTRUCTOR
	  Purpose : to instantiate a new PioneerCarRadio object by calling a constructor from the parent class AmFmRadio
	  Inputs	:	newOn			Bool		on
					newButton		Freqs       button
	  Outputs	:	NONE
	  Returns	:	Nothing
  */
PioneerCarRadio::PioneerCarRadio(bool newOn, Freqs newButton[MAX_FREQS], int newRadioType) : AmFmRadio(false, newButton, newRadioType ) {}


/*  -- Method Header Comment
	Name	: ~PioneerCarRadio -- DESTRUCTOR
	Purpose : to destroy the PioneerCarRadio object - free up the memory associated with the object
	Inputs	:	NONE
	Outputs	:	a final message from the object before being destroyed
	Returns	:	Nothing
*/
PioneerCarRadio::~PioneerCarRadio(void)
{
	if (GetDisplayOutPut())
	{
		cout << "Destroying Pioneer XS440 Radio\n";
	}
}

/*  -- Method Header Comment
	Name	: DisplayRadio
	Purpose : This method will display all current settings of the radio to stdout.
	Inputs	:	NONE
	Outputs	:	All the current settings
	Returns	:	NONE
*/
void PioneerCarRadio::DisplayRadio(void)
{
	// Check the type of radio before displaying
	switch (GetTypeOfRadio()) {

	case Pioneer_XS440:
		cout << "Pioneer XS440" << std::endl;
		break;

	case Pioneer_XS440_AM:
		cout << "Pioneer XS440-AM" << std::endl;
		break;

	case Pioneer_XS440_WRLD:
		cout << "Pioneer XS440-WRLD" << std::endl;
		break;

	default:
		break;


	}
	cout << "Radio is ";
	
	// Check the radio is on or off
	if (IsRadioOn() == false)
	{
		cout << "off" << endl;
	}
	else
	{
		cout << "on" << endl;

		// display volume
		cout << "Volume: " << GetNewVolume() << endl;

		// display the current station
		cout << "Current Station: " << setw(5) << GetCurrentStation();
		
		char* frequency = NULL;

		// Call the method to get "AM or FM" and then assign it to frequency variable
		frequency = GetFrequency();

		// Compare the string is AM or FM frequency
		if (strcmp(frequency, "AM") == 0)
		{
			cout << " AM" << endl;
		}
		else
		{
			cout << " PM" << endl;
		}

		cout << "AM buttons:" << endl;

		// Display all 5 "AM" buttons values in Freqs array 
		cout << "1: " << setw(5) << GetButton()[0].AMFreq << ",  ";
		cout << "2: " << setw(5) << GetButton()[1].AMFreq << ",  ";
		cout << "3: " << setw(5) << GetButton()[2].AMFreq << ",  ";
		cout << "4: " << setw(5) << GetButton()[3].AMFreq << ",  ";
		cout << "5: " << setw(5) << GetButton()[4].AMFreq << endl;


		if (GetTypeOfRadio() == Pioneer_XS440)
		{
			cout << "PM buttons:" << endl;
			// Display all 5 "PM" buttons values in Freqs array 
			cout << "1: " << setw(5) << (GetButton()[0].FMFreq) << ",  ";
			cout << "2: " << setw(5) << GetButton()[1].FMFreq << ",  ";
			cout << "3: " << setw(5) << GetButton()[2].FMFreq << ",  ";
			cout << "4: " << setw(5) << GetButton()[3].FMFreq << ",  ";
			cout << "5: " << setw(5) << GetButton()[4].FMFreq << endl;
		}
	}
}


/*  -- Method Header Comment
	Name	: RadioManagement
	Purpose : This method will handle the user's input, then It will respond to the input to
	perfrom an specific operation.
	Inputs	:	NONE
	Outputs	:	NONE
	Returns	:	int - 0 indicates successfull
*/
int PioneerCarRadio::RadioManagement(void)
{
	char userInput = 0;

	// Check if the user's input is 'x' character
	while (userInput != 'x')
	{
		int temporaryVolume = 0;

		// Clear the screen
		system("cls");

		// Display the radio
		DisplayRadio();

		// Get user's input
		userInput = getch();

		switch (userInput)
		{
		// User enters 'o' character to turn on or turn off the radio
		case 'o':
			// call PowerToggle to turn on or turn off the radio
			PowerToggle();
			break;
		// User enters '+' character to volume up by 1
		case '+':
			// assign the current volume to temporaryVolume variable
			temporaryVolume = GetNewVolume();
			// increasing by 1
			++temporaryVolume;
			// Then put the variable into setVolume method to set a new volume
			SetVolume(temporaryVolume);
			break;
		// User enters '-' character to volume down by 1
		case '_':
			// assign the current volume to temporaryVolume variable
			temporaryVolume = GetNewVolume();
			// decreasing by 1
			--temporaryVolume;
			// Then put the variable into setVolume method to set a new volume
			SetVolume(temporaryVolume);
			break;
		// User enters '=' character to scan up the current station
		case '=':
			// call ScanUp method the Scan up the current station
			ScanUp();
			break;
		// User enters '-' character to scan down the current station
		case '-':
			// call ScanUp method the Scan down the current station
			ScanDown();
			break;
		// User enters 'b' chacracter to switch band 
		case 'b':
			// Call the ToggleFrequency method to switch AM to FM or FM to AM
			ToggleFrequency();
			break;
		// User enters the number character 1 to 5
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
			// Subtract to '0' character to get the number 
			userInput = userInput - '0';
			// minus 1 to get the real index of array
			userInput = userInput - 1;	
			// Put the number into SelectCurrentStation method
			SelectCurrentStation(userInput);
			break;
		// User enter '!' to set button number one
		case '!':
			SetButton(0);
			break;
		// User enter '@' to set button number two
		case '@':
			SetButton(1);
			break;
		// User enter '#' to set button number three
		case '#':
			SetButton(2);
			break;
		// User enter '$' to set button number four
		case '$':
			SetButton(3);
			break;
		// User enter '%' to set button number five
		case '%':
			SetButton(4);
			break;
		// User enter 'x' to exit
		case 'x':
			break;
		default:
			break;
		}

	}

	return 0;
}

